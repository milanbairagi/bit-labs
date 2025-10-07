"""
Parse Tree Generator - Simple Version (No External Libraries)
Draws parse trees for simple English sentences
"""

# Define grammar rules
grammar = {
    'S': [['NP', 'VP']],
    'NP': [['Det', 'N'], ['Det', 'Adj', 'N'], ['N']],
    'VP': [['V', 'NP'], ['V', 'Adj'], ['V']],
    'Det': [['the'], ['a'], ['an']],
    'N': [['cat'], ['dog'], ['boy'], ['girl'], ['ball'], ['book']],
    'V': [['chased'], ['ate'], ['read'], ['is'], ['loves']],
    'Adj': [['big'], ['small'], ['red'], ['happy'], ['good']]
}

# Terminal symbols (actual words)
terminals = ['the', 'a', 'an', 'cat', 'dog', 'boy', 'girl', 'ball', 'book',
             'chased', 'ate', 'read', 'is', 'loves', 'big', 'small', 'red', 'happy', 'good']

class Node:
    """Tree node for parse tree"""
    def __init__(self, label, children=None):
        self.label = label
        self.children = children or []
    
    def __str__(self, level=0):
        """Print tree structure"""
        indent = "  " * level
        result = f"{indent}{self.label}\n"
        for child in self.children:
            if isinstance(child, Node):
                result += child.__str__(level + 1)
            else:
                result += f"{indent}  {child}\n"
        return result

def parse_sentence(words, pos=0, symbol='S'):
    """Recursive parser to build parse tree"""
    # Base case: terminal symbol
    if symbol.lower() in terminals:
        if pos < len(words) and words[pos] == symbol.lower():
            return Node(symbol, [words[pos]]), pos + 1
        return None, pos
    
    # Non-terminal: try each production rule
    if symbol in grammar:
        for rule in grammar[symbol]:
            children = []
            current_pos = pos
            success = True
            
            for part in rule:
                result, new_pos = parse_sentence(words, current_pos, part)
                if result:
                    children.append(result)
                    current_pos = new_pos
                else:
                    success = False
                    break
            
            if success:
                return Node(symbol, children), current_pos
    
    return None, pos

def draw_tree(sentence):
    """Parse and draw the tree"""
    words = sentence.lower().split()
    
    print(f"\nInput: {sentence}")
    print(f"Words: {words}\n")
    
    # Check if all words are valid
    invalid_words = [w for w in words if w not in terminals]
    if invalid_words:
        print(f"Error: Unknown words - {invalid_words}")
        print("\nValid words are:")
        print(f"  Determiners: the, a, an")
        print(f"  Nouns: cat, dog, boy, girl, ball, book")
        print(f"  Verbs: chased, ate, read, is, loves")
        print(f"  Adjectives: big, small, red, happy, good")
        return
    
    # Parse the sentence
    tree, final_pos = parse_sentence(words, 0, 'S')
    
    if tree and final_pos == len(words):
        print("Parse Tree:")
        print("-" * 50)
        print(tree)
    else:
        print("No valid parse found!")
        print("Sentence doesn't match grammar rules.")
        print("\nTry sentences like:")
        print("  - the cat chased the dog")
        print("  - a boy read the book")
        print("  - the dog is happy")

# Main Program
print("=" * 60)
print("Parse Tree Generator")
print("=" * 60)
print("\nGrammar Rules:")
print("  S  -> NP VP           (Sentence = Noun Phrase + Verb Phrase)")
print("  NP -> Det N           (Noun Phrase = Determiner + Noun)")
print("  NP -> Det Adj N       (Noun Phrase = Det + Adjective + Noun)")
print("  VP -> V NP            (Verb Phrase = Verb + Noun Phrase)")
print("  VP -> V Adj           (Verb Phrase = Verb + Adjective)")
print("=" * 60)

print("\nExample Sentences:")
examples = [
    "the cat chased the dog",
    "a boy read the book",
    "the dog is happy",
    "a big cat ate the small ball"
]

for ex in examples:
    print(f"  - {ex}")

print("\n" + "=" * 60)

# Interactive mode
while True:
    sentence = input("\nEnter a sentence (or 'quit' to exit): ").strip()
    
    if sentence.lower() == 'quit':
        print("Goodbye!")
        break
    
    if sentence:
        draw_tree(sentence)
    else:
        print("Please enter a valid sentence!")
