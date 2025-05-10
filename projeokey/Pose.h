#pragma once
#ifndef POSE_H
#define POSE_H

#include <cmath>

class Pose {
private:
    double x;  // Robotun x koordinat� (metre cinsinden)
    double y;  // Robotun y koordinat� (metre cinsinden)
    double th; // Robotun y�n� (derece cinsinden)

public:
    // Constructor (varsay�lan ve parametreli)
    Pose(double x = 0.0, double y = 0.0, double th = 0.0);

    // Getter ve Setter fonksiyonlar�
    double getX() const;
    void setX(double x);

    double getY() const;
    void setY(double y);

    double getTh() const;
    void setTh(double th);

    // Pose bilgilerini toplu olarak alma ve ayarlama
    void getPose(double& x, double& y, double& th) const;
    void setPose(double x, double y, double th);

    // Mesafe hesaplama fonksiyonu
    double findDistanceTo(const Pose& other) const;

    // A�� hesaplama fonksiyonu
    double findAngleTo(const Pose& other) const;

    // Operat�r a��r� y�klemeleri
    bool operator==(const Pose& other) const;
    Pose operator+(const Pose& other) const;
    Pose operator-(const Pose& other) const;
    Pose& operator+=(const Pose& other);
    Pose& operator-=(const Pose& other);
    Pose& operator=(const Pose& other);
};

#endif