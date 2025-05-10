#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"

class Mapper {
private:
    MAP map; // MAP sýnýfýnýn bir örneði

public:
    Mapper(int x, int y, double gridSize);

    void addPoint(int x, int y);                      // Haritaya nokta ekler
    void clearAll();                                  // Haritayý sýfýrlar
    void print();                                     // Haritayý konsola yazdýrýr
    void save(const std::string& fileName);           // Haritayý dosyaya kaydeder
    void load(const std::string& fileName);           // Haritayý dosyadan yükler
};

#endif // MAPPER_H