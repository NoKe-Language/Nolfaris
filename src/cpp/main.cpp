#include <iostream>
#include "../headers/tools.hpp"
#include "../headers/error.h"

int main()
{
    // load json
#ifdef GRAMMAR_JSON
    std::string rules;
    tools::readFile(GRAMMAR_JSON, rules);
    std::cout << rules << std::endl;


    nolfaris::throwError(0, nolfaris::NObjectPosition(678, GRAMMAR_JSON));
#else
    throw std::runtime_error("Could not load the grammar rules.");
#endif 

    // rapidjson::Document document;
    // document.Parse(json);

    // rapidjson::Value& s = document["project"];

    // std::cout << s.GetString() << std::endl;

    std::cout << std::endl
              << "---"
              << std::endl;
    return 0;
}
