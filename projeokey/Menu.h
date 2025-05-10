#pragma once
#ifndef MENU_H
#define MENU_H

class Menu {
public:
    // Ana menüyü görüntüler ve kullanýcýdan seçim alýr
    int displayMainMenu();

    // Baðlantý menüsünü görüntüler ve kullanýcýdan seçim alýr
    int displayConnectionMenu();

    // Hareket menüsünü görüntüler ve kullanýcýdan seçim alýr
    int displayMotionMenu();

    // Sensör menüsünü görüntüler ve kullanýcýdan seçim alýr
    int displaySensorMenu();

    // Baðlantý menüsü iþlemlerini yönetir
    void handleConnectionMenu();

    // Hareket menüsü iþlemlerini yönetir
    void handleMotionMenu();

    // Sensör menüsü iþlemlerini yönetir
    void handleSensorMenu();
};

#endif // MENU_H