"""Lab 4: Implement Huffman Coding in Python."""

import heapq
from collections import defaultdict


class Node:
    def __init__(self, char=None, freq=0, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.freq < other.freq


def build_frequency_map(text: str):
    freq = defaultdict(int)
    for ch in text:
        freq[ch] += 1
    return freq


def build_huffman_tree(text: str):
    freq_map = build_frequency_map(text)
    if not freq_map:
        return None

    heap = [Node(char, freq) for char, freq in freq_map.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        parent = Node(freq=left.freq + right.freq, left=left, right=right)
        heapq.heappush(heap, parent)

    return heap[0]


def build_codes(node, prefix="", code_map=None):
    if code_map is None:
        code_map = {}

    if node is None:
        return code_map

    if node.char is not None:
        code_map[node.char] = prefix if prefix else "0"
        return code_map

    build_codes(node.left, prefix + "0", code_map)
    build_codes(node.right, prefix + "1", code_map)
    return code_map


def huffman_encode(text: str):
    if not text:
        return "", {}

    root = build_huffman_tree(text)
    code_map = build_codes(root)
    encoded = "".join(code_map[ch] for ch in text)
    return encoded, code_map


def huffman_decode(encoded_bits: str, code_map):
    if not encoded_bits:
        return ""

    reverse_map = {code: char for char, code in code_map.items()}
    decoded = ""
    current = ""

    for bit in encoded_bits:
        current += bit
        if current in reverse_map:
            decoded += reverse_map[current]
            current = ""

    return decoded


if __name__ == "__main__":
    sample = "this is an example of a huffman encoding algorithm"
    encoded_bits, codes = huffman_encode(sample)
    decoded_text = huffman_decode(encoded_bits, codes)

    print("Original text:", sample)
    print("Huffman codes:", codes)
    print("Encoded bits:", encoded_bits)
    print("Decoded text:", decoded_text)
