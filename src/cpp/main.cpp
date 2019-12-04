#include <iostream>
#include "../headers/tools.hpp"
#include "../headers/error.hpp"
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/cmdline.hpp>
#include <fstream>

using namespace boost::program_options;

int main(int argc, char *argv[])
{
    // define the command line options
    options_description desc{"Options"};
    // clang-format off
    desc.add_options()
        ("compile,c", value<std::string>(), "Compile a file (arg: path of the file")
        ("help,h", "Help screen")
        ("verbose,v", bool_switch()->default_value(false), "Log compilation details");
    // clang-format on

    // scan the command line args to see if there are options
    variables_map vm;

    try
    {
        store(parse_command_line(argc, argv, desc), vm);
        // notify(vm);
    }
    catch (const error &ex)
    {
        std::string what = ex.what();
        nolfaris::throwError(what, "cli_error");
    }

    // interpret the results

    // show the help screen
    if (vm.count("help"))
    {
        std::cout << std::endl
                  << desc
                  << std::endl;
    }
    // compile the given file
    else if (vm.count("compile"))
    {
        if (vm["verbose"].as<bool>())
        {
            tools::VERBOSE = true;
        }
        else
        {
            tools::VERBOSE = false;
        }

        std::string fileName = vm["compile"].as<std::string>();
        // Compile the file 8-)

        std::stringstream source;

        std::fstream file(fileName);
        tools::logl("Opening \"" + fileName + "\"...");
        if (file)
        {
            tools::logl("File opened successfully.");
            source << file.rdbuf();

        }
        else
        {
            nolfaris::throwError("Could not find the file \"" + fileName + "\".", "compiler_internal");
        }
        file.close();

        // At this point, the source code is stored in "source"

        
    }
    else
    {
        std::cout << "Please provide options. Use --help for help."
                  << std::endl;
    }

    std::cout << "---"
              << std::endl;
    return 0;
}
