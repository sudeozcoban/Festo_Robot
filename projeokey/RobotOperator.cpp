/// @file RobotOperator.cpp
/// @brief RobotOperator sýnýfýnýn implementasyon dosyasý
/// @author Sude Özçoban
/// @date 16.12.2025

#include "RobotOperator.h"
#include <iostream>

/// @brief Constructor
/// @param name Operatörün adýdýr
/// @param surname Operatörün soyadýdýr
/// @param code Operatörün eriþim kodudur
RobotOperator::RobotOperator(const std::string& name, const std::string& surname, int code)
    : name(name), surname(surname), accessCode(code), accessState(false) {
}

/// @brief Eriþim kodunu kontrol eder
/// @return Eðer kod doðruysa true, aksi takdirde false dondurur 
bool RobotOperator::checkAccessCode(int code) {
    return code == accessCode;
}

/// @brief Eriþim kodunu þifreler
/// @param code Eriþim kodu
void RobotOperator::encryptCode(int code) {
    Encryption encryption;
    accessCode = encryption.encrypt(code);
}

/// @brief Eriþim kodunu çözer
/// @param code Þifreli kod
void RobotOperator::decryptCode(int code) {
    Encryption encryption;
    accessCode = encryption.decrypt(code);
}

/// @brief Operatörün bilgilerini print ederiz
void RobotOperator::print() const {
    std::cout << "Name: " << name << ", Surname: " << surname << std::endl;
}