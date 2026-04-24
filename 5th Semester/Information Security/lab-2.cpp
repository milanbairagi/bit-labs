// 2. WAP to implement Mono-Alphabetic Cipher Algorithm.

#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == ' ') {
            result += ' ';
        } else {
            result += key[ch - 'a'];
        }
    }
    return result;
}

string decrypt(string text, string key) {
    string result = "";
    // Create reverse mapping
    char reverseKey[26];
    for (int i = 0; i < 26; i++) {
        reverseKey[key[i] - 'a'] = 'a' + i;
    }
    
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == ' ') {
            result += ' ';
        } else {
            result += reverseKey[ch - 'a'];
        }
    }
    return result;
}

int main() {
    string text, key;
    int choice;
    
    cout << "Enter 1 to encrypt or 2 to decrypt: ";
    cin >> choice;
    cin.ignore();
    
    cout << "Enter text (lowercase): ";
    getline(cin, text);
    
    cout << "Enter substitution key (26 chars, a-z): ";
    getline(cin, key);
    
    if (choice == 1) {
        cout << "Encrypted: " << encrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Decrypted: " << decrypt(text, key) << endl;
    }

    cout << "\nProgrammed by Milan Bairagi...";
    
    return 0;
}