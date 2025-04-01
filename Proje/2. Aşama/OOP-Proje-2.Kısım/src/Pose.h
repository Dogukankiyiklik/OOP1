/**
*@file Pose.h
*@Author Yusuf Eren Hoþgör (152120211123)
*@date 25.12.2023
*@brief holding the position information about the robot.
*/
#ifndef POSE_H
#define POSE_H

class Pose {
private:
    //! Coordinates and orientation of the pose
    double x;
    double y;
    double th;

public:
    //! Default constructor initializes pose to (0, 0, 0)
    Pose();

    //! Parameterized constructor initializes pose with provided values or default to (0, 0, 0)
    Pose(double _x, double _y, double _th);

    //! Getter for X coordinate
    double getX() const;

    //! Setter for X coordinate
    void setX(double _x);

    //! Getter for Y coordinate
    double getY() const;

    //! Setter for Y coordinate
    void setY(double _y);

    //! Getter for Theta (orientation)
    double getTh() const;

    //! Setter for Theta (orientation)
    void setTh(double _th);

    //! Equality operator checks if two poses are equal
    bool operator==(const Pose& other) const;

    //! Addition operator adds corresponding components of two poses
    Pose operator+(const Pose& other) const;

    //! Subtraction operator subtracts corresponding components of two poses
    Pose operator-(const Pose& other) const;

    //! Compound addition operator adds corresponding components of two poses and modifies the current pose
    Pose& operator+=(const Pose& other);

    //! Compound subtraction operator subtracts corresponding components of two poses and modifies the current pose
    Pose& operator-=(const Pose& other);

    //! Less than operator checks if the current pose is less than the other pose
    bool operator<(const Pose& other) const;

    //! Getter for all components of the pose
    void getPose(double& _x, double& _y, double& _th) const;

    //! Setter for all components of the pose
    void setPose(double _x, double _y, double _th);

    //! Calculate the Euclidean distance between two poses
    double findDistanceTo(const Pose& pos) const;

    //! Calculate the angle between the line connecting two poses and the x-axis
    double findAngleTo(const Pose& pos) const;
};

#endif // POSE_H
