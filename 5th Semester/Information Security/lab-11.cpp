#include <iostream>
#include <cmath>

using namespace std;

// Function to compute GCD using Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute Euler's Totient Function φ(n)
// φ(n) counts integers from 1 to n that are coprime with n
int eulerTotient(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1)
            result++;
    }
    return result;
}

// Function for modular exponentiation: (base^exp) % mod
long long modExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to check if two numbers are relatively prime (coprime)
bool areRelativelyPrime(int a, int b) {
    return gcd(a, b) == 1;
}

// Function to verify Euler's Theorem
// If gcd(a, n) = 1, then a^φ(n) ≡ 1 (mod n)
bool verifyEulerTheorem(int a, int n) {
    if (!areRelativelyPrime(a, n)) {
        cout << "Numbers are not coprime. Euler's Theorem does not apply.\n";
        return false;
    }
    
    int phi_n = eulerTotient(n);
    long long result = modExponentiation(a, phi_n, n);
    
    cout << "Euler's Totient φ(" << n << ") = " << phi_n << "\n";
    cout << a << "^" << phi_n << " mod " << n << " = " << result << "\n";
    
    return result == 1;
}

int main() {
    int num1, num2;
    
    cout << "=== Euler's Theorem: Checking Relatively Prime Numbers ===\n\n";
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "\n=== Results ===\n";
    
    // Check if relatively prime
    if (areRelativelyPrime(num1, num2)) {
        cout << num1 << " and " << num2 << " are relatively prime.\n";
        cout << "GCD(" << num1 << ", " << num2 << ") = " << gcd(num1, num2) << "\n\n";
        
        // Verify Euler's Theorem with first number as base and second as modulus
        cout << "=== Verifying Euler's Theorem ===\n";
        if (verifyEulerTheorem(num1, num2)) {
            cout << "Euler's Theorem verified: a^φ(n) ≡ 1 (mod n)\n";
        }
    } else {
        cout << num1 << " and " << num2 << " are not relatively prime.\n";
        cout << "GCD(" << num1 << ", " << num2 << ") = " << gcd(num1, num2) << "\n";
    }

    cout << "\nProgrammed by Milan Bairagi..." << endl;
    
    return 0;
}
