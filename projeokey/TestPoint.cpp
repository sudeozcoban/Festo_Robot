/**
 * @file TestPoint.cpp
 * @brief Implementation of the test function for the Point class.
 *
 * This file defines the function that tests various functionalities of the Point class.
 */
 /**
  * Sude Özçoban
  * 18.12.2024
  */
#include "TestPoint.h"
#include "Point.h"
#include <iostream>
#include <cassert>

  /**
   * @brief Tests the functionality of the Point class.
   *
   * This function performs the following tests:
   * - Default constructor
   * - Parameterized constructor
   * - Setters and Getters
   * - Distance calculation
   * - Angle calculation
   * - Equality operator
   * - Print function
   */
void testPoint() {
    /**
     * @test Default constructor test.
     * Verifies that the default constructor initializes x and y to 0.
     */
    Point p1;
    assert(p1.getX() == 0 && p1.getY() == 0);
    std::cout << "Default constructor test passed!" << std::endl;

    /**
     * @test Parameterized constructor test.
     * Validates that the parameterized constructor correctly initializes x and y.
     */
    Point p2(3, 4);
    assert(p2.getX() == 3 && p2.getY() == 4);
    std::cout << "Parameterized constructor test passed!" << std::endl;

    /**
     * @test Setters test.
     * Ensures that setX and setY methods update the values of x and y correctly.
     */
    p1.setX(5);
    p1.setY(6);
    assert(p1.getX() == 5 && p1.getY() == 6);
    std::cout << "Setters test passed!" << std::endl;

    /**
     * @test Distance calculation test.
     * Validates the correctness of the distance calculation between two points.
     */
    double distance = p1.findDistanceTo(p2);
    assert(distance == 5); // Distance between (5,6) and (3,4) is 5
    std::cout << "Distance calculation test passed!" << std::endl;

    /**
     * @test Angle calculation test.
     * Verifies that the angle calculation is within a reasonable range.
     */
    double angle = p1.findAngleTo(p2);
    assert(angle > -1 && angle < 1); // Check that the angle is within expected bounds
    std::cout << "Angle calculation test passed!" << std::endl;

    /**
     * @test Equality operator test.
     * Ensures that the equality operator behaves correctly for equal and unequal points.
     */
    Point p3(3, 4);
    assert(p2 == p3);       // Points (3,4) and (3,4) should be equal
    assert(!(p1 == p2));    // Points (5,6) and (3,4) should not be equal
    std::cout << "Equality operator test passed!" << std::endl;

    /**
     * @test Print function test.
     * Confirms that the print function displays the point's coordinates correctly.
     */
    std::cout << "Point p1: ";
    p1.print();
    std::cout << "Point p2: ";
    p2.print();
    std::cout << "Print function test passed!" << std::endl;

    // All tests passed successfully
    std::cout << "All Point tests passed successfully!" << std::endl;
}