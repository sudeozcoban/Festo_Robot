/// @file RobotOperator.h
/// @brief RobotOperator s�n�f�n�n ba�l�k dosyas�
/// @author Sude �z�oban
/// @date 16.12.2025

#ifndef ROBOT_OPERATOR_H
#define ROBOT_OPERATOR_H

#include <string>
#include "Encryption.h"

class RobotOperator {
private:
    std::string name; ///< Operat�r�n ad�
    std::string surname; ///< Operat�r�n soyad�
    unsigned int accessCode; ///< Operat�r�n eri�im kodu
    bool accessState; ///< Operat�r�n eri�im durumunu tan�mlad�k
    /// <summary>
    /// std i�,n usingnampe space kullanmad�k cunku buyuk capl� projelerde karmasaya yol a�abilir
    /// </summary>

public:
    /// @brief Constructor
    RobotOperator(const std::string& name, const std::string& surname, int code);

    /// @brief Eri�im kodunu kontrol eder verilen kodla sistemdeki kod ayn� m� d�ye kontrol sa�lan�r 
    /// @param code Eri�im kodu
    /// @return E�er kod do�ruysa true, aksi takdirde false dondurur 
    bool checkAccessCode(int code);

    /// @brief Eri�im kodunu �ifreler
    void encryptCode(int code);

    /// @brief Eri�im kodunu ��zer
    void decryptCode(int code);

    /// @brief Operat�r�n print ederiz
    void print() const;
};

#endif