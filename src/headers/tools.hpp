#ifndef TOOLS_HPP_INCLUDED
#define TOOLS_HPP_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

namespace tools
{

extern bool VERBOSE;

void readFile(std::string filePath, std::string &output);

void logl(std::string const& str);

void log(std::string const& str);

std::string colored(std::string const& str, std::string const& color);

std::string strip(std::string const &str, char c);

int customStrip(std::string &str, char c);

std::string multiplyString(std::string const& str, int factor);

class Coords
{
public:
    int line;
    int column;
    int charCount;
    Coords(int line, int column, int charCount)
    {
        this->line = line;
        this->column = column;
        this->charCount = charCount;
    }
    static tools::Coords fromPosition(int position, std::string filePath);
    const std::string toString();
    friend std::ostream &operator<<(std::ostream &stream, Coords &c);
};

} // namespace tools

#endif