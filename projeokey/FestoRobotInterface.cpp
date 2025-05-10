#pragma once
#include <stdexcept>  // invalid_argument i�in gerekli
#include <string>     // std::string i�in gerekli
#include <vector>     // std::vector i�in gerekli (IRSensor gibi kullan�m varsa)
#include <iostream>   // Gerekli durumlarda ��kt� i�lemleri i�in

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
