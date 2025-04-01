/**
*@file Node.h
*@Author Yusuf Eren Hoþgör (152120211123)
*@date 25.12.2023
*@brief defining a node structure for linkedlist.
*/
#pragma once

#include "Pose.h"
#include <iostream>

// Structure representing a node in the linked list
struct Node {
    Node* next;   //! Pointer to the next node in the linked list
    Pose pose;    //! Pose data stored in the node

    // Constructor initializes the node with default values
    Node() {
        next = nullptr;
        pose.setPose(0, 0, 0);
    }

    // Destructor recursively deletes the entire linked list starting from this node
    ~Node() {
        delete next;
    }
};
