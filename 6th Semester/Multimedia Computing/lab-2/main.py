"""Lab 2: Convert a grayscale image to black and white using Python."""

try:
    from PIL import Image
except ImportError:
    raise SystemExit("Pillow is required. Install it using: pip install pillow")


def grayscale_to_black_and_white(input_path: str, output_path: str, threshold: int = 128) -> str:
    """Convert grayscale image to black and white using thresholding."""
    grayscale = Image.open(input_path).convert("L")
    binary = grayscale.point(lambda p: 255 if p > threshold else 0)
    binary.save(output_path)
    return output_path


def create_demo_grayscale_image(path: str) -> None:
    """Create a sample grayscale image for conversion."""
    img = Image.new("L", (220, 140))
    pixels = img.load()

    for y in range(img.height):
        for x in range(img.width):
            value = int((x / img.width) * 255)
            pixels[x, y] = value

    img.save(path)


if __name__ == "__main__":
    input_path = "lab-2/input_grayscale.png"
    output_path = "lab-2/output_black_white.png"

    create_demo_grayscale_image(input_path)
    grayscale_to_black_and_white(input_path, output_path)
    print(f"Grayscale image converted to black-and-white and saved to: {output_path}")
