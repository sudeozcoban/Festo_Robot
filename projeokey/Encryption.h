/// @file Encryption.h
/// @brief Encryption sýnýfýnýn baþlýk dosyasý
/// @author Sude Özçoban
/// @date 16.12.2024

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {
public:
    /// @brief Þifreleme fonksiyonu
    /// @param num Þifrelenecek sayý
    /// @return Þifrelenmiþ sayý
    int encrypt(int num);

    /// @brief Þifre çözme fonksiyonu
    /// @param num Þifreli sayý
    /// @return Çözülmüþ sayý
    int decrypt(int num);
};

#endif