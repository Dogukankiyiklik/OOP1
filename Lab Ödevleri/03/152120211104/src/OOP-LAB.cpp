#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*! Class for multiplication operation */
class Multiplication {
private:
    string firstNumber, secondNumber;
    vector<int> result;

public:
    /*! Constructor */
    Multiplication(string first, string second) {
        firstNumber = first;
        secondNumber = second;
        result.resize(firstNumber.size() + secondNumber.size());
    }
    /*! Multiplication operation */
    void doMultiplication() {
        /*! Convert strings to vectors of integers */
        vector<int> number1, number2;
        for (int i = 0; i < firstNumber.size(); i++)
            number1.push_back(firstNumber[i] - '0');
        for (int i = 0; i < secondNumber.size(); i++)
            number2.push_back(secondNumber[i] - '0');

        /*! Reverse the vectors for calculation */
        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());

        /*! Multiply the numbers */
        int size1 = number1.size();
        int size2 = number2.size();

        for (int i = 0; i < size1; i++) {
            int carry = 0;
            for (int j = 0; j < size2 || carry; j++) {
                int temp = result[i + j] + number1[i] * (j < size2 ? number2[j] : 0) + carry;
                result[i + j] = temp % 10;
                carry = temp / 10;
            }
        }

        /*! Remove leading zeros */
        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }

        /*! Reverse the result vector for display */
        reverse(result.begin(), result.end());
        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());
    }
    /*! Printing the result */
    void print() {
        cout << "The result of " << firstNumber << " * " << secondNumber << " is: ";
        for (auto i : result) {
            cout << i;
        }
        cout << endl;
    }
};

/*! Class for addition operation */
class Addition {
private:
    string firstNumber, secondNumber;
    vector<int> result;

public:
    /*! Constructor */
    Addition(string first, string second) {
        firstNumber = first;
        secondNumber = second;
    }
    /*! Addition operation */
    void doAddition() {
        /*! Convert strings to vectors of integers */
        vector <int> number1, number2;
        for (int i = 0; i < firstNumber.size(); i++)
            number1.push_back(firstNumber[i] - '0');
        for (int i = 0; i < secondNumber.size(); i++)
            number2.push_back(secondNumber[i] - '0');

        /*! Reverse the vectors for calculation */
        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());

        /*! Addition the numbers */
        int maxDigit = max(number1.size(), number2.size());
        int carry = 0;
        int tempResult;

        if (number1.size() > number2.size()) {
            int sayac = maxDigit - number2.size();
            for (int i = 0; i < sayac; i++) {
                number2.push_back(0);
            }
        }

        if (number1.size() < number2.size()) {
            int sayac = maxDigit - number1.size();
            for (int i = 0; i < sayac; i++) {
                number1.push_back(0);
            }
        }

        for (int i = 0; i < maxDigit; i++) {
            tempResult = number1[i] + number2[i] + carry;
            result.push_back(tempResult % 10);
            carry = tempResult / 10;
        }

        while (carry) {
            result.push_back(carry % 10);
            carry = carry / 10;
        }

        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());
        reverse(result.begin(), result.end());

        while (number1[0] == 0 || number2[0] == 0) {

            if (number1[0] == 0) {
                number1.erase(number1.begin());
            }

            else if (number2[0] == 0) {
                number2.erase(number2.begin());
            }
        }
    }
    /*! Printing the result */
    void print() {
        cout << "The result of " << firstNumber << " + " << secondNumber << " is: ";
        for (auto i : result) {
            cout << i;
        }
        cout << endl;
    }
};

/*! Class for substraction operation */
class Substraction {
private:
    string firstNumber, secondNumber;
    vector<int> result;

public:
    /*! Constructor */
    Substraction(string first, string second) {
        firstNumber = first;
        secondNumber = second;
    }
    /*! Substraction operation */
    void doSubstraction() {
        // creating vectors to store numbers digit
        vector<int> number1, number2;
        // storing into vectors
        for (int i = 0; i < firstNumber.size(); i++)
            number1.push_back(firstNumber[i] - '0');
        for (int i = 0; i < secondNumber.size(); i++)
            number2.push_back(secondNumber[i] - '0');

        // Make sure number1 is greater than or equal to number2
        if (number1.size() < number2.size() ||
            (number1.size() == number2.size() && number1 < number2)) {
            swap(number1, number2);
        }

        // reversing numbers for operate math operations
        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());

        // subtraction algorithm
        int borrow = 0;
        for (int i = 0; i < number1.size(); i++) {
            int tempResult = number1[i] - borrow;
            if (i < number2.size())
                tempResult -= number2[i];

            if (tempResult < 0) {
                tempResult += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }

            result.push_back(tempResult);
        }

        // remove leading zeros
        while (!result.empty() && result.back() == 0) {
            result.pop_back();
        }

        // reverse the result to print it correctly
        reverse(result.begin(), result.end());
    }
    /*! Printing the result */
    void print() {
        if (result.empty()) {
            cout << "The result of " << firstNumber << " - " << secondNumber << " is: 0" << endl;
        }
        else {
            if (firstNumber.size() < secondNumber.size() || (firstNumber.size() == secondNumber.size() && firstNumber < secondNumber)) {
                cout << "The result of " << firstNumber << " - " << secondNumber << " is: -";
                for (auto i : result) {
                    cout << i;
                }
                cout << endl;
            }

            else {
                cout << "The result of " << firstNumber << " - " << secondNumber << " is: ";
                for (auto i : result) {
                    cout << i;
                }
                cout << endl;
            }
        }
    }
};

/*! Reading from file */
class fileReader {
private:
    string filePath;

public:
    /*! Constructor */
    fileReader(string path) { filePath = path; }

    void read() {
        ifstream myFile(filePath);

        /*! checks if the file couldn't be opened */
        if (!myFile) cout << "File could not be opened" << endl;

        int pieceOfNumbers, digitNumOfNumbers, x, y;
        char operation;
        string largeNumber;

        myFile >> pieceOfNumbers;

        int* digitNum = new int[pieceOfNumbers];
        vector<string> largeNumbers;

        for (int i = 0; i < pieceOfNumbers; i++) {
            myFile >> digitNumOfNumbers;
            digitNum[i] = digitNumOfNumbers;

            myFile >> largeNumber;
            largeNumbers.push_back(largeNumber);
        }

        while (myFile >> operation) {

            myFile >> x >> y;

            switch (operation) {
            case 'A':
            {
                Addition resultOfAddition(largeNumbers[x - 1], largeNumbers[y - 1]);
                resultOfAddition.doAddition();
                resultOfAddition.print();
                break;
            }

            case 'M':
            {
                Multiplication resultOfMultiplication(largeNumbers[x - 1], largeNumbers[y - 1]);
                resultOfMultiplication.doMultiplication();
                resultOfMultiplication.print();
                break;
            }

            case 'S':
            {
                Substraction resultOfSubstractionn(largeNumbers[x - 1], largeNumbers[y - 1]);
                resultOfSubstractionn.doSubstraction();
                resultOfSubstractionn.print();
                break;
            }

            default:
                break;
            }
        }
    }
};

int main()
{
    fileReader file("input.txt");
    file.read();
}