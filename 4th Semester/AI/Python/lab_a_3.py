class GoalBasedAgent:
    def __init__(self):
        self.goal = "find_gold_and_exit"
        self.has_gold = False
        self.plan = []
        self.step = 0

    def make_plan(self, breeze, stench, glitter, bump):
        """Create a simple plan based on percepts"""
        if glitter and not self.has_gold:
            self.plan = ['Grab', 'TurnLeft', 'Turnright', 'Forward', 'Climb']
        elif self.has_gold:
            self.plan = ['TurnLeft', 'Turnright', 'Forward', 'Climb']
        elif stench:
            self.plan = ['Shoot', 'Forward']
        elif breeze:
            self.plan = ['TurnRight', 'Forward']
        elif bump:
            self.plan = ['TurnLeft', 'Forward']
        else:
            self.plan = ['Forward']
        self.step = 0

    def act(self, breeze, stench, glitter, bump, scream):
        """Perform next action from plan or create a new plan"""
        if not self.plan or self.step >= len(self.plan):
            self.make_plan(breeze, stench, glitter, bump)

        action = self.plan[self.step]
        self.step += 1

        if action == 'Grab':
            self.has_gold = True

        return action, self.plan


# Test the agent
agent = GoalBasedAgent()
print("Goal Based Agent - Wumpus World")
print("Goal:", agent.goal)

test= [
    (False, False, True, False, False, "Gold found"),
    (False, True, False, False, False, "Wumpus nearby"),
    (True, False, False, False, False, "Pit nearby"),
    (False, False, False, True, False, "Hit wall")
]

for b, s, g, bu, sc, desc in test:
    action, plan = agent.act(b, s, g, bu, sc)
    print(f"{desc}: Action={action}, Plan={plan}")
    agent = GoalBasedAgent()  # Reset for next test

print("\nProgrammed by Milan Bairagi...")
