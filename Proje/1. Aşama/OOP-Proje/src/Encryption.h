
/**
 * @file Encryption.h
 * @Author Safiullah SEDIQI (safiullahsediqi34@gmail.com)
 * @date September, 25/12/2023
 * @brief This class is designed to be used for basic encryption and decryption operations.
          The header file includes include guards to prevent multiple inclusion and ensure the content
          is only processed once during compilation.
 *
 * 
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

//! This class provides encryption and decryption functionality
class Encryption {
public:
    //! Encrypts the given code
    static int encrypt(int code);

    //! Decrypts the given code
    static int decrypt(int code);
};

#endif //! ENCRYPTION_H
