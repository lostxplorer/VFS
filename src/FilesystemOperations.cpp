#include "FilesystemOperations.h"

void mkdir(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands)
{
    if (input_commands.size() == 1) 
    {
        std::cout << "Usage: mkdir <directory_name>" << std::endl;
    }
    for (size_t index = 1; index < input_commands.size(); index++)
    {
        std::vector<std::string> directories = parser.split_path(input_commands[index]);
        bool cd_success = true;
        size_t subdir_index = 0;
        for (subdir_index = 0; subdir_index < directories.size() - 1; subdir_index++)
        {
            if(!command.cd(directories[subdir_index]))
            {
                cd_success = false;
                std::cout << "Error: " << directories[subdir_index] << " directory not found." << std::endl;
                break;
            }
        }
        if(cd_success)
        {
            if (command.find(directories.back()))
            {
                std::cout << "File " << directories.back() << " already exist" << std::endl;
            }
            
            command.mkdir(directories.back());
        }
        for (size_t super_directory = subdir_index; super_directory > 0; super_directory--)
        {
            command.cd("..");
        }
    }
}

void rmdir(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands)
{
    if (input_commands.size() == 1) 
    {
        std::cout << "Usage: rmdir <directory_name>" << std::endl;
    }
    else
    {
        for (size_t index = 1; index < input_commands.size(); index++)
        {
            std::vector<std::string> directories = parser.split_path(input_commands[index]);
            if (directories.empty())
            {
                command.rmdir(input_commands[index]);
            }
            else
            {
                for (size_t subdir_index = 0; subdir_index < directories.size() - 1; subdir_index++)
                {
                    command.cd(directories[subdir_index]);
                }
                auto lastDirectory = command.get_current_directory()->find_directory(directories.back());

                if (lastDirectory)
                {
                    if (lastDirectory->get_sub_directory().empty())
                    {
                        if(command.rmdir(directories.back()))
                        {
                            std::cout << "Removed directory '" << directories.back() << "'." << std::endl;
                        } 
                        else 
                        {
                            std::cout << "Error: Directory '" << directories.back() << "' not found." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Error: Directory '" << directories.back() << "' is not empty." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Error: Directory '" << directories.back() << "' not found." << std::endl;
                }
            }
            command.cd("..");
        }
    }
}

void touch(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands)
{
    if (input_commands.size() == 1) 
    {
        std::cout << "Usage: mkdir <directory_name>" << std::endl;
    }
    for (size_t index = 1; index < input_commands.size(); index++)
    {
        std::vector<std::string> directories = parser.split_path(input_commands[index]);
        bool cd_success = true;
        size_t subdir_index = 0;
        for (subdir_index = 0; subdir_index < directories.size() - 1; subdir_index++)
        {
            if(!command.cd(directories[subdir_index]))
            {
                cd_success = false;
                std::cout << "Error: " << directories[subdir_index] << " directory not found." << std::endl;
                break;
            }
        }
        if(cd_success)
        {
            if (command.find(directories.back()))
            {
                std::cout << "File " << directories.back() << " already exist" << std::endl;
            }
            
            command.touch(directories.back());
        }
        for (size_t super_directory = subdir_index; super_directory > 0; super_directory--)
        {
            command.cd("..");
        }
    }
}

void rm(ExecutableCommands& command, const std::vector<std::string>& input_commands)
{
    if (input_commands.size() == 1) 
    {
        std::cout << "Usage: rm <file_name>" << std::endl;
    }
    else
    {
        for (size_t index = 1; index < input_commands.size(); index++)
        {
            if(command.rm(input_commands[index]))
            {
                std::cout << "file '" << input_commands[index] << "' is removed." << std::endl;
            }
            else
            {
                std::cout << "Error: file '" << input_commands[index] << "' is not present." << std::endl;
            }
        }
    }
}

void cd(ExecutableCommands& command, Parser& parser, const std::vector<std::string>& input_commands)
{
    if (input_commands.size() == 1) 
    {
        command.cd("/");
    }
    else
    {
        std::vector<std::string> directories = parser.split_path(input_commands[1]);
        for (size_t index = 0; index < directories.size(); index++)
        {
            if(!command.cd(directories[index]))
            {
                std::cout << "Error: Directory '" << directories[index] << "' is not found" << std::endl;
            }
        }
    }
}

void ls(ExecutableCommands& command, const std::vector<std::string>& input_commands)
{
    if(input_commands.back() == "-t")
    {
        command.ls("-t");
    }
    else
    {
        command.ls(" ");
    }
}

void find(ExecutableCommands& command, const std::vector<std::string>& input_commands)
{
    if (input_commands.size() == 1) 
    {
        std::cout << "Usage: find <directory_name or filename>" << std::endl;
    }
    else
    {
        for (size_t index = 1; index < input_commands.size(); index++)
        {
            if(command.find(input_commands[index]))
            {
                std::cout << input_commands[index] << " found." << std::endl;
            }
            else
            {
                std::cout << input_commands[index] << " not found." << std::endl;
            }
        }
    }
}

void find_by_time(ExecutableCommands& command, const std::vector<std::string>& input_commands)
{
    if (input_commands.size() == 1) 
    {
        std::cout << "Usage: find <time>" << std::endl;
    }
    else
    {
        std::string input_time;
        for (size_t index = 1; index < input_commands.size(); index++)
        {
            input_time += input_commands[index] + " ";
            if(index == 2)
            {
                input_time += " ";
            } 
        }
        std::string found_component = command.find_by_time(input_time);
        if(found_component == " ")
        {
            std::cout << "Error: no file/directory created at the given time." << std::endl;
        }
        else
        {
            std::cout << found_component << " found which is created at the given time." << std::endl;
        }
    }
}