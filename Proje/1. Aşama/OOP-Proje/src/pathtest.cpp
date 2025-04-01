#if 0
#include <iostream>
#include "Path.h"

using namespace std;

int main() {
    //! Test Path class

    //! Create a Path object
    Path path;

    //! Create Pose objects
    Pose pose1(1.0, 2.0, 3.0);
    Pose pose2(4.0, 5.0, 6.0);
    Pose pose3(7.0, 8.0, 9.0);
    Pose pose4(10.0, 11.0, 12.0);

    //! Add poses to the path
    path.addPos(pose1);
    path.addPos(pose2);
    path.addPos(pose3);
    path.addPos(pose4);

    //! Insert a pose at a specific index
    path.insertPos(3, pose4);

    //! Print the path
    path.print();

    //! Access and display a specific pose
    cout << path.getPos(1).getX() << endl;

    //! Remove a pose from the path
    path.removePos(0);

    //! Print the updated path
    path.print();

    //! Access and display a specific pose using operator[]
    cout << path[0].getX() << endl;

    //! Display the path using overloaded stream insertion operator
    cout << path;

    //! Input a new pose to the path using overloaded stream extraction operator
    cin >> path;

    //! Display the updated path
    cout << path;

    return 0;
}
#endif // !0
