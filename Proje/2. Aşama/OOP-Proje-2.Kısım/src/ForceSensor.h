#ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include "NaoRobotSensorInterface.h"

class ForceSensor :public NaoRobotSensorInterface {
private:
    double force;

public:
    // Kurucu fonksiyon
    ForceSensor();

    // Sensörden kuvvet deðerini alýr
    double getForce();

    // Robotun düþüp düþmediðini kontrol eder
    bool checkFall();


    // Sensörü günceller
    void updateSensor() override;
    string getSensorType() override;
    string getSensorValue() override;
};

#endif // !FORCESENSOR_H
