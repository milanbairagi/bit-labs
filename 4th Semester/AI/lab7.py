import numpy as np
import random

# Genetic Algorithm to maximize f(x) = x^2 where x is in [0, 31]
POP_SIZE = 6
GENERATIONS = 15
MUTATION_RATE = 0.1

# Fitness function
def fitness(x):
    return x ** 2

# Convert binary list to decimal
def decode(chromosome):
    return int(''.join(map(str, chromosome)), 2)

# Initialize population (5 bits = 0-31)
population = [list(np.random.randint(0, 2, 5)) for _ in range(POP_SIZE)]

print("Genetic Algorithm: Maximizing f(x) = x^2\n")

# Evolution loop
for gen in range(GENERATIONS):
    # Evaluate fitness
    x_values = [decode(ind) for ind in population]
    fit_values = [fitness(x) for x in x_values]
    
    best_x = x_values[fit_values.index(max(fit_values))]
    print(f"Gen {gen+1}: Best x = {best_x}, f(x) = {fitness(best_x)}")
    
    # Create new generation
    new_pop = []
    for _ in range(POP_SIZE // 2):
        # Selection: Pick 2 parents based on fitness
        parents = random.choices(population, weights=fit_values, k=2)
        
        # Crossover: Single point
        point = random.randint(1, 4)
        child1 = parents[0][:point] + parents[1][point:]
        child2 = parents[1][:point] + parents[0][point:]
        
        # Mutation: Flip bits randomly
        for child in [child1, child2]:
            for i in range(5):
                if random.random() < MUTATION_RATE:
                    child[i] = 1 - child[i]
        
        new_pop.extend([child1, child2])
    
    population = new_pop

# Final result
x_values = [decode(ind) for ind in population]
fit_values = [fitness(x) for x in x_values]
best_x = x_values[fit_values.index(max(fit_values))]
print(f"\nOptimal Solution: x = {best_x}, f(x) = {fitness(best_x)}")
