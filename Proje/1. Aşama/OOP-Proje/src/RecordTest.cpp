#if 0
#include "Record.h"
#include <iostream>
using namespace std;
int main() {

    //! Test 1: Create a Record object
    Record myRecord("test.txt");

    //! Test 2: Open the file
    if (myRecord.openFile()) {
        cout << "File opened successfully." << endl;

        //! Test 3: Read lines from the file
        string line1, line2;
        myRecord >> line1 >> line2;

        cout << "Line 1: " << line1 << endl;
        cout << "Line 2: " << line2 << endl;

        //! Test 4: Close the file
        if (myRecord.closeFile()) {
            cout << "File closed successfully." << endl;
        }
        else {
            cerr << "Error: Unable to close the file." << endl;
            return 1;
        }
    }
    else {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    return 0;
}
#endif