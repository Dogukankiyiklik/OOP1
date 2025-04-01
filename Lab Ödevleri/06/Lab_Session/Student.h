#pragma once

#include <string>
using namespace std;

namespace Developer2{

class Student
{
public:
	void setStudent(string _name, int _id);
	void print();
	int calculateGrade();

private:
	string name;
	int id;
	int midTermExam;
	int finalExam;
};
}
