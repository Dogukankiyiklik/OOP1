#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;

    //! sizes of strings
    int length_A = a.size();
    int length_B = b.size();

    //! printing a + b 
    string c = a + b;

    //! swapping first letters
    char temp_A = a[0];
    char temp_B = b[0];

    a[0] = temp_B;
    b[0] = temp_A;


    cout << length_A << " " << length_B << endl;
    cout << c << endl;
    cout << a << " " << b;

    return 0;
}