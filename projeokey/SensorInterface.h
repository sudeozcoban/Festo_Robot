#pragma once
#include <string>
#include <vector>
#include <stdexcept>

class SensorInterface {
public:
    SensorInterface() = default;
    virtual ~SensorInterface() {}

    // Sens�r t�r�n� d�nd�r�r (�rne�in, "IR", "Lidar")
    virtual std::string getSensorType() const = 0;

    // Belirtilen bir sens�r�n de�erini d�nd�r�r
    virtual double getSensorValue(int index) const {
        if (index < 0 || index >= sensorValues.size()) {
            throw std::invalid_argument("Sensor index out of range");
        }
        return sensorValues[index];
    }

    // Sens�r verilerini g�nceller
    virtual void updateSensor() = 0; // update() yerine updateSensor olarak adland�r�ld�

protected:
    std::vector<double> sensorValues; // Sens�r verileri (�rne�in IR/Lidar)
};
