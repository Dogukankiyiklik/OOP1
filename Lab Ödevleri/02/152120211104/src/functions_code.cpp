#include <iostream>
#include <cstdio>
using namespace std;

//! max_of_four fonksiyonu ile 4 sayının arasındaki en büyük sayı bulunup main fonksiyona döndürülür.
int max_of_four(int a, int b, int c, int d) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (d > max) {
        max = d;
    }
    return max;

}
int main() {
    //! kullanıcıdan alınacak 4 sayı tanımlanır ve istenir.
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //! fonksiyon çağırılarak en büyük sayı bir başka değişkene tanımlanır.
    int ans = max_of_four(a, b, c, d);
    //! değişken yazdırılır.
    cout << ans;

    return 0;
}
