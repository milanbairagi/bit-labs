# Lab 63: Attributes vs Elements in XML

## Objective
Demonstrate the use of XML attributes vs elements using a real-world example (product catalog).
Explain the pros and cons of each approach.

## Files
- `products.xml` - Contains product data using three different approaches
- `comparison.md` - Detailed comparison of approaches

## Two Approaches Used

### 1. Elements Approach
```xml
<productWithElements>
    <name>Laptop</name>
    <price>999.99</price>
</productWithElement>
```

### 2. Attributes Approach
```xml
<productWithAttributes name="Laptop" price="999.99"/>
```

## Pros and Cons

### Elements Approach
**Pros:**
- More readable and structured
- Easy to extend with complex data types
- Better for hierarchical relationships
- Supports namespaces naturally
- Can contain multiple children with same name

**Cons:**
- More verbose (larger file size)
- Slower to parse
- More redundant code

### Attributes Approach
**Pros:**
- Compact and concise
- Faster to parse
- Better for simple key-value pairs
- Smaller file size
- Good for unique identifiers

**Cons:**
- Limited to simple string values
- Cannot contain multiple values easily
- Less readable for complex data
- Limited ability to extend
- Cannot have repeating attributes
