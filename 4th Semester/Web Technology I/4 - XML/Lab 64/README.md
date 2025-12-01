# Lab 64: Employee XML with External DTD

## Objective
Create an XML document for employee data and write an external DTD to validate it.
Include elements: employee, name, id, department, and salary.

## Files
- `employees.xml` - Contains employee data with DTD reference
- `employees.dtd` - External DTD defining the structure

## DTD Structure
The DTD defines:
- `employees` root element containing zero or more `employee` elements
- Each `employee` must contain exactly these elements in order:
  - `id` - Text data for employee ID
  - `name` - Text data for employee name
  - `department` - Text data for department name
  - `salary` - Text data for salary amount

## Validation
The XML document references the external DTD:
```xml
<!DOCTYPE employees SYSTEM "employees.dtd">
```

This means the XML parser will validate the document against the rules defined in `employees.dtd`.
