import heapq

class AStarGraph:
    def __init__(self):
        self.edges = {}
        self.heuristics = {}

    def add_edge(self, u, v, w):
        self.edges.setdefault(u, []).append((v, w))

    def set_heuristic(self, node, h_val):
        self.heuristics[node] = h_val

    def h(self, node):
        return self.heuristics.get(node, 0)

    def a_star(self, start, goal):
        pq = [(self.h(start), start, [start], 0)]  # (f, node, path, g)
        best_g = {start: 0}

        while pq:
            f, node, path, g = heapq.heappop(pq)

            if node == goal:
                return path, g

            for neigh, w in self.edges.get(node, []):
                new_g = g + w
                new_f = new_g + self.h(neigh)

                if neigh not in best_g or new_g < best_g[neigh]:
                    best_g[neigh] = new_g
                    heapq.heappush(pq, (new_f, neigh, path + [neigh], new_g))

        return None, float("inf")


def main():
    g = AStarGraph()

    heuristics = {
        'S': 12, 'A': 8, 'D': 6, 'B': 7,
        'E': 4, 'C': 5, 'F': 2, 'G': 0
    }
    for node, h in heuristics.items():
        g.set_heuristic(node, h)

    edges = [
        ('S', 'A', 6), ('S', 'D', 3),
        ('A', 'B', 5), ('A', 'D', 5),
        ('B', 'C', 4), ('B', 'E', 5),
        ('D', 'E', 2), ('E', 'F', 4),
        ('F', 'C', 4), ('F', 'G', 3)
    ]
    for u, v, w in edges:
        g.add_edge(u, v, w)

    path, cost = g.a_star('S', 'G')

    if path:
        print("Optimal path:", " → ".join(path))
        print("Total cost:", cost)
    else:
        print("No path found")


if __name__ == "__main__":
    main()
print("\nProgrammed by: Devashish Poudel")