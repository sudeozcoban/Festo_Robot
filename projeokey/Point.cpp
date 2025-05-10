/// @file Point.cpp
/// @brief Point s�n�f�n�n implementasyon dosyas�
/// @author Sude �z�oban
/// @date 17.12.2024

#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;

/// @brief Default constructor kullanarak x ve y koordinatlar�n� s�f�rlad�k.
Point::Point() : x(0), y(0) {}

/// @brief Parametreli constructor, x ve y koordinatlar�n� verilen de�erlere ayarlar.
/// @param x X koordinat�
/// @param y Y koordinat�
Point::Point(double x, double y) : x(x), y(y) {}

/// @brief X koordinat�n� d�nd�r�r.
/// @return X koordinat� dondurur.
double Point::getX() const { return x; }

/// @brief Y koordinat�n� d�nd�r�r.
/// @return Y koordinat� dondurur 
double Point::getY() const { return y; }

/// @brief X koordinat�n� verilen de�ere ayarlar.
/// @param xVal Yeni X koordinat� olur
void Point::setX(double xVal) { x = xVal; }

/// @brief Y koordinat�n� verilen de�ere ayarlar.
/// @param yVal Yeni Y koordinat� olur
void Point::setY(double yVal) { y = yVal; }

/// @brief Bu nokta ile ba�ka bir nokta aras�ndaki mesafeyi hesaplar.
/// @return �ki nokta aras�ndaki mesafedir
/// @details Mesafe form�l�: \f$\sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}\f$ budur 
double Point::findDistanceTo(const Point& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

/// @brief Bu nokta ile ba�ka bir nokta aras�ndaki a��y� hesaplar.
/// @return �ki nokta aras�ndaki a��y� hesaplar ve bu radyan c�ns�nde olmal�d�r 
/// @details A�� form�l�: \f$\text{atan2}(y_2 - y_1, x_2 - x_1)\f$ bu da formuludur 
double Point::findAngleTo(const Point& other) const {
    return atan2(other.y - y, other.x - x);
}

/// @brief �ki noktan�n e�it olup olmad���n� kontrol eder.
/// @return E�er iki nokta e�itse true, aksi takdirde false dondurur 
bool Point::operator==(const Point& other) const {
    return (x == other.x && y == other.y);
}

/// @brief Noktan�n x ve y koordinatlar�n� print ederiz
void Point::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}