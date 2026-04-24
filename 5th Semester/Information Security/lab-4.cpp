// 4. WAP to implement Hill Cipher Algorithm.

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int BLOCK_SIZE = 2;

// Function to find modular multiplicative inverse
int modularInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Function to find determinant of 2x2 matrix
int determinant(int matrix[BLOCK_SIZE][BLOCK_SIZE]) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

// Function to find inverse of 2x2 matrix modulo 26
void inverseMatrix(int matrix[BLOCK_SIZE][BLOCK_SIZE], int invMatrix[BLOCK_SIZE][BLOCK_SIZE]) {
    int det = determinant(matrix);
    det = ((det % 26) + 26) % 26;
    
    int detInv = modularInverse(det, 26);
    
    // Inverse = (1/det) * [d, -b; -c, a]
    invMatrix[0][0] = ((detInv * matrix[1][1]) % 26 + 26) % 26;
    invMatrix[0][1] = ((detInv * (-matrix[0][1])) % 26 + 26) % 26;
    invMatrix[1][0] = ((detInv * (-matrix[1][0])) % 26 + 26) % 26;
    invMatrix[1][1] = ((detInv * matrix[0][0]) % 26 + 26) % 26;
}

// Function to multiply matrix with vector
void multiplyMatrixVector(int matrix[BLOCK_SIZE][BLOCK_SIZE], 
                         int vector[BLOCK_SIZE], 
                         int result[BLOCK_SIZE]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < BLOCK_SIZE; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
        // Proper modulo handling for negative numbers
        result[i] = ((result[i] % 26) + 26) % 26;
    }
}

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

// Function to pad plaintext with 'X' if length is odd
string padText(string text) {
    if (text.length() % BLOCK_SIZE != 0) {
        text += 'X';
    }
    return text;
}

// Encryption function
string encrypt(string plaintext, int keyMatrix[BLOCK_SIZE][BLOCK_SIZE]) {
    plaintext = preprocessText(plaintext);
    plaintext = padText(plaintext);
    
    string ciphertext = "";
    
    for (int i = 0; i < plaintext.length(); i += BLOCK_SIZE) {
        int plainBlock[BLOCK_SIZE];
        int cipherBlock[BLOCK_SIZE];
        
        // Convert characters to numbers (A=0, B=1, ..., Z=25)
        plainBlock[0] = plaintext[i] - 'A';
        plainBlock[1] = plaintext[i + 1] - 'A';
        
        // Multiply key matrix with plaintext block
        multiplyMatrixVector(keyMatrix, plainBlock, cipherBlock);
        
        // Convert back to characters
        ciphertext += (char)('A' + cipherBlock[0]);
        ciphertext += (char)('A' + cipherBlock[1]);
    }
    
    return ciphertext;
}

// Decryption function
string decrypt(string ciphertext, int keyMatrix[BLOCK_SIZE][BLOCK_SIZE]) {
    // Find inverse of key matrix
    int invMatrix[BLOCK_SIZE][BLOCK_SIZE];
    inverseMatrix(keyMatrix, invMatrix);
    
    string plaintext = "";
    
    for (int i = 0; i < ciphertext.length(); i += BLOCK_SIZE) {
        int cipherBlock[BLOCK_SIZE];
        int plainBlock[BLOCK_SIZE];
        
        // Convert characters to numbers
        cipherBlock[0] = ciphertext[i] - 'A';
        cipherBlock[1] = ciphertext[i + 1] - 'A';
        
        // Multiply inverse matrix with ciphertext block
        multiplyMatrixVector(invMatrix, cipherBlock, plainBlock);
        
        // Convert back to characters
        plaintext += (char)('A' + plainBlock[0]);
        plaintext += (char)('A' + plainBlock[1]);
    }
    
    return plaintext;
}

int main() {
    int keyMatrix[BLOCK_SIZE][BLOCK_SIZE] = {
        {3, 3},
        {2, 5}
    };

    int choice;

    cout << "Enter 1 for encryption and 2 for decryption: ";
    cin >> choice;
    cin.ignore();
    
    string plaintext;
    
    cout << "====== HILL CIPHER ALGORITHM ======\n" << endl;
    cout << "Key Matrix:" << endl;
    cout << keyMatrix[0][0] << " " << keyMatrix[0][1] << endl;
    cout << keyMatrix[1][0] << " " << keyMatrix[1][1] << endl << endl;
    
    cout << "Enter" << (choice == 1 ? " plaintext" : " ciphertext") << ": ";
    getline(cin, plaintext);
    
    if (choice == 1) {
        // Encryption
        string ciphertext = encrypt(plaintext, keyMatrix);
        cout << "\nEncrypted text: " << ciphertext << endl;
    } else if (choice == 2) {
        // Decryption
        string decryptedtext = decrypt(plaintext, keyMatrix);
        cout << "\nDecrypted text: " << decryptedtext << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    cout << "\nProgrammed by Milan Bairagi..." << endl;
    
    return 0;
}
