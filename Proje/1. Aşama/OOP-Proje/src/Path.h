/**
*@file Path.h
*@Author Yusuf Eren Hoþgör (152120211123)
*@date 25.12.2023
*@brief holding the positions of the robot with using linkedlist structure.
*/
#ifndef PATH_H
#define PATH_H

#include "Pose.h"
#include <iostream>

class Path {
private:
    //! Node structure for a linked list
    struct Node {
        Node* next;
        Pose pose;

        //! Constructor initializes the next pointer to nullptr and pose to default
        Node() : next(nullptr), pose() {}

        //! Destructor recursively deletes the next nodes
        ~Node() {
            delete next;
        }
    };

    //! Pointer to the tail of the linked list
    Node* tail;

    //! Pointer to the head of the linked list
    Node* head;

    //! Number of nodes in the linked list
    int number;

public:
    //! Constructor initializes the head, tail, and number
    Path();

    //! Destructor deletes all nodes in the linked list
    ~Path();

    //! Add a new pose to the end of the linked list
    void addPos(const Pose& pose);

    //! Print all poses in the linked list
    void print() const;

    //! Overloaded subscript operator to access a pose at a specific index
    Pose operator[](int index) const;

    //! Get the pose at a specific index
    Pose getPos(int index) const;

    //! Remove the pose at a specific index
    bool removePos(int index);

    //! Insert a pose at a specific index
    void insertPos(int index, const Pose& pose);

    //! Friend function to overload the output stream operator for easy printing
    friend std::ostream& operator<<(std::ostream& out, const Path& path);

    //! Friend function to overload the input stream operator for easy reading
    friend std::istream& operator>>(std::istream& in, Path& path);
};

#endif //! PATH_H
