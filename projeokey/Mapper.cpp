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
        map.insertPoint(x, y); // MAP sýnýfýnýn insertPoint fonksiyonunu çaðýrýr
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Haritayý sýfýrlar
void Mapper::clearAll() {
    map.clearMap(); // MAP sýnýfýnýn clearMap fonksiyonunu çaðýrýr
}

// Haritayý konsola yazdýrýr
void Mapper::print() {
    map.printToConsole(); // MAP sýnýfýnýn printToConsole fonksiyonunu çaðýrýr
}

// Haritayý dosyaya kaydeder
void Mapper::save(const std::string& fileName) {
    if (!map.saveToFile(fileName)) {
        std::cerr << "Error: Failed to save map to file." << std::endl;
    }
}

// Haritayý dosyadan yükler
void Mapper::load(const std::string& fileName) {
    if (!map.loadFromFile(fileName)) {
        std::cerr << "Error: Failed to load map from file." << std::endl;
    }
}