// Create a class called Complex to represent complex numbers with data members for 
// real and imaginary parts. Overload the + and - operators for complex number addition 
// and subtraction. Create objects of the Complex class and demonstrate operator 
// overloading.


#include <iostream>

using namespace std;

class Complex {
    float real, img;

public:
    Complex(float r=0, float i=0) : real(r), img(i) {};

    Complex operator+(Complex cpxNum) {
        Complex res;
        res.real = real + cpxNum.real;
        res.img = img + cpxNum.img;
        return res;
    }

    Complex operator-(Complex cpxNum) {
        Complex res;
        res.real = real - cpxNum.real;
        res.img = img - cpxNum.img;
        return res;
    }

    void print() {
        cout << real << " + " << img << "i" << endl;
    }

};

int main() {
    Complex cpx1(5, 4);
    Complex cpx2(6, 2);

    Complex cpx3;
    Complex cpx4;

    cpx3 = cpx1 + cpx2;
    cpx4 = cpx1 - cpx2;

    cout << "Complex number 1: ";
    cpx1.print();

    cout << "Complex number 2: ";
    cpx2.print();

    cout << endl << "Sum: ";
    cpx3.print();
    
    cout << endl << "Difference: ";
    cpx4.print();

    cout << endl << "Programmed by Milan Bairagi...";

    return 0;
}