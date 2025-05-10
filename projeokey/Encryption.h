/// @file Encryption.h
/// @brief Encryption s�n�f�n�n ba�l�k dosyas�
/// @author Sude �z�oban
/// @date 16.12.2024

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {
public:
    /// @brief �ifreleme fonksiyonu
    /// @param num �ifrelenecek say�
    /// @return �ifrelenmi� say�
    int encrypt(int num);

    /// @brief �ifre ��zme fonksiyonu
    /// @param num �ifreli say�
    /// @return ��z�lm�� say�
    int decrypt(int num);
};

#endif