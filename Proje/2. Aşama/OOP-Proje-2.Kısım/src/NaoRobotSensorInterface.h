#pragma once

#include "SensorInterface.h"
#include "NaoRobotAPI.h"

class NaoRobotSensorInterface :public SensorInterface {
protected:
	NaoRobotAPI* robotAPI;

public:
	void updateSensor() override;
	string getSensorType() override;
	string getSensorValue() override;
};