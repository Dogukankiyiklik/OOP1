#include "BumperSensor.h"

// Constructor
BumperSensor::BumperSensor(NaoRobotAPI* api) : robotAPI(api) {
    for (int i = 0; i < 4; ++i) {
        states[i] = false;
    }
}

// Update sensor states with the given array
void BumperSensor::updateSensor() {
    bool leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right;
    robotAPI->getFootBumpers(leftFoot_left, leftFoot_right, rightFoot_left, rightFoot_right);
    states[0] = leftFoot_left;
    states[1] = leftFoot_right;
    states[2] = rightFoot_left;
    states[3] = rightFoot_right;
   
}

// Get the state of the sensor at the specified index
bool BumperSensor::getState(int index) {
    if (index >= 0 && index < 4) {
        return states[index];
    }
    else {
        // Handle invalid index, returning false
        return false;
    }
}

bool BumperSensor::checkTouch() {
    for (int i = 0; i < 4; ++i) {
        if (states[i]) {
            return true;
        }
    }
    return false;
}
