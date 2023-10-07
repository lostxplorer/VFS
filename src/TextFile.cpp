#include <memory>
#include "TextFile.h"

TextFile::TextFile(const std::string& name)
{
    this->name = name;
    std::time_t currentTime = std::time(nullptr);
    this->time_stamp = std::ctime(&currentTime);
}

std::string TextFile::get_name()
{
    return name;
}

std::string TextFile::get_time_stamp()
{
    return time_stamp;
}

bool TextFile::is_directory()
{
    return false;
}