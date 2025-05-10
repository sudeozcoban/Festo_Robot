#pragma once
#include <string>
#include "FestoRobotAPI.h"
#include "Mapper.h"
#include "LidarSensor.h"
#include "MAP.h"
#include "Menu.h"

class RobotControl {
public:
    RobotControl();
    ~RobotControl();

    // Sens�r verilerini ekrana yazd�r�r
    void printSensorData();

    // Oda ke�fi i�in robotu hareket ettirir
    void exploreRoom();

    // Robotu belirtilen y�nde hareket ettirir
    void moveRobot(int direction);

    // Ana men�y� ba�lat�r
    void start();

private:
    FestoRobotAPI* robotino; // Robot API nesnesi
    MAP map;                // Haritalama nesnesi
    LidarSensor* lidar;     // Lidar sens�r�
    Mapper* mapper;         // Haritac� nesne
    Menu menu; // Men� nesnesi


};
