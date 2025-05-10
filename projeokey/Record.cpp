#include "Record.h"
#include <iostream>

Record::Record() {}

Record::~Record() {
    if (file.is_open()) {
        file.close();
    }
}

void Record::setFileName(const std::string& name) {
    fileName = name;
}

void Record::openFile(std::ios::openmode mode) {
    file.open(fileName, mode);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

void Record::closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

std::string Record::readLine() {
    std::string line;
    if (file.is_open() && std::getline(file, line)) {
        return line;
    }
    return "";
}

void Record::writeLine(const std::string& line) {
    if (file.is_open()) {
        file << line << '\n';
    }
}

std::ostream& operator<<(std::ostream& os, const Record& record) {
    os << "File: " << record.fileName;
    return os;
}

std::istream& operator>>(std::istream& is, Record& record) {
    is >> record.fileName;
    return is;
}