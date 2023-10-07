#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "IFileSystemComponent.h"
#include "IFile.h"

class Directory : public IFileSystemComponent, public std::enable_shared_from_this<Directory>
{
private:
    std::vector<std::shared_ptr<IFileSystemComponent>> sub_directory;
    std::shared_ptr<Directory> super_directory;
public:
    Directory(const std::string& name);
    std::string get_name() override;
    std::string get_time_stamp() override;
    bool is_directory() override;
    void add_file_system_component(std::shared_ptr<IFileSystemComponent> sub_dir);
    bool remove_file_system_component(const std::string& sub_dir);
    std::shared_ptr<Directory> find_directory(const std::string& name);
    std::shared_ptr<IFile> find_file(const std::string& name);
    void list_contents(const std::string& flag);
    std::shared_ptr<Directory> get_super_directory();
    std::vector<std::shared_ptr<IFileSystemComponent>>& get_sub_directory();
};

#endif