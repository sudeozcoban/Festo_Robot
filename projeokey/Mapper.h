#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"

class Mapper {
private:
    MAP map; // MAP s�n�f�n�n bir �rne�i

public:
    Mapper(int x, int y, double gridSize);

    void addPoint(int x, int y);                      // Haritaya nokta ekler
    void clearAll();                                  // Haritay� s�f�rlar
    void print();                                     // Haritay� konsola yazd�r�r
    void save(const std::string& fileName);           // Haritay� dosyaya kaydeder
    void load(const std::string& fileName);           // Haritay� dosyadan y�kler
};

#endif // MAPPER_H