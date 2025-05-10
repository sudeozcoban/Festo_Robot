/// @file Point.h
/// @brief Point s�n�f�n�n ba�l�k dosyas�
/// @author Sude �z�oban
/// @date 17.12.2024

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    double x; ///< X koordinat�
    double y; ///< Y koordinat�

public:
    /// @brief Parametresiz constructor olusturduk
    Point();

    /// @brief Parametreli constructor parametre olarak x ve y al�r
    /// @param x X koordinat�
    /// @param y Y koordinat�
    Point(double x, double y);

    /// @brief X koordinat�n� d�nd�r�r.
    double getX() const;

    /// @brief Y koordinat�n� d�nd�r�r.
    double getY() const;

    /// @brief X koordinat�n� verilen de�ere gore ayarlar.
    /// @param xVal Yeni X koordinat� olmus olur
    void setX(double xVal);

    /// @brief Y koordinat�n� verilen de�ere gore ayarlar.
    /// @param yVal Yeni Y koordinat� olmus olur
    void setY(double yVal);

    /// @brief Bu nokta ile ba�ka bir nokta aras�ndaki mesafeyi hesaplar.
    /// @return �ki nokta aras�ndaki mesafedir
    double findDistanceTo(const Point& other) const;

    /// @brief Bu nokta ile ba�ka bir nokta aras�ndaki a��y� hesaplar.
    /// @return �ki nokta aras�ndaki a�� (radyan cinsinden)
    double findAngleTo(const Point& other) const;

    /// @brief �ki noktan�n e�it olup olmad���n� kontrol eder
    /// @return E�er iki nokta e�itse true, aksi takdirde false dondurur 
    bool operator==(const Point& other) const;

    /// @brief Noktan�n x ve y koordinatlar�n� print ederiz
    void print() const;
};

#endif