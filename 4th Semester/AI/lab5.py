print("=" * 50)
print("AND GATE USING NEURAL NETWORKS")
print("=" * 50)

X = [[-1, -1],
     [-1, 1],
     [1, -1],
     [1, 1]]
b = [1, 1, 1, 1]
y = [-1, -1, -1, 1]

# ===============================================
# 1) HEBBIAN NEURAL NETWORK
# ===============================================
print("\n1) HEBBIAN NEURAL NETWORK")
print("-" * 50)

# Initialize weights and bias
w_hebb = [0.0, 0.0]
b_hebb = 0.0

# Training
# learning_rate = 0.1
for i in range(len(X)):
    # Hebbian learning rule: w_i(new) = w_i(old) + (x_i, y)
    # b = b + y
    w_hebb[0] += X[i][0] * y[i]
    w_hebb[1] += X[i][1] * y[i]
    b_hebb += y[i]

print(f"Trained Weights: {w_hebb}")
print(f"Trained Bias: {b_hebb}")

# Testing
print("\nTesting Hebbian Network:")
for i in range(len(X)):
    output = X[i][0] * w_hebb[0] + X[i][1] * w_hebb[1] + b[i] * b_hebb
    prediction = 1 if output >= 1 else -1
    print(f"Input: {X[i]} -> Output: {prediction} (Expected: {y[i]})")

# ===============================================
# 2) PERCEPTRON NEURAL NETWORK
# ===============================================

# Training data for AND gate
X = [[0, 0], [0, 1], [1, 0], [1, 1]]
y = [0, 0, 0, 1]

print("\n\n2) PERCEPTRON NEURAL NETWORK")
print("-" * 50)

# Initialize weights and bias
w_perceptron = [1.2, 0.6]

# Training
learning_rate = 0.5

MAX_EPOCHS = 10
epoch = 0

while epoch < MAX_EPOCHS:
    global_error = 0
    
    for i in range(len(X)):
        output = X[i][0] * w_perceptron[0] + X[i][1] * w_perceptron[1]
        prediction = 1 if output >= 1 else 0
        error = y[i] - prediction
        if error != 0:
            w_perceptron[0] += learning_rate * error * X[i][0]
            w_perceptron[1] += learning_rate * error * X[i][1]
            global_error += abs(error)
            break

    if global_error == 0:
        break
    
    epoch += 1

print(f"Trained Weights: [{w_perceptron[0]}, {w_perceptron[1]}]")

# Testing
print("\nTesting Perceptron Network:")
for i in range(len(X)):
    output = X[i][0] * w_perceptron[0] + X[i][1] * w_perceptron[1]
    prediction = 1 if output >= 1 else 0
    print(f"Input: {X[i]} -> Output: {prediction} (Expected: {y[i]})")

