#ifndef COMMAND_LINE_PARSER_HH
#define COMMAND_LINE_PARSER_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>


class CommandLineParser {

public:
    
    CommandLineParser(int argc, char** argv);
    
    bool isHelpRequested() const;
    
    std::string getOption(const std::string& option) const;

    void printHelp() const;

    bool isValidFilterType(const std::string& type) const;

    bool isValidOutput(const std::string& path) const;
    
    std::map<std::string, std::string> args_;
    std::vector<std::string> positionalArguments_;


private:
    
    void parse(int argc, char** argv);


};



#endif