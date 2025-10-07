# Block World Problem using Hill Climbing Search

def print_state(state):
    """Display blocks in stacks"""
    max_height = max(len(s) for s in state) if state else 0
    for level in range(max_height - 1, -1, -1):
        for stack in state:
            if level < len(stack):
                print(f" {stack[level]} ", end="")
            else:
                print("   ", end="")
        print()
    print("-" * (len(state) * 3))

def heuristic(state, goal):
    """Count correctly placed blocks from bottom"""
    score = 0
    for i in range(len(state)):
        for j in range(len(state[i])):
            if j < len(goal[i]) and state[i][j] == goal[i][j]:
                score += 1
            else:
                break
    return score

def get_moves(state):
    """Get all possible moves"""
    moves = []
    for i in range(len(state)):
        if state[i]:
            for j in range(len(state)):
                if i != j:
                    new_state = [s[:] for s in state]
                    block = new_state[i].pop()
                    new_state[j].append(block)
                    moves.append((new_state, f"Move {block}: Stack {i} -> {j}"))
    return moves

def hill_climbing(start, goal):
    """Hill Climbing Search Algorithm"""
    current = [s[:] for s in start]
    path = []
    
    print("\n=== HILL CLIMBING SEARCH ===")
    print("\nInitial State:")
    print_state(start)
    print("\nGoal State:")
    print_state(goal)
    
    iteration = 0
    while current != goal and iteration < 20:
        iteration += 1
        print(f"\n--- Iteration {iteration} ---")
        
        # Find best move
        best_state = None
        best_score = heuristic(current, goal)
        best_move = None
        
        for state, move in get_moves(current):
            score = heuristic(state, goal)
            if score > best_score:
                best_score = score
                best_state = state
                best_move = move
        
        # Check if stuck
        if best_state is None:
            print("Stuck! No better move found.")
            return False, path
        
        # Make move
        current = best_state
        path.append(best_move)
        print(f"{best_move} (score: {best_score})")
        print_state(current)
        
        # Check goal
        if current == goal:
            print("\n=== GOAL REACHED! ===")
            print(f"Total moves: {len(path)}")
            return True, path
    
    return False, path


# Example: Build stack A-B-C
initial = [['A'], ['B'], ['C']]
goal = [['A', 'B', 'C'], [], []]

success, moves = hill_climbing(initial, goal)

if success:
    print("\nSolution:")
    for i, move in enumerate(moves, 1):
        print(f"{i}. {move}")
else:
    print("\nFailed - Got stuck in local maximum!")

