#pragma once

#include "NaoRobotAPI.h"
#include "RobotInterface.h"
#include <iostream>
using namespace std;

class NaoRobotInterface : public RobotInterface {
	NaoRobotAPI* robotAPI = new NaoRobotAPI();

public:
	void turnLeft() override;
	void turnRight() override;
	void forward() override;
	void backward() override;
	void moveLeft() override;
	void moveRight() override;
	void stop() override;
	void connect() override;
	void disconnect() override;
	Pose* getPose() override;
	void print() override;
};