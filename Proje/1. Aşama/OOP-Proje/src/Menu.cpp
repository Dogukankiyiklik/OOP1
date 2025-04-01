/**
* @file Menu.cpp
* @Author Doðukan Kýyýklýk 152120211104 (kiyiklik.dogukan@hotmail.com)
* @date 30.12.2023
* @brief This cpp file allows us user interaction for robot methods.
*/

#if 1
#include <iostream>
#include <limits>
#include "SonarSensor.h"
#include "BumperSensor.h"
#include "ForceSensor.h"
#include "RobotControl.h"
#include "RobotOperator.h"
#include "Path.h"
#include "Pose.h"

using namespace std;

class Menu {
public:
    //! Constructor
    Menu() {
        realApi = new NaoRobotAPI();
        sonarSensor = new SonarSensor(realApi);
        forceSensor = new ForceSensor(realApi);
        bumperSensor = new BumperSensor(realApi);
        robot = new RobotControl(realApi);
        path = new Path();
        Robot_operator_1 = new RobotOperator("Safiullah", "Sediqi", 1234);
        Robot_operator_2 = new RobotOperator("aaaa", "bbbbb", 5678);
    }

    //! Displays Connection Menu
    void displayConnectionMenu() const {
        cout << "Connection Menu" << endl;
        cout << "1. Connect Robot\n";
        cout << "2. Disconnect Robot\n";
        cout << "3. Back\n";
        cout << "Choose One: ";
    }

    //! Displays Motion Menu
    void displayMotionMenu() const {
        cout << "Motion Menu" << endl;
        cout << "1. Move Robot\n";
        cout << "2. Safe Move Robot\n";
        cout << "3. Turn Left\n";
        cout << "4. Turn Right\n";
        cout << "5. Move Distance\n";
        cout << "6. Close Wall\n";
        cout << "7. Back\n";
        cout << "Choose One: ";
    }

    //! Displays Sensor Menu
    void displaySensorMenu() const {
        cout << "Sensor Menu" << endl;
        cout << "1. Display Sonar Sensor Data\n";
        cout << "2. Display Force Sensor Data\n";
        cout << "3. Display Bumper Sensor Data\n";
        cout << "4. Back\n";
        cout << "Choose One: ";
    }

    //! Displays Main Menu
    void displayMainMenu() const {
        cout << "Main Menu\n";
        cout << "1. Connection\n";
        cout << "2. Motion\n";
        cout << "3. Sensor\n";
        cout << "4. Quit\n";
        cout << "Choose One: ";
    }

    //! Displays Robot Menu
    void moveRobotMenu() {
        cout << "Move Menu\n";
        cout << "1. Forward\n";
        cout << "2. Backward\n";
        cout << "3. Left\n";
        cout << "4. Right\n";
        cout << "5. Back\n";
        cout << "Choose One: ";
    }

    //! Displays Safe Robot Menu
    void safeMoveRobotMenu() {
        cout << "Move Menu\n";
        cout << "1. Forward\n";
        cout << "2. Backward\n";
        cout << "3. Left\n";
        cout << "4. Right\n";
        cout << "5. Back\n";
        cout << "Choose One: ";
    }

    //! Take a choice variable for menu options
    int getUserChoice(int maxChoice) const {
        int choice;
        cin >> choice;

        // Check for valid input
        const int maxBufferSize = 1000;  // Use a large constant value
        while (cin.fail() || choice < 1 || choice > maxChoice) {
            cin.clear();  // Clear the error flag
            cin.ignore(maxBufferSize, '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and " << maxChoice << ": ";
            cin >> choice;
        }

        return choice;
    }

    //! Run entire program
    void runMenu() {

        displayMainMenu();
        int choice = getUserChoice(4);
        int connectionChoice = 0;
        int sensorChoice = 0;
        int motionChoice = 0;

        while (choice != 4) {
            if (choice == 1) {
                system("cls");
                displayConnectionMenu();
                connectionChoice = getUserChoice(3);

                while (connectionChoice != 3) {
                    if (connectionChoice == 1) { 
                        //!!!!!!!!! Opeartorden access code'u iste
                        robot->connectRobot(); 
                        cout << "Connect..." << endl;
                        Sleep(2000);
                        cout << "Robot is connected" << endl;
                        Sleep(1000);
                        system("cls");
                    }
                    else if (connectionChoice == 2) { 
                        robot->disconnectRobot(); 
                        cout << "Connect..." << endl;
                        Sleep(5000);
                        cout << "Robot is disconnected" << endl;
                        system("cls");
                    }

                    system("cls");
                    displayConnectionMenu();
                    connectionChoice = getUserChoice(3);
                }       
            }

            else if (choice == 2) {
                system("cls");
                displayMotionMenu();
                motionChoice = getUserChoice(7);

                while (motionChoice != 7) {
                    if (motionChoice == 1) { 
                        system("cls");

                        moveRobotMenu();
                        int moveChoice = getUserChoice(5);

                        while (moveChoice != 5) {
                            if (moveChoice == 1) { 
                                robot->forward();
                                Sleep(5000);
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }
                            else if (moveChoice == 2) { 
                                robot->backward();
                                Sleep(5000);
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }
                            else if (moveChoice == 3) { 
                                robot->moveLeft();
                                Sleep(5000);
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }
                            else if (moveChoice == 4) { 
                                robot->moveRight();
                                Sleep(5000);
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }

                            system("cls");
                            moveRobotMenu();
                            moveChoice = getUserChoice(5);
                        }
                    } 

                    else if (motionChoice == 2) {
                        system("cls");

                        safeMoveRobotMenu();
                        int safeMoveChoice = getUserChoice(5);
                        bumperSensor->updateSensor();
                        bool statement = bumperSensor->checkTouch();

                        while (safeMoveChoice != 5) {
                            if (safeMoveChoice == 1) {
                                while (!(statement)) {
                                    robot->forward();
                                    bumperSensor->updateSensor();
                                    statement = bumperSensor->checkTouch();
                                }
                                statement = false;
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }
                            else if (safeMoveChoice == 2) {
                                while (!(statement)) {
                                    robot->backward();
                                    bumperSensor->updateSensor();
                                    statement = bumperSensor->checkTouch();
                                }
                                statement = false;
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }
                            else if (safeMoveChoice == 3) {
                                while (!(statement)) {
                                    robot->moveLeft();
                                    bumperSensor->updateSensor();
                                    statement = bumperSensor->checkTouch();
                                }
                                statement = false;
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }
                            else if (safeMoveChoice == 4) {
                                while (!(statement)) {
                                    robot->moveRight();
                                    bumperSensor->updateSensor();
                                    statement = bumperSensor->checkTouch();
                                }
                                statement = false;
                                robot->stop();

                                pose.setX(realApi->getX());
                                pose.setY(realApi->getY());
                                pose.setTh(realApi->getTh());
                                path->addPos(pose);
                            }

                            system("cls");
                            safeMoveRobotMenu();
                            safeMoveChoice = getUserChoice(5);
                        }
                    }

                    else if (motionChoice == 3) { 
                        robot->turnLeft(); 
                        Sleep(5000);
                        robot->stop();

                        pose.setX(realApi->getX());
                        pose.setY(realApi->getY());
                        pose.setTh(realApi->getTh());
                        path->addPos(pose);
                    }

                    else if (motionChoice == 4) {
                        robot->turnRight();
                        Sleep(5000);
                        robot->stop();

                        pose.setX(realApi->getX());
                        pose.setY(realApi->getY());
                        pose.setTh(realApi->getTh());
                        path->addPos(pose);
                    }

                    else if (motionChoice == 5) {
                        double distance, old_distance, new_distance;
                        int index = 1;
                        cout << "Please Enter the distance: ";
                        cin >> distance;

                        while (distance > 0) {
                            sonarSensor->updateSensor();
                            old_distance = abs(sonarSensor->getMax(index) + sonarSensor->getMin(index)) / 2;
                            robot->forward();
                            sonarSensor->updateSensor();
                            new_distance = abs(sonarSensor->getMax(index) + sonarSensor->getMin(index)) / 2;
                            distance -= abs(old_distance - new_distance);
                        }

                        sonarSensor->updateSensor();
                        pose.setX(realApi->getX());
                        pose.setY(realApi->getY());
                        pose.setTh(realApi->getTh());
                        path->addPos(pose);
                    }

                    else if (motionChoice == 6) {
                        int index = 0;
                        sonarSensor->updateSensor();
                        double wall_distance = abs((sonarSensor->getMin(index) + sonarSensor->getMax(index)) / 2);
                        while (wall_distance > 0.3) {
                            robot->forward();
                            sonarSensor->updateSensor();
                            wall_distance = abs((sonarSensor->getMin(index) + sonarSensor->getMax(index)) / 2);
                        }

                        robot->stop();

                        pose.setX(realApi->getX());
                        pose.setX(realApi->getY());
                        pose.setX(realApi->getTh());
                        path->addPos(pose);
                    }

                    system("cls");
                    displayMotionMenu();
                    motionChoice = getUserChoice(7);
                }
            }

            else if (choice == 3) {
                system("cls");
                displaySensorMenu();
                sensorChoice = getUserChoice(7);

                while (sensorChoice != 4) {
                    int index = 0;
                    if (sensorChoice == 1) {
                        sonarSensor->updateSensor();
                        cout << "Sonar Sensor Data" << endl;
                        cout << "------------------" << endl;
                        cout << "Range is: " << sonarSensor->getRange(index) << endl;
                        cout << "Max Range is: " << sonarSensor->getMax(index) << endl;
                        cout << "Min Range is: " << sonarSensor->getMin(index) << endl;
                    }
                    else if (sensorChoice == 2) {
                        forceSensor->updateSensor();
                        cout << "force Sensor Data" << endl;
                        cout << "------------------" << endl;
                        cout << "Force is: " << forceSensor->getForce() << endl;
                        cout << "Fall statement is: " << forceSensor->checkFall() << endl;
                    }
                    else if (sensorChoice == 3) {
                        bumperSensor->updateSensor();
                        cout << "Bumper Sensor Data" << endl;
                        cout << "------------------" << endl;
                        cout << "Bumper Statement is: " << bumperSensor->getState(index) << endl;
                        cout << "Touch statement is: " << bumperSensor->checkTouch() << endl;
                    } 

                    displaySensorMenu();
                    sensorChoice = getUserChoice(4);
                }
            }
    
            system("cls");
            displayMainMenu();
            choice = getUserChoice(4);
        }
    }

private:
    NaoRobotAPI* realApi;
    SonarSensor* sonarSensor;
    ForceSensor* forceSensor;
    BumperSensor* bumperSensor;
    RobotControl* robot;
    RobotOperator* Robot_operator_1;
    RobotOperator* Robot_operator_2;
    Path* path;
    Pose pose;
};

int main() {
    Menu* menu = new Menu();
    menu->runMenu();

    return 0;
}
#endif