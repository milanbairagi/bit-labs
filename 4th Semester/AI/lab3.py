# Path Problem using Best First Search and A* Search
from queue import PriorityQueue

# Graph representation - Map from textbook
graph = {
    'S': [('A', 3), ('B', 5)],
    'A': [('B', 4), ('D', 3)],
    'B': [('C', 4)],
    'C': [('E', 6)],
    'D': [('G', 5)],
    'E': [('G', 4)],
    'G': []
}

# Heuristic values (straight-line distance to goal)
heuristic = {
    'S': 10,
    'A': 7,
    'B': 6,
    'C': 7,
    'D': 5,
    'E': 4,
    'G': 0
}

def best_first_search(start, goal):
    """Best First Search - uses only heuristic h(n)"""
    pq = PriorityQueue()
    pq.put((heuristic[start], start, [start]))
    visited = set()
    
    print("\n--- Best First Search ---")
    while not pq.empty():
        h_val, node, path = pq.get()
        
        if node in visited:
            continue
            
        visited.add(node)
        print(f"Visiting: {node}, Path: {' -> '.join(path)}, h = {h_val}")
        
        if node == goal:
            print(f"\nGoal reached! Path: {' -> '.join(path)}")
            return path
        
        for neighbor, cost in graph[node]:
            if neighbor not in visited:
                new_path = path + [neighbor]
                pq.put((heuristic[neighbor], neighbor, new_path))
    
    return None

def a_star_search(start, goal):
    """A* Search - uses f(n) = g(n) + h(n)"""
    pq = PriorityQueue()
    pq.put((heuristic[start], 0, start, [start]))  # (f, g, node, path)
    visited = set()
    
    print("\n--- A* Search ---")
    while not pq.empty():
        f_val, g_val, node, path = pq.get()
        
        if node in visited:
            continue
            
        visited.add(node)
        h_val = heuristic[node]
        print(f"Visiting: {node}, Path: {' -> '.join(path)}, g = {g_val}, h = {h_val}, f = {f_val}")
        
        if node == goal:
            print(f"\nGoal reached! Path: {' -> '.join(path)}, Total Cost: {g_val}")
            return path, g_val
        
        for neighbor, cost in graph[node]:
            if neighbor not in visited:
                new_g = g_val + cost
                new_f = new_g + heuristic[neighbor]
                new_path = path + [neighbor]
                pq.put((new_f, new_g, neighbor, new_path))
    
    return None, float('inf')

# Run both algorithms
if __name__ == "__main__":
    start_node = 'S'
    goal_node = 'G'
    
    print("=" * 50)
    print("Path Problem Solver")
    print("=" * 50)
    
    # Best First Search
    bfs_path = best_first_search(start_node, goal_node)
    
    print("\n" + "=" * 50)
    
    # A* Search
    astar_path, astar_cost = a_star_search(start_node, goal_node)
    
    print("\n" + "=" * 50)
    print("COMPARISON")
    print("=" * 50)
    print(f"Best First Search: {' -> '.join(bfs_path) if bfs_path else 'No path found'}")
    print(f"A* Search: {' -> '.join(astar_path) if astar_path else 'No path found'} (Cost: {astar_cost})")
