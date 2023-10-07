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
    virtual void mkdir(const std::string& directory_name);
    virtual bool rmdir(const std::string& directory_name);
    virtual std::string& pwd();
    virtual bool cd(const std::string& directory_name);
    virtual void ls(const std::string& flag);
    virtual bool touch(const std::string& file_name);
    virtual bool rm(const std::string& file_name);
    virtual bool find(const std::string& name);
    virtual std::string find_by_time(const std::string& time);
    virtual std::shared_ptr<Directory> get_current_directory();
};

#endif