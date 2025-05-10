#include "FestoRobotSensorInterface.h"

FestoRobotSensorInterface::FestoRobotSensorInterface(const std::string& type)
    : sensorType(type) {
}

void FestoRobotSensorInterface::updateSensor() {
    // Sensör verilerini güncellemek için uygulanacak kod
}

std::string FestoRobotSensorInterface::getSensorType() const {
    return sensorType;
}

double FestoRobotSensorInterface::getSensorValue(int index) const {
    if (index >= 0 && index < static_cast<int>(sensorData.size())) {
        return sensorData[index];
    }
    return 0.0; // Geçersiz indeks için varsayýlan deðer
}

void FestoRobotSensorInterface::addSensorData(double value) {
    sensorData.push_back(value);
}