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

inline std::vector<std::string> extractStrings(const std::string& str)
{
    std::vector<std::string> res;
    std::string concat = "";
    for (const auto& s : str)
    {
        if (s == ' ')
        {
            res.push_back(concat);
            concat = "";
            continue;
        }
        concat += s;
    }
    // std::string withoutBar = "";
    // for(int i = 0; i < concat.length(); ++i)
    // {
    //     if(i == concat.length() - 2) continue;
    //     withoutBar += concat[i];
    // }
    res.push_back(concat);
    return res;
}

inline std::string reverse(const std::string& str)
{
    std::string newStr;
    for (int i = str.length() - 1; i >= 0; --i)
    {

        newStr += str[i];
    }
    return newStr;
}
inline std::string extractFileName(const std::string& str)
{
    std::string newStr;
    for (int i = str.length() - 1; i >= 0; --i)
    {
        if (str[i] != '/')
        {
            newStr += str[i];
        }
        else
        {
            break;
        }
    }

    return reverse(newStr);
}
#endif