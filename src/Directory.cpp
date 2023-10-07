#include <iostream>
#include <memory>

#include "IFileSystemComponent.h"
#include "Directory.h"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

Directory::Directory(const std::string& name)
{
    this->name = name;
    std::time_t currentTime = std::time(nullptr);
    this->time_stamp = std::ctime(&currentTime);
    this->is_dir = true;
    this->super_directory = nullptr;
}

std::string Directory::get_name()
{
    return name;
}

std::string Directory::get_time_stamp()
{
    return time_stamp;
}

bool Directory::is_directory()
{
    return is_dir;
}

void Directory::add_file_system_component(std::shared_ptr<IFileSystemComponent> sub_dir)
{
    sub_directory.push_back(sub_dir);
    if (sub_dir->is_directory()) 
    {
        std::static_pointer_cast<Directory>(sub_dir)->super_directory = shared_from_this();
    }
}

bool Directory::remove_file_system_component(const std::string& sub_dir)
{
    auto iterator = sub_directory.begin();
    while (iterator != sub_directory.end())
    {
        if ((*iterator)->get_name() == sub_dir)
        {
            iterator = sub_directory.erase(iterator);
            return true;
        }
        else
        {
            iterator++;
        }
    }
    return false;
}

std::shared_ptr<Directory> Directory::find_directory(const std::string& name)
{
    for (const auto& component : sub_directory)
    {
        if (component->is_directory() && component->get_name() == name)
        {
            return std::static_pointer_cast<Directory>(component);
        }
    }
    return nullptr;
}

std::shared_ptr<IFile> Directory::find_file(const std::string& name)
{
    for (const auto& component : sub_directory)
    {
        if (!component->is_directory() && component->get_name() == name)
        {
            return std::static_pointer_cast<IFile>(component);
        }
    }
    return nullptr;
}

void Directory::list_contents(const std::string& flag)
{
    for (const auto& component : sub_directory)
    {
        if(component->is_directory())
        {
            std::cout << GREEN_TEXT << component->get_name() << RESET_TEXT;
        }
        else
        {
            std::cout << RED_TEXT << component->get_name() << RESET_TEXT;
        }
        if(flag == "-t")
        {
            std::cout << ": " << component->get_time_stamp();
        }
        std::cout << std::endl;
    }
}

std::shared_ptr<Directory> Directory::get_super_directory() 
{
    return super_directory;
}

std::vector<std::shared_ptr<IFileSystemComponent>>& Directory::get_sub_directory() 
{
    return sub_directory;
}