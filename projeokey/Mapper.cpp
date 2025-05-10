#include "Mapper.h"
#include <iostream>
#include <stdexcept>
#include "Map.h"

// Constructor
Mapper::Mapper(int x, int y, double gridSize)
    : map(x, y, gridSize) {
}

// Haritaya bir nokta ekler
void Mapper::addPoint(int x, int y) {
    try {
        map.insertPoint(x, y); // MAP s�n�f�n�n insertPoint fonksiyonunu �a��r�r
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Haritay� s�f�rlar
void Mapper::clearAll() {
    map.clearMap(); // MAP s�n�f�n�n clearMap fonksiyonunu �a��r�r
}

// Haritay� konsola yazd�r�r
void Mapper::print() {
    map.printToConsole(); // MAP s�n�f�n�n printToConsole fonksiyonunu �a��r�r
}

// Haritay� dosyaya kaydeder
void Mapper::save(const std::string& fileName) {
    if (!map.saveToFile(fileName)) {
        std::cerr << "Error: Failed to save map to file." << std::endl;
    }
}

// Haritay� dosyadan y�kler
void Mapper::load(const std::string& fileName) {
    if (!map.loadFromFile(fileName)) {
        std::cerr << "Error: Failed to load map from file." << std::endl;
    }
}