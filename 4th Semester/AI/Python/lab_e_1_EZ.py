import numpy as np

class HebbianNet:
    def __init__(self, size, lr=0.1):
        self.w = np.zeros(size)     # start with zero weights
        self.b = 0.0                # bias
        self.lr = lr

    def activation(self, x):
        return 1 if x >= 0 else 0

    def predict(self, x):
        return self.activation(np.dot(x, self.w) + self.b)

    def train(self, data, epochs=10):
        for _ in range(epochs):
            for x, t in data:
                # Hebbian update
                self.w += self.lr * x * t
                self.b += self.lr * t

# AND gate data
data = [
    (np.array([0,0]), 0),
    (np.array([0,1]), 0),
    (np.array([1,0]), 0),
    (np.array([1,1]), 1)
]

# Train
net = HebbianNet(size=2, lr=0.1)
net.train(data, epochs=20)

# Test
print("Hebbian Network for AND Gate")
print("="*35)
print("Input\tExpected\tPredicted")
for x, t in data:
    print(f"{x}\t\t{t}\t\t\t\t{net.predict(x)}")

print("\nFinal weights:", net.w)
print("Final bias:", round(net.b,4))
print("\nProgrammed by: Devashish Poudel")
