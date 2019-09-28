#include "../headers/tools.h"

#include <string>
#include <fstream>
#include <sstream>

namespace tools
{
void readFile(std::string filePath, std::string &output)
{
    std::ifstream file(filePath);

    if (file)
    {
        // extract the string from the file
        std::stringstream stream;
        stream << file.rdbuf();

        // save it in outputString-
        output = stream.str();
    }
    else
    {
        // error
        throw new std::runtime_error("Unable to read the file \"" + filePath + "\".");
    }

    file.close();
}
} // namespace tools