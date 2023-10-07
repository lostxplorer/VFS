#ifndef FILE_SYSTEM_MANAGER_H
#define FILE_SYSTEM_MANAGER_H

#include <iostream>
#include <memory>

#include "Directory.h"

class FileSystemManager
{
protected:
    std::string current_path;
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> current_directory;

    // virtual void mkdir(const std::string& directory_name) = 0;
    // virtual bool rmdir(const std::string& directory_name) = 0;
    // virtual std::string& pwd() = 0;
    // virtual bool cd(const std::string& directory_name) = 0;
    // virtual void ls(const std::string& flag) = 0;
    // virtual bool touch(const std::string& file_name) = 0;
    // virtual bool rm(const std::string& file_name) = 0;
    virtual bool find(const std::string& name) = 0;
    // virtual std::string find_by_time(const std::string& time) = 0;
    // virtual std::shared_ptr<Directory> get_current_directory() = 0;
};

#endif