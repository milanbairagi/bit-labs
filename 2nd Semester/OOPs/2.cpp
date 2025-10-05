// Create a class called Rectangle that has data members for width and height and member 
// functions to calculate the area and perimeter of the rectangle. Create objects of the 
// Rectangle class and demonstrate how to set and retrieve values for width and height.

#include <iostream>

using namespace std;

class Rectangle {
    float width;
    float height;

public:
    Rectangle() {
        width = 0.0;
        height = 0.0;
    }
    
    Rectangle(float w, float h) {
        width = w;
        height = h;
    }

    void setWidth(float w) {
        width = w;
    }
    void setHeight(float h) {
        height = h;
    }

    float getWidth() { 
        return width;
    }
    float getHeight() { 
        return height;
    }

    float perimeter() {
        return 2 * (width + height);
    }
    float area() {
        return width * height;
    }
};

int main() {
    Rectangle rect;

    rect.setWidth(10);
    rect.setHeight(5);

    cout << "After setting width = 10 and height = 5 of a rectangle..." << endl;

    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;

    cout << "\nPerimeter: " << rect.perimeter() << endl;
    cout << "Area: " << rect.area() << endl;

    cout << "\nProgrammed by Milan Bairagi...";

    return 0;
}