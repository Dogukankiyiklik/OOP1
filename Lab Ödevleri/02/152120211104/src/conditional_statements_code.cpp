#include <iostream>
using namespace std;

int main() {
    //! kullanıcıdan alınacak sayı tanımlanır 
    int n;
    //! kullanıcıdan sayı alınır.
    cin >> n;
    //! kullanıcıdan alınan sayının 1-9 arasında olduğu kontrol edilir.
    if (n == 1) {
        cout << "one";
    }
    else if (n == 2) {
        cout << "two";
    }
    else if (n == 3) {
        cout << "three";
    }
    else if (n == 4) {
        cout << "four";
    }
    else if (n == 5) {
        cout << "five";
    }
    else if (n == 6) {
        cout << "six";
    }
    else if (n == 7) {
        cout << "seven";
    }
    else if (n == 8) {
        cout << "eight";
    }
    else if (n == 9) {
        cout << "nine";
    }
    //! 9'dan büyükse verilecek output
    else {
        cout << "Greater than 9";
    }

    return 0;
}
