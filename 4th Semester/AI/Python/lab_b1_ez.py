from collections import deque

class EightPuzzleBFS:
    def __init__(self):
        self.goal = [[1,2,3],[4,5,6],[7,8,0]]

    def solve(self, start):
        if start == self.goal:
            return [start]

        # Use queue for BFS
        q = deque([(start, [start])])
        seen = {self.to_tuple(start)}

        while q:
            state, path = q.popleft()

            for next_state in self.neighbors(state):
                t = self.to_tuple(next_state)
                if t not in seen:
                    seen.add(t)
                    new_path = path + [next_state]

                    if next_state == self.goal:
                        return new_path

                    q.append((next_state, new_path))
        return None

    def to_tuple(self, state):
        return tuple(tuple(row) for row in state)

    def neighbors(self, state):
        # find 0 (blank)
        for i in range(3):
            for j in range(3):
                if state[i][j] == 0:
                    x, y = i, j
        moves = [(1,0), (-1,0), (0,1), (0,-1)]
        res = []
        for dx, dy in moves:
            nx, ny = x+dx, y+dy
            if 0 <= nx < 3 and 0 <= ny < 3:
                new_state = [row[:] for row in state]
                new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
                res.append(new_state)
        return res

solver = EightPuzzleBFS()
start = [[1,2,3],[4,0,6],[7,5,8]]

print("8-Puzzle BFS Solver\n")
print("Start:")
for row in start: print(row)
print("\nGoal:")
for row in solver.goal: print(row)

solution = solver.solve(start)
if solution:
    print(f"\nSolved in {len(solution)-1} moves:\n")
    for step, s in enumerate(solution):
        print(f"Step {step}:")
        for row in s: print(row)
        print()
else:
    print("\nNo solution found")

print("Programmed by: Devashish Poudel")
