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

    // Sensör verilerini ekrana yazdýrýr
    void printSensorData();

    // Oda keþfi için robotu hareket ettirir
    void exploreRoom();

    // Robotu belirtilen yönde hareket ettirir
    void moveRobot(int direction);

    // Ana menüyü baþlatýr
    void start();

private:
    FestoRobotAPI* robotino; // Robot API nesnesi
    MAP map;                // Haritalama nesnesi
    LidarSensor* lidar;     // Lidar sensörü
    Mapper* mapper;         // Haritacý nesne
    Menu menu; // Menü nesnesi


};
