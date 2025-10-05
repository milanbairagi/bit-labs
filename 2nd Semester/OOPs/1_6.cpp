// Declare an integer array of size 5 and populate it with user-input values. Print the 
// elements of the array in reverse order

#include <iostream>

using namespace std;

int main() {
    int nums[5];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }

    cout << "Array in reversed order: ";
    for (int i = 4; i >= 0; i--) {
        cout << nums[i] << " ";
    }

    cout << "\n\nProgrammed by Milan Bairagi...";

    return 0;
}