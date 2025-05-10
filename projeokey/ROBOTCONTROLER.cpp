#include "ROBOTCONTROLER.h"
#include <iostream>

RobotControler::RobotControler(std::shared_ptr<RobotInterface> robot, const std::string& password)
    : robot(robot), accessGranted(false), password(password) {
}

void RobotControler::openAccess(const std::string& inputPassword) {
    if (inputPassword == password) {
        accessGranted = true;
        std::cout << "Eri�im a��ld�.\n";
    }
    else {
        std::cerr << "Hatal� �ifre.\n";
    }
}

void RobotControler::closeAccess() {
    accessGranted = false;
    std::cout << "Eri�im kapat�ld�.\n";
}

void RobotControler::moveForward() {
    if (accessGranted) {
        robot->forward();
    }
    else {
        std::cerr << "Eri�im reddedildi.\n";
    }
}

void RobotControler::moveBackward() {
    if (accessGranted) {
        robot->backward();
    }
    else {
        std::cerr << "Eri�im reddedildi.\n";
    }
}

void RobotControler::stop() {
    if (accessGranted) {
        robot->stop();
    }
    else {
        std::cerr << "Eri�im reddedildi.\n";
    }
}

void RobotControler::addSensor(std::shared_ptr<SensorInterface> sensor) {
    robot->addSensor(sensor);
}

void RobotControler::updateSensors() {
    if (accessGranted) {
        robot->updateSensors();
    }
    else {
        std::cerr << "Eri�im reddedildi.\n";
    }
}