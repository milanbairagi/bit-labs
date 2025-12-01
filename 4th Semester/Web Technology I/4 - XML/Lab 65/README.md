# Lab 65: Modified Employee XML with Multiple Phone Numbers and Optional Email

## Objective
Modify the XML and DTD to allow:
- Multiple phone numbers for each employee
- Optional email addresses for each employee

## Files
- `employees.xml` - Updated employee data with multiple phones and optional emails
- `employees.dtd` - Modified DTD with new constraints

## Key DTD Changes

### Multiple Phone Numbers
```dtd
<!ELEMENT phoneNumbers (phone+)>
<!ELEMENT phone (#PCDATA)>
```
- `phone+` means one or more phone numbers are required
- Each phone number is a separate element

### Optional Email
```dtd
<!ELEMENT email (#PCDATA)>
```
The `?` after `email` in the employee element definition means:
- Email is optional (0 or 1 occurrence)

## Updated Structure
```dtd
<!ELEMENT employee (id, name, department, salary, phoneNumbers, email?)>
```

- `id` - Required
- `name` - Required
- `department` - Required
- `salary` - Required
- `phoneNumbers` - Required (contains one or more phone elements)
- `email` - Optional (0 or 1 occurrence)
