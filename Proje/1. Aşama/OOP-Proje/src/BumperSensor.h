/**
*@file BumperSensor.h
*@Author Salih Enes Unal (152120211061)
*@date 24.12.2023
*@brief This class checks whether there is touch with any of the sensors in front of the robot's feet.
*/

#ifndef BUMPERSSENSOR_H
#define BUMPERSSENSOR_H

#include "NaoRobotAPI.h"

class BumperSensor {
private:
    double states[4]; 
    NaoRobotAPI* robotAPI; 

public:
    //! Constructor
    BumperSensor(NaoRobotAPI* api);
    //! Update sensor states with the given array
    void updateSensor();
    //!Get the state of the sensor at the specified index
    bool getState(int index);
    //! Returns true if any sensor has touch in front of feet
    bool checkTouch();
};

#endif // !BUMPERSSENSOR_H

