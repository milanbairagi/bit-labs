// 7. WAP to implement Rail Fence Cipher Algorithm.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Function to encrypt text using Rail Fence Cipher
string railFenceEncrypt(string text, int rails) {
    if (rails == 1) return text;
    
    // Create a 2D array to store characters
    vector<vector<char>> fence(rails, vector<char>(text.length(), '\0'));
    
    int rail = 0;
    int direction = 1;  // 1 for down, -1 for up
    
    // Place characters in zigzag pattern
    for (int i = 0; i < text.length(); i++) {
        fence[rail][i] = text[i];
        
        // Change direction at top and bottom rails
        if (rail == 0) {
            direction = 1;
        } else if (rail == rails - 1) {
            direction = -1;
        }
        
        rail += direction;
    }
    
    // Read the fence row by row
    string encrypted = "";
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < text.length(); j++) {
            if (fence[i][j] != '\0') {
                encrypted += fence[i][j];
            }
        }
    }
    
    return encrypted;
}

// Function to decrypt text using Rail Fence Cipher
string railFenceDecrypt(string encrypted, int rails) {
    if (rails == 1) return encrypted;
    
    int n = encrypted.length();
    
    // Create a 2D array to mark positions
    vector<vector<bool>> fence(rails, vector<bool>(n, false));
    
    int rail = 0;
    int direction = 1;
    
    // Mark the zigzag pattern positions
    for (int i = 0; i < n; i++) {
        fence[rail][i] = true;
        
        if (rail == 0) {
            direction = 1;
        } else if (rail == rails - 1) {
            direction = -1;
        }
        
        rail += direction;
    }
    
    // Fill the marked positions with encrypted characters
    vector<vector<char>> fenceChars(rails, vector<char>(n, '\0'));
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < n; j++) {
            if (fence[i][j] && index < encrypted.length()) {
                fenceChars[i][j] = encrypted[index++];
            }
        }
    }
    
    // Read the fence in zigzag order
    string decrypted = "";
    rail = 0;
    direction = 1;
    for (int i = 0; i < n; i++) {
        decrypted += fenceChars[rail][i];
        
        if (rail == 0) {
            direction = 1;
        } else if (rail == rails - 1) {
            direction = -1;
        }
        
        rail += direction;
    }
    
    return decrypted;
}

int main() {
    int choice, rails;
    string text;
    
    cout << "\n===== Rail Fence Cipher Algorithm =====" << endl;

    cout << "Enter plaintext: ";
    getline(cin, text);

    cout << "Enter number of rails: ";
    cin >> rails;
    cin.ignore();  // Ignore newline after cin

    cout << "\n===== ENCRYPTION =====" << endl;
    cout << "Plaintext: " << text << endl;
    cout << "Number of rails: " << rails << endl;
    string encrypted = railFenceEncrypt(text, rails);
    cout << "Encrypted text: " << encrypted << endl;

    cout << "\n===== DECRYPTION =====" << endl;
    cout << "Ciphertext: " << encrypted << endl;
    cout << "Number of rails: " << rails << endl;
    string decrypted = railFenceDecrypt(encrypted, rails);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}