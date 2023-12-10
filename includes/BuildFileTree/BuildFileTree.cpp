#include "BuildFileTree.h"

BuildFileTree::BuildFileTree(std::string filepath)
{
    FileReader Reader;
    std::vector<std::string> theFileInfo = Reader.ReadInfoFile(filepath);
    for (int i = 0; i < theFileInfo.size(); ++i)
    {
        std::vector<std::string> s = extractStrings(theFileInfo[i]);
        if (s[2] == "true")
        {
            this->Filetree.push(s[0], s[1], true);

            // std::cout << s[2] << std::endl;
        }
        else
        {
            this->Filetree.push(s[0], s[1], false);
            // std::cout << s[2] << std::endl;
        }
    }
}

FileTree& BuildFileTree::getFileTree()
{
    return this->Filetree;
}