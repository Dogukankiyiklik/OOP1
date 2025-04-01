#pragma once

#include <string>
using namespace std;

namespace Developer2 {

	class Student
	{
	public:
		void setStudent(string _name, int _id);
		void print();
		int calculateGrade();
		Student(int id = 0, int midTermExam = 0, int finalExam = 0) {
			this->id = id;
			this->midTermExam = midTermExam;
			this->finalExam = finalExam;
		}

	private:
		string name;
		int id;
		int midTermExam;
		int finalExam;
	};
}
