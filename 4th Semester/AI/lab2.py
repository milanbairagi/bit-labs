"""
8-Puzzle Problem Solver using BFS, DFS, and IDDFS
"""

from collections import deque

def find_blank(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                return i, j

def get_moves(board):
    """Get all possible next states"""
    moves = []
    row, col = find_blank(board)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # UP, DOWN, LEFT, RIGHT
    
    for dr, dc in directions:
        new_row, new_col = row + dr, col + dc
        if 0 <= new_row < 3 and 0 <= new_col < 3:
            new_board = [r[:] for r in board]  # Copy board
            new_board[row][col], new_board[new_row][new_col] = new_board[new_row][new_col], new_board[row][col]
            moves.append(new_board)
    return moves

def board_to_str(board):
    return str(board)

def print_board(board):
    for row in board:
        print(" ".join(str(x) if x != 0 else "_" for x in row))
    print()

def bfs(start, goal):
    """Breadth First Search"""
    print("\n--- BFS ---")
    if start == goal:
        return [start]
    
    queue = deque([(start, [start])])
    visited = {board_to_str(start)}
    nodes = 0
    
    while queue:
        board, path = queue.popleft()
        nodes += 1
        
        for next_board in get_moves(board):
            state = board_to_str(next_board)
            if state not in visited:
                if next_board == goal:
                    print(f"Solution found! Nodes: {nodes}, Depth: {len(path)}")
                    return path + [next_board]
                queue.append((next_board, path + [next_board]))
                visited.add(state)
    
    print("No solution")
    return None

def dfs_helper(board, goal, visited, path, max_depth, nodes):
    if board == goal:
        return path, nodes[0]
    if len(path) >= max_depth:
        return None, nodes[0]
    
    nodes[0] += 1
    visited.add(board_to_str(board))
    
    for next_board in get_moves(board):
        if board_to_str(next_board) not in visited:
            result, count = dfs_helper(next_board, goal, visited, path + [next_board], max_depth, nodes)
            if result:
                return result, count
    
    visited.remove(board_to_str(board))
    return None, nodes[0]

def dfs(start, goal, max_depth=20):
    """Depth First Search"""
    print("\n--- DFS ---")
    nodes = [0]
    result, count = dfs_helper(start, goal, set(), [start], max_depth, nodes)
    if result:
        print(f"Solution found! Nodes: {count}, Depth: {len(result)-1}")
    else:
        print(f"No solution found. Nodes explored: {count}")
    return result

def iddfs(start, goal, max_depth=20):
    """Iterative Deepening DFS"""
    print("\n--- IDDFS ---")
    total_nodes = 0
    
    for depth in range(max_depth + 1):
        nodes = [0]
        result, count = dfs_helper(start, goal, set(), [start], depth, nodes)
        total_nodes += count
        if result:
            print(f"Solution found! Nodes: {total_nodes}, Depth: {len(result)-1}")
            return result
    
    print(f"No solution found. Nodes: {total_nodes}")
    return None

def print_solution(path):
    if not path:
        return
    print("\nSolution:")
    for i, board in enumerate(path):
        print(f"Step {i}:")
        print_board(board)

# Test the algorithms
initial = [[1, 2, 3], [4, 5, 6], [0, 7, 8]]
goal = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

print("Initial State:")
print_board(initial)
print("Goal State:")
print_board(goal)

# Run all three algorithms
bfs_result = bfs(initial, goal)
print_solution(bfs_result)

dfs_result = dfs(initial, goal)
print_solution(dfs_result)

iddfs_result = iddfs(initial, goal)
print_solution(iddfs_result)
