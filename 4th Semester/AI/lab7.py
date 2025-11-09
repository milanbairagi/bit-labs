import numpy as np
import random

class GA:
    def __init__(self, pop_size=10, generations=20, mutation_rate=0.1, bits=5):
        self.pop_size = pop_size
        self.generations = generations
        self.mutation_rate = mutation_rate
        self.bits = bits
    
    def fitness(self, x):
        return -x**2 + 8*x + 5
    
    def decode(self, chrom):
        return int(''.join(map(str, chrom)), 2)
    
    def selection(self, pop, fit_vals):
        # Shift fitness to make all values positive
        min_fit = min(fit_vals)
        if min_fit <= 0:
            fit_vals = [f - min_fit + 1 for f in fit_vals]
        
        total = sum(fit_vals)
        probs = [f / total for f in fit_vals]
        return random.choices(pop, weights=probs, k=2)
    
    def crossover(self, p1, p2):
        pt = random.randint(1, self.bits - 1)
        return p1[:pt] + p2[pt:], p2[:pt] + p1[pt:]
    
    def mutation(self, chrom):
        for i in range(self.bits):
            if random.random() < self.mutation_rate:
                chrom[i] = 1 - chrom[i]
        return chrom
    
    def evolve(self):
        pop = [list(np.random.randint(0, 2, self.bits)) for _ in range(self.pop_size)]
        best_ever_x, best_ever_fit = None, float('-inf')
        
        print("GENETIC ALGORITHM: Maximize f(x) = -x^2 + 8x + 5\n")
        
        for gen in range(self.generations):
            x_vals = [self.decode(ind) for ind in pop]
            fit_vals = [self.fitness(x) for x in x_vals]
            best_x, best_fit = x_vals[fit_vals.index(max(fit_vals))], max(fit_vals)
            
            # Keep track of best solution ever found
            if best_fit > best_ever_fit:
                best_ever_x, best_ever_fit = best_x, best_fit
            
            print(f"Gen {gen+1}: x = {best_x}, f(x) = {best_fit:.2f}")
            
            new_pop = []
            for _ in range(self.pop_size // 2):
                # Selection
                p1, p2 = self.selection(pop, fit_vals)
                
                # Crossover
                c1, c2 = self.crossover(p1.copy(), p2.copy())
                
                # Mutation
                c1 = self.mutation(c1)
                c2 = self.mutation(c2)
                
                new_pop.extend([c1, c2])
            
            pop = new_pop
        
        print(f"\nFinal Best: x = {best_ever_x}, f(x) = {best_ever_fit:.2f}")
        print(f"Expected: x = 4, f(x) = 21.00")

GA(pop_size=12, generations=20, mutation_rate=0.1, bits=5).evolve()
print("\nProgrammed by Milan Bairagi...")
