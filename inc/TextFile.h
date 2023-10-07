#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include <IFile.h>

class TextFile: public IFile
{
public:
    TextFile(const std::string& name);
    std::string get_name() override;
    std::string get_time_stamp() override;
    bool is_directory() override;
};

#endif