#if 0
#include <iostream>
#include "Encryption.h"

using namespace std;

int main() {

    //! Test encryption and decryption with normal values
    int originalCode = 3206;
    int encryptedCode = Encryption::encrypt(originalCode);
    int decryptedCode = Encryption::decrypt(encryptedCode);

    //! print the original code 
    cout << "Original Code: " << originalCode <<  endl;

    //! Print results of Encrypted Code and Decrypted Code
    cout << "Encrypted Code: " << encryptedCode <<  endl;
    cout << "Decrypted Code: " << decryptedCode <<  endl;

    //! Test encryption and decryption with edge cases
    int edgeCase1 = 9999;  // Maximum 4-digit number
    int edgeCase2 = 0;     // Minimum 4-digit number

    //! Encrypting and decrypted edge cases using the Encryption and Decryption classes
    int encryptedEdgeCase1 = Encryption::encrypt(edgeCase1);
    int decryptedEdgeCase1 = Encryption::decrypt(encryptedEdgeCase1);
    int encryptedEdgeCase2 = Encryption::encrypt(edgeCase2);
    int decryptedEdgeCase2 = Encryption::decrypt(encryptedEdgeCase2);

    //! print the edge case 1
    cout << "\nEdge Case 1: " << edgeCase1 << endl;
    cout << "Encrypted Edge Case 1: " << encryptedEdgeCase1 <<  endl;
    cout << "Decrypted Edge Case 1: " << decryptedEdgeCase1 <<  endl;

    //! print the edge case 2
    cout << "\nEdge Case 2: " << edgeCase2 << endl;
    cout << "Encrypted Edge Case 2: " << encryptedEdgeCase2 <<  endl;
    cout << "Decrypted Edge Case 2: " << decryptedEdgeCase2 <<  endl;

    return 0;
}
#endif