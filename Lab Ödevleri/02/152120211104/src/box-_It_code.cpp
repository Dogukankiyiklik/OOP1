#include<bits.h>
#include <iostream>
using namespace std;

// calculates volume
class Box {
private:
    int l;
    int b;
    int h;

public:
    Box() {
        l = 0;
        b = 0;
        h = 0;
    }
    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }
    Box(Box& B) {
        l = B.l;
        b = B.b;
        h = B.h;
    }

    // Functions:   
    int getLength() {
        return l;
    }
    int getBreadth() {
        return b;
    }
    int getHeight() {
        return h;
    }
    long long CalculateVolume() {
        return (long long)l * b * h;
    }

    //Overload operator < as specified
    friend bool operator<(Box& A, Box& B) {
        bool value = false;
        if (A.l < B.l) {
            value = true;
        }
        if ((A.b < B.b) && (A.l == B.l)) {
            value = true;
        }
        if ((A.h < B.h) && (A.b == B.b) && (A.l == B.l)) {
            value = true;
        }
        return value;
    }

    //Overload operator << as specified
    friend ostream& operator<<(ostream& out, Box& B) {
        out << B.l << ' ' << B.b << ' ' << B.h;
        return out;
    }
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}