#pragma once
#ifndef MENU_H
#define MENU_H

class Menu {
public:
    // Ana men�y� g�r�nt�ler ve kullan�c�dan se�im al�r
    int displayMainMenu();

    // Ba�lant� men�s�n� g�r�nt�ler ve kullan�c�dan se�im al�r
    int displayConnectionMenu();

    // Hareket men�s�n� g�r�nt�ler ve kullan�c�dan se�im al�r
    int displayMotionMenu();

    // Sens�r men�s�n� g�r�nt�ler ve kullan�c�dan se�im al�r
    int displaySensorMenu();

    // Ba�lant� men�s� i�lemlerini y�netir
    void handleConnectionMenu();

    // Hareket men�s� i�lemlerini y�netir
    void handleMotionMenu();

    // Sens�r men�s� i�lemlerini y�netir
    void handleSensorMenu();
};

#endif // MENU_H