#include "Encryption.h"

int Encryption::encrypt(int code) {

    //! Encryption algorithm implementation
    //! Add 7 to each digit and get the remainder after dividing by 10
    //! Swap the first digit with the third, and swap the second digit with the fourth

    int digit1 = (code / 1000 + 7) % 10;
    int digit2 = ((code % 1000) / 100 + 7) % 10;
    int digit3 = ((code % 100) / 10 + 7) % 10;
    int digit4 = (code % 10 + 7) % 10;

    //! Swap digits
    int encryptedCode = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;

    return encryptedCode;
}

int Encryption::decrypt(int code) {

    //! Decryption algorithm implementation
    //! Reverse the encryption scheme to get the original number

    int digit1 = (code / 1000 + 3) % 10;  // Subtract 7 and handle negative values
    int digit2 = ((code % 1000) / 100 + 3) % 10;
    int digit3 = ((code % 100) / 10 + 3) % 10;
    int digit4 = (code % 10 + 3) % 10;

    //! Swap digits back to the original order
    int decryptedCode = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;

    return decryptedCode;
}
