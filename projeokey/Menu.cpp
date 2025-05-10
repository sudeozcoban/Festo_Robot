#include "Menu.h"
#include <iostream>
using namespace std;

// Ana menüyü gösterir
int Menu::displayMainMenu() {
    cout << "\n---------------- MAIN MENU ----------------\n";
    cout << "1. Connection Menu\n";
    cout << "2. Motion Menu\n";
    cout << "3. Sensor Menu\n";
    cout << "4. Quit\n";
    cout << "------------------------------------------\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// Baðlantý menüsünü gösterir
int Menu::displayConnectionMenu() {
    cout << "\n-------------- CONNECTION MENU --------------\n";
    cout << "1. Connect Robot\n";
    cout << "2. Disconnect Robot\n";
    cout << "3. Back to Main Menu\n";
    cout << "---------------------------------------------\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// Hareket menüsünü gösterir
int Menu::displayMotionMenu() {
    cout << "\n----------------- MOTION MENU -----------------\n";
    cout << "1. Move Forward\n";
    cout << "2. Stop\n";
    cout << "3. Turn Left\n";
    cout << "4. Turn Right\n";
    cout << "5. Explore Room\n";
    cout << "6. Back to Main Menu\n";
    cout << "------------------------------------------------\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// Sensör menüsünü gösterir
int Menu::displaySensorMenu() {
    cout << "\n----------------- SENSOR MENU -----------------\n";
    cout << "1. Print Sensor Data\n";
    cout << "2. Back to Main Menu\n";
    cout << "------------------------------------------------\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// Baðlantý menüsünü yönetir
void Menu::handleConnectionMenu() {
    cout << "Connection menu handling is under construction.\n";
}

// Hareket menüsünü yönetir
void Menu::handleMotionMenu() {
    cout << "Motion menu handling is under construction.\n";
}

// Sensör menüsünü yönetir
void Menu::handleSensorMenu() {
    cout << "Sensor menu handling is under construction.\n";
}