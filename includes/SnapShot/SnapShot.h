#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include <string>

class SnapShot
{
private:
public:
    std::string data;
    SnapShot();
    SnapShot(std::string theData);
    ~SnapShot() = default;
};
#endif