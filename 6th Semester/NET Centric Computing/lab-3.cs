/*
Lab 3: Define Lambda. Write a program to display student list filter by department Id using
Lambda expression. Student has attributes(Id, DepartmentId, Name and Address) and take any number
of students.
*/

class Student
{
    public int Id { get; set; }
    public int DepartmentId { get; set; }
    public string Name { get; set; }
    public string Address { get; set; }

    public Student(int id, int departmentId, string name, string address)
    {
        Id = id;
        DepartmentId = departmentId;
        Name = name;
        Address = address;
    }
}

class Program
{
    static void Main()
    {
        List<Student> students =
        [
            new Student(1, 101, "Alice", "Balaju"),
            new Student(2, 102, "Bob", "Kapan"),
            new Student(3, 101, "Charlie", "Patan"),
            new Student(4, 103, "David", "Thamel"),
            new Student(5, 102, "Eve", "Baneshwor")
        ];

        Console.Write("Enter Department Id to filter students: ");
        int departmentId = Convert.ToInt32(Console.ReadLine());

        var filteredStudents = students.Where(s => s.DepartmentId == departmentId);

        Console.WriteLine($"Students in Department {departmentId}:");
        Console.WriteLine("Id\tName\tAddress");
        foreach (var student in filteredStudents)
        {
            Console.WriteLine($"{student.Id}\t{student.Name}\t{student.Address}");
        }
    }
}