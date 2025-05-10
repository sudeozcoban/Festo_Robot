#include "RobotInterface.h"
#include "SensorInterface.h"
#include <iostream>

void RobotInterface::addSensor(std::shared_ptr<SensorInterface> sensor) {
    sensorList.push_back(sensor);
}

void RobotInterface::updateSensors() {
    for (const auto& sensor : sensorList) {
        sensor-> updateSensor();
    }
    std::cout << "Tüm sensörler güncellendi.\n";
}