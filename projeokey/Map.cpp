#include "Map.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>

// Constructor
MAP::MAP(int x, int y, double size)
    : numberX(x), numberY(y), gridSize(size), grid(x, std::vector<int>(y, 0)) {
}

// Haritaya bir nokta ekler
void MAP::insertPoint(int x, int y) {
    if (x >= 0 && x < numberX && y >= 0 && y < numberY) {
        grid[x][y] = 1; // Nokta ekleniyor
    }
    else {
        throw std::out_of_range("Point is out of map bounds.");
    }
}

// Belirli bir h�creye de�er atar
void MAP::setGridIndex(int x, int y, int value) {
    if (x >= 0 && x < numberX && y >= 0 && y < numberY) {
        grid[x][y] = value;
    }
    else {
        throw std::out_of_range("Index is out of map bounds.");
    }
}

// Belirli bir h�crenin de�erini al�r
int MAP::getGridIndex(int x, int y) const {
    if (x >= 0 && x < numberX && y >= 0 && y < numberY) {
        return grid[x][y];
    }
    else {
        throw std::out_of_range("Index is out of map bounds.");
    }
}

// Haritay� s�f�rlar
void MAP::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

// Haritay� konsola yazd�r�r
void MAP::printToConsole() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell ? 'x' : '.') << " ";
        }
        std::cout << std::endl;
    }
}

// Haritay� dosyaya kaydeder
bool MAP::saveToFile(const std::string& name) {
    std::ofstream file(name);
    if (!file.is_open()) {
        return false;
    }

    file << numberX << " " << numberY << " " << gridSize << "\n";
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            file << cell << " ";
        }
        file << "\n";
    }

    file.close();
    return true;
}

// Haritay� dosyadan y�kler
bool MAP::loadFromFile(const std::string& name) {
    std::ifstream file(name);
    if (!file.is_open()) {
        return false;
    }

    file >> numberX >> numberY >> gridSize;
    grid.resize(numberX, std::vector<int>(numberY));
    for (auto& row : grid) {
        for (auto& cell : row) {
            file >> cell;
        }
    }

    file.close();
    return true;
}

// Getter ve Setter fonksiyonlar�
int MAP::getNumberX() const {
    return numberX;
}

int MAP::getNumberY() const {
    return numberY;
}

double MAP::getGridSize() const {
    return gridSize;
}

void MAP::setGridSize(int x, int y, double size) {
    numberX = x;
    numberY = y;
    gridSize = size;
    grid.resize(x, std::vector<int>(y, 0));
}

// Haritay� yazd�rmak i�in friend fonksiyonu
std::ostream& operator<<(std::ostream& os, const MAP& map) {
    for (const auto& row : map.grid) {
        for (const auto& cell : row) {
            os << (cell ? 'x' : '.') << " ";
        }
        os << "\n";
    }
    return os;
}