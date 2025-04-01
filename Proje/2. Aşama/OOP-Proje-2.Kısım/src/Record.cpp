#include "Record.h"
#include <iostream>

using namespace std;

//! Constructor for the Record class, initializes the fileName
Record::Record(const string& name) : fileName(name) {}

//! Destructor for the Record class, ensures the file is closed upon destruction
Record::~Record() {
    closeFile();
}

//! Opens the file in input, output, and append mode, returns true if successful
bool Record::openFile() {
    file.open(fileName, ios::in | ios::out | ios::app);
    return file.is_open();
}

//! Closes the file and returns true if the file was successfully closed
bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

//! Reads a line from the file and returns it as a string
string Record::readLine() {
    string line;
    getline(file, line);
    return line;
}

//! Writes a line to the file and returns true if successful
bool Record::writeLine(const string& str) {
    this->openFile();
    if (file.is_open()) {
        file << str << std::endl;
        this->closeFile();
        return true;
    }
    return false;
}

//! Overloaded operator to write a line to the file using the << operator
Record& Record::operator<<(const string& str) {
    this->openFile();
    writeLine(str);
    return *this;
}

//! Overloaded operator to read a line from the file using the >> operator
Record& Record::operator>>(string& str) {
    str = readLine();
    return *this;
}