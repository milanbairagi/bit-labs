class EightPuzzleDFS:
    def __init__(self):
        self.goal = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
        self.limit = 20  # depth limit

    def neighbors(self, state):
        # locate blank (0)
        for i in range(3):
            for j in range(3):
                if state[i][j] == 0: x, y = i, j
        moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        result = []
        for dx, dy in moves:
            nx, ny = x + dx, y + dy
            if 0 <= nx < 3 and 0 <= ny < 3:
                new_state = [row[:] for row in state]
                new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
                result.append(new_state)
        return result

    def dfs(self, state, path, seen, depth):
        if depth > self.limit: return None
        if state == self.goal: return path

        seen.add(tuple(map(tuple, state)))

        for nxt in self.neighbors(state):
            t = tuple(map(tuple, nxt))
            if t not in seen:
                res = self.dfs(nxt, path + [nxt], seen, depth + 1)
                if res: return res
        return None

    def solve(self, start):
        return self.dfs(start, [start], set(), 0)

solver = EightPuzzleDFS()
start = [[1, 2, 3], [4, 0, 6], [7, 5, 8]]

print("8-Puzzle DFS Solver\n")
print("Start:")
for row in start: print(row)
print("\nGoal:")
for row in solver.goal: print(row)

solution = solver.solve(start)
if solution:
    print(f"\nSolved in {len(solution) - 1} moves:\n")
    for step, s in enumerate(solution):
        print(f"Step {step}:")
        for row in s: print(row)
        print()
else:
    print("\nNo solution found within depth limit")

print("Programmed by: Devashish Poudel")
