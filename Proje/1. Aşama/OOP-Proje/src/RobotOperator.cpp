#include "RobotOperator.h"
#include "Encryption.h"
#include <iostream>
using namespace std;
//! Constructor for RobotOperator class, initializes name, surname, and encrypts the accessCode
RobotOperator::RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode)
    : name(name), surname(surname), accessCode(Encryption::encrypt(accessCode)), accessState(false) {}

//! Encrypts a given code using the Encryption class
int RobotOperator::encryptCode(int code) {
    return Encryption::encrypt(code);
}

//! Decrypts a given code using the Encryption class
int RobotOperator::decryptCode(int code) {
    return Encryption::decrypt(code);
}

//! Checks if a given code matches the encrypted accessCode
bool RobotOperator::checkAccessCode(int code) {
    return (accessCode == encryptCode(code));
}

//! Prints the details of the RobotOperator
void RobotOperator::print() {
    cout << "Name: " << name << "\nSurname: " << surname << "\nAccess State: " << (accessState ? "Authorized" : "Unauthorized") << std::endl;
}
