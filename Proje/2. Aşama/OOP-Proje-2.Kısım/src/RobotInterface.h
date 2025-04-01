#pragma once

#include "Pose.h"
#include "SensorInterface.h"
#include <vector>
using namespace std;

class RobotInterface {
protected:
	Pose* position = new Pose();
	int status = 0;
	vector<SensorInterface*> sensorList;

public:
	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;
	virtual void forward() = 0;
	virtual void backward() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void stop() = 0;
	virtual void connect() = 0;
	virtual void disconnect() = 0;
	virtual Pose* getPose() = 0;
	virtual void print() = 0;
};