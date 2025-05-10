#pragma once
#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>

class Record {
private:
    std::string fileName;
    std::fstream file;

public:
    Record();
    ~Record();

    void setFileName(const std::string& name);
    void openFile(std::ios::openmode mode);
    void closeFile();
    std::string readLine();
    void writeLine(const std::string& line);

    friend std::ostream& operator<<(std::ostream& os, const Record& record);
    friend std::istream& operator>>(std::istream& is, Record& record);
};

#endif // RECORD_H