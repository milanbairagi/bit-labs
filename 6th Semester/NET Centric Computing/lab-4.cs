/*
Lab 4: Define LINQ.
LINQ stands for Language Integrated Query. It is used to query and filter data in a C#-style syntax.
Write a program to display voter name whose age is greater than 18 and lives in "Patan".
*/

using System;
using System.Collections.Generic;
using System.Linq;

class Voter
{
    public string Name { get; set; }
    public int Age { get; set; }
    public string Address { get; set; }

    public Voter(string name, int age, string address)
    {
        Name = name;
        Age = age;
        Address = address;
    }
}

class Program
{
    static void Main()
    {
        List<Voter> voters = new List<Voter>
        {
            new Voter("Aarav Shrestha", 19, "Patan"),
            new Voter("Nisha Karki", 17, "Patan"),
            new Voter("Suman Thapa", 22, "Kathmandu"),
            new Voter("Priya Maharjan", 25, "Patan"),
            new Voter("Ramesh Lama", 18, "Patan"),
        };

        // 1. Query Syntax
        // IEnumerable<Voter> eligibleVoters =
        //     from voter in voters
        //     where voter.Age > 18 && voter.Address == "Patan"
        //     select voter;

        // 2. Method Syntax
        IEnumerable<Voter> eligibleVoters = voters.Where(voter =>
            voter.Age > 18 && voter.Address == "Patan"
        );

        Console.WriteLine("Eligible voter names:");
        foreach (var voter in eligibleVoters)
        {
            Console.WriteLine(voter.Name);
        }
    }
}
