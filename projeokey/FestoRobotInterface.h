#pragma once
#pragma once
#include "SensorInterface.h"
#include "FestoRobotAPI.h"
#include <vector>
#include <string>

class FestoRobotInterface : public SensorInterface {
private:
    FestoRobotAPI* robotAPI;

public:
    // Constructor
    FestoRobotInterface(FestoRobotAPI* api);

    // Destructor
    ~FestoRobotInterface();

    // Override methods from SensorInterface
    std::string getSensorType() const override;
    double getSensorValue(int index) const override;

    // Additional methods specific to FestoRobotInterface
    void updateSensor() override; // Updates all sensor values
};
