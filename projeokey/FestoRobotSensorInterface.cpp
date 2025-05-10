#include "FestoRobotSensorInterface.h"

FestoRobotSensorInterface::FestoRobotSensorInterface(const std::string& type)
    : sensorType(type) {
}

void FestoRobotSensorInterface::updateSensor() {
    // Sens�r verilerini g�ncellemek i�in uygulanacak kod
}

std::string FestoRobotSensorInterface::getSensorType() const {
    return sensorType;
}

double FestoRobotSensorInterface::getSensorValue(int index) const {
    if (index >= 0 && index < static_cast<int>(sensorData.size())) {
        return sensorData[index];
    }
    return 0.0; // Ge�ersiz indeks i�in varsay�lan de�er
}

void FestoRobotSensorInterface::addSensorData(double value) {
    sensorData.push_back(value);
}