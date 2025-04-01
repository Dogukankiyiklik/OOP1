//! Pose.cpp
#include "Pose.h"
#include <cmath>

//! Default constructor initializes pose to (0, 0, 0)
Pose::Pose() : x(0.0), y(0.0), th(0.0) {}

//! Parameterized constructor initializes pose with provided values or default to (0, 0, 0)
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

//! Getter for X coordinate
double Pose::getX() const {
    return x;
}

//! Setter for X coordinate
void Pose::setX(double _x) {
    x = _x;
}

//! Getter for Y coordinate
double Pose::getY() const {
    return y;
}

//! Setter for Y coordinate
void Pose::setY(double _y) {
    y = _y;
}

//! Getter for Theta (orientation)
double Pose::getTh() const {
    return th;
}

//! Setter for Theta (orientation)
void Pose::setTh(double _th) {
    th = _th;
}

//! Equality operator checks if two poses are equal
bool Pose::operator==(const Pose& other) const {
    return (x == other.x) && (y == other.y) && (th == other.th);
}

//! Addition operator adds corresponding components of two poses
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

//! Subtraction operator subtracts corresponding components of two poses
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

//! Compound addition operator adds corresponding components of two poses and modifies the current pose
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

//! Compound subtraction operator subtracts corresponding components of two poses and modifies the current pose
Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

//! Less than operator checks if the current pose is less than the other pose
bool Pose::operator<(const Pose& other) const {
    return (x < other.x) || ((x == other.x) && (y < other.y)) || ((x == other.x) && (y == other.y) && (th < other.th));
}

//! Getter for all components of the pose
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

//! Setter for all components of the pose
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

//! Calculate the Euclidean distance between two poses
double Pose::findDistanceTo(const Pose& pos) const {
    double dx = pos.x - x;
    double dy = pos.y - y;
    return std::sqrt(dx * dx + dy * dy);
}

//! Calculate the angle between the line connecting two poses and the x-axis
double Pose::findAngleTo(const Pose& pos) const {
    return std::atan2(pos.y - y, pos.x - x);
}
