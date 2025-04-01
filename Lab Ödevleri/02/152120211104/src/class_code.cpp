#include <iostream>
#include <sstream>
using namespace std;

class Student {
private:
    int age;
    int standart;
    string first_name;
    string last_name;

public:
    //! takes students informations
    void set_age(int Age) {
        age = Age;
    }
    void set_standard(int Standard) {
        standart = Standard;
    }
    void set_first_name(string First_name) {
        first_name = First_name;
    }
    void set_last_name(string Last_name) {
        last_name = Last_name;
    }
    //! and inialize them
    int get_age() {
        return age;
    }
    string get_last_name() {
        return last_name;
    }
    string get_first_name() {
        return first_name;
    }
    int get_standard() {
        return standart;
    }
    string to_string() {
        stringstream birlestir;
        birlestir << age << "," << first_name << "," << last_name << "," << standart;
        return birlestir.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}