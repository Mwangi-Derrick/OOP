#include <iostream>
#include <fstream> // Standard library for file operations
#include <string>

using namespace std;

int main() {
    // 1. CREATE AND WRITE TO A FILE
    // 'ofstream' (output file stream) creates the file
    ofstream MyFile("example.txt");

    if (MyFile.is_open()) {
        MyFile << "Hello, this is a C++ file handling example!\n";
        MyFile << "Writing data is simple using the << operator.";
        
        // Always close your file when finished to free memory
        MyFile.close(); 
        cout << "File written successfully." << endl;
    } else {
        cerr << "Error: Could not create file." << endl;
    }

    // 2. READ FROM THE FILE
    // 'ifstream' (input file stream) reads the file
    string line;
    ifstream MyReadFile("example.txt");

    if (MyReadFile.is_open()) {
        cout << "\nReading from file:" << endl;
        // Use a loop with getline() to read line-by-line
        while (getline(MyReadFile, line)) {
            cout << line << endl;
        }
        MyReadFile.close();
    } else {
        cerr << "Error: Could not open file for reading." << endl;
    }

    return 0;
}
