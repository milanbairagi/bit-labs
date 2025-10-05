// Write a program that asks the user to enter an integer. Check if the number is even or 
// odd and display an appropriate message.

#include <iostream>

using namespace std;

bool isEven(int num) {
    return (num % 2 == 0) ? true : false;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isEven(num)) 
        cout << "The number '" << num << "' is even." << endl;
    else 
        cout << "The number '" << num << "' is odd." << endl;
    
    cout << endl << "Programmed by Milan Bairagi..";

    return 0;
}