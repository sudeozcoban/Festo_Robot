#pragma once
#ifndef FESTOROBOTSENSORINTERFACE_H
#define FESTOROBOTSENSORINTERFACE_H

#include "SensorInterface.h"
#include <string>
#include <vector>

class FestoRobotSensorInterface : public SensorInterface {
protected:
    std::string sensorType; // Sens�r tipi ("IR", "Lidar" vb.)
    std::vector<double> sensorData; // Sens�r verileri

public:
    FestoRobotSensorInterface(const std::string& type);
    virtual ~FestoRobotSensorInterface() = default;

    virtual void updateSensor() override; // Sens�r verilerini g�ncelle
    virtual std::string getSensorType() const override; // Sens�r tipini d�nd�r
    virtual double getSensorValue(int index) const override; // Belirtilen indeksin sens�r verisini d�nd�r
    void addSensorData(double value); // Sens�r verisi ekle
};

#endif // FESTOROBOTSENSORINTERFACE_H