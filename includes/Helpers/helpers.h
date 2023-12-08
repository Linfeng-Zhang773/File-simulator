#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

inline std::vector<std::string> extractWords(const std::string& input)
{
    std::vector<std::string> result;
    std::string currentWord;
    std::istringstream iss(input);

    while (iss >> currentWord)
    {
        if (currentWord.find("int") == 0)
        {
            result.push_back("int");
        }
        else if (currentWord.find("char") == 0)
        {
            result.push_back("char");
        }
        else if (currentWord.find("float") == 0)
        {
            result.push_back("float");
        }
        else if (currentWord.find("double") == 0)
        {
            result.push_back("double");
        }
        else
        {
            for (char c : currentWord)
            {
                result.push_back(std::string(1, c));
            }
        }

        if (!iss.eof())
        {
            result.push_back(" "); // Preserve spaces between words
        }
    }

    return result;
}
#endif