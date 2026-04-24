#include <iostream>
#include <iomanip>
using namespace std;

// Euclidean Algorithm with steps visualization in table format
int gcd(int a, int b) {
    cout << "\nEuclidean Algorithm Steps:" << endl;
    cout << "======================================================" << endl;
    cout << setw(5) << "Step" << " | " << setw(10) << "Dividend" << " | " 
         << setw(8) << "Divisor" << " | " << setw(10) << "Remainder" << " | " 
         << setw(8) << "Quotient" << endl;
    cout << "------|------------|----------|------------|----------" << endl;
    
    if (a < b) {
        swap(a, b);
    }

    int step = 1;
    
    while (b != 0) {
        int q = a / b;
        int r = a % b;
        
        cout << setw(5) << step << " | " << setw(10) << a << " | " 
             << setw(8) << b << " | " << setw(10) << r << " | " 
             << setw(8) << q << endl;
        
        a = b;
        b = r;
        step++;
    }
    
    cout << "======================================================" << endl;    
    return a;
}

int main() {
    int num1, num2;
    
    cout << "\n===== Euclidean Algorithm =====" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    if (num1 < 0 || num2 < 0) {
        cout << "Please enter non-negative numbers!" << endl;
        return 0;
    }
    
    int result = gcd(num1, num2);
    cout << "\nGCD(" << num1 << ", " << num2 << ") = " << result << endl;
    
    return 0;
}
