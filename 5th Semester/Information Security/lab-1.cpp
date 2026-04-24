// 1. WAP to implement Caesar Cipher Algorithm.

#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == ' ') {
            result += ' ';
        } else {
            ch = ((ch - 'a' + key) % 26) + 'a';
            result += ch;
        }
    }
    return result;
}

string decrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == ' ') {
            result += ' ';
        } else {
            ch = ((ch - 'a' - key + 26) % 26) + 'a';
            result += ch;
        }
    }
    return result;
}

int main() {
    string text;
    int key;
    int choice;

    cout << "Enter 1 to encrypt or 2 to decrypt: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter text (lowercase): ";
    getline(cin, text);
    
    cout << "Enter Key value: ";
    cin >> key;
    
    if (choice == 1) {
        cout << "Encrypted: " << encrypt(text, key) << endl;
    } else {
        cout << "Decrypted: " << decrypt(text, key) << endl;
    }

    cout << "\nProgrammed by Milan Bairagi...";
    return 0;
}