#ifndef FILE_SYSTEM_COMPONENT_H
#define FILE_SYSTEM_COMPONENT_H

#include <string>
#include <vector>
#include <ctime>

class IFileSystemComponent 
{
protected:
    std::string name;
    std::string time_stamp;
    bool is_dir;
public:
    virtual std::string get_name() = 0;
    virtual std::string get_time_stamp() = 0;
    virtual bool is_directory() = 0;
};

#endif