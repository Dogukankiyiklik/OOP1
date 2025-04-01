#include "Student.h"
#include "Clock.h"

#include <iostream>
using namespace std;
using namespace Developer1;
using namespace Developer2;

void test();

/*
 * Question1: Fix the code and compile it */
int main() {

	CClock myClock;

	CClock yourClock(3, 50);

	{
		CClock clock(1, 1, 1);

	}

	Student student;

	student.setStudent("Ali", 123456);

	student.print();
	myClock.setTime(7, 15, 25);
	test();
	return 0;
}

void test() {
	 const CClock myClock(3, 60);
	/* Question2: Block the changing hour and minute values of above object.
	 * Do not remove or change main function implementation */
	//myClock.incrementHours();
	//myClock.incrementMinutes();
	//myClock.incrementSeconds();
	myClock.printTime();

	CClock clock1(1, 1, 1);
	CClock clock2(1, 1, 1);
	clock1.incrementHours();
	clock1.incrementSeconds();
	/* Question3: Compare clock1 and clock2 objects and print if they are equal or not. */
	cout << endl;
	if (clock1.equalTime(clock2))
		cout << "clock1 and clock2 equal";
	else
		cout << "clock1 and clock2 NOT equal";

	/* Question4: Add a timeZone variable whcih can not be changed by anyone.
	 * timezone default value is "GMT+3" */
	const CClock timeZone(6, 0, 0);

	 /* Question5: Overload the incrementSeconds method to increment second value as given parameter */

}

/*
 * Question6: Review the code and fix the bugs
 */