#if 0
// SonarSensorTest.cpp
#include <iostream>
#include "SonarSensor.h"
using namespace std;
int main() {
    // Create a robot object
    NaoRobotAPI* nao = new NaoRobotAPI();

    // Make connection to Nao
    nao->connect();

    // Create a SonarSensor object
    SonarSensor* sonarSensor = new SonarSensor(nao);

    // Update and print initial sensor values
    sonarSensor->updateSensor();
    cout << "Initial Sonar Values: " << endl;
    cout << "Sonar Left: " << sonarSensor->getRange(0) << " meters" << endl;
    cout << "Sonar Right: " << sonarSensor->getRange(1) << " meters" << endl;

    // Move forward for a few steps and update sensor values
    nao->moveRobot(FORWARD);
    Sleep(5000); // Adjust sleep time as needed
    nao->stopRobot();
    sonarSensor->updateSensor();

    // Print updated sensor values
    cout << "\nSonar Values After Moving Forward: " << endl;
    cout << "Sonar Left: " << sonarSensor->getRange(0) << " meters" << endl;
    cout << "Sonar Right: " << sonarSensor->getRange(1) << " meters" << endl;

    // Move backward for a few steps and update sensor values
    nao->moveRobot(BACKWARD);
    Sleep(5000); // Adjust sleep time as needed
    nao->stopRobot();
    sonarSensor->updateSensor();

    // Print updated sensor values
    cout << "\nSonar Values After Moving Backward: " << endl;
    cout << "Sonar Left: " << sonarSensor->getRange(0) << " meters" << endl;
    cout << "Sonar Right: " << sonarSensor->getRange(1) << " meters" << endl;

    // Close connection to the robot
    nao->disconnect();

    // Delete objects
    delete sonarSensor;
    delete nao;

    return 0;
}
#endif