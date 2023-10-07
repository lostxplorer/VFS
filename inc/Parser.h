#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser
{
private:
    std::vector<std::string> input_commands;

public:
    void parse(std::string input_commands);
    std::vector<std::string> get_input_commands();
    std::vector<std::string> split_path(const std::string& path);
};

#endif