#include "LidarSensor.h"
#include <iostream>

LidarSensor::LidarSensor(FestoRobotAPI& robotAPI)
    : robotAPI(robotAPI), rangeCount(0), ranges(nullptr), angles(nullptr) {
}

void LidarSensor::update() {
    rangeCount = robotAPI.getLidarRangeNumber();
    delete[] ranges;
    delete[] angles;

    ranges = new float[rangeCount];
    angles = new int[rangeCount];

    robotAPI.getLidarRange(ranges);
    for (int i = 0; i < rangeCount; ++i) {
        angles[i] = i * (360 / rangeCount); // Örnek açý hesaplama
    }
}

int LidarSensor::getRangeCount() const {
    return rangeCount;
}

float LidarSensor::getRange(int index) const {
    if (index >= 0 && index < rangeCount) {
        return ranges[index];
    }
    std::cerr << "Invalid Lidar range index: " << index << std::endl;
    return -1.0f; // Hatalý indeks
}

int LidarSensor::getAngle(int index) const {
    if (index >= 0 && index < rangeCount) {
        return angles[index];
    }
    std::cerr << "Invalid Lidar angle index: " << index << std::endl;
    return -1; // Hatalý indeks
}