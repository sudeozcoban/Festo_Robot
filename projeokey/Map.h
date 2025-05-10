#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>

class MAP {
private:
    std::vector<std::vector<int>> grid; // 2D harita gridi
    int numberX;                        // Griddeki X eksenindeki h�cre say�s�
    int numberY;                        // Griddeki Y eksenindeki h�cre say�s�
    double gridSize;                    // Bir h�crenin boyutu (�r: 1x1 birim)
    std::string fileName;               // Kaydetme ve y�kleme i�in dosya ad�

public:
    MAP(int x = 10, int y = 10, double size = 1.0);

    void insertPoint(int x, int y);                     // Haritaya bir nokta ekler
    void setGridIndex(int x, int y, int value);         // Belirli bir h�creye de�er atar
    int getGridIndex(int x, int y) const;               // Belirli bir h�crenin de�erini al�r
    void clearMap();                                    // Haritay� s�f�rlar
    void printToConsole() const;                        // Haritay� konsola yazd�r�r
    bool saveToFile(const std::string& name);           // Haritay� bir dosyaya kaydeder
    bool loadFromFile(const std::string& name);         // Haritay� bir dosyadan y�kler

    // Getter ve Setter fonksiyonlar�
    int getNumberX() const;
    int getNumberY() const;
    double getGridSize() const;
    void setGridSize(int x, int y, double size);

    friend std::ostream& operator<<(std::ostream& os, const MAP& map); // Haritay� yazd�rmak i�in
};

#endif // MAP_H