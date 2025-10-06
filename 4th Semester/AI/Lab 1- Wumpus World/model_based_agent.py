
class ModelBasedAgent:
    def __init__(self):
        self.visited = set()
        self.safe = set()
        self.danger = set()
        self.turn_count = 0
        
    def act(self, percept):
        if percept['glitter']:
            return 'GRAB'
        
        if percept['breeze'] or percept['stench']:
            self.turn_count += 1
            if self.turn_count < 2:
                return 'TURN_LEFT'
            else:
                self.turn_count = 0
                return 'FORWARD'
        else:
            self.turn_count = 0
            return 'FORWARD'