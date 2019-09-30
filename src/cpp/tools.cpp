#include "../headers/tools.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void tools::readFile(std::string filePath, std::string &output)
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

/// Compute the line and column of the given position in the given file.
/// It will throw a runtime error if the file doesn't exist, or if the position
tools::Coords tools::Coords::fromPosition(int position, std::string filePath)
{
    std::string str;
    tools::readFile(filePath, str);

    // if the position is valid
    if (position >= 0 && str.length() > position)
    {
        int lineCounter = 1;
        int columnCounter = 1;

        for (int i = 0; i < position; i++)
        {
            if (str[i] == '\n')
            {
                lineCounter++;
                columnCounter = 1;
            }
            else
            {
                columnCounter++;
            }
        }

        std::cout << Coords(lineCounter, columnCounter, position).toString()
                  << std::endl;

        return Coords(lineCounter, columnCounter, position);
    }
    else
    {
        throw std::runtime_error("[internal] The given position is invalid: " + std::to_string(position) + " in file \"" + filePath + "\"");
    }
}

std::string tools::colored(std::string const& str, std::string const& color){
    if (color == "yellow"){
        return "\e[33m" + str + "\e[m";
    }
    else{
        return str;
    }
}

std::string tools::strip(std::string const &str, char c){
    std::string finalStr = "";
    while (str.length() > 0 && str[0] == c)
    {
        finalStr = str.substr(1);
         //count the number of char removed at the beginning
    }
    // end
    while (str.length() > 0 && str[str.length() - 1] == c)
    {
        finalStr = str.substr(0, str.length() - 1);
    }
    return finalStr;
}

int tools::customStrip(std::string &str, char c)
{
    int delta = 0;
    // beginning
    while (str.length() > 0 && str[0] == c)
    {
        str = str.substr(1);
        delta++; //count the number of char removed at the beginning
    }
    // end
    while (str.length() > 0 && str[str.length() - 1] == c)
    {
        str = str.substr(0, str.length() - 1);
    }
    // return the number of char removed at the beginning
    return delta;
}

std::string tools::multiplyString(std::string const &str, int factor)
{
    std::string outputStr = "";
    for (int i = 0; i < factor; i++){
        outputStr += str;
    }
    return outputStr;
}

const std::string tools::Coords::toString()
{
    return "(Ln " + std::to_string(this->line) + ", Col " + std::to_string(this->column) + ")";
}

std::ostream &operator<<(std::ostream &stream, tools::Coords &c)
{
    return stream << c.toString();
}