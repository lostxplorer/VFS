#include <sstream>
#include <iostream>

#include "Parser.h"

void Parser::parse(std::string command)
{
    std::istringstream token(command);
    std::string word;
    while (token >> word)
    {
        std::string parsed_word;        
        for (char c : word)
        {
            if (c != '\\')
            {
                parsed_word += c;
            }
        }
        input_commands.emplace_back(parsed_word);
    }
}


std::vector<std::string> Parser::get_input_commands()
{
    return input_commands;
}

std::vector<std::string> Parser::split_path(const std::string& path)
{
    std::vector<std::string> directories;
    std::istringstream token(path);
    std::string directory;

    while (std::getline(token, directory, '/'))
    {
        if (!directory.empty())
        {
            directories.emplace_back(directory);
        }
    }
    return directories;
}
