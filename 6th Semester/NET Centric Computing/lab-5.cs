// Lab 5: What exception handling? Write a program to handle exception when User put character in price field.

using System;

class Program
{
    static void Main()
    {
        Console.Write("Enter the price: ");
        string input = Console.ReadLine();

        try
        {
            decimal price = Convert.ToDecimal(input);
            Console.WriteLine($"The price entered is: {price}");
        }
        catch (FormatException)
        {
            Console.WriteLine("Error: Please enter a valid numeric value for the price.");
        }
        catch (OverflowException)
        {
            Console.WriteLine("Error: The number entered is too large or too small for a decimal.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"An unexpected error occurred: {e.Message}");
        }
    }
}
