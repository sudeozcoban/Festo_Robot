#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H

#include "MAP.h"

class SafeNavigation {
private:
    MAP map; // MAP s�n�f�n�n bir �rne�i

public:
    SafeNavigation(int x, int y, double gridSize);

    void addObstacle(int x, int y);              // Haritaya bir engel ekler
    void clearAllObstacles();                   // Haritadaki t�m engelleri kald�r�r
    void displayMap() const;                    // Haritay� konsola yazd�r�r
    void saveMap(const std::string& fileName);  // Haritay� bir dosyaya kaydeder
    void loadMap(const std::string& fileName);  // Haritay� bir dosyadan y�kler
};

#endif // SAFENAVIGATION_H