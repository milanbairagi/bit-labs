// 3. WAP to implement Playfair cipher Algorithm.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char matrix[5][5];

void createMatrix(string key) {
    bool used[26] = {false};
    int row = 0, col = 0;
    
    // Insert key characters
    for (char c : key) {
        if (!isalpha(c)) continue;
        c = tolower(c);
        if (c == 'j') c = 'i';
        
        if (!used[c - 'a']) {
            matrix[row][col] = c;
            used[c - 'a'] = true;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
    
    // Fill remaining letters
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'j') continue;
        if (!used[c - 'a']) {
            matrix[row][col] = c;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
}

void findPos(char ch, int &row, int &col) {
    if (ch == 'j') ch = 'i';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string encrypt(string text, string key) {
    createMatrix(key);
    string result = "";
    
    // Remove spaces and convert to lowercase
    string processed = "";
    for (char c : text) {
        if (isalpha(c)) {
            processed += tolower(c);
        }
    }
    
    // Handle repeated letters by inserting filler 'x'
    string filled = "";
    for (int i = 0; i < processed.length(); i++) {
        filled += processed[i];
        if (i < processed.length() - 1 && processed[i] == processed[i + 1]) {
            filled += 'x';
        }
    }
    
    // Add padding if odd length
    if (filled.length() % 2 == 1) {
        filled += 'z';
    }
    
    // Encrypt pairs
    for (int i = 0; i < filled.length(); i += 2) {
        char ch1 = filled[i];
        char ch2 = filled[i + 1];
        
        int r1, c1, r2, c2;
        findPos(ch1, r1, c1);
        findPos(ch2, r2, c2);
        
        if (c1 == c2) {  // Same column
            r1 = (r1 + 1) % 5;
            r2 = (r2 + 1) % 5;
        } else if (r1 == r2) {  // Same row
            c1 = (c1 + 1) % 5;
            c2 = (c2 + 1) % 5;
        } else {  // Rectangle
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }
        
        result += matrix[r1][c1];
        result += matrix[r2][c2];
    }
    
    return result;
}

string decrypt(string text, string key) {
    createMatrix(key);
    string result = "";
    
    for (int i = 0; i < text.length(); i += 2) {
        char ch1 = text[i];
        char ch2 = text[i + 1];
        
        int r1, c1, r2, c2;
        findPos(ch1, r1, c1);
        findPos(ch2, r2, c2);
        
        if (c1 == c2) {  // Same column
            r1 = (r1 - 1 + 5) % 5;
            r2 = (r2 - 1 + 5) % 5;
        } else if (r1 == r2) {  // Same row
            c1 = (c1 - 1 + 5) % 5;
            c2 = (c2 - 1 + 5) % 5;
        } else {  // Rectangle
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }
        
        result += matrix[r1][c1];
        result += matrix[r2][c2];
    }
    
    return result;
}

int main() {
    string text, key;
    int choice;
    
    cout << "Enter 1 to encrypt or 2 to decrypt: ";
    cin >> choice;
    cin.ignore();
    
    cout << "Enter text: ";
    getline(cin, text);
    
    cout << "Enter key: ";
    getline(cin, key);
    
    if (choice == 1) {
        cout << "Encrypted: " << encrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Decrypted: " << decrypt(text, key) << endl;
    }

    cout << "\nProgrammed by Milan Bairagi...";
    
    return 0;
}
