// Create a class called Student with data members for name, roll number, and marks.
// Implement constructors to initialize objects and a destructor to release resources.
// Create an array of Student objects and demonstrate constructor and destructor calls.

#include <iostream>

using namespace std;

class Student {
    string name;
    int rollnum;
    float marks;

public:
    Student() {
        name = "Unknown";
        rollnum = 0;
        marks = 0.0;
        cout << "Default constructor called for student: " << name << endl;
    }

    Student(string n, int r, float m) {
        name = n;
        rollnum = r;
        marks = m;

        cout << "Parameterized constructor called for student: " << name << endl;
    }

    ~Student() {
        cout << "Destructor for student: " << name << endl;
    }

    void display() {
        cout << "Name: " << name << ", Roll No.: " << rollnum << ", Marks: " << marks << endl;
    }
};

int main() {
    Student stds[4] = {
        Student("Sasuke", 1, 92.5),
        Student("Sakura", 2, 65.3), 
        Student("Naruto", 3, 20.5),
        Student()
    };

    for (int i = 0; i < 4; i++) {
        stds[i].display();
    }
 
    cout << "\n\nProgrammed by Milan Bairagi...\n\n";

    return 0;
}