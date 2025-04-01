#pragma once

#include <string>

using namespace std;

class SensorInterface {
	string sensorType;

public:
	virtual void updateSensor() = 0;
	virtual string getSensorType() = 0;
	virtual string getSensorValue() = 0;
};