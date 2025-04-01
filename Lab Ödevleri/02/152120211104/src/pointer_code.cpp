#include <stdio.h>
#include <iostream>

using namespace std;

//! mathematical operations on pointers
void update(int* a, int* b) {
    *a += *b;
    *b = *b - (*a - *b);

    if (*b < 0) {
        *b *= -1;
    }
}

int main() {
    int a, b;
    int* pa = &a, * pb = &b;

    cin >> *pa >> *pb;
    update(pa, pb);
    cout << a << endl;
    cout << b;

    return 0;
}