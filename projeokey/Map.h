#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>

class MAP {
private:
    std::vector<std::vector<int>> grid; // 2D harita gridi
    int numberX;                        // Griddeki X eksenindeki hücre sayýsý
    int numberY;                        // Griddeki Y eksenindeki hücre sayýsý
    double gridSize;                    // Bir hücrenin boyutu (ör: 1x1 birim)
    std::string fileName;               // Kaydetme ve yükleme için dosya adý

public:
    MAP(int x = 10, int y = 10, double size = 1.0);

    void insertPoint(int x, int y);                     // Haritaya bir nokta ekler
    void setGridIndex(int x, int y, int value);         // Belirli bir hücreye deðer atar
    int getGridIndex(int x, int y) const;               // Belirli bir hücrenin deðerini alýr
    void clearMap();                                    // Haritayý sýfýrlar
    void printToConsole() const;                        // Haritayý konsola yazdýrýr
    bool saveToFile(const std::string& name);           // Haritayý bir dosyaya kaydeder
    bool loadFromFile(const std::string& name);         // Haritayý bir dosyadan yükler

    // Getter ve Setter fonksiyonlarý
    int getNumberX() const;
    int getNumberY() const;
    double getGridSize() const;
    void setGridSize(int x, int y, double size);

    friend std::ostream& operator<<(std::ostream& os, const MAP& map); // Haritayý yazdýrmak için
};

#endif // MAP_H