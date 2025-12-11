class SimpleAgent:
    def __init__(self):
        self.world = {}        # Stores knowledge of the world
        self.position = (0, 0) # Starting position
        self.has_gold = False
        self.arrow = True
        self.visited = set()

    def update_world(self, breeze, stench, glitter):
        """Update knowledge about current cell"""
        x, y = self.position
        self.world[(x, y)] = {
            "breeze": breeze,
            "stench": stench,
            "glitter": glitter,
            "safe": not (breeze or stench),
            "visited": True
        }
        self.visited.add((x, y))

    def is_safe(self, pos):
        """Check if a cell is safe to move into"""
        if pos in self.world:
            return self.world[pos].get("safe", False)
        return False

    def choose_action(self, breeze, stench, glitter, bump, scream):
        self.update_world(breeze, stench, glitter)

        if glitter and not self.has_gold:
            self.has_gold = True
            return "Grab"

        if self.has_gold and self.position == (0, 0):
            return "Climb"

        if stench and self.arrow:
            self.arrow = False
            return "Shoot"

        if bump:
            return "TurnRight"

        x, y = self.position
        for nx, ny in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
            if (nx, ny) not in self.visited and self.is_safe((nx, ny)):
                return "Forward"

        return "TurnRight"


agent = SimpleAgent()
print("Simple Model-Based Agent (Wumpus World)\n")

test= [

    (False, True,  False, False, False, "Wumpus nearby"),
    (True,  False, False, False, False, "Pit nearby"),
    (False, False, False, True,  False, "Bumped wall"),
    (False, False, True,  False, False, "Gold found"),
    (False, False, False, False, False, "Safe cell")
]

for b, s, g, bu, sc, desc in test:
    action = agent.choose_action(b, s, g, bu, sc)
    print(f"{desc} → {action}")

print("\nProgrammed by Milan Bairagi...")
