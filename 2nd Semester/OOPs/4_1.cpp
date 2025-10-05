// Create a base class called Shape with a pure virtual function area() and another virtual 
// function display(). Create two derived classes, Circle and Triangle, inheriting from the 
// Shape class. Implement the area() function in each derived class.

#include <iostream>

using namespace std;

class Shape {
public:
    virtual float area() = 0;

    virtual void display() {
        cout << "Area: " << area() << endl;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}

    float area() {
        return 3.14 * radius * radius;
    }

    void display() {
        cout << "The area of circle with radius " << radius 
            << " is " << area() << "." << endl;
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

    void display() {
        cout << "The area of triangle with height " << height 
            << " and base " << base <<  " is " << area() << "." << endl;
    }
};

int main() {
    Circle circle(5.0);
    Triangle triangle(10.0, 5.0);

    circle.display();
    triangle.display();

    cout << "\nProgrammed by Milan Bairagi...";

    return 0;
}