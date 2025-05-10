#ifndef LIDAR_SENSOR_H
#define LIDAR_SENSOR_H

#include "FestoRobotAPI.h"

class LidarSensor {
public:
    LidarSensor(FestoRobotAPI& robotAPI); // Yeni yapýlandýrýcý
    void update(); // Sensör verilerini güncelle
    int getRangeCount() const; // Lidar ölçüm sayýsýný al
    float getRange(int index) const; // Belirli bir mesafe ölçümünü al
    int getAngle(int index) const; // Belirli bir açý ölçümünü al

private:
    FestoRobotAPI& robotAPI; // Robot API referansý
    int rangeCount;
    float* ranges;
    int* angles;
};

#endif