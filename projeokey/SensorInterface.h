#pragma once
#include <string>
#include <vector>
#include <stdexcept>

class SensorInterface {
public:
    SensorInterface() = default;
    virtual ~SensorInterface() {}

    // Sensör türünü döndürür (örneðin, "IR", "Lidar")
    virtual std::string getSensorType() const = 0;

    // Belirtilen bir sensörün deðerini döndürür
    virtual double getSensorValue(int index) const {
        if (index < 0 || index >= sensorValues.size()) {
            throw std::invalid_argument("Sensor index out of range");
        }
        return sensorValues[index];
    }

    // Sensör verilerini günceller
    virtual void updateSensor() = 0; // update() yerine updateSensor olarak adlandýrýldý

protected:
    std::vector<double> sensorValues; // Sensör verileri (örneðin IR/Lidar)
};
