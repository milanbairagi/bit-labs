
class GoalBasedAgent:
    def __init__(self):
        self.goal = 'FIND_GOLD'
        self.has_gold = False
        self.turn_count = 0
        
    def act(self, percept):
        if self.goal == 'FIND_GOLD':
            if percept['glitter']:
                self.has_gold = True
                self.goal = 'EXIT'
                return 'GRAB'
            if percept['stench'] or percept['breeze']:
                self.turn_count += 1
                if self.turn_count < 2:
                    return 'TURN_LEFT'
                else:
                    self.turn_count = 0
                    return 'FORWARD'
            return 'FORWARD'
        
        elif self.goal == 'EXIT':
            return 'CLIMB'