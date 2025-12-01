# Lab 67: Student Records with XSD (Complex Types)

## Objective
Write an XML Schema (XSD) to validate a student record system where:
- Students have complex types including:
  - Address (sub-elements: street, city, zip code)
  - Simple types: name and grade

## Files
- `students.xml` - Student record data
- `students.xsd` - XML Schema with complex types

## XSD Structure

### Complex Types
1. **StudentType**
   - Contains: name, grade, address
   - Attribute: studentId (required)

2. **AddressType**
   - Contains: street, city, zipCode
   - Represents nested/complex address information

### Simple Types with Restrictions

1. **NameType**
   - Base type: xs:string
   - Constraints:
     - Minimum length: 1 character
     - Maximum length: 100 characters

2. **GradeType**
   - Base type: xs:string
   - Enumeration (allowed values):
     - A+, A, B, C, D, F

3. **ZipCodeType**
   - Base type: xs:string
   - Pattern: 5 digits `[0-9]{5}`

## Key Concepts Demonstrated

### Nested Complex Types
- Address is a complex type nested within StudentType
- Shows hierarchical data structure

### Type Inheritance and Restriction
- Simple types are created by restricting base types
- Patterns and enumerations validate data format

### Attributes
- studentId is an attribute (required)
- Attributes provide additional metadata

## Validation Rules
- Student ID must be provided
- Name must be 1-100 characters
- Grade must be one of the allowed values
- Zip code must be exactly 5 digits
