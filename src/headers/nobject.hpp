#ifndef NOBJECT_H_INCLUDED
#define NOBJECT_H_INCLUDED

#include <string>

namespace nolfaris
{
struct NObjectPosition
{
    int start;
    std::string file;
    NObjectPosition(int start = -1, std::string file  = "")
    {
        this->start = start;
        this->file = file;
    }
};
} // namespace nolfaris

#endif