#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    //! kullanıcıdan alınacak veriler ve veri tipleri tanımlanır.
    int a;
    long b;
    char c;
    float d;
    double e;
    //! kullanıcıdan veriler alınır.
    cin >> a >> b >> c >> d >> e;
    //! cstdio kütüphanesi ile eklenen printf fonksiyonuyla veriler yazdırılır.
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", a, b, c, d, e);
    return 0;
}
