import random

class SimpleReflexAgent:
    def perceive(self, breeze, stench, glitter, bump, scream):
        """Decide action based on simple rules"""
        if glitter:  return 'Grab'
        if bump:     return 'TurnRight'
        if stench:   return 'Shoot'
        if breeze:   return 'TurnLeft'
        return random.choice(['Forward', 'TurnLeft', 'TurnRight'])

# Test the agent
agent = SimpleReflexAgent()
print("Simple Reflex Agent - Wumpus World\n")

tests = [
    (False, False, True, False, False, "Glitter present"),
    (False, False, False, True, False, "Bump detected"),
    (False, True, False, False, False, "Stench detected"),
    (True, False, False, False, False, "Breeze detected"),
    (False, False, False, False, False, "No perception")
]

for b, s, g, bp, sc, desc in tests:
    print(f"{desc}: {agent.perceive(b, s, g, bp, sc)}")

print("\nProgrammed by Milan Bairagi...")
