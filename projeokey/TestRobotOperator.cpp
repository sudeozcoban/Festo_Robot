/**
 * @file TestRobotOperator.cpp
 * @brief Implementation of the test function for the RobotOperator class.
 *
 * This file defines the function that tests various functionalities
 * of the RobotOperator class.
 */
 /**
  * Sude Özçoban
  * 18.12.2024
  */
#include "TestRobotOperator.h"
#include "RobotOperator.h"
#include <iostream>
#include <cassert>

  /**
   * @brief Tests the functionality of the RobotOperator class.
   *
   * This function performs a series of tests to ensure the RobotOperator
   * class behaves as expected:
   * - Verifies access code correctness.
   * - Tests encryption of the access code.
   * - Tests decryption of the access code.
   * - Prints operator information to the console.
   */
void testRobotOperator() {
    /**
     * @test Access code verification test.
     * Ensures that the checkAccessCode method functions correctly for valid
     * and invalid access codes.
     */
    RobotOperator operator1("Sude", "Ozçoban", 1234); // Create operator instance
    assert(operator1.checkAccessCode(1234) == true);  // Valid code
    assert(operator1.checkAccessCode(4321) == false); // Invalid code
    std::cout << "Access code check passed!" << std::endl;

    /**
     * @test Access code encryption test.
     * Validates that encryptCode successfully encrypts the access code,
     * making it invalid until decrypted.
     */
    operator1.encryptCode(1234); // Encrypt the code
    assert(operator1.checkAccessCode(1234) == false); // Encrypted code should fail
    std::cout << "Encryption test passed!" << std::endl;

    /**
     * @test Access code decryption test.
     * Validates that decryptCode successfully restores the original access code.
     */
    operator1.decryptCode(1234); // Decrypt the code
    assert(operator1.checkAccessCode(1234) == true); // Original code should pass
    std::cout << "Decryption test passed!" << std::endl;

    /**
     * @test Operator information display test.
     * Confirms that operator information is displayed correctly using the print method.
     */
    std::cout << "Operator information:" << std::endl;
    operator1.print();

    // All tests passed successfully
    std::cout << "All tests passed successfully!" << std::endl;
}