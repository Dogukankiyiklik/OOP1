// SonarSensor.h
#ifndef SONAR_SENSOR_H
#define SONAR_SENSOR_H
#include "NaoRobotSensorInterface.h"

class SonarSensor :public NaoRobotSensorInterface {
private:
    double ranges[2];

public:
    SonarSensor();

    double getRange(int index) const;
    double getMax(int& index) const;
    double getMin(int& index) const;
    double operator[](int index) const;

    void updateSensor() override;
    string getSensorType() override;
    string getSensorValue() override;
};

#endif // SONAR_SENSOR_H