#include "Student.h"
#include <iostream>
using namespace std;
using namespace Developer2;
void Student::setStudent(string _name, int _id)
{
	name = _name;
	id = _id;
}



int Student::calculateGrade() {
	return midTermExam + finalExam / 2;
}

void Student::print()
{

	cout << "Name : " << name << endl;
	cout << "ID   : " << id << endl;
	cout << "ID   : " << calculateGrade() << endl;

}
