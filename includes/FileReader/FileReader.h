#ifndef FILEREADER
#define FILEREADER
#include <fstream>
#include <iostream>

#include <string>
#include <vector>
class FileReader
{
    // private:
    // std::ifstream inputFile;
    // std::string line; // read line by line
    // std::ofstream outputFile;

public:
    FileReader() = default;
    std::vector<std::string> ReadMetaData(std::string filepath);
    void WriteMetaData(std::vector<std::string> metaData, std::string filepath);
    std::string ReadFile(std::string filepath);
    void ModifyFile(std::string changes, std::string filepath);
    //for reading the info about files to build a tree
    std::vector<std::string> ReadInfoFile(std::string filepath);
    void ModifyInfoFile(std::vector<std::string> FileInfo, std::string filepath);
};

#endif