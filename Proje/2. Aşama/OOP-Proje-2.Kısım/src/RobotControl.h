/**
* @file RobotControl.h
* @Author Doðukan Kýyýklýk 152120211104 (kiyiklik.dogukan@hotmail.com)
* @date 27.12.2023
* @brief This class allows us to control robot.
*/

#pragma once

#include "Pose.h"
#include "SensorInterface.h"
#include "RobotInterface.h"
#include "Path.h"
#include "Record.h"
#include "RobotOperator.h"

class RobotControl {
	int state;
	bool access_statement;
	Pose* position;
	vector<SensorInterface*> sensorList;
	RobotInterface* robot_interface;
	Path* path;
	Record* record;
	RobotOperator* robot_operator;

public:
	//! Constructor
	RobotControl(RobotInterface* api, string);
	//! Destructor
	~RobotControl(); 
	//! Robot turns left
	void turnLeft(); 
	//! Robot turns left
	void turnRight(); 
	//! Robot moves forward
	void forward(); 
	//! Robot moves backward
	void backward(); 
	//! Robot moves left
	void moveLeft(); 
	//! Robot moves right
	void moveRight(); 
	//! Robot stops
	void stop();
	//! Robot prints X, Y and Th values
	void print();
	//! Connects Robot
	void connectRobot();
	//! Disconnects Robot
	void disconnectRobot();


	bool addToPath();
	void clearPath();
	bool openAccess(int);
	bool closeAccess(int);
	void addSensor(SensorInterface*);

	bool recordPathToFile();
	bool recordSensor(string);
	void printSensor(string);
};