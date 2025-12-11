class UtilityBasedAgent:
    def __init__(self):
        self.actions = ['Forward', 'TurnLeft', 'TurnRight', 'Grab', 'Shoot', 'Climb']
        self.utilities = {
            'Grab': 1000,  # High utility for gold
            'Climb': 100,  # Medium utility for escape
            'Shoot': 50,  # Medium utility for safety
            'Forward': 10,  # Low utility for exploration
            'TurnLeft': 5,  # Low utility for turning
            'TurnRight': 5  # Low utility for turning
        }

    def calculate_utility(self, action, breeze, stench, glitter, bump):
        base_utility = self.utilities[action]

        # Adjust utility based on percepts
        if action == 'Grab' and glitter:
            return base_utility
        elif action == 'Shoot' and stench:
            return base_utility
        elif action == 'Forward' and (breeze or stench):
            return -100  # Negative utility for dangerous moves
        elif action == 'Forward' and bump:
            return -50  # Negative utility for invalid moves

        return base_utility if action != 'Grab' or not glitter else 0

    def choose_action(self, breeze, stench, glitter, bump, scream):
        best_action = None
        best_utility = float('-inf')

        for action in self.actions:
            utility = self.calculate_utility(action, breeze, stench, glitter, bump)
            if utility > best_utility:
                best_utility = utility
                best_action = action

        return best_action, best_utility


# Test the agent
agent = UtilityBasedAgent()
print("Utility Based Agent - Wumpus World")

test_cases = [
    (False, False, True, False, False, "Glitter present"),
    (False, True, False, False, False, "Stench detected"),
    (True, False, False, False, False, "Breeze detected"),
    (False, False, False, True, False, "Bump detected"),
    (False, False, False, False, False, "Safe environment")
]

for b, s, g, bu, sc, description in test_cases:
    action, utility = agent.choose_action(b, s, g, bu, sc)
    print(f"{description}: Action={action}, Utility={utility}")

print("\nProgrammed by Milan Bairagi...")