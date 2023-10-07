#include <iostream>
#include <memory>

#include "ExecutableCommands.h"
#include "Directory.h"
#include "TextFile.h"

ExecutableCommands::ExecutableCommands()
{
    root = std::make_shared<Directory>("/");
    current_directory = root;
    current_path = "/";
}

void ExecutableCommands::mkdir(const std::string& directory_name)
{
    auto new_directory = std::make_shared<Directory>(directory_name);
    current_directory->add_file_system_component(new_directory);
}

bool ExecutableCommands::rmdir(const std::string& directory_name)
{
    bool is_removed = current_directory->remove_file_system_component(directory_name);
    return is_removed;
}

std::string& ExecutableCommands::pwd()
{
    return current_path;
}

bool ExecutableCommands::cd(const std::string& directory_name) 
{
    bool directory_found = true;
    if (directory_name == "..") 
    { 
        if (current_directory != root) 
        {
            current_directory = current_directory->get_super_directory();
            size_t lastSlashPos = current_path.find_last_of('/');
            if (lastSlashPos != std::string::npos)
            {
                current_path = current_path.substr(0, lastSlashPos);
                if(current_directory == root)
                {
                    current_path = "/";
                }
            }
        }
    }
    else if(directory_name == "/")
    {
        current_directory = root;
        current_path = "/";
    }
    else
    {
        auto target = current_directory->find_directory(directory_name);
        if (target)
        {
            current_directory = target;
            if (current_path == "/") 
            {
                current_path += directory_name;
            }
            else
            {
                current_path += "/" + directory_name;
            }
        }
        else
        {
            directory_found = false;
        }
    }
    return directory_found;
}

void ExecutableCommands::ls(const std::string& flag) 
{
    current_directory->list_contents(flag);
}

bool ExecutableCommands::touch(const std::string& file_name)
{
    bool is_file_created = false;
    if (current_directory->find_file(file_name) == nullptr)
    {
        auto new_file = std::make_shared<TextFile>(file_name);
        current_directory->add_file_system_component(new_file);
        is_file_created = true;
    }
    return is_file_created;
}

bool ExecutableCommands::find(const std::string& name)
{
    bool found = false;
    for(auto& cur : current_directory->get_sub_directory())
    {
        if(name == cur->get_name())
        {
            found = true;
            break;
        }
        else
        {
            found = false;
        }
    }
    return found;
}

std::string ExecutableCommands::find_by_time(const std::string& time)
{
    std::string found_component_name = " ";
    for(auto& cur : current_directory->get_sub_directory())
    {
        std::string clean_time = time;
        std::string clean_cur_time = cur->get_time_stamp();
        clean_time.erase(clean_time.find_last_not_of(" \n\r\t") + 1);
        clean_cur_time.erase(clean_cur_time.find_last_not_of(" \n\r\t") + 1);        
        if(clean_time == clean_cur_time)
        {
            found_component_name = cur->get_name();
            break;
        }
    }
    return found_component_name;
}
std::shared_ptr<Directory> ExecutableCommands::get_current_directory()
{
    return current_directory;
}

bool ExecutableCommands::rm(const std::string& file_name) 
{
    bool is_file_removed = false;
    auto file = current_directory->find_file(file_name);
    if (file) 
    {
        if(current_directory->remove_file_system_component(file_name))
        {
            is_file_removed = true;
        }
    }
    return is_file_removed;
}