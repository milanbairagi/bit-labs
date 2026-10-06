"""Lab 1: Convert a color image to grayscale using Python."""

try:
    from PIL import Image
except ImportError:
    raise SystemExit("Pillow is required. Install it using: pip install pillow")


def color_to_grayscale(input_path: str, output_path: str) -> str:
    """Convert an RGB image into a grayscale image."""
    img = Image.open(input_path).convert("RGB")
    grayscale = Image.new("L", img.size)
    pixels = img.load()
    gray_pixels = grayscale.load()

    for y in range(img.height):
        for x in range(img.width):
            r, g, b = pixels[x, y]
            value = int(0.299 * r + 0.587 * g + 0.114 * b)
            gray_pixels[x, y] = value

    grayscale.save(output_path)
    return output_path


def create_demo_color_image(path: str) -> None:
    """Create a sample RGB image for demonstration."""
    img = Image.new("RGB", (220, 140))
    pixels = img.load()

    for y in range(img.height):
        for x in range(img.width):
            r = int((x / img.width) * 255)
            g = int((y / img.height) * 255)
            b = 255 - int((x / img.width) * 255)
            pixels[x, y] = (r, g, b)

    img.save(path)


if __name__ == "__main__":
    input_path = "lab-1/input_color.png"
    output_path = "lab-1/output_grayscale.png"

    create_demo_color_image(input_path)
    color_to_grayscale(input_path, output_path)
    print(f"Color image converted to grayscale and saved to: {output_path}")
