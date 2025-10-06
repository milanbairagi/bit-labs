# Simple Reflex Agent for Wumpus World - demonstration
# This code defines a tiny Wumpus World environment and a simple reflex agent.
# The agent reacts only to the current percept (no internal memory/model).
# Actions: "FORWARD", "TURN_LEFT", "TURN_RIGHT", "GRAB", "SHOOT", "CLIMB"
# Percepts: (stench, breeze, glitter, bump, scream) -> booleans
#
# We"ll run a short simulation and print the agent"s decisions and environment responses.

from environment import WumpusWorld, Percept


class SimpleReflexAgent:
    """A very simple reflex agent for Wumpus World.
    Rules (priority):
    1. If glitter -> GRAB
    2. If stench and has arrow -> SHOOT
    3. If bump -> TURN_RIGHT
    4. If breeze -> TURN_RIGHT (avoid)
    5. Otherwise -> FORWARD
    If agent has grabbed gold and is at (0,0) -> CLIMB (exit)
    """
    def __init__(self):
        self.has_arrow = True

    def action(self, percept: Percept, env: WumpusWorld):
        # If on gold -> grab
        if percept.glitter:
            return "GRAB"
        # If agent has gold and at start -> climb out
        if env.agent_has_gold and env.agent_pos == (0,0):
            return "CLIMB"
        # If stench and has arrow -> shoot
        if percept.stench and self.has_arrow and env.has_arrow:
            return "SHOOT"
        # If bump -> turn right to change direction
        if percept.bump:
            return "TURN_RIGHT"

        # If breeze occurs, update direction to avoid
        if percept.breeze:
            if not hasattr(self, "turned_for_breeze"):
                self.turned_for_breeze = False
            if not self.turned_for_breeze:
                self.turned_for_breeze = True
                return "TURN_RIGHT"
            else:
                self.turned_for_breeze = False
                return "FORWARD"
        # If scream occurs, update arrow state if we shot earlier
        if percept.scream:
            # no immediate action decided by scream
            pass
        # default: move forward
        return "FORWARD"

