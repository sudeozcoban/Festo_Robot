#ifndef ROBOTCONTROLER_H
#define ROBOTCONTROLER_H

#include "RobotInterface.h"
#include "SensorInterface.h"
#include <string>
#include <memory>

class RobotControler {
private:
    std::shared_ptr<RobotInterface> robot; ///< Robot nesnesi
    bool accessGranted; ///< Eriþim durumu
    std::string password; ///< Eriþim için gerekli þifre

public:
    RobotControler(std::shared_ptr<RobotInterface> robot, const std::string& password);
    virtual ~RobotControler() = default;

    /**
     * @brief Eriþim açar.
     * @param inputPassword Kullanýcýdan alýnan þifre.
     */
    void openAccess(const std::string& inputPassword);

    /**
     * @brief Eriþimi kapatýr.
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
     * @brief Sensör ekler.
     * @param sensor Eklenecek sensör nesnesi.
     */
    void addSensor(std::shared_ptr<SensorInterface> sensor);

    /**
     * @brief Tüm sensörlerin güncellenmesini saðlar.
     */
    void updateSensors();
};

#endif // ROBOTCONTROLER_H