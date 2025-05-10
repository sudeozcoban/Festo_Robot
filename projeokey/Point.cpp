/// @file Point.cpp
/// @brief Point sýnýfýnýn implementasyon dosyasý
/// @author Sude Özçoban
/// @date 17.12.2024

#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;

/// @brief Default constructor kullanarak x ve y koordinatlarýný sýfýrladýk.
Point::Point() : x(0), y(0) {}

/// @brief Parametreli constructor, x ve y koordinatlarýný verilen deðerlere ayarlar.
/// @param x X koordinatý
/// @param y Y koordinatý
Point::Point(double x, double y) : x(x), y(y) {}

/// @brief X koordinatýný döndürür.
/// @return X koordinatý dondurur.
double Point::getX() const { return x; }

/// @brief Y koordinatýný döndürür.
/// @return Y koordinatý dondurur 
double Point::getY() const { return y; }

/// @brief X koordinatýný verilen deðere ayarlar.
/// @param xVal Yeni X koordinatý olur
void Point::setX(double xVal) { x = xVal; }

/// @brief Y koordinatýný verilen deðere ayarlar.
/// @param yVal Yeni Y koordinatý olur
void Point::setY(double yVal) { y = yVal; }

/// @brief Bu nokta ile baþka bir nokta arasýndaki mesafeyi hesaplar.
/// @return Ýki nokta arasýndaki mesafedir
/// @details Mesafe formülü: \f$\sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}\f$ budur 
double Point::findDistanceTo(const Point& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

/// @brief Bu nokta ile baþka bir nokta arasýndaki açýyý hesaplar.
/// @return Ýki nokta arasýndaki açýyý hesaplar ve bu radyan cýnsýnde olmalýdýr 
/// @details Açý formülü: \f$\text{atan2}(y_2 - y_1, x_2 - x_1)\f$ bu da formuludur 
double Point::findAngleTo(const Point& other) const {
    return atan2(other.y - y, other.x - x);
}

/// @brief Ýki noktanýn eþit olup olmadýðýný kontrol eder.
/// @return Eðer iki nokta eþitse true, aksi takdirde false dondurur 
bool Point::operator==(const Point& other) const {
    return (x == other.x && y == other.y);
}

/// @brief Noktanýn x ve y koordinatlarýný print ederiz
void Point::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}