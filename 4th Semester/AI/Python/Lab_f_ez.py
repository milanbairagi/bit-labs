import numpy as np


class SimpleBPNetwork:
    def __init__(self, input_size, hidden_size, output_size, lr=0.5):
        self.lr = lr
        self.W1 = np.random.randn(input_size, hidden_size) * 0.5
        self.b1 = np.zeros((1, hidden_size))
        self.W2 = np.random.randn(hidden_size, output_size) * 0.5
        self.b2 = np.zeros((1, output_size))

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-np.clip(x, -500, 500)))

    def sigmoid_derivative(self, x):
        return x * (1 - x)

    def forward(self, X):
        self.a1 = self.sigmoid(np.dot(X, self.W1) + self.b1)
        self.a2 = self.sigmoid(np.dot(self.a1, self.W2) + self.b2)
        return self.a2

    def backward(self, X, y, output):
        dz2 = output - y
        dz1 = np.dot(dz2, self.W2.T) * self.sigmoid_derivative(self.a1)
        self.W2 -= self.lr * np.dot(self.a1.T, dz2)
        self.b2 -= self.lr * dz2.sum(axis=0)
        self.W1 -= self.lr * np.dot(X.T, dz1)
        self.b1 -= self.lr * dz1.sum(axis=0)

    def train(self, X, y, epochs=1000):
        for epoch in range(epochs):
            out = self.forward(X)
            self.backward(X, y, out)
            if (epoch + 1) % 200 == 0:
                error = np.mean((out - y) ** 2)
                print(f"Epoch {epoch + 1}: Error = {error:.6f}")

    def predict(self, X):
        return self.forward(X)


# XOR problem
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([[0], [1], [1], [0]])

net = SimpleBPNetwork(2, 4, 1, lr=0.5)
print("Training Backpropagation NN on XOR")
net.train(X, y, epochs=1000)

# Test
print("\nTesting network:")
preds = net.predict(X)
for i in range(len(X)):
    print(f"{X[i]} -> Expected: {y[i][0]}, Predicted: {preds[i][0]:.4f}, Rounded: {round(preds[i][0])}")

accuracy = np.mean(np.round(preds) == y) * 100
print(f"\nAccuracy: {accuracy:.1f}%")
print("\nProgrammed by: Devashish Poudel")