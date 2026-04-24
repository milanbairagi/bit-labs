// 6. WAP to implement Vernam Cipher Algorithm.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

// Function to generate random key of same length as plaintext
string generateRandomKey(int length) {
    string key = "";
    for (int i = 0; i < length; i++) {
        key += (char)('A' + rand() % 26);
    }
    return key;
}

// Function to generate key from user input (repeated to match plaintext length)
// string prepareKey(string plaintext, string key) {
//     key = preprocessText(key);
//     string result = "";
//     int keyIndex = 0;
    
//     // If key is shorter than plaintext, repeat it
//     for (int i = 0; i < plaintext.length(); i++) {
//         if (keyIndex < key.length()) {
//             result += key[keyIndex];
//         } else {
//             result += key[keyIndex % key.length()];
//         }
//         keyIndex++;
//     }
//     return result;
// }

// Encryption function
string encrypt(string plaintext, string key) {
    plaintext = preprocessText(plaintext);
    // key = prepareKey(plaintext, key);
    
    string ciphertext = "";
    
    for (int i = 0; i < plaintext.length(); i++) {
        // Get the shift value from key (A=0, B=1, ..., Z=25)
        int shift = key[i] - 'A';
        
        // Encrypt: C = (P + K) mod 26
        int encryptedChar = ((plaintext[i] - 'A' + shift) % 26);
        ciphertext += (char)('A' + encryptedChar);
    }
    
    return ciphertext;
}

// Decryption function
string decrypt(string ciphertext, string key) {
    ciphertext = preprocessText(ciphertext);
    // key = prepareKey(ciphertext, key);
    
    string plaintext = "";
    
    for (int i = 0; i < ciphertext.length(); i++) {
        // Get the shift value from key (A=0, B=1, ..., Z=25)
        int shift = key[i] - 'A';
        
        // Decrypt: P = (C - K) mod 26
        int decryptedChar = ((ciphertext[i] - 'A' - shift) % 26 + 26) % 26;
        plaintext += (char)('A' + decryptedChar);
    }
    
    return plaintext;
}


int main() {
    srand(time(0));
    
    string plaintext, key;
    int choice;
    
    cout << "====== VERNAM CIPHER ALGORITHM ======\n" << endl;
    
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    
    plaintext = preprocessText(plaintext);

    key = generateRandomKey(plaintext.length());
    cout << "\nGenerated key: " << key << endl;
    
    string ciphertext = encrypt(plaintext, key);
    // displayCipherProcess(plaintext, key, true);
    cout << "\nPlaintext: " << plaintext << endl;
    cout << "Encrypted text: " << ciphertext << endl;
    
    string decryptedtext = decrypt(ciphertext, key);
    cout << "\nCiphertext: " << ciphertext << endl;
    cout << "Decrypted text: " << decryptedtext << endl;
    // displayCipherProcess(ciphertext, key, false);

    cout << "\nProgrammed by Milan Bairagi..." << endl;
    
    return 0;
}