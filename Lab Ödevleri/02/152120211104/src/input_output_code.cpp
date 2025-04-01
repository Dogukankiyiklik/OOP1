#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    //! kullanıcıdan alınacak değişkenler ve hesaplanacak toplam tanımlanır.
    int a, b, c, sum;
    //! kullanıcıdan değişkenler alınır.
    cin >> a >> b >> c;
    //! toplam hesaplanır.
    sum = a + b + c;
    //! toplam yazdırılır.
    cout << sum;

    return 0;
}
