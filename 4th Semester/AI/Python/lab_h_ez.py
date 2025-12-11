import math
import re
from collections import defaultdict


class NaiveBayesSpam:
    def __init__(self):
        self.spam_counts = defaultdict(int)
        self.ham_counts = defaultdict(int)
        self.spam_total = 0
        self.ham_total = 0
        self.spam_emails = 0
        self.ham_emails = 0
        self.vocab = set()

    def tokenize(self, text):
        return re.sub(r'[^a-zA-Z\s]', '', text.lower()).split()

    def train(self, emails, labels):
        for email, label in zip(emails, labels):
            words = self.tokenize(email)
            self.vocab.update(words)
            if label == 'spam':
                self.spam_emails += 1
                for w in words:
                    self.spam_counts[w] += 1
                    self.spam_total += 1
            else:
                self.ham_emails += 1
                for w in words:
                    self.ham_counts[w] += 1
                    self.ham_total += 1

    def word_prob(self, word, counts, total):
        return (counts[word] + 1) / (total + len(self.vocab))

    def predict(self, email):
        words = self.tokenize(email)
        total_emails = self.spam_emails + self.ham_emails
        spam_log = math.log(self.spam_emails / total_emails)
        ham_log = math.log(self.ham_emails / total_emails)
        for w in words:
            if w in self.vocab:
                spam_log += math.log(self.word_prob(w, self.spam_counts, self.spam_total))
                ham_log += math.log(self.word_prob(w, self.ham_counts, self.ham_total))
        return 'spam' if spam_log > ham_log else 'ham'

    def evaluate(self, emails, labels):
        correct = sum(self.predict(e) == l for e, l in zip(emails, labels))
        return correct / len(emails)


# Example usage
train_emails = [
    "win money now click here", "meeting tomorrow at 3pm", "free viagra buy now",
    "project deadline reminder", "congratulations you won lottery"
]
train_labels = ['spam', 'ham', 'spam', 'ham', 'spam']

test_emails = ["free money offer now", "meeting scheduled tomorrow", "win lottery today"]
test_labels = ['spam', 'ham', 'spam']

nb = NaiveBayesSpam()
nb.train(train_emails, train_labels)

print("Predictions:")
for email in test_emails:
    print(f"Email: '{email}' => {nb.predict(email).upper()}")

accuracy = nb.evaluate(test_emails, test_labels)
print(f"\nAccuracy: {accuracy:.2%}")
print("\nProgrammed by: Devashish Poudel")