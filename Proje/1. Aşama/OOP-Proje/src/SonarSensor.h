// SonarSensor.h
#ifndef SONAR_SENSOR_H
#define SONAR_SENSOR_H
#include "NaoRobotAPI.h" // Include the actual header for NaoRobotAPI

class SonarSensor {
private:
    double ranges[2];
    NaoRobotAPI* robotAPI;

public:
    SonarSensor(NaoRobotAPI* api);

    double getRange(int index) const;
    double getMax(int& index) const;
    double getMin(int& index) const;
    void updateSensor(); 

    double operator[](int index) const;
};

#endif // SONAR_SENSOR_H