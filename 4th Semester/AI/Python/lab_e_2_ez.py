import numpy as np

class Perceptron:
    def __init__(self, size, lr=0.1):
        self.w = np.zeros(size)   # start with zeros
        self.b = 0.0
        self.lr = lr

    def activation(self, x):
        return 1 if x >= 0 else 0

    def predict(self, x):
        return self.activation(np.dot(x, self.w) + self.b)

    def train(self, data, epochs=20):
        for _ in range(epochs):
            for x, t in data:
                y = self.predict(x)
                error = t - y
                # Perceptron learning rule
                self.w += self.lr * error * x
                self.b += self.lr * error

# AND gate training data
data = [
    (np.array([0,0]), 0),
    (np.array([0,1]), 0),
    (np.array([1,0]), 0),
    (np.array([1,1]), 1)
]

# Train perceptron
net = Perceptron(size=2, lr=0.1)
net.train(data, epochs=20)

# Test perceptron
print("Perceptron for AND Gate")
print("="*30)
print("Input\tExpected\tPredicted")
for x, t in data:
    print(f"{x}\t\t{t}\t\t\t\t{net.predict(x)}")

print("\nFinal weights:", net.w)
print("Final bias:", round(net.b,4))
print("\nProgrammed by: Devashish Poudel")