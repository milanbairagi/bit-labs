#include <iostream>

using namespace std; 

int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

// Euler Totient Function 
int etf(int n) { 
    int result = 1;
    cout << "Numbers coprime to " << n << ": 1 ";
    for (int i = 2; i < n; i++) 
        if (gcd(i, n) == 1) {
            result++; 
            cout << i << " ";
        }
    
    cout << endl;
    return result; 
} 

// Driver Code
int main() { 
    int n;
    
    cout << "Enter a number: ";
    cin >> n;

    int result = etf(n);
    cout << "Euler's Totient Function for " << n << " is " << result << endl;

    cout << "\nProgrammed by Milan Bairagi..." << endl;
    return 0; 
}