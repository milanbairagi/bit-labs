# Lab 68: XML Namespaces

## Objective
Create an XML document that uses two different namespaces:
1. One for employee personal details
2. One for job-related information

Display how to differentiate elements using prefixes.

## Files
- `employees_namespace.xml` - Employee data using multiple namespaces

## Namespace Declarations

### Personal Namespace
```xml
xmlns:personal="http://www.company.com/personal"
```
- **Prefix**: `personal`
- **URI**: `http://www.company.com/personal`
- **Used for**: Personal details, address, contact information

### Job Namespace
```xml
xmlns:job="http://www.company.com/job"
```
- **Prefix**: `job`
- **URI**: `http://www.company.com/job`
- **Used for**: Job-related information, salary, department, designation

## Why Use Namespaces?

### Advantages
1. **Avoid Name Conflicts**: Elements with same name in different namespaces won't clash
2. **Clear Organization**: Data is logically grouped
3. **Better Maintainability**: Easier to identify what each element represents
4. **Modularity**: Personal and job info can be managed independently
5. **Reusability**: Namespaces can be used in other XML documents

### Example
Without namespaces:
```xml
<id>123</id>  <!-- Is this personal ID or employee ID? -->
```

With namespaces:
```xml
<personal:id>123-ABC</personal:id>
<job:employeeId>E001</job:employeeId>
```

## Namespace Prefix Usage

### Personal Details Elements
- `personal:firstName`
- `personal:lastName`
- `personal:dateOfBirth`
- `personal:address`
- `personal:contactNumber`
- `personal:email`

### Job Details Elements
- `job:employeeId`
- `job:designation`
- `job:department`
- `job:dateOfJoining`
- `job:salary`
- `job:manager`
- `job:performanceRating`

## Nested Namespaces

The address is a complex element nested within personal details:
```xml
<personal:address>
    <personal:street>...</personal:street>
    <personal:city>...</personal:city>
    <personal:state>...</personal:state>
    <personal:zipCode>...</personal:zipCode>
</personal:address>
```

All child elements inherit the namespace from their parent.
