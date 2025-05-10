#pragma once
#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include "SensorInterface.h"
#include <vector>
#include <memory>

class RobotInterface {
protected:
    std::vector<std::shared_ptr<SensorInterface>> sensorList; ///< Sensör listesi

public:
    virtual ~RobotInterface() = default;

    /**
     * @brief Robotun ileri gitmesini saðlar.
     */
    virtual void forward() = 0;

    /**
     * @brief Robotun geri gitmesini saðlar.
     */
    virtual void backward() = 0;

    /**
     * @brief Robotun durmasýný saðlar.
     */
    virtual void stop() = 0;

    /**
     * @brief Sensör ekler.
     * @param sensor Eklenecek sensör nesnesi.
     */
    virtual void addSensor(std::shared_ptr<SensorInterface> sensor);

    /**
     * @brief Tüm sensörlerin güncellenmesini saðlar.
     */
    virtual void updateSensors();
};

#endif // ROBOTINTERFACE_H