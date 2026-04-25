// 9. WAP to find first twenty Prime numbers.
#include <iostream>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    
    // Check divisibility from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "\n===== First 20 Prime Numbers =====" << endl;
    
    int count = 0;
    int num = 2;
    
    // Find first 20 prime numbers
    while (count < 20) {
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }

    cout << "\n\nProgrammed by Milan Bairagi..." << endl;
    
    return 0;
}
