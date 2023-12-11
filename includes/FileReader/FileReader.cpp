#include "FileReader.h"

std::vector<std::string> FileReader::ReadMetaData(std::string filepath)
{

    std::ifstream inputFile(filepath);
    if (!inputFile.is_open())
    {
        std::cout << "File Open Failed" << std::endl;
        return std::vector<std::string>();
    }
    std::vector<std::string> v;
    std::string Eachline;
    while (std::getline(inputFile, Eachline))
    {
        v.push_back(Eachline);
    }

    inputFile.close();

    return v;
}
void FileReader::WriteMetaData(std::vector<std::string> metaData, std::string filepath)
{
    std::fstream outputFile(filepath, std::ios::out);
    if (!outputFile.is_open())
    {
        std::cout << "File Open Failed" << std::endl;
        return;
    }
    for (int i = 0; i < metaData.size(); ++i)
    {
        outputFile << metaData[i] << std::endl;
    }

    outputFile.close();
}
std::string FileReader::ReadFile(std::string filepath)
{
    std::ifstream inputFile(filepath);
    if (!inputFile.is_open())
    {
        std::cout << "File Open Failed" << std::endl;
        return "error";
        // Return an error code
    }

    std::string Eachline;
    std::string content;
    while (std::getline(inputFile, Eachline))
    {
        content += Eachline;
    }

    inputFile.close();

    return content;
}
void FileReader::ModifyFile(std::string changes, std::string filepath)
{
    std::fstream outputFile(filepath, std::ios::out);
    if (!outputFile.is_open())
    {
        std::cerr << "File Open Failed" << std::endl;
        return;
    }

    outputFile << changes << std::endl;

    outputFile.close();
}

std::vector<std::string> FileReader::ReadInfoFile(std::string filepath)
{
    std::ifstream inputFile(filepath);
    if (!inputFile.is_open())
    {
        std::cout << "File Open Failed" << std::endl;
        return std::vector<std::string>();
    }
    std::vector<std::string> v;
    std::string Eachline;
    while (std::getline(inputFile, Eachline))
    {
        // std::cout << Eachline << std::endl;
        v.push_back(Eachline);
    }

    inputFile.close();

    return v;
}
void FileReader::ModifyInfoFile(std::vector<std::string> FileInfo, std::string filepath)
{
    std::fstream outputFile(filepath, std::ios::out);
    if (!outputFile.is_open())
    {
        std::cout << "File Open Failed" << std::endl;
        exit(1);
    }
    for (int i = 0; i < FileInfo.size(); ++i)
    {
        outputFile << FileInfo[i] << std::endl;
    }

    outputFile.close();
}

void FileReader::createNewFile(std::string filepath)
{
    std::fstream outputFile(filepath, std::ios::out);
    if (!outputFile.is_open())
    {
        std::cerr << "File Open Failed" << std::endl;
        exit(1);
    }
    outputFile.close();
}