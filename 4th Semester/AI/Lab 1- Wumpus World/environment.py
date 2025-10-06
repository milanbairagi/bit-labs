from dataclasses import dataclass

@dataclass
class Percept:
    stench: bool
    breeze: bool
    glitter: bool
    bump: bool
    scream: bool
    

class WumpusWorld:
    def __init__(self, size=4, pits=None, wumpus=(2,2), gold=(0,3), agent_pos=(0,0), agent_dir="E"):
        self.size = size
        self.pits = set(pits or [(1,3), (3,1)])  # sample pit coords (x,y)
        self.wumpus = wumpus  # coordinates of wumpus; None if dead
        self.gold = gold      # coordinates of gold
        self.agent_pos = agent_pos
        self.agent_dir = agent_dir  # "N","E","S","W"
        self.agent_has_gold = False
        self.agent_alive = True
        self.has_arrow = True
        self.scream = False

    def in_bounds(self, x, y):
        return 0 <= x < self.size and 0 <= y < self.size

    def adjacent(self, x, y):
        # returns coordinates adjacent (4-neighborhood)
        return [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]

    def percept(self):
        x,y = self.agent_pos
        stench = False
        breeze = False
        glitter = False
        bump = False
        scream = self.scream
        # stench if adjacent to live wumpus
        if self.wumpus is not None:
            wx,wy = self.wumpus
            stench = any((nx,ny) == (wx,wy) for (nx,ny) in self.adjacent(x,y))
        # breeze if adjacent to any pit
        breeze = any((nx,ny) in self.pits for (nx,ny) in self.adjacent(x,y))
        # glitter if on gold
        glitter = (x,y) == self.gold
        return Percept(stench, breeze, glitter, bump, scream)

    def forward_delta(self):
        x,y = self.agent_pos
        if self.agent_dir == "N":
            return (x, y+1)
        if self.agent_dir == "S":
            return (x, y-1)
        if self.agent_dir == "E":
            return (x+1, y)
        if self.agent_dir == "W":
            return (x-1, y)

    def do_action(self, action):
        """Execute action and return resulting percept (with bump & scream updated)."""
        self.scream = False
        bump = False
        
        if action == "FORWARD":
            nx,ny = self.forward_delta()
            if not self.in_bounds(nx,ny):
                bump = True
            else:
                self.agent_pos = (nx,ny)
                # check hazards
                if self.wumpus is not None and self.agent_pos == self.wumpus:
                    # agent walks into live wumpus -> dead
                    self.agent_alive = False
                if self.agent_pos in self.pits:
                    self.agent_alive = False
                    
        elif action == "TURN_LEFT":
            dirs = ["N","W","S","E"]
            i = dirs.index(self.agent_dir)
            self.agent_dir = dirs[(i+1)%4]
            
        elif action == "TURN_RIGHT":
            dirs = ["N","E","S","W"]
            i = dirs.index(self.agent_dir)
            self.agent_dir = dirs[(i+1)%4]
            
        elif action == "GRAB":
            if self.agent_pos == self.gold:
                self.agent_has_gold = True
                self.gold = None
                
        elif action == "SHOOT":
            if self.has_arrow:
                self.has_arrow = False
                # arrow flies straight until wall; if hits wumpus, it dies and scream is True
                x,y = self.agent_pos
                dx,dy = 0,0
                if self.agent_dir == "N": dx,dy = 0,1
                if self.agent_dir == "S": dx,dy = 0,-1
                if self.agent_dir == "E": dx,dy = 1,0
                if self.agent_dir == "W": dx,dy = -1,0
                tx,ty = x+dx, y+dy
                while self.in_bounds(tx,ty):
                    if self.wumpus == (tx,ty):
                        self.wumpus = None
                        self.scream = True
                        break
                    tx += dx
                    ty += dy
                    
        elif action == "CLIMB":
            # agent can climb out only if at (0,0) - standard
            if self.agent_pos == (0,0):
                return "EXIT"
        else:
            pass
        
        # create percept after action; include bump and scream flags
        p = self.percept()
        # override bump and scream in percept to reflect this action
        p = Percept(p.stench, p.breeze, p.glitter, bump, self.scream)
        return p
    
    def draw(self):
        grid = [[" " for _ in range(self.size)] for _ in range(self.size)]

        if self.gold is not None:
            gx, gy = self.gold
            grid[gy][gx] = "G"
            
        for (px,py) in self.pits:
            grid[py][px] = "P"
            
        if self.wumpus is not None:
            wx, wy = self.wumpus
            grid[wy][wx] = "W"
            
        for (ax,ay) in [self.agent_pos]:
            grid[ay][ax] = "A"
        
        # Print grid Upside down (y=0 at bottom)
        dir = {
            "N": "↑", "E": "→", "S": "↓", "W": "←"
        }
        print("Direction:", dir[self.agent_dir])
        for j in range(self.size-1, -1, -1):
            row = grid[j]
            print("|", " | ".join(row), "|")
            if j > 0:
                print("|", "- + " * (self.size -1) + "-", "|")