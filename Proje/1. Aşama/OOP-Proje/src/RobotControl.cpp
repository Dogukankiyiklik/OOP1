#include "RobotControl.h"
#include <iostream>
using namespace std;

RobotControl::RobotControl(NaoRobotAPI* api) {
	robotAPI = api;
	position = new Pose();
	state = 0;
}

RobotControl::~RobotControl() { delete position; }

void RobotControl::turnLeft() { 
	robotAPI->turnRobot(LEFT);
}

void RobotControl::turnRight() { 
	robotAPI->turnRobot(RIGHT);
}

void RobotControl::forward() { 
	robotAPI->moveRobot(FORWARD);
}

void RobotControl::backward() {
	robotAPI->moveRobot(BACKWARD); 
}

void RobotControl::moveLeft() { 
	robotAPI->moveRobot(LEFT);
}

void RobotControl::moveRight() { 
	robotAPI->moveRobot(RIGHT);
}

void RobotControl::stop() { 
	robotAPI->stopRobot(); 
	position->setPose(robotAPI->getX(), robotAPI->getY(), robotAPI->getTh());
}

Pose* RobotControl::getPose() { return position; }

void RobotControl::connectRobot() {
	robotAPI->connect();
}

void RobotControl::disconnectRobot() {
	robotAPI->disconnect();
}


void RobotControl::print() {
	cout << "X value is: " << position->getX() << "; ";
	cout << "Y value is: " << position->getY() << "; ";
	cout << "Angle is: " << position->getTh() << endl;
}

double RobotControl::get_X() { return robotAPI->getX(); }