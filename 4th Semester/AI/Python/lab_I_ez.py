import re

class Node:
    def __init__(self, label, children=None):
        self.label = label
        self.children = children or []

class SimpleParser:
    def __init__(self):
        # Grammar rules
        self.grammar = {
            'S': [['NP', 'VP']],
            'NP': [['DT', 'NN'], ['DT', 'JJ', 'NN'], ['NN'], ['JJ', 'NN']],
            'VP': [['VB', 'NP'], ['VB'], ['VB', 'JJ']],
        }
        # Lexicon
        self.lexicon = {
            'DT': ['the', 'a', 'an', 'this', 'that'],
            'NN': ['cat', 'dog', 'man', 'woman', 'book', 'car'],
            'VB': ['runs', 'walks', 'reads', 'writes', 'sleeps', 'eats'],
            'JJ': ['big', 'small', 'red', 'blue', 'happy', 'sad']
        }
        # Reverse lookup
        self.word_to_category = {w: cat for cat, words in self.lexicon.items() for w in words}

    def tokenize(self, sentence):
        return re.sub(r'[^\w\s]', '', sentence.lower()).split()

    def parse_recursive(self, words, symbol, pos):
        # Terminal
        if symbol in self.lexicon:
            if pos < len(words) and words[pos] in self.lexicon[symbol]:
                return Node(f"{symbol}({words[pos]})"), pos + 1
            return None, pos
        # Non-terminal
        if symbol in self.grammar:
            for rule in self.grammar[symbol]:
                children = []
                cur_pos = pos
                for s in rule:
                    node, new_pos = self.parse_recursive(words, s, cur_pos)
                    if not node:
                        break
                    children.append(node)
                    cur_pos = new_pos
                else:
                    return Node(symbol, children), cur_pos
        return None, pos

    def parse(self, sentence):
        words = self.tokenize(sentence)
        for w in words:
            if w not in self.word_to_category:
                return None
        tree, pos = self.parse_recursive(words, 'S', 0)
        if tree and pos == len(words):
            return tree
        return None

    def print_tree(self, node, indent=""):
        print(indent + node.label)
        for child in node.children:
            self.print_tree(child, indent + "  ")

    def bracket_notation(self, node):
        if not node.children:
            return node.label
        return f"[{node.label.split('(')[0]} " + " ".join(self.bracket_notation(c) for c in node.children) + "]"

# Example usage
if __name__ == "__main__":
    parser = SimpleParser()
    sentences = ["the cat runs", "a big dog eats", "the man reads the book"]

    for s in sentences:
        print(f"\nSentence: {s}")
        tree = parser.parse(s)
        if tree:
            print("Tree:")
            parser.print_tree(tree)
            print("Bracket notation:")
            print(parser.bracket_notation(tree))
        else:
            print("Could not parse.")
