import numpy as np

class SimpleBPNetwork:
    """Simple Backpropagation Neural Network for XOR Problem"""
    
    def __init__(self, input_size, hidden_size, output_size, lr=0.5):
        self.lr = lr
        # Initialize weights with small random values
        self.W1 = np.random.randn(input_size, hidden_size) * 0.5
        self.b1 = np.zeros((1, hidden_size))
        self.W2 = np.random.randn(hidden_size, output_size) * 0.5
        self.b2 = np.zeros((1, output_size))

    def sigmoid(self, x):
        """Activation function with numerical stability"""
        return 1 / (1 + np.exp(-np.clip(x, -500, 500)))

    def sigmoid_derivative(self, x):
        """Derivative of sigmoid"""
        return x * (1 - x)

    def forward(self, X):
        """Forward propagation"""
        self.a1 = self.sigmoid(np.dot(X, self.W1) + self.b1)
        self.a2 = self.sigmoid(np.dot(self.a1, self.W2) + self.b2)
        return self.a2

    def backward(self, X, y, output):
        """Backpropagation"""
        m = X.shape[0]
        
        # Output layer gradient
        dz2 = (output - y) * self.sigmoid_derivative(output)
        dW2 = np.dot(self.a1.T, dz2) / m
        db2 = dz2.sum(axis=0, keepdims=True) / m
        
        # Hidden layer gradient
        dz1 = np.dot(dz2, self.W2.T) * self.sigmoid_derivative(self.a1)
        dW1 = np.dot(X.T, dz1) / m
        db1 = dz1.sum(axis=0, keepdims=True) / m
        
        # Update weights and biases
        self.W2 -= self.lr * dW2
        self.b2 -= self.lr * db2
        self.W1 -= self.lr * dW1
        self.b1 -= self.lr * db1

    def train(self, X, y, epochs=1000):
        """Train the network"""
        print("Training Backpropagation Neural Network on XOR\n")
        
        for epoch in range(epochs):
            # Forward and backward pass
            output = self.forward(X)
            self.backward(X, y, output)
            
            # Print progress
            if (epoch + 1) % 200 == 0:
                error = np.mean((output - y) ** 2)
                print(f"Epoch {epoch + 1}: Error = {error:.6f}")

    def predict(self, X):
        """Make predictions"""
        return self.forward(X)


# ============ XOR Problem ============
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([[0], [1], [1], [0]])

# ============ Train Network ============
np.random.seed(42)
net = SimpleBPNetwork(2, 4, 1, lr=0.5)
net.train(X, y, epochs=5000)

# ============ Test Results ============
print("\nTesting Network:")
print("-" * 50)
preds = net.predict(X)
for i in range(len(X)):
    print(f"{X[i]} -> Expected: {y[i][0]}, Predicted: {preds[i][0]:.4f}, Rounded: {round(preds[i][0])}")

accuracy = np.mean(np.round(preds) == y) * 100
print(f"\nAccuracy: {accuracy:.1f}%")

print("\nProgrammed by Milan Bairagi...")