#define _USE_MATH_DEFINES
#include "Pose.h"
#include <cmath>

// Constructor
Pose::Pose(double x, double y, double th) : x(x), y(y), th(th) {}

// Getter ve Setter fonksiyonlarý
double Pose::getX() const {
    return x;
}

void Pose::setX(double x) {
    this->x = x;
}

double Pose::getY() const {
    return y;
}

void Pose::setY(double y) {
    this->y = y;
}

double Pose::getTh() const {
    return th;
}

void Pose::setTh(double th) {
    this->th = th;
}

// Pose bilgilerini toplu olarak alma ve ayarlama
void Pose::getPose(double& x, double& y, double& th) const {
    x = this->x;
    y = this->y;
    th = this->th;
}

void Pose::setPose(double x, double y, double th) {
    this->x = x;
    this->y = y;
    this->th = th;
}

// Mesafe hesaplama fonksiyonu
double Pose::findDistanceTo(const Pose& other) const {
    return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
}

// Açý hesaplama fonksiyonu
double Pose::findAngleTo(const Pose& other) const {
    return std::atan2(other.y - y, other.x - x) * (180.0 / M_PI);
}

// Operatör aþýrý yüklemeleri
bool Pose::operator==(const Pose& other) const {
    return (x == other.x) && (y == other.y) && (th == other.th);
}

Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

Pose& Pose::operator=(const Pose& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        th = other.th;
    }
    return *this;
}