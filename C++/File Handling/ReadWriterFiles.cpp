#include <iostream>
#include <fstream> // read and write to files
#include <string> // for getline()
using namespace std;

int main(void) {
    fstream myFile;

    // Opening a File
    myFile.open("test.txt", ios::out); // ios::out -> write mode

    // Writing to a File

    // make sure the file is successfully opened
    if (myFile.is_open()) {
        myFile << "Hello from Kamal Stark.\nCool Right ~\n";
        myFile << "This is another line.\n";

        myFile.close();
    }

    // Appending to a File

    myFile.open("test.txt", ios::app); // ios::app -> append mode
    if (myFile.is_open()) {
        myFile << "Haha car go vroom vroom boom boom brrr...\n";
        myFile.close();
    }

    // Reading from a File

    myFile.open("test.txt", ios::in); // ios::in -> read mode

    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            cout << line << "\n";
        }
        myFile.close();
    }

    return 0;
}