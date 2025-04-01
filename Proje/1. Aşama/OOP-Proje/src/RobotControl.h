/**
* @file RobotControl.h
* @Author Doðukan Kýyýklýk 152120211104 (kiyiklik.dogukan@hotmail.com)
* @date 27.12.2023
* @brief This class allows us to control robot.
*/

#pragma once

#include "Pose.h"
#include "NaoRobotAPI.h"

class RobotControl {
	Pose* position;
	NaoRobotAPI* robotAPI;
	int state;

public:
	//! Constructor
	RobotControl(NaoRobotAPI* api); 
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
	//! Robot returns a position information
	Pose* getPose();
	//! Robot prints X, Y and Th values
	void print();
	//! Connects Robot
	void connectRobot();
	//! Disconnects Robot
	void disconnectRobot();
	//! Returns X coordinate value
	double get_X();
};