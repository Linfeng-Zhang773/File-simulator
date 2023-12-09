#ifndef BUILDFILETREE_H
#define BUILDFILETREE_H
#include "../FileTree/FileTree.h"
#include "../Helpers/helpers.h"
#include "../fileReader/FileReader.h"
#include <string>
#include <vector>
class BuildFileTree
{
    // FileTree fileTree;
    // fileTree.push(" ", "Directory 1", true);
    // fileTree.push("Directory 1", "file 1", false);
    // // fileTree.push("222", "333", false); // still some bugs...===
    // fileTree.push("Directory 1", "file 2", false);
    // fileTree.push("Directory 1", "Directory 2", true);
    // fileTree.push("Directory 2", "file 3", false);
    // fileTree.push("Directory 2", "file 4", false);
    // fileTree.push("Directory 2", "file 5", false);
    // fileTree.push("Directory 2", "Directory 3", true);
    // fileTree.push("Directory 3", "file 6", false);
    // fileTree.push("Directory 3", "file 7", false);
private:
    FileTree Filetree;

public:
    BuildFileTree(std::string filepath);
    FileTree& getFileTree();
};

#endif