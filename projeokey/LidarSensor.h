#ifndef LIDAR_SENSOR_H
#define LIDAR_SENSOR_H

#include "FestoRobotAPI.h"

class LidarSensor {
public:
    LidarSensor(FestoRobotAPI& robotAPI); // Yeni yap�land�r�c�
    void update(); // Sens�r verilerini g�ncelle
    int getRangeCount() const; // Lidar �l��m say�s�n� al
    float getRange(int index) const; // Belirli bir mesafe �l��m�n� al
    int getAngle(int index) const; // Belirli bir a�� �l��m�n� al

private:
    FestoRobotAPI& robotAPI; // Robot API referans�
    int rangeCount;
    float* ranges;
    int* angles;
};

#endif