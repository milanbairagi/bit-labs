// 5. WAP to implement Vigenere Cipher Algorithm.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to convert plaintext to uppercase and remove spaces
string preprocessText(string text) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }
    return result;
}

// Function to prepare key (repeat it to match plaintext length)
string prepareKey(string plaintext, string key) {
    key = preprocessText(key);
    string result = "";
    int keyIndex = 0;
    
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            result += key[keyIndex % key.length()];
            keyIndex++;
        }
    }
    return result;
}

// Encryption function
string encrypt(string plaintext, string key) {
    plaintext = preprocessText(plaintext);
    key = prepareKey(plaintext, key);
    
    string ciphertext = "";
    
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            // Get the shift value from key (A=0, B=1, ..., Z=25)
            int shift = key[i] - 'A';
            
            // Encrypt: C = (P + K) mod 26
            int encryptedChar = ((plaintext[i] - 'A' + shift) % 26);
            ciphertext += (char)('A' + encryptedChar);
        }
    }
    
    return ciphertext;
}

// Decryption function
string decrypt(string ciphertext, string key) {
    ciphertext = preprocessText(ciphertext);
    key = prepareKey(ciphertext, key);
    
    string plaintext = "";
    
    for (int i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            // Get the shift value from key (A=0, B=1, ..., Z=25)
            int shift = key[i] - 'A';
            
            // Decrypt: P = (C - K) mod 26
            int decryptedChar = ((ciphertext[i] - 'A' - shift) % 26 + 26) % 26;
            plaintext += (char)('A' + decryptedChar);
        }
    }
    
    return plaintext;
}

// Function to display the cipher process step by step
void displayCipherProcess(string plaintext, string key, bool isEncrypt) {
    plaintext = preprocessText(plaintext);
    key = prepareKey(plaintext, key);
    
    cout << "\nCipher Process:" << endl;
    cout << "Plaintext:  ";
    for (char c : plaintext) cout << c << " ";
    cout << endl;
    
    cout << "Key:        ";
    for (char c : key) cout << c << " ";
    cout << endl;
    
    cout << "Values:     ";
    for (char c : plaintext) cout << (c - 'A') << " ";
    cout << endl;
    
    cout << "Key Values: ";
    for (char c : key) cout << (c - 'A') << " ";
    cout << endl;
    
    if (isEncrypt) {
        cout << "Result:     ";
        for (int i = 0; i < plaintext.length(); i++) {
            int val = ((plaintext[i] - 'A' + (key[i] - 'A')) % 26);
            cout << (char)('A' + val) << " ";
        }
    } else {
        cout << "Result:     ";
        for (int i = 0; i < plaintext.length(); i++) {
            int val = ((plaintext[i] - 'A' - (key[i] - 'A')) % 26 + 26) % 26;
            cout << (char)('A' + val) << " ";
        }
    }
    cout << endl << endl;
}

int main() {
    string plaintext, key;
    int choice;
    
    cout << "====== VIGENERE CIPHER ALGORITHM ======\n" << endl;
    
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    
    cout << "Enter the key: ";
    getline(cin, key);
    
    cout << "\n1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "3. Both" << endl;
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;
    
    if (choice == 1 || choice == 3) {
        string ciphertext = encrypt(plaintext, key);
        cout << "\nEncrypted text: " << ciphertext << endl;
        displayCipherProcess(plaintext, key, true);
    }
    
    if (choice == 2) {
        string decryptedtext = decrypt(plaintext, key);
        cout << "\nDecrypted text: " << decryptedtext << endl;
        displayCipherProcess(plaintext, key, false);
    }
    
    if (choice == 3) {
        string ciphertext = encrypt(plaintext, key);
        string decryptedtext = decrypt(ciphertext, key);
        cout << "\nDecrypted text: " << decryptedtext << endl;
        displayCipherProcess(ciphertext, key, false);
    }
    
    return 0;
}
