#pragma once
#ifndef FESTOROBOTSENSORINTERFACE_H
#define FESTOROBOTSENSORINTERFACE_H

#include "SensorInterface.h"
#include <string>
#include <vector>

class FestoRobotSensorInterface : public SensorInterface {
protected:
    std::string sensorType; // Sensör tipi ("IR", "Lidar" vb.)
    std::vector<double> sensorData; // Sensör verileri

public:
    FestoRobotSensorInterface(const std::string& type);
    virtual ~FestoRobotSensorInterface() = default;

    virtual void updateSensor() override; // Sensör verilerini güncelle
    virtual std::string getSensorType() const override; // Sensör tipini döndür
    virtual double getSensorValue(int index) const override; // Belirtilen indeksin sensör verisini döndür
    void addSensorData(double value); // Sensör verisi ekle
};

#endif // FESTOROBOTSENSORINTERFACE_H