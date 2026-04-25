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
        
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    
    return result;
}

int main() {
    long long P, G, a, b, x, y, ka, kb;
    cout << "=== Diffie-Hellman Key Exchange Algorithm ===" << endl;
    
    // Step 1: Choose a large public prime numbers P and G
    P = 23;
    G = 5;
    cout << "Public Key Generation:" << endl;
    cout << "Prime number (P) = " << P << endl;
    cout << "Primitive root (G) = " << G << endl;

    // Step 2: Choose private keys a and b
    a = 4; // Alice's private key
    b = 3; // Bob's private key
    cout << "\nAlice's private key (a) = " << a << endl;
    cout << "Bob's private key (b) = " << b << endl;

    // Step 3: Compute public keys
    x = powerMod(G, a, P); // Alice's public key
    y = powerMod(G, b, P); // Bob's public key
    cout << "\nAlice's public key (x) = " << "G^a mod P = " << x << endl;
    cout << "Bob's public key (y) = " << "G^b mod P = " << y << endl;

    // Step 4: Alice and Bob exchange public keys
    cout << "\nAlice(x) and Bob(y) exchange their public keys.\n" << endl;

    // Step 5: Compute shared secrets
    ka = powerMod(y, a, P);
    kb = powerMod(x, b, P);
    cout << "Shared secret (Alice): " << "y^a mod P = " << ka << endl;
    cout << "Shared secret (Bob): " << "x^b mod P = " << kb << endl;

    cout << "\nProgrammed by Milan Bairagi..." << endl;
    
    return 0;
}