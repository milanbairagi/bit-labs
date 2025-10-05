// Create a program that performs basic arithmetic operations (addition, subtraction, 
// multiplication, division) on two user-input numbers.

#include <iostream>

using namespace std;

int main() {
    float num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;

    cout << "\nProgrammed by Milan Bairagi...";
    return 0;
}