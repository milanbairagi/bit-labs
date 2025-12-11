class EightPuzzleIDDFS:
    def __init__(self):
        self.goal = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

    def neighbors(self, state):
        # find blank (0)
        for i in range(3):
            for j in range(3):
                if state[i][j] == 0: x, y = i, j
        moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        res = []
        for dx, dy in moves:
            nx, ny = x + dx, y + dy
            if 0 <= nx < 3 and 0 <= ny < 3:
                new_state = [row[:] for row in state]
                new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
                res.append(new_state)
        return res

    def dls(self, state, path, seen, limit):
        if len(path) > limit: return None
        if state == self.goal: return path

        seen.add(tuple(map(tuple, state)))
        for nxt in self.neighbors(state):
            t = tuple(map(tuple, nxt))
            if t not in seen:
                res = self.dls(nxt, path + [nxt], seen, limit)
                if res: return res
        return None

    def solve(self, start, max_depth=15):
        for depth in range(max_depth + 1):
            print(f"Searching at depth {depth}...")
            res = self.dls(start, [start], set(), depth)
            if res: return res, depth
        return None, -1

solver = EightPuzzleIDDFS()
start = [[1, 2, 3], [4, 0, 6], [7, 5, 8]]

print("8-Puzzle IDDFS Solver\n")
print("Start:")
for row in start: print(row)
print("\nGoal:")
for row in solver.goal: print(row)

solution, depth = solver.solve(start)
if solution:
    print(f"\nSolved at depth {depth} in {len(solution) - 1} moves:\n")
    for step, s in enumerate(solution):
        print(f"Step {step}:")
        for row in s: print(row)
        print()
else:
    print("\nNo solution found")

print("Programmed by: Devashish Poudel")
