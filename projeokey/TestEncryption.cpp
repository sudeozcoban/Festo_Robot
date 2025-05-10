/**
 * @file TestEncryption.cpp
 * @brief Implementation of the test function for the Encryption class.
 *
 * This file defines the test function that validates the encryption and decryption
 * functionalities of the Encryption class.
 */
 /**
  * Sude Özçoban
  * 18.12.2024
  */
#include "TestEncryption.h"
#include "Encryption.h"
#include <iostream>
#include <cassert>

  /**
   * @brief Tests the functionality of the Encryption class.
   *
   * This function performs the following tests:
   * - Validates that the encrypt method produces a different value from the original.
   * - Ensures that the decrypt method correctly restores the original value.
   */
void testEncryption() {
    Encryption encryption; ///< Instance of the Encryption class

    /**
     * @test Encryption test.
     * Verifies that the encrypt method transforms the original value into
     * a different, expected encrypted value.
     */
    int original = 1234; // Original value
    int encrypted = encryption.encrypt(original); // Encrypted value
    std::cout << "Original: " << original << ", Encrypted: " << encrypted << std::endl;

    // Ensure the encrypted value is different from the original
    assert(encrypted != original);

    /**
     * @test Decryption test.
     * Ensures that the decrypt method correctly restores the original value
     * from the encrypted value.
     */
    int decrypted = encryption.decrypt(encrypted); // Decrypted value
    std::cout << "Encrypted: " << encrypted << ", Decrypted: " << decrypted << std::endl;

    // Ensure the decrypted value matches the original
    assert(decrypted == original);

    // All tests passed successfully
    std::cout << "Encryption and Decryption tests passed!" << std::endl;
}