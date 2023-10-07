#ifndef BINARY_FILE_H
#define BINARY_FILE_H

#include "IFile.h"

class BinaryFile: public IFile
{
public:
    BinaryFile(const std::string& name);
    std::string get_name() override;
    std::string get_time_stamp() override;
    bool is_directory() override;
};

#endif