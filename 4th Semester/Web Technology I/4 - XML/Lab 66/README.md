# Lab 66: Order XML with XSD Schema

## Objective
Design an XML document for an online order containing:
- Customer details
- Order ID
- List of products (with name, quantity, and price)
- Total amount

Write an XSD schema to validate with appropriate data types and constraints.

## Files
- `orders.xml` - Contains order data
- `orders.xsd` - XML Schema Definition for validation

## Key Features

### Data Types Used
- `xs:string` - For text fields (customer name, email, product name)
- `xs:integer` - For quantity
- `xs:decimal` - For prices and total amount
- `xs:attribute` - For orderId (required)

### Constraints Applied
- Order ID is a required attribute
- Customer details are mandatory
- At least one product must be present
- Prices and quantities are numeric with appropriate types
- Total amount is decimal format

### XSD Structure
- **Root Element**: `orders` containing multiple `order` elements
- **Order Type**: Contains customer details, products, and total amount
- **Customer Details**: Name, email, phone, address
- **Products**: Array of product elements
- **Product Type**: Name, quantity, price

## Validation Benefits
- Ensures data integrity
- Prevents invalid entries
- Type checking at schema level
- Required field enforcement
