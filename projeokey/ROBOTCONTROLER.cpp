#include "ROBOTCONTROLER.h"
#include <iostream>

RobotControler::RobotControler(std::shared_ptr<RobotInterface> robot, const std::string& password)
    : robot(robot), accessGranted(false), password(password) {
}

void RobotControler::openAccess(const std::string& inputPassword) {
    if (inputPassword == password) {
        accessGranted = true;
        std::cout << "Eriþim açýldý.\n";
    }
    else {
        std::cerr << "Hatalý þifre.\n";
    }
}

void RobotControler::closeAccess() {
    accessGranted = false;
    std::cout << "Eriþim kapatýldý.\n";
}

void RobotControler::moveForward() {
    if (accessGranted) {
        robot->forward();
    }
    else {
        std::cerr << "Eriþim reddedildi.\n";
    }
}

void RobotControler::moveBackward() {
    if (accessGranted) {
        robot->backward();
    }
    else {
        std::cerr << "Eriþim reddedildi.\n";
    }
}

void RobotControler::stop() {
    if (accessGranted) {
        robot->stop();
    }
    else {
        std::cerr << "Eriþim reddedildi.\n";
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
        std::cerr << "Eriþim reddedildi.\n";
    }
}