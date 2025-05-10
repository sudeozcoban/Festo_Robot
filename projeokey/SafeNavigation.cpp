#include "SafeNavigation.h"
#include <iostream>

// Constructor
SafeNavigation::SafeNavigation(int x, int y, double gridSize)
    : map(x, y, gridSize) {
}

// Haritaya bir engel ekler
void SafeNavigation::addObstacle(int x, int y) {
    map.setGridIndex(x, y, 1); // 1 deðeri bir engeli temsil eder
}

// Haritadaki tüm engelleri kaldýrýr
void SafeNavigation::clearAllObstacles() {
    map.clearMap(); // MAP sýnýfýnýn clearMap fonksiyonunu çaðýrýr
}

// Haritayý konsola yazdýrýr (const üye iþlevi)
void SafeNavigation::displayMap() const { // Burada const ekledik
    map.printToConsole(); // MAP sýnýfýnýn printToConsole fonksiyonunu çaðýrýr
}

// Haritayý bir dosyaya kaydeder
void SafeNavigation::saveMap(const std::string& fileName) {
    if (!map.saveToFile(fileName)) {
        std::cerr << "Error: Failed to save map to file." << std::endl;
    }
}

// Haritayý bir dosyadan yükler
void SafeNavigation::loadMap(const std::string& fileName) {
    if (!map.loadFromFile(fileName)) {
        std::cerr << "Error: Failed to load map from file." << std::endl;
    }
}