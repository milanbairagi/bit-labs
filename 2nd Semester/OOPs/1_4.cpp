// Create a program that uses a loop (for and while) to print numbers from 1 to 10.

#include <iostream>

using namespace std;

int main() {
    // Print numbers from 1 to 10 usin for loop
    cout << "Using for loop:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << endl;
    }

    cout << "\nUsing while loop:" << endl;
    int i = 1;
    while (i <= 10) {
        cout << i << endl;
        i++;
    }
    
    cout << "\nProgrammed by Milan Bairagi...";

    return 0;
}