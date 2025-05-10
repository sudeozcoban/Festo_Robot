#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H

#include "MAP.h"

class SafeNavigation {
private:
    MAP map; // MAP sýnýfýnýn bir örneði

public:
    SafeNavigation(int x, int y, double gridSize);

    void addObstacle(int x, int y);              // Haritaya bir engel ekler
    void clearAllObstacles();                   // Haritadaki tüm engelleri kaldýrýr
    void displayMap() const;                    // Haritayý konsola yazdýrýr
    void saveMap(const std::string& fileName);  // Haritayý bir dosyaya kaydeder
    void loadMap(const std::string& fileName);  // Haritayý bir dosyadan yükler
};

#endif // SAFENAVIGATION_H