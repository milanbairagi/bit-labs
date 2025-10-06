
"""
Goal-Based Agent for Wumpus World

A goal-based agent makes decisions by:
1. Maintaining explicit goals (FIND_GOLD, RETURN_HOME, EXIT)
2. Creating plans to achieve those goals
3. Executing the plan step-by-step
4. Updating goals based on the current state

Key differences from model-based agent:
- Explicitly tracks and switches between goals
- Plans entire sequences of actions to achieve goals
- More strategic: knows WHY it's doing each action
"""

from collections import deque

class GoalBasedAgent:
    def __init__(self):
        self.visited = set()
        self.safe = set()
        self.has_arrow = True
        self.goal = "FIND_GOLD"  # Goals: FIND_GOLD, RETURN_HOME, EXIT
        self.plan = []  # Sequence of actions to achieve current goal
        
    def update_knowledge(self, percept, pos, size):
        """Update world knowledge based on percepts."""
        x, y = pos
        self.visited.add(pos)
        self.safe.add(pos)
        
        # Mark adjacent cells as safe if no danger perceived
        if not percept.breeze and not percept.stench:
            for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
                adj = (x+dx, y+dy)
                if 0 <= adj[0] < size and 0 <= adj[1] < size:
                    self.safe.add(adj)
    
    def update_goal(self, env):
        """Update current goal based on world state."""
        if env.agent_has_gold and self.goal == "FIND_GOLD":
            self.goal = "RETURN_HOME"
            self.plan = []  # Clear old plan
        elif env.agent_has_gold and env.agent_pos == (0, 0):
            self.goal = "EXIT"
            
    def make_plan_for_goal(self, env):
        """Create a plan to achieve the current goal."""
        if self.goal == "FIND_GOLD":
            # Plan: explore safe unvisited cells to find gold
            return self.plan_exploration(env)
        elif self.goal == "RETURN_HOME":
            # Plan: navigate back to (0,0) through visited cells
            return self.plan_path_to_start(env.agent_pos)
        elif self.goal == "EXIT":
            # No plan needed, just climb
            return ["CLIMB"]
        return []
    
    def plan_exploration(self, env):
        """Plan to explore nearest safe unvisited cell."""
        x, y = env.agent_pos
        
        # Check adjacent safe unvisited cells
        for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
            adj = (x+dx, y+dy)
            if adj in self.safe and adj not in self.visited:
                return [self.get_move_action(env.agent_pos, adj, env.agent_dir)]
        
        # Find path to any safe unvisited cell through visited cells
        for safe_cell in self.safe - self.visited:
            path = self.find_path(env.agent_pos, safe_cell)
            if path and len(path) > 1:
                return [self.get_move_action(env.agent_pos, path[1], env.agent_dir)]
        
        return ["TURN_RIGHT"]  # No safe cells to explore
    
    def plan_path_to_start(self, current_pos):
        """Plan path back to (0,0) using BFS through visited cells."""
        if current_pos == (0, 0):
            return []
        
        path = self.find_path(current_pos, (0, 0))
        if path and len(path) > 1:
            return path
        return []
    
    def find_path(self, start, goal):
        """BFS to find path from start to goal through visited cells."""
        if start == goal:
            return [start]
        
        queue = deque([(start, [start])])
        seen = {start}
        
        while queue:
            pos, path = queue.popleft()
            x, y = pos
            
            for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
                next_pos = (x+dx, y+dy)
                if next_pos == goal:
                    return path + [next_pos]
                if next_pos in self.visited and next_pos not in seen:
                    seen.add(next_pos)
                    queue.append((next_pos, path + [next_pos]))
        return []
    
    def get_move_action(self, from_pos, to_pos, current_dir):
        """Get action needed to move from one position to adjacent position."""
        dx = to_pos[0] - from_pos[0]
        dy = to_pos[1] - from_pos[1]
        
        # Map movement to required direction
        dir_map = {(0,1): "N", (1,0): "E", (0,-1): "S", (-1,0): "W"}
        target_dir = dir_map.get((dx, dy))
        
        if not target_dir:
            return "FORWARD"
        
        # Calculate turn needed
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
            return "TURN_RIGHT"  # 180 degree turn
    
    def execute_plan(self, env):
        """Execute next action from current plan."""
        if not self.plan:
            return None
            
        action = self.plan[0]
        
        # If action is FORWARD and we're following a path, pop it after execution
        if action == "FORWARD" and len(self.plan) > 0:
            self.plan.pop(0)
        # For turns, remove from plan
        elif action in ["TURN_LEFT", "TURN_RIGHT", "CLIMB"]:
            self.plan.pop(0)
        # For paths (list of positions), convert next step to action
        elif isinstance(self.plan[0], tuple) and len(self.plan) > 1:
            next_pos = self.plan[1]
            action = self.get_move_action(env.agent_pos, next_pos, env.agent_dir)
            if action == "FORWARD":
                self.plan.pop(0)
            return action
        else:
            self.plan.pop(0)
            
        return action
    
    def action(self, percept, env):
        """Main decision-making method."""
        # Update world knowledge
        self.update_knowledge(percept, env.agent_pos, env.size)
        
        # Immediate reactions (override planning)
        if percept.glitter:
            return "GRAB"
        
        # Update goal based on current state
        self.update_goal(env)
        
        # If goal is EXIT and we're at start, climb out
        if self.goal == "EXIT" and env.agent_pos == (0, 0):
            return "CLIMB"
        
        # Try to execute existing plan
        if self.plan:
            action = self.execute_plan(env)
            if action:
                return action
        
        # Create new plan for current goal
        self.plan = self.make_plan_for_goal(env)
        
        # Execute first step of new plan
        if self.plan:
            return self.execute_plan(env)
        
        # Fallback: turn right if no plan available
        return "TURN_RIGHT"