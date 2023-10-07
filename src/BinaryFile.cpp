#include "BinaryFile.h"

BinaryFile::BinaryFile(const std::string& name)
{
    this->name = name;
    std::time_t current_time = std::time(nullptr);
    this->time_stamp = std::ctime(&current_time);
}

std::string BinaryFile::get_name()
{
    return name;
}

std::string BinaryFile::get_time_stamp()
{
    return time_stamp;
}

bool BinaryFile::is_directory()
{
    return false;
}