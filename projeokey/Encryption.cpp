/// @file Encryption.cpp
/// @brief Encryption sýnýfýnýn implementasyon dosyasý
/// @author Sude Özçoban
/// @date 16.12.2024
#include "Encryption.h"
#include <algorithm> // std::swap kullanýmý için eklendi

/// @brief Þifreleme iþlemi yapar.
/// @param num Þifrelenecek sayý
/// @return Þifrelenmiþ sayý
int Encryption::encrypt(int num) {
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 7) % 10;
    }
    /// @details Þifreleme algoritmasý þu adýmlardan oluþur:
    ///  1. Her bir basamaða 7 eklenir ve mod 10 alýnýr.
    ///  2. 1. ve 3. basamaklar yer deðiþtirir, 2. ve 4. basamaklar yer deðiþtirir.
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);
    // 1. ve 3. rakam yer deðiþtirir
    // 2. ve 4. rakam yer deðiþtirir
    int encryptedNum = 0;
    for (int i = 0; i < 4; ++i) {
        encryptedNum = encryptedNum * 10 + digits[i];
    }

    return encryptedNum;
}

/// @brief Verilen sayýyý deþifreler.
/// @details Deþifreleme iþlemi þu adýmlardan oluþur:
///  1. 1. ve 3. basamaklar yer deðiþtirir, 2. ve 4. basamaklar yer deðiþtirir.
///  2. Her bir basamaða 3 eklenir ve mod 10 alýnýr 7'yi geri almak için yapýlýr bu iþlem.
/// bi nevi sifrelemek için yapýlan iþlemin tersi olarak düsünülünebilir 
int Encryption::decrypt(int num) {
    int digits[4];
    for (int i = 3; i >= 0; --i) {
        digits[i] = num % 10;
        num /= 10;
    }
    // Deðiþim swap kullanýlarak yapýldý
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    for (int i = 0; i < 4; ++i) {
        digits[i] = (digits[i] + 3) % 10; // 10 - 7 = 3
    }
    // Deþifreleme adýmý: her rakama 3 eklenir ve mod 10 alýnýr
    int decryptedNum = 0;
    for (int i = 0; i < 4; ++i) {
        decryptedNum = decryptedNum * 10 + digits[i];
    }

    return decryptedNum;
}