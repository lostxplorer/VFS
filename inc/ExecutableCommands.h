#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include <memory>
#include <stack>
#include <string>

#include "IFileSystemComponent.h"
#include "Directory.h"
#include "FileSystemManager.h"

class ExecutableCommands: public FileSystemManager
{
public:
    ExecutableCommands();
    void mkdir(const std::string& directory_name);
    bool rmdir(const std::string& directory_name);
    std::string& pwd();
    bool cd(const std::string& directory_name);
    void ls(const std::string& flag);
    bool touch(const std::string& file_name);
    bool rm(const std::string& file_name);
    bool find(const std::string& name);
    std::string find_by_time(const std::string& time);
    std::shared_ptr<Directory> get_current_directory();
};

#endif