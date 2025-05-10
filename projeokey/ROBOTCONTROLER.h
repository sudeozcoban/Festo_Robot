#ifndef ROBOTCONTROLER_H
#define ROBOTCONTROLER_H

#include "RobotInterface.h"
#include "SensorInterface.h"
#include <string>
#include <memory>

class RobotControler {
private:
    std::shared_ptr<RobotInterface> robot; ///< Robot nesnesi
    bool accessGranted; ///< Eri�im durumu
    std::string password; ///< Eri�im i�in gerekli �ifre

public:
    RobotControler(std::shared_ptr<RobotInterface> robot, const std::string& password);
    virtual ~RobotControler() = default;

    /**
     * @brief Eri�im a�ar.
     * @param inputPassword Kullan�c�dan al�nan �ifre.
     */
    void openAccess(const std::string& inputPassword);

    /**
     * @brief Eri�imi kapat�r.
     */
    void closeAccess();

    /**
     * @brief Robotu ileri hareket ettirir.
     */
    void moveForward();

    /**
     * @brief Robotu geri hareket ettirir.
     */
    void moveBackward();

    /**
     * @brief Robotu durdurur.
     */
    void stop();

    /**
     * @brief Sens�r ekler.
     * @param sensor Eklenecek sens�r nesnesi.
     */
    void addSensor(std::shared_ptr<SensorInterface> sensor);

    /**
     * @brief T�m sens�rlerin g�ncellenmesini sa�lar.
     */
    void updateSensors();
};

#endif // ROBOTCONTROLER_H