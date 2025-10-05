// Create a template class called Stack to implement a generic stack data structure.
// Implement functions for pushing and popping elements from the stack. Create instances 
// of the Stack class for both integers and strings and demonstrate their usage.

#include <iostream>

using namespace std;

template <typename T>
class Stack {
    static const int MAX = 10;
    T stack[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(T element) {
        stack[++top] = element;
        cout << element << " is pushed!" << endl;
    }
    void pop() {
        cout << stack[top] << " is popped!" << endl;
        --top;
    }

    void display() {
        cout << "Stack Content: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> intStack;
    Stack<string> stringStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << endl;
    cout << "Integer Stack:" << endl; 
    intStack.display();
    cout << endl;

    intStack.pop();

    cout << endl;
    cout << "Integer Stack:" << endl; 
    intStack.display();
    cout << endl;

    stringStack.push("Hello");
    stringStack.push("World");

    
    cout << endl;
    cout << "String Stack:" << endl; 
    stringStack.display();
    cout << endl;

    stringStack.pop();
    
    cout << endl;
    cout << "String Stack:" << endl; 
    stringStack.display();
    cout << endl;

    cout << endl << "Programmed by Milan Bairagi...";

    return 0;
}