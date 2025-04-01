#ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include "NaoRobotSensorInterface.h"

class ForceSensor :public NaoRobotSensorInterface {
private:
    double force;

public:
    // Kurucu fonksiyon
    ForceSensor();

    // Sens�rden kuvvet de�erini al�r
    double getForce();

    // Robotun d���p d��medi�ini kontrol eder
    bool checkFall();


    // Sens�r� g�nceller
    void updateSensor() override;
    string getSensorType() override;
    string getSensorValue() override;
};

#endif // !FORCESENSOR_H
