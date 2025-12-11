import copy
class BlockWorld:
    def __init__(self, start, goal):
        self.start = start
        self.goal = goal

    def heuristic(self, state):
        """Count blocks in correct place"""
        score = 0
        for i in range(min(len(state), len(self.goal))):
            for j in range(min(len(state[i]), len(self.goal[i]))):
                if state[i][j] == self.goal[i][j]:
                    score += 1
        return score

    def neighbors(self, state):
        """Generate moves: take top block and move it"""
        moves = []
        for i, stack in enumerate(state):
            if stack:
                block = stack[-1]
                new_state = copy.deepcopy(state)
                new_state[i].pop()

                # Move to another existing stack
                for j in range(len(state)):
                    if i != j:
                        temp = copy.deepcopy(new_state)
                        temp[j].append(block)
                        moves.append(temp)

                # Move to new stack
                temp = copy.deepcopy(new_state)
                temp.append([block])
                moves.append(temp)
        return moves

    def hill_climb(self):
        state = copy.deepcopy(self.start)
        path = [state]

        while True:
            if state == self.goal:
                return path, "Goal reached!"

            best = state
            best_score = self.heuristic(state)

            for n in self.neighbors(state):
                score = self.heuristic(n)
                if score > best_score:
                    best, best_score = n, score

            if best == state:  # No better neighbor
                return path, "Stuck at local maximum!"

            state = best
            path.append(state)


# Example
start = [['A', 'B'], ['C']]
goal = [['A'], ['B'], ['C']]

bw = BlockWorld(start, goal)
path, result = bw.hill_climb()

print("Hill Climbing - Block World\n" + "=" * 40)
for i, p in enumerate(path):
    print(f"Step {i}: {p}")
print("\nResult:", result)
print("\nProgrammed by: Devashish Poudel")