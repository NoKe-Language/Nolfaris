#include "../headers/error.h"

#include "../headers/tools.hpp"
#include "../headers/nobject.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "../standalone_libs/json.hpp"

using json = nlohmann::json;

namespace nolfaris
{

json _getJson()
{
#ifdef ERRORS_JSON
    // get the error json
    // since the program crashes after the error is throw,
    // we can fetch the json directly in this function
    std::string str;
    tools::readFile(ERRORS_JSON, str);
    return json::parse(str);
#else
    throwError("Compiler internal error. Could not load the error json.");
#endif
}

void _generateBaseErrorInfo(std::stringstream &message, NObjectPosition const &position, std::string const &stack)
{
    message << "NoKe compiler has encountered an "
            << tools::colored("error", "red")
            << ".  (︶︿︶)"
            << std::endl;

    if (stack != "")
    {
        message << stack;
    }
    // if a position is given : display where the error is, the line and point the problematic char
    if (position.start >= 0)
    {
        const auto coords = tools::Coords::fromPosition(position.start, position.file);
        if (coords.line != 0 && position.file != "")
        {
            std::ifstream file(position.file);
            if (file)
            {
                std::string temp;
                // go to the line of the error
                for (int i = 0; i < coords.line - 1; i++)
                {
                    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                // get the line where the error is
                getline(file, temp);
                int delta = tools::customStrip(temp, ' ');
                // message += 'In File "%s" on line %d, column %d:\n-> %s' % (position.file, coords.line, coords.column, temp[0])
                //                                                               message += "  " + (coords.column - temp[1]) * " " + "^\n"
                message << "In File \""
                        << position.file
                        << "\" on line "
                        << coords.line
                        << ", column "
                        << coords.column
                        << ":\n-> "
                        << temp
                        << "  \n"
                        << "  "
                        << tools::multiplyString(" ", coords.column - delta)
                        << "^\n";
            }
            else
            {
                throwError("Could not open the file: \"" + position.file + "\"", "compiler_internal");
            }
        }
    }
}

void throwError(int const &id, NObjectPosition const &position, std::string const &stack)
{
    auto data = _getJson();
    std::stringstream message;

    _generateBaseErrorInfo(message, position, stack);

    // add the error info
    message << tools::colored((std::string)data["types"][(std::string)data["number"][std::to_string(id)]["type"]] + " " + (std::string)data["number"][std::to_string(id)]["content"], "yellow")
            << std::endl
            << std::endl;

    // throw
    std::cout << message.str() << std::endl;
    std::exit(1); //meta break with exit code 1 (error)
}

void throwError(std::string const &msg, std::string const &errorType, NObjectPosition const &position, std::string const &stack)
{
    std::stringstream message;

    _generateBaseErrorInfo(message, position, stack);

    // add the error info

    std::string errorDescription = "";

    if (errorType != "")
    {
        auto data = _getJson();
        if (data["types"].contains(errorType))
        {
            errorDescription += (std::string)data["types"][errorType] + " ";
        }
    }
    errorDescription += msg;

    message << tools::colored(errorDescription, "yellow")
            << std::endl
            << std::endl;

    // throw
    std::cout << message.str() << std::endl;
    std::exit(1); //meta break with exit code 1 (error)
}

} // namespace nolfaris