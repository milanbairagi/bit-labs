import heapq
class Graph:
    def __init__(self):
        self.edges = {}
        self.heuristics = {}

    def add_edge(self, u, v, w):
        self.edges.setdefault(u, []).append((v, w))

    def set_heuristic(self, node, h_val):
        self.heuristics[node] = h_val

    def h(self, node):
        return self.heuristics.get(node, 0)

    def best_first(self, start, goal):
        pq = [(self.h(start), start, [start], 0)]
        visited = set()

        while pq:
            h_val, node, path, cost = heapq.heappop(pq)

            if node == goal:
                return path, cost

            if node in visited:
                continue
            visited.add(node)

            for neigh, edge_w in self.edges.get(node, []):
                if neigh not in visited:
                    new_path = path + [neigh]
                    new_cost = cost + edge_w
                    heapq.heappush(pq, (self.h(neigh), neigh, new_path, new_cost))

        return None, float("inf")


def main():
    g = Graph()

    heuristics = {
        'S': 12, 'A': 8, 'D': 6, 'B': 7,
        'E': 4, 'C': 5, 'F': 2, 'G': 0
    }
    for node, h_val in heuristics.items():
        g.set_heuristic(node, h_val)

    edges = [
        ('S', 'A', 6), ('S', 'D', 3),
        ('A', 'B', 5), ('A', 'D', 5),
        ('B', 'C', 4), ('B', 'E', 5),
        ('D', 'E', 2), ('E', 'F', 4),
        ('F', 'C', 4), ('F', 'G', 3)
    ]
    for u, v, w in edges:
        g.add_edge(u, v, w)

    path, cost = g.best_first('S', 'G')

    if path:
        print("Path found:", " → ".join(path))
        print("Total cost:", cost)
    else:
        print("No path found!")


if __name__ == "__main__":
    main()
print("\nProgrammed by: Devashish Poudel")