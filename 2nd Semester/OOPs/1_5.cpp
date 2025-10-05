// Define a function that calculates the factorial of a given integer.

#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    cout << "The factorial of " << num << " is " << 
            factorial(num) << "." << endl;

    cout << "\nProgrammed by Milan Bairagi...";

    return 0;
}