/// @file RobotOperator.h
/// @brief RobotOperator sýnýfýnýn baþlýk dosyasý
/// @author Sude Özçoban
/// @date 16.12.2025

#ifndef ROBOT_OPERATOR_H
#define ROBOT_OPERATOR_H

#include <string>
#include "Encryption.h"

class RobotOperator {
private:
    std::string name; ///< Operatörün adý
    std::string surname; ///< Operatörün soyadý
    unsigned int accessCode; ///< Operatörün eriþim kodu
    bool accessState; ///< Operatörün eriþim durumunu tanýmladýk
    /// <summary>
    /// std iç,n usingnampe space kullanmadýk cunku buyuk caplý projelerde karmasaya yol açabilir
    /// </summary>

public:
    /// @brief Constructor
    RobotOperator(const std::string& name, const std::string& surname, int code);

    /// @brief Eriþim kodunu kontrol eder verilen kodla sistemdeki kod ayný mý dýye kontrol saðlanýr 
    /// @param code Eriþim kodu
    /// @return Eðer kod doðruysa true, aksi takdirde false dondurur 
    bool checkAccessCode(int code);

    /// @brief Eriþim kodunu þifreler
    void encryptCode(int code);

    /// @brief Eriþim kodunu çözer
    void decryptCode(int code);

    /// @brief Operatörün print ederiz
    void print() const;
};

#endif