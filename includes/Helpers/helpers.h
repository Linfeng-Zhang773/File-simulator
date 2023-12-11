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
inline int ReturnStringAsInt(std::string s)
{

    if (s == "Directory_1")
    {
        return 1;
    }
    else if (s == "Directory_2")
    {
        return 2;
    }
    else if (s == "Directory_3")
    {
        return 3;
    }
    else if (s == "Directory_4")
    {
        return 4;
    }
    else if (s == "Directory_5")
    {
        return 5;
    }
    else if (s == "Directory_6")
    {
        return 6;
    }
    else
    {
        return -1;
    }
}
inline std::vector<std::string> SortFileInfo(std::vector<std::string> v)
{
    // empty Directory_1 true
    // Directory_1 file_1 false
    // Directory_1 file_2 false
    // Directory_1 Directory_2 true
    // Directory_2 file_99 false
    // Directory_2 file_4 false
    // Directory_2 file_5 false
    // Directory_1 file_6 false
    // Directory_2 Directory_3 true

    // Directory_3 file_7 false
    int n = v.size();
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 1; j < n - i - 1; ++j)
        {
            // std::cout <<ReturnStringAsInt(v[j].substr(12, 11));
            int a = ReturnStringAsInt(v[j].substr(0, 11));
            int b = ReturnStringAsInt(v[j + 1].substr(0, 11));
            int c = ReturnStringAsInt(v[j].substr(12, 11));
            int d = ReturnStringAsInt(v[j + 1].substr(12, 11));
            // std::cout << "Directory: " << v[j].substr(0, 11) << " NextIndex Directory: " << v[j + 1].substr(0, 11) << "!" << std::endl;
            // std::cout << "sub string is: " << v[j].substr(12, 11) << " next sub String is: " << v[j + 1].substr(12, 11) << "!" << std::endl;
            if (a > b)
            {
                std::swap(v[j], v[j + 1]);
            }
            else if ((a == b) && (c > d))
            {
                std::swap(v[j], v[j + 1]);
            }

            // if ()
            // {

            //     std::cout << "Swaped" << std::endl;
            //     std::swap(v[j], v[j + 1]);
            // }
        }
    }
    return v;
}
// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - i - 1; ++j) {
//             if (arr[j] > arr[j + 1]) {
//                 std::swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

#endif