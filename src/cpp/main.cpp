#include <iostream>
#include "../headers/tools.h"

int main()
{
    // load json
#ifdef GRAMMAR_JSON
    std::string rules;
    tools::readFile(GRAMMAR_JSON, rules);
    std::cout << rules << std::endl;
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
