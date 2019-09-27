#include <iostream>
#include <stdio.h>
#include <boost/xpressive/xpressive.hpp>

using namespace boost;
using namespace xpressive;

void test(void){
    std::cout << "hello from another function";
}

int main(int argc, const char * argv[]) {
    int bob = 0;
    
    std::string str("tweet");
    xpressive::sregex rx = sregex::compile("(?P<char>.)(?P=char)");
    smatch what;
    if(regex_search(str, what, rx))
    {
        std::cout << "char = " << what["char"] << std::endl;
    }
    

    return 0;
}

