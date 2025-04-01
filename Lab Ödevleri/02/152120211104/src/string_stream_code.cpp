#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

//! Verilen stringi parçalayarak içindeki tamsayıları bir vektörde depolayan fonksiyon
vector<int> parseInts(string str) {
    //!tam sayıların depolandığı vektör
    vector<int> ints;
    //! String'i işlemek için stringstream nesnesi oluşturulur
    stringstream ss(str);
    int i;
    char ch;
    //! stringstream'den tamsayı okunduğu sürece döngü devam eder
    while (ss >> i)
    {
        //! Okunan tamsayı vektöre eklenir
        ints.push_back(i);
        ss >> ch;
    }
    //! Depolanan tamsayıların bulunduğu vektör geri döndürülür
    return ints;
}

int main() {
    string str;
    //! kullanıcıdan string alınır
    cin >> str;
    //! fonksiyon çağırılır ve sonuç vektörde depolanır
    vector<int> integers = parseInts(str);
    //! vektördeki tam sayılar ekrana yazdırılır
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n"; 
    }

    return 0;
}
