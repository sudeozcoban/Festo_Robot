/// @file Point.h
/// @brief Point sýnýfýnýn baþlýk dosyasý
/// @author Sude Özçoban
/// @date 17.12.2024

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    double x; ///< X koordinatý
    double y; ///< Y koordinatý

public:
    /// @brief Parametresiz constructor olusturduk
    Point();

    /// @brief Parametreli constructor parametre olarak x ve y alýr
    /// @param x X koordinatý
    /// @param y Y koordinatý
    Point(double x, double y);

    /// @brief X koordinatýný döndürür.
    double getX() const;

    /// @brief Y koordinatýný döndürür.
    double getY() const;

    /// @brief X koordinatýný verilen deðere gore ayarlar.
    /// @param xVal Yeni X koordinatý olmus olur
    void setX(double xVal);

    /// @brief Y koordinatýný verilen deðere gore ayarlar.
    /// @param yVal Yeni Y koordinatý olmus olur
    void setY(double yVal);

    /// @brief Bu nokta ile baþka bir nokta arasýndaki mesafeyi hesaplar.
    /// @return Ýki nokta arasýndaki mesafedir
    double findDistanceTo(const Point& other) const;

    /// @brief Bu nokta ile baþka bir nokta arasýndaki açýyý hesaplar.
    /// @return Ýki nokta arasýndaki açý (radyan cinsinden)
    double findAngleTo(const Point& other) const;

    /// @brief Ýki noktanýn eþit olup olmadýðýný kontrol eder
    /// @return Eðer iki nokta eþitse true, aksi takdirde false dondurur 
    bool operator==(const Point& other) const;

    /// @brief Noktanýn x ve y koordinatlarýný print ederiz
    void print() const;
};

#endif