from collections import deque

class ModelBasedAgent:
    def __init__(self):
        self.visited = set()
        self.safe = set()
        self.has_arrow = True
        self.path_to_start = []  # Store path back to start after getting gold

    def update_model(self, percept, pos, size):
        """Update knowledge about safe cells."""
        x, y = pos
        self.visited.add(pos)
        self.safe.add(pos)
        
        # If no breeze and no stench, all adjacent cells are safe
        if not percept.breeze and not percept.stench:
            for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
                adj = (x+dx, y+dy)
                if 0 <= adj[0] < size and 0 <= adj[1] < size:
                    self.safe.add(adj)

    def get_safe_path_to_start(self, start):
        """BFS to find path back to (0,0) through visited cells."""
        if start == (0, 0):
            return []
        
        queue = deque([(start, [start])])
        seen = {start}
        
        while queue:
            pos, path = queue.popleft()
            x, y = pos
            
            for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
                next_pos = (x+dx, y+dy)
                if next_pos == (0, 0):
                    return path + [(0, 0)]
                if next_pos in self.visited and next_pos not in seen:
                    seen.add(next_pos)
                    queue.append((next_pos, path + [next_pos]))
        return []

    def get_next_move(self, from_pos, to_pos, current_dir):
        """Get action to move from one position to an adjacent position."""
        dx = to_pos[0] - from_pos[0]
        dy = to_pos[1] - from_pos[1]
        
        # Map delta to direction
        dir_map = {(0,1): "N", (1,0): "E", (0,-1): "S", (-1,0): "W"}
        target_dir = dir_map.get((dx, dy))
        
        if not target_dir:
            return "FORWARD"
        
        # Calculate turns needed
        dirs = ["N", "E", "S", "W"]
        current_idx = dirs.index(current_dir)
        target_idx = dirs.index(target_dir)
        diff = (target_idx - current_idx) % 4
        
        if diff == 0:
            return "FORWARD"
        elif diff == 1:
            return "TURN_RIGHT"
        elif diff == 3:
            return "TURN_LEFT"
        else:
            return "TURN_RIGHT"  # Turn around (will need 2 turns)

    def action(self, percept, env):
        """Decide action based on percepts and internal model."""
        self.update_model(percept, env.agent_pos, env.size)
        
        # Grab gold if found
        if percept.glitter:
            return "GRAB"
        
        # Climb out if at start with gold
        if env.agent_has_gold and env.agent_pos == (0, 0):
            return "CLIMB"
        
        # Return to start if we have gold
        if env.agent_has_gold:
            if not self.path_to_start:
                self.path_to_start = self.get_safe_path_to_start(env.agent_pos)
            
            if len(self.path_to_start) > 1:
                next_pos = self.path_to_start[1]
                action = self.get_next_move(env.agent_pos, next_pos, env.agent_dir)
                if action == "FORWARD":
                    self.path_to_start.pop(0)
                return action
        
        # Explore: find path to nearest safe unvisited cell
        x, y = env.agent_pos
        for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
            adj = (x+dx, y+dy)
            if adj in self.safe and adj not in self.visited:
                return self.get_next_move(env.agent_pos, adj, env.agent_dir)
        
        # No adjacent unvisited safe cells, backtrack to find one
        for safe_cell in self.safe - self.visited:
            path = self.find_path_through_visited(env.agent_pos, safe_cell)
            if path and len(path) > 1:
                next_pos = path[1]
                return self.get_next_move(env.agent_pos, next_pos, env.agent_dir)
        
        # Default: turn right if stuck
        return "TURN_RIGHT"
    
    def find_path_through_visited(self, start, goal):
        """BFS to find path from start to goal through visited cells."""
        queue = deque([(start, [start])])
        seen = {start}
        
        while queue:
            pos, path = queue.popleft()
            if pos == goal:
                return path
            
            x, y = pos
            for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
                next_pos = (x+dx, y+dy)
                # Allow stepping into the goal even if it's not yet in visited
                if next_pos not in seen and (next_pos == goal or next_pos in self.visited):
                    seen.add(next_pos)
                    queue.append((next_pos, path + [next_pos]))
        return []