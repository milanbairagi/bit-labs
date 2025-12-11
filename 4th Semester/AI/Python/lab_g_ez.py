import numpy as np
import random


class SimpleGA:
    def __init__(self, pop_size, chrom_len, mut_rate=0.05, cross_rate=0.8):
        self.pop_size = pop_size
        self.chrom_len = chrom_len
        self.mut_rate = mut_rate
        self.cross_rate = cross_rate
        self.population = np.random.randint(0, 2, (pop_size, chrom_len))

    def fitness(self, chrom):
        return np.sum(chrom)  # maximize number of 1s

    def select(self):
        """Select top half based on fitness"""
        scores = [self.fitness(c) for c in self.population]
        indices = np.argsort(scores)[-self.pop_size // 2:]
        return self.population[indices]

    def crossover(self, p1, p2):
        if random.random() < self.cross_rate:
            point = random.randint(1, self.chrom_len - 1)
            return np.concatenate([p1[:point], p2[point:]]), np.concatenate([p2[:point], p1[point:]])
        return p1.copy(), p2.copy()

    def mutate(self, chrom):
        for i in range(self.chrom_len):
            if random.random() < self.mut_rate:
                chrom[i] = 1 - chrom[i]
        return chrom

    def evolve(self, generations):
        for g in range(generations):
            selected = self.select()
            new_pop = []
            while len(new_pop) < self.pop_size:
                p1, p2 = random.sample(list(selected), 2)
                c1, c2 = self.crossover(p1, p2)
                new_pop.append(self.mutate(c1))
                if len(new_pop) < self.pop_size:
                    new_pop.append(self.mutate(c2))
            self.population = np.array(new_pop)
            best_fit = max([self.fitness(c) for c in self.population])
            if (g + 1) % 10 == 0:
                print(f"Generation {g + 1}: Best fitness = {best_fit}")
        # return best solution
        fitness_scores = [self.fitness(c) for c in self.population]
        best_idx = np.argmax(fitness_scores)
        return self.population[best_idx], fitness_scores[best_idx]


# Run the simplified GA
print("Simplified Genetic Algorithm - Maximize 1s")
POP_SIZE = 20
CHROM_LEN = 10
GENERATIONS = 50

ga = SimpleGA(POP_SIZE, CHROM_LEN)
best_chrom, best_fit = ga.evolve(GENERATIONS)

print("\nBest chromosome:", best_chrom)
print("Best fitness:", best_fit)
print("\nProgrammed by: Devashish Poudel")