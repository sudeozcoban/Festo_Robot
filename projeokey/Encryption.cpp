/// @file Encryption.cpp
/// @brief Encryption s�n�f�n�n implementasyon dosyas�
/// @author Sude �z�oban
/// @date 16.12.2024
#include "Encryption.h"
#include <algorithm> // std::swap kullan�m� i�in eklendi

/// @brief �ifreleme i�lemi yapar.
/// @param num �ifrelenecek say�
/// @return �ifrelenmi� say�
int Encryption::encrypt(int num) {
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 7) % 10;
    }
    /// @details �ifreleme algoritmas� �u ad�mlardan olu�ur:
    ///  1. Her bir basama�a 7 eklenir ve mod 10 al�n�r.
    ///  2. 1. ve 3. basamaklar yer de�i�tirir, 2. ve 4. basamaklar yer de�i�tirir.
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);
    // 1. ve 3. rakam yer de�i�tirir
    // 2. ve 4. rakam yer de�i�tirir
    int encryptedNum = 0;
    for (int i = 0; i < 4; ++i) {
        encryptedNum = encryptedNum * 10 + digits[i];
    }

    return encryptedNum;
}

/// @brief Verilen say�y� de�ifreler.
/// @details De�ifreleme i�lemi �u ad�mlardan olu�ur:
///  1. 1. ve 3. basamaklar yer de�i�tirir, 2. ve 4. basamaklar yer de�i�tirir.
///  2. Her bir basama�a 3 eklenir ve mod 10 al�n�r 7'yi geri almak i�in yap�l�r bu i�lem.
/// bi nevi sifrelemek i�in yap�lan i�lemin tersi olarak d�s�n�l�nebilir 
int Encryption::decrypt(int num) {
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = num % 10;
        num /= 10;
    }
    // De�i�im swap kullan�larak yap�ld�
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 3) % 10; // 10 - 7 = 3
    }
    // De�ifreleme ad�m�: her rakama 3 eklenir ve mod 10 al�n�r
    int decryptedNum = 0;
    for (int i = 0; i < 4; ++i) {
        decryptedNum = decryptedNum * 10 + digits[i];
    }

    return decryptedNum;
}