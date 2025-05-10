#include "SafeNavigation.h"
#include <iostream>

// Constructor
SafeNavigation::SafeNavigation(int x, int y, double gridSize)
    : map(x, y, gridSize) {
}

// Haritaya bir engel ekler
void SafeNavigation::addObstacle(int x, int y) {
    map.setGridIndex(x, y, 1); // 1 de�eri bir engeli temsil eder
}

// Haritadaki t�m engelleri kald�r�r
void SafeNavigation::clearAllObstacles() {
    map.clearMap(); // MAP s�n�f�n�n clearMap fonksiyonunu �a��r�r
}

// Haritay� konsola yazd�r�r (const �ye i�levi)
void SafeNavigation::displayMap() const { // Burada const ekledik
    map.printToConsole(); // MAP s�n�f�n�n printToConsole fonksiyonunu �a��r�r
}

// Haritay� bir dosyaya kaydeder
void SafeNavigation::saveMap(const std::string& fileName) {
    if (!map.saveToFile(fileName)) {
        std::cerr << "Error: Failed to save map to file." << std::endl;
    }
}

// Haritay� bir dosyadan y�kler
void SafeNavigation::loadMap(const std::string& fileName) {
    if (!map.loadFromFile(fileName)) {
        std::cerr << "Error: Failed to load map from file." << std::endl;
    }
}