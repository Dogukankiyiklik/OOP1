#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    //! değişkenler tanımlanır ve kullanıcıdan alınır
    int n, q;
    cin >> n >> q;
    //! array depolamak için vector oluşturulur
    vector<vector<int>> arrays(n);
    //! diziler kullanıcıdan alınır
    for (int i = 0; i < n; ++i) {
        int k;
        //! dizilerin uzunluğu alınır
        cin >> k;
        arrays[i].resize(k);
        //! dizilerin elemanları alınır ve kaydedilir
        for (int j = 0; j < k; ++j) {
            cin >> arrays[i][j];
        }
    }


    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        //! dizideki değer ekrana yazdırılır
        cout << arrays[a][b] << endl;
    }

    return 0;
}
