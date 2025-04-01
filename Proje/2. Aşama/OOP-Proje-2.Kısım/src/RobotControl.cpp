#include "RobotControl.h"
#include <iostream>
using namespace std;

RobotControl::RobotControl(RobotInterface* api, string file_name) {
	robot_interface = api;
	position = new Pose();
	path = new Path();
	robot_operator = new RobotOperator("Dogukan", "Kiyiklik", 1234);
	record = new Record(file_name);
	state = 0;
	access_statement = false;
}

RobotControl::~RobotControl() { 
	delete position; 
	delete path;
	delete robot_operator;
	delete robot_interface;
	delete record;
}

void RobotControl::turnLeft() { 
	if(access_statement){ robot_interface->turnLeft(); }
}

void RobotControl::turnRight() { 
	if (access_statement){ robot_interface->turnRight(); }
}

void RobotControl::forward() { 
	if (access_statement){ robot_interface->forward(); }
}

void RobotControl::backward() {
	if (access_statement){ robot_interface->backward(); }
}

void RobotControl::moveLeft() { 
	if (access_statement){ robot_interface->moveLeft(); }
}

void RobotControl::moveRight() { 
	if (access_statement){ robot_interface->moveRight(); }
}

void RobotControl::stop() { 
	if (access_statement){ robot_interface->stop(); }
}

void RobotControl::connectRobot() {
	if (access_statement){ robot_interface->connect(); }
}

void RobotControl::disconnectRobot() {
	if (access_statement){ robot_interface->disconnect(); }
}

void RobotControl::print() {
	robot_interface->print();
}

bool RobotControl::addToPath() {
	position = robot_interface->getPose();
	path->addPos(*position);
	return true;
}

void RobotControl::clearPath() {
	for (int i = 0; i < path->getNumber(); i++) {
		path->removePos(i);
	}
}

bool RobotControl::openAccess(int password) {
	if (robot_operator->checkAccessCode(password)) {
		access_statement = true;
		return true;
	}
	else { return false; }
}

bool RobotControl::closeAccess(int password) {
	if (robot_operator->checkAccessCode(password)) {
		access_statement = false;
		return true;
	}
	else { return false; }
}

void RobotControl::addSensor(SensorInterface* sensor) {
	sensorList.push_back(sensor);
}

bool RobotControl::recordPathToFile() {
	for (int i = 0; i < path->getNumber(); i++) {
		position = path->getPos(i);
		string position_values;
		position_values = "X: " + to_string(position->getX());
		position_values += " Y: " + to_string(position->getY());
		position_values += " Z: " + to_string(position->getTh());

		record->writeLine(position_values);
	}
	return true;
}

bool RobotControl::recordSensor(string type) {
	for (auto& it : sensorList) {
		if (it->getSensorType() == type) {
			record->writeLine(it->getSensorValue());
		}
	}
	return true;
}

void RobotControl::printSensor(string type) {
	for (auto& it : sensorList) {
		if (it->getSensorType() == type) {
			cout << it->getSensorValue();
		}
	}
}