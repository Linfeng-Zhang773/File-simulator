#include "BuildFileTree.h"
FileTree BuildFileTree::Filetree;

void BuildFileTree::setUp(std::string filepath)
{
    BuildFileTree::Filetree.reset();
    FileReader Reader;
    std::vector<std::string> theFileInfo = Reader.ReadInfoFile(filepath);
    for (int i = 0; i < theFileInfo.size(); ++i)
    {
        std::vector<std::string> s = extractStrings(theFileInfo[i]);
        if (s[2] == "true")
        {
            BuildFileTree::Filetree.push(s[0], s[1], true);

            // std::cout << s[2] << std::endl;
        }
        else
        {
            BuildFileTree::Filetree.push(s[0], s[1], false);
            // std::cout << s[2] << std::endl;
        }
    }
}

FileTree& BuildFileTree::getFileTree()
{
    return BuildFileTree::Filetree;
}