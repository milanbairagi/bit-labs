// Create a program that reads two integers and performs division. Implement exception 
// handling to catch divide-by-zero errors and display appropriate error messages.
// Demonstrate the program with both valid and invalid inputs

#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    float result;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    try {
        if (num2 == 0) {
            throw runtime_error("Division by zero is not allowed!");
        }

        result = (float) num1 / num2;        
        cout << num1 << " / " << num2 << " = " << result;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl << "Programmed by Milan Bairagi..." << endl;

    return 0;
}