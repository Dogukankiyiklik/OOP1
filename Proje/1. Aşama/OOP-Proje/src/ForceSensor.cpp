#include "ForceSensor.h"

// Constructor
ForceSensor::ForceSensor(NaoRobotAPI* api) : robotAPI(api) , force(0.0) {}

// Updates the sensor with the current force value
void ForceSensor::updateSensor() {
    this->force = robotAPI->getFootForce();
}

// Gets the force value from the sensor
double ForceSensor::getForce() {
    return force;
}

// Checks if the robot has fallen based on the force sensor data
bool ForceSensor::checkFall() {
    // Assuming a threshold value for detecting a fall, adjust as needed

    //SAYI DEÐÝÞTÝRÝLECEK!
    const double fallThreshold = 1.5;

    // Get the total force at the bottom of the foot from the robot API
    double totalFootForce = robotAPI->getFootForce();

    // Compare the current force with the threshold
    return totalFootForce < fallThreshold;
}
