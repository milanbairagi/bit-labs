#include <iostream>
#include <cmath>
using namespace std;

// Function to compute modular exponentiation: (base^exp) % mod
// Uses fast exponentiation to avoid precision loss with large numbers
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        
        exp = exp >> 1;  // Right shift exponent: exp = exp / 2
        base = (base * base) % mod;
    }
    
    return result;
}

// Function to compute GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular multiplicative inverse using Extended Euclidean Algorithm
long long modInverse(long long e, long long phi) {
    long long m0 = phi, x0 = 0, x1 = 1;
    
    if (phi == 1)
        return 0;
    
    while (e > 1) {
        long long q = e / phi;
        long long t = phi;
        
        phi = e % phi;
        e = t;
        
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}


int main() {
    cout << "=== RSA Algorithm ===" << endl;
    
    cout << "\n=== Key Generation ===" << endl;
    
    // Step 1: Choose two distinct large prime numbers p and q
    long long p, q;
    p = 7919;
    q = 1009;
    cout << "Chosen prime numbers:" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    
    
    // Step 2: Compute n = p * q
    long long n = p * q;
    cout << "n = p * q = " << p << " * " << q << " = " << n << endl;
    
    // Step 3: Compute Euler's Totient function φ(n) = (p-1)(q-1)
    long long phi = (p - 1) * (q - 1);
    cout << "φ(n) = (p-1)(q-1) = " << (p-1) << " * " << (q-1) << " = " << phi << endl;
    
    // Step 4: Choose e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1
    long long e;
    cout << "\nChoose public exponent (e) where 1 < e < φ(n): " << endl;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }
    cout << "Public exponent (e) = " << e << endl;
    
    // Step 5: Compute d as the modular multiplicative inverse of e modulo φ(n)
    long long d = modInverse(e, phi);
    cout << "Private exponent (d) = " << d << " (where e * d ≡ 1 (mod φ(n)))" << endl;
    
    cout << "\n=== Public and Private Keys ===" << endl;
    cout << "Public Key (e, n) = (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n) = (" << d << ", " << n << ")" << endl;
    
    // Step 6: Encryption and Decryption
    cout << "\n=== Encryption/Decryption ===" << endl;
    long long plaintext;
    plaintext = 123;
    cout << "Plaintext message (M) = " << plaintext << endl;
    
    // Encryption: C = M^e mod n
    long long ciphertext = powerMod(plaintext, e, n);
    cout << "\nEncryption:" << endl;
    cout << "Ciphertext (C) = M^e mod n = " << plaintext << "^" << e << " mod " << n << " = " << ciphertext << endl;
    
    // Decryption: M = C^d mod n
    long long decrypted = powerMod(ciphertext, d, n);
    cout << "\nDecryption:" << endl;
    cout << "Decrypted Message (M) = C^d mod n = " << ciphertext << "^" << d << " mod " << n << " = " << decrypted << endl;
    
    cout << "\nProgrammed by Milan Bairagi..." << endl;
    
    return 0;
}
