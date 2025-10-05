// Write a program that reads data from a text file (e.g., "input.txt") and writes it to 
// another file (e.g., "output.txt").

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inpFile("input.txt");
    ofstream outFile("output.txt");

    // Check if the input file was opened successfully
    if (!inpFile) {
        cerr << "Error: Could not open input file 'input.txt'." << endl;
        return 1; // Return with an error code
    }

    // Check if the output file was opened successfully
    if (!outFile) {
        cerr << "Error: Could not open output file 'output.txt'." << endl;
        return 1; // Return with an error code
    }

    string text;

    while (getline(inpFile, text)) {
        outFile << text << endl;
    }

    inpFile.close();
    outFile.close();

    cout << "Data has been successfully copied from input.txt to outfile.txt." << endl;
    cout << endl << "Programmed by Milan Bairagi...";

    return 0;
}