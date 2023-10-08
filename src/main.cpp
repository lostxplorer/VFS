#include <iostream>
#include <memory>
#include <sstream>

#include "IFileSystemComponent.h"
#include "Parser.h" 
#include "ExecutableCommands.h"
#include "Directory.h"
#include "FilesystemOperations.h"

int main()
{
    std::string input;
    ExecutableCommands command;
    while (true)
    {
        std::cout << command.pwd() << "> ";
        std::getline(std::cin, input);

        Parser parser;
        parser.parse(input);
        const std::vector<std::string>& input_commands = parser.get_input_commands();

        if (input_commands.empty())
        {
            continue;
        }
        else if (input_commands[0] == "mkdir")
        {
            mkdir(command, parser, input_commands);
        }
        else if (input_commands[0] == "rmdir")
        {
            rmdir(command, parser, input_commands);
        }
        else if (input_commands[0] == "pwd")
        {
            std::cout << command.pwd() << std::endl;
        }
        else if (input_commands[0] == "ls")
        {
            ls(command, input_commands);
        }
        else if (input_commands[0] == "cd")
        {
            ascd(command, parser, input_commands);
        }
        else if (input_commands[0] == "touch")
        {
            touch(command, parser, input_commands);
        }
        else if (input_commands[0] == "rm")
        {
            rm(command, parser, input_commands);
        }
        else if (input_commands[0] == "find")
        {
            find(command, input_commands);
        }
        else if (input_commands[0] == "findbytime")
        {
            find_by_time(command, input_commands);
        }
        else if (input_commands[0] == "clear")
        {
            system("clear");
        }
        else if (input_commands[0] == "exit")
        {
            exit(0);
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
    }
    return 0;
}