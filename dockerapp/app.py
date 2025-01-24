from flask import Flask, request, jsonify
import numpy as np

app = Flask(__name__)

# Logistic regression model parameters
theta = np.array([0, 0, 0], dtype=float)
alpha = 0.0001
iterations = 100
X = np.array([
    [1, 172, 68],
    [1, 163, 52],
    [1, 158, 50],
    [1, 180, 75]
])  # Input data
y = np.array([0, 1, 1, 0])  # Labels
m = len(y)

# Hypothesis function
def hypothesis(X, theta):
    return 1 / (1 + np.exp(-X @ theta))

# Training function
def train(X, y, theta, alpha, iterations):
    m = len(y)
    for i in range(iterations):
        predictions = hypothesis(X, theta)
        errors = predictions - y
        gradient = 1 / m * (X.T @ errors)
        theta -= alpha * gradient
    return theta

# Train the model
theta = train(X, y, theta, alpha, iterations)

@app.route('/predict', methods=['POST'])
def predict():
    data = request.json
    height = data['height']
    weight = data['weight']
    tmd = np.array([1, height, weight])
    gender_prob = hypothesis(tmd, theta)
    gender = "male" if gender_prob < 0.5 else "female"
    return jsonify({"gender_probability": gender_prob, "predicted_gender": gender})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
