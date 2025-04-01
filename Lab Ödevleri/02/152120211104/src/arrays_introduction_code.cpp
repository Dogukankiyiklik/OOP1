#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //! Kullanıcıdan dizinin boyutunu al
    int n;
    cin >> n;
    //! Dizi boyutu kadar bir vektör oluştur
    vector <int> arr(n);
    //! Kullanıcıdan dizinin elemanlarını al
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //! Diziyi tersten yazdır
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}
