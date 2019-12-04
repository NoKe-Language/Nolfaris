#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include <string>
#include "nobject.hpp"

namespace nolfaris
{
void throwError(int const& id, NObjectPosition const& position = NObjectPosition(), std::string const& stack = "");

void throwError(std::string const& msg, std::string const& errorType = "", NObjectPosition const& position = NObjectPosition(), std::string const& stack = "");

} // namespace nolfaris

#endif