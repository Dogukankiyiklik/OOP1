#if 0
#include "Pose.h"
#include <iostream>
using namespace std;

int main() {
    //! Test Pose class

    //! Create Pose objects
    Pose pose1(1.0, 2.0, 45.0);
    Pose pose2(2.0, 3.0, 90.0);

    //! Display initial poses
    cout << "Initial Pose 2: X=" << pose2.getX() << ", Y=" << pose2.getY() << ", Th=" << pose2.getTh() << " degrees" << endl;

    //! Test operators
    Pose sumPose = pose1 + pose2;
    Pose diffPose = pose1 - pose2;

    cout << "Sum of Poses: X=" << sumPose.getX() << ", Y=" << sumPose.getY() << ", Th=" << sumPose.getTh() << " degrees" << endl;
    cout << "Difference of Poses: X=" << diffPose.getX() << ", Y=" << diffPose.getY() << ", Th=" << diffPose.getTh() << " degrees" << endl;

    //! Test comparison operators
    if (pose1 == pose2) {
        cout << "Pose 1 is equal to Pose 2" << endl;
    }
    else {
        cout << "Pose 1 is not equal to Pose 2" << endl;
    }

    if (pose1 < pose2) {
        cout << "Pose 1 is less than Pose 2" << endl;
    }
    else {
        cout << "Pose 1 is not less than Pose 2" << endl;
    }

    //! Test distance and angle calculations
    double distance = pose1.findDistanceTo(pose2);
    double angle = pose1.findAngleTo(pose2);

    cout << "Distance between Pose 1 and Pose 2: " << distance << " meters" << endl;
    cout << "Angle from Pose 1 to Pose 2: " << angle << " radians" << endl;

    return 0;
}
#endif
