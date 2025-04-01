#include "NaoRobotInterface.h"

void NaoRobotInterface::turnLeft() {
	robotAPI->turnRobot(LEFT);
}

void NaoRobotInterface::turnRight() {
	robotAPI->turnRobot(RIGHT);
}

void NaoRobotInterface::forward() {
	robotAPI->moveRobot(FORWARD);
}

void NaoRobotInterface::backward() {
	robotAPI->moveRobot(BACKWARD);
}

void NaoRobotInterface::moveLeft() {
	robotAPI->moveRobot(LEFT);
}

void NaoRobotInterface::moveRight() {
	robotAPI->moveRobot(RIGHT);
}

void NaoRobotInterface::stop() {
	robotAPI->stopRobot();
}

void NaoRobotInterface::connect() {
	robotAPI->connect();
}

void NaoRobotInterface::disconnect() {
	robotAPI->disconnect();
}

Pose* NaoRobotInterface::getPose() {
	position->setPose(robotAPI->getX(), robotAPI->getY(), robotAPI->getTh());
	return position;
}

void NaoRobotInterface::print() {
	cout << "X value is: " << robotAPI->getX() << endl;
	cout << "Y value is: " << robotAPI->getY() << endl;
	cout << "Th value is: " << robotAPI->getTh() << endl;
}