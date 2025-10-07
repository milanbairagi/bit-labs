from collections import defaultdict
import math

# Training data: (message, label)
training_data = [
    ("win free money now", "spam"),
    ("claim your prize", "spam"),
    ("free offer click here", "spam"),
    ("winner congratulations", "spam"),
    ("meeting schedule tomorrow", "ham"),
    ("project deadline next week", "ham"),
    ("lunch plans today", "ham"),
    ("how are you doing", "ham")
]

# Test data
test_data = [
    "win prize free",
    "meeting tomorrow",
    "free money offer",
    "project update"
]

# Naive Bayes Classifier
class SpamClassifier:
    def __init__(self):
        self.word_count = {'spam': defaultdict(int), 'ham': defaultdict(int)}
        self.label_count = {'spam': 0, 'ham': 0}
        self.vocab = set()
    
    def train(self, data):
        # Count words and labels
        for message, label in data:
            words = message.lower().split()
            self.label_count[label] += 1
            
            for word in words:
                self.word_count[label][word] += 1
                self.vocab.add(word)
        
        print(f"Training completed!")
        print(f"Spam messages: {self.label_count['spam']}")
        print(f"Ham messages: {self.label_count['ham']}")
        print(f"Vocabulary size: {len(self.vocab)}\n")
    
    def predict(self, message):
        words = message.lower().split()
        total_messages = sum(self.label_count.values())
        
        # Calculate probabilities for each label
        scores = {}
        for label in ['spam', 'ham']:
            # Prior probability: P(label)
            score = math.log(self.label_count[label] / total_messages)
            
            # Likelihood: P(word|label) with Laplace smoothing
            total_words = sum(self.word_count[label].values())
            vocab_size = len(self.vocab)
            
            for word in words:
                # Laplace smoothing: (count + 1) / (total + vocab_size)
                word_prob = (self.word_count[label][word] + 1) / (total_words + vocab_size)
                score += math.log(word_prob)
            
            scores[label] = score
        
        # Return label with highest score
        return 'spam' if scores['spam'] > scores['ham'] else 'ham'

# Create and train classifier
print("=" * 50)
print("Spam Detection using Naive Bayes Classifier")
print("=" * 50 + "\n")

classifier = SpamClassifier()
classifier.train(training_data)

# Test the classifier
print("Testing Results:")
print("-" * 50)
for message in test_data:
    prediction = classifier.predict(message)
    print(f"Message: '{message}'")
    print(f"Prediction: {prediction.upper()}\n")

# Manual test
print("=" * 50)
print("Try your own message:")
user_message = input("Enter a message: ")
result = classifier.predict(user_message)
print(f"\nPrediction: {result.upper()}")
