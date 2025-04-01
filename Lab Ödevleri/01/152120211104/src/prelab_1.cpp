#include <iostream>
#include <fstream>

using namespace std;

//! Toplama işlemi fonksiyonu
int toplama(int size, int* numbers){
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += numbers[i];
	}
	return sum;
}

//! Çarpma işlemi fonksiyonu
int carpma(int size, int* numbers) {
	int product = 1;
	for (int i = 0; i < size; i++) {
		product *= numbers[i];
	}
	return product;
}

//! Ortalama Bulma işlemi fonksiyonu
int ortalama(int size, int sum) {
	float average = sum / size;
	return average;
}

//! En Küçüğü bulma işlemi fonksiyonu
int en_kucuk(int size, int* numbers) {
	int smallest = numbers[0];

	for (int i = 0; i < size - 1; i++) {
		if (numbers[i + 1] < numbers[i]) {
			smallest = numbers[i + 1];
		}
	}
	return smallest;
}

int main()
{
	//! Dosyadan Okuma ve Bastırma
	ifstream myFile("input.txt");
	int size;
	myFile >> size;
	int* numbers = new int[size];

	for (int i = 0; i < size; i++) {
		myFile >> numbers[i];
	}

	cout << size << endl;
	for (int i = 0; i < size; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
	cout << "--------------" << endl;

	//! Fonksiyonları çağırma
	int sum = toplama(size, numbers);
	int product = carpma(size, numbers);
	float average = ortalama(size, sum);
	int smallest = en_kucuk(size, numbers);

	//! Ekrana Bastırma 
	cout << "Sum is " << sum << endl;
	cout << "Product is " << product << endl;
	cout << "Average is " << average << endl;
	cout << "Smallest is " << smallest << endl;
}