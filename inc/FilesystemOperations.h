#ifndef NEW_H
#define NEW_H

#include <iostream>

#include "ExecutableCommands.h"
#include "Parser.h"

void mkdir(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands);
void rmdir(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands);
void touch(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands);
void ascd(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands);
void rm(ExecutableCommands& command, const std::vector<std::string>& input_commands);
void ls(ExecutableCommands& command, const std::vector<std::string>& input_commands);
void find(ExecutableCommands& command, const std::vector<std::string>& input_commands);
void find_by_time(ExecutableCommands& command, const std::vector<std::string>& input_commands);

#endif