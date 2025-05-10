#include "FestoRobotAPI.h"
#include "Mapper.h"
#include "LidarSensor.h"
#include "Map.h"
#include "Menu.h"
#include <iostream>
#include <thread> // Sleep için
#include "RobotController.h"

FestoRobotAPI* robotino = nullptr;
MAP map(50, 50, 0.1); // 50x50 grid, 0.1m çözünürlük
LidarSensor* lidar = nullptr;
Mapper* mapper = nullptr;

void turnLeft() {
    robotino->rotate(LEFT);
    std::cout << "Robot is turning left." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    robotino->stop();
}

void turnRight() {
    robotino->rotate(RIGHT);
    std::cout << "Robot is turning right." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    robotino->stop();
}

void moveLeft() {
    robotino->move(LEFT);
    std::cout << "Robot is moving left." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    robotino->stop();
}

void moveRight() {
    robotino->move(RIGHT);
    std::cout << "Robot is moving right." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    robotino->stop();
}

void getPose() {
    double x, y, th;
    robotino->getXYTh(x, y, th);
    std::cout << "Current Pose: (X) " << x << " meters, (Y) " << y << " meters, (Th) " << (th * 180) / 3.14 << " degrees" << std::endl;
}

void printSensorData() {
    double ir[9];
    for (int i = 0; i < 9; i++)
        ir[i] = robotino->getIRRange(i);

    double x, y, th;
    robotino->getXYTh(x, y, th);

    std::cout << "--------------------SENSOR VALUES-------------------------------------" << std::endl;
    std::cout << "POSE         : (X) " << x << " meters, "
              << "(Y) " << y << " meters, "
              << "(Th) " << (th * 180) / 3.14 << " degrees" << std::endl << std::endl;
    std::cout << "IR RANGES : " << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << "IR[" << i << "] = " << ir[i] << " ";
    }
    std::cout << std::endl;

    int lidarCount = robotino->getLidarRangeNumber();
    float* ranges = new float[lidarCount];
    robotino->getLidarRange(ranges);

    std::cout << "--------------------LIDAR VALUES (in meters)--------------------------" << std::endl;
    for (int i = 0; i < lidarCount; i++) {
        std::cout << "Lidar[" << i << "] = " << ranges[i] << " ";
    }
    std::cout << std::endl;
    delete[] ranges;

    std::cout << "----------------------------------------------------------------------" << std::endl;
}

void connectRobot() {
    robotino->connect();
    std::cout << "Robot is connected." << std::endl;
}

void disconnectRobot() {
    robotino->disconnect();
    std::cout << "Robot is disconnected." << std::endl;
}

void exploreRoom() {
    for (int step = 0; step < 10; ++step) {
        robotino->move(FORWARD);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        robotino->stop();

        lidar->update();
        mapper->updateMap();
        mapper->showMap();

        robotino->rotate(LEFT);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        robotino->stop();
    }
}

void moveRobot(int direction) {
    switch (direction) {
    case 1: // Forward
        robotino->move(FORWARD);
        std::cout << "Robot is moving forward." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        robotino->stop();
        break;
    case 2: // Stop
        robotino->stop();
        std::cout << "Robot stopped safely." << std::endl;
        break;
    case 3:
        turnLeft();
        break;
    case 4:
        turnRight();
        break;
    case 5:
        moveLeft();
        break;
    case 6:
        moveRight();
        break;
    default:
        std::cout << "Invalid movement command!" << std::endl;
    }
}

int main() {
    // Robot nesnelerini oluþtur
    robotino = new FestoRobotAPI();
    lidar = new LidarSensor(*robotino);
    mapper = new Mapper(map, *lidar);

    // Menü sýnýfýný baþlat
    Menu menu;

    // Ana menüyü çalýþtýr
    bool running = true;
    while (running) {
        int mainChoice = menu.displayMainMenu();
        switch (mainChoice) {
        case 1: { // Connection Menu
            int connectionChoice = menu.displayConnectionMenu();
            switch (connectionChoice) {
            case 1:
                connectRobot();
                break;
            case 2:
                disconnectRobot();
                break;
            case 3: // Back
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
            }
            break;
        }
        case 2: { // Motion Menu
            int motionChoice = menu.displayMotionMenu();
            if (motionChoice >= 1 && motionChoice <= 6) {
                moveRobot(motionChoice);
            }
            else if (motionChoice == 8) {
                running = false;
            }
            else {
                std::cout << "Invalid choice!" << std::endl;
            }
            break;
        }
        case 3: { // Sensor Menu
            printSensorData();
            break;
        }
        case 4:
            running = false;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }

    // Baðlantýyý kes ve bellek temizliði
    disconnectRobot();
    delete mapper;
    delete lidar;
    delete robotino;

    std::cout << "Simulation ended. Goodbye!" << std::endl;
    return 0;
}
