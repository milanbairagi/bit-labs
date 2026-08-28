/*
Lab 2: What is inheritance? Write a program to implement multiple inheritance
*/

// C# does not support multiple inheritance with classes.
// But we can achieve the same effect using interfaces.

interface IStudent
{
    void Study();
}

interface IEmployee
{
    void Work();
}

class Student : IStudent
{
    public void Study()
    {
        Console.WriteLine("Student is studying.");
    }
}

class Employee : IEmployee
{
    public void Work()
    {
        Console.WriteLine("Employee is working.");
    }
}

class Intern : Student, IEmployee
{
    public void Work()
    {
        Console.WriteLine("Intern is working as an employee.");
    }
}

class Program
{
    static void Main()
    {
        Intern intern = new Intern();
        intern.Study();
        intern.Work();
    }
}
