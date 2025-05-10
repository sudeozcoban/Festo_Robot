#pragma once
#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include "SensorInterface.h"
#include <vector>
#include <memory>

class RobotInterface {
protected:
    std::vector<std::shared_ptr<SensorInterface>> sensorList; ///< Sens�r listesi

public:
    virtual ~RobotInterface() = default;

    /**
     * @brief Robotun ileri gitmesini sa�lar.
     */
    virtual void forward() = 0;

    /**
     * @brief Robotun geri gitmesini sa�lar.
     */
    virtual void backward() = 0;

    /**
     * @brief Robotun durmas�n� sa�lar.
     */
    virtual void stop() = 0;

    /**
     * @brief Sens�r ekler.
     * @param sensor Eklenecek sens�r nesnesi.
     */
    virtual void addSensor(std::shared_ptr<SensorInterface> sensor);

    /**
     * @brief T�m sens�rlerin g�ncellenmesini sa�lar.
     */
    virtual void updateSensors();
};

#endif // ROBOTINTERFACE_H