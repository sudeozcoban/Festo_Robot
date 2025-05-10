#pragma once
#include <stdexcept>  // invalid_argument için gerekli
#include <string>     // std::string için gerekli
#include <vector>     // std::vector için gerekli (IRSensor gibi kullaným varsa)
#include <iostream>   // Gerekli durumlarda çýktý iþlemleri için

#include "FestoRobotInterface.h"

// Constructor
FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* api) : robotAPI(api) {
    if (!robotAPI) {
        throw std::invalid_argument("FestoRobotAPI instance cannot be null.");
    }
}

// Destructor
FestoRobotInterface::~FestoRobotInterface() {}

// Returns the type of the sensor as a string
std::string FestoRobotInterface::getSensorType() const {
    return "FestoSensor";
}

// Gets the value of a specific sensor (by index)
double FestoRobotInterface::getSensorValue(int index) const {
    if (index < 0 || index >= 9) { // Assuming 9 IR sensors
        throw std::out_of_range("Sensor index out of range.");
    }
    return robotAPI->getIRRange(index);
}

// Updates all sensor values (for dynamic use)
void FestoRobotInterface::updateSensor() {
    for (int i = 0; i < 9; ++i) { // Again assuming 9 sensors
        double range = robotAPI->getIRRange(i);
        if (range < 0) {
            std::cerr << "Sensor " << i << " returned invalid range." << std::endl;
        }
    }
}
