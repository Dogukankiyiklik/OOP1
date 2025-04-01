#if 0
#include <iostream>
#include "BumperSensor.h"

int main() {
    // Create a NaoRobotAPI object
    NaoRobotAPI* robotAPI = new NaoRobotAPI();

    // Create a BumperSensor object
    BumperSensor* bumperSensor = new BumperSensor(robotAPI);

    // Connect to the robot
    robotAPI->connect();

    // Move the robot forward for a few steps
    robotAPI->moveRobot(FORWARD);
    Sleep(100); // Sleep for 5 seconds
    robotAPI->stopRobot();

    // Read bumper sensor values and update BumperSensor
    bool bumperStates[4] = { false, false, false, false };
    bumperSensor->updateSensor();

    // Print the sensor states
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            std::cout << "Left Foot Left Bumper Sensor: " << (bumperSensor->getState(i) ? "Touched" : "Not Touched") << std::endl;

        }
        else if (i == 1) {
            std::cout << "Left Foot Right Bumper Sensor: " << (bumperSensor->getState(i) ? "Touched" : "Not Touched") << std::endl;

        }
        else if (i == 2) {
            std::cout << "Right Foot Left Bumper Sensor: " << (bumperSensor->getState(i) ? "Touched" : "Not Touched") << std::endl;

        }
        else {
            std::cout << "Right Foot Right Bumper Sensor: " << (bumperSensor->getState(i) ? "Touched" : "Not Touched") << std::endl;

        }
        
        
        
    }

    // Check if any sensor is touched
    if (bumperSensor->checkTouch()) {
        std::cout << "At least one bumper is touched." << std::endl;
    }
    else {
        std::cout << "No bumper is touched." << std::endl;
    }

    // Disconnect from the robot
    robotAPI->disconnect();

    // Delete objects
    delete robotAPI;
    delete bumperSensor;

    return 0;
}
#endif