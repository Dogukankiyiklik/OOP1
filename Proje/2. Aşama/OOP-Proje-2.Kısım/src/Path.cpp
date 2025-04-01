#include "Path.h"
using namespace std;

//! Constructor initializes tail, head, and number
Path::Path() : tail(nullptr), head(nullptr), number(0) {}

//! Destructor deletes the linked list starting from head
Path::~Path() {
    delete head;
}

//! Add a new pose to the end of the linked list
void Path::addPos(const Pose& pose) {
    Node* newNode = new Node();
    newNode->pose = pose;

    if (!head) {
        //! If the list is empty, set head and tail to the new node
        head = newNode;
        tail = newNode;
    }
    else {
        //! If the list is non-empty, add the new node to the end
        tail->next = newNode;
        tail = newNode;
    }

    number++;
}

//! Print all poses in the linked list
void Path::print() const {
    Node* current = head;
    while (current) {
        cout << "X: " << current->pose.getX() << ", Y: " << current->pose.getY()
            << ", Th: " << current->pose.getTh() << " " << endl;
        current = current->next;
    }
    cout << endl;
}

//! Overloaded subscript operator to access a pose at a specific index
Pose Path::operator[](int index) const {
    Node* current = head;
    int i = 0;
    while (current) {
        if (i == index) {
            return current->pose;
        }
        current = current->next;
        i++;
    }
    return Pose(0, 0, 0);
}

//! Get the pose at a specific index
Pose* Path::getPos(int index) const {
    Node* current = head;
    int i = 0;
    while (current) {
        if (i == index) {
            return &(current->pose);
        }
        current = current->next;
        i++;
    }
    return NULL;
}

//! Remove the pose at a specific index
bool Path::removePos(int index) {
    if (index < 0 || index >= number) {
        return false;
    }

    if (index == 0) {
        //! If removing the first node, update head and delete the node
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        number--;
        return true;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    temp->next = nullptr;
    delete temp;
    number--;

    if (index == number - 1) {
        //! If removing the last node, update tail
        tail = current;
    }

    return true;
}

//! Insert a pose at a specific index
void Path::insertPos(int index, const Pose& pose) {
    if (index < 0 || index > number) {
        return;
    }

    Node* newNode = new Node();
    newNode->pose = pose;

    if (index == number) {
        if (!head) {
            //! If the list is empty, set head and tail to the new node
            head = newNode;
            tail = newNode;
        }
        else {
            //! If the list is non-empty, add the new node to the end
            tail->next = newNode;
            tail = newNode;
        }
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        //! Check if the new node is added at the end
        if (index == number - 1) {
            tail = newNode;
        }
    }

    number++;
}

//! Overloaded output stream operator for easy printing
ostream& operator<<(ostream& out, const Path& path) {
    Path::Node* current = path.head;
    while (current) {
        out << "X: " << current->pose.getX() << ", Y: " << current->pose.getY()
            << ", Th: " << current->pose.getTh() << " " << endl;
        current = current->next;
    }
    out << endl;
    return out;
}

//! Overloaded input stream operator for easy reading
istream& operator>>(istream& in, Path& path) {
    double x, y, th;
    cout << "Enter X coordinate for new pose: ";
    in >> x;
    cout << "Enter Y coordinate for new pose: ";
    in >> y;
    cout << "Enter Th value for new pose: ";
    in >> th;

    Pose pose(x, y, th);
    path.addPos(pose);
    return in;
}

int Path::getNumber() { return number; }