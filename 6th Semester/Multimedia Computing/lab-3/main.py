"""Lab 3: Implement Run Length Coding (RLC) in Python."""


def rle_encode(data: str):
    """Encode a string using Run Length Encoding."""
    if not data:
        return []

    encoded = []
    count = 1
    current = data[0]

    for ch in data[1:]:
        if ch == current:
            count += 1
        else:
            encoded.append((current, count))
            current = ch
            count = 1

    encoded.append((current, count))
    return encoded


def rle_decode(encoded):
    """Decode an RLE encoded list back to the original string."""
    result = ""
    for ch, count in encoded:
        result += ch * count
    return result


if __name__ == "__main__":
    sample = "WWWWWWBBBYYYYYAAAAAARRRRRRR"
    encoded = rle_encode(sample)
    decoded = rle_decode(encoded)

    print("Original data:", sample)
    print("Encoded data:", encoded)
    print("Decoded data:", decoded)
