// Demonstrate polymorphism by creating an array of Shape pointers and calling the area() 
// function for different shapes.

#include <iostream>

using namespace std;

class Shape {
public:
    virtual float area() = 0;
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}

    float area() {
        return 3.14 * radius * radius;
    }
};


class Triangle : public Shape {
    float base;
    float height;
public:
    Triangle(float h, float b) : height(h), base(b) {}

    float area() {
        return (base * height) / 2;
    }
};

int main() {
    Shape* shapes[3];

    shapes[0] = new Circle(5);
    shapes[1] = new Triangle(10, 5);
    shapes[2] = new Circle(2);

    for (int i = 0; i < 3; i++) {
        cout << "Area of shape " << i << " is " << shapes[i]->area() << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    cout << "\nProgrammed by Milan Bairagi...";

    return 0;
}