#ifndef FILE_H
#define FILE_H

#include "IFileSystemComponent.h"

class IFile : public IFileSystemComponent 
{
protected:
    std::string name;
    std::string time_stamp;
public:
    virtual std::string get_name() override = 0;
    virtual std::string get_time_stamp() override = 0;
    virtual bool is_directory() override = 0;
};

#endif