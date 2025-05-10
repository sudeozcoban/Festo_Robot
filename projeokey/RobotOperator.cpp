/// @file RobotOperator.cpp
/// @brief RobotOperator s�n�f�n�n implementasyon dosyas�
/// @author Sude �z�oban
/// @date 16.12.2025

#include "RobotOperator.h"
#include <iostream>

/// @brief Constructor
/// @param name Operat�r�n ad�d�r
/// @param surname Operat�r�n soyad�d�r
/// @param code Operat�r�n eri�im kodudur
RobotOperator::RobotOperator(const std::string& name, const std::string& surname, int code)
    : name(name), surname(surname), accessCode(code), accessState(false) {
}

/// @brief Eri�im kodunu kontrol eder
/// @return E�er kod do�ruysa true, aksi takdirde false dondurur 
bool RobotOperator::checkAccessCode(int code) {
    return code == accessCode;
}

/// @brief Eri�im kodunu �ifreler
/// @param code Eri�im kodu
void RobotOperator::encryptCode(int code) {
    Encryption encryption;
    accessCode = encryption.encrypt(code);
}

/// @brief Eri�im kodunu ��zer
/// @param code �ifreli kod
void RobotOperator::decryptCode(int code) {
    Encryption encryption;
    accessCode = encryption.decrypt(code);
}

/// @brief Operat�r�n bilgilerini print ederiz
void RobotOperator::print() const {
    std::cout << "Name: " << name << ", Surname: " << surname << std::endl;
}