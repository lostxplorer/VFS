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
};

#endif