class UtilityBasedAgent:
    def __init__(self):
        self.score = 0
        self.turn_count = 0
        
    def calculate_utility(self, action, percept):
        if action == 'GRAB' and percept['glitter']:
            return 1000
        if action == 'FORWARD' and not percept['breeze'] and not percept['stench']:
            return 50
        if action == 'TURN_LEFT':
            return 10
        if action == 'FORWARD' and (percept['breeze'] or percept['stench']):
            return -20
        return 0