#include <fstream>
#include <iostream>
#include <filesystem>

#include "Configurator/FileIO.hpp"

namespace PFSWireGuardGeneratorCore
{
    std::string FileIO::getTextFromFile(const char* file_name, std::string path)
    {
        std::ifstream in(path + file_name, std::ios::binary);

        if (in.is_open())
        {
            std::string text;
            in.seekg(0, std::ios::end);
            text.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&text[0], text.size());
            in.close();

            size_t pos = text.find_last_not_of("\n\r");
            if (pos != std::string::npos)
                text.erase(pos + 1);
            else
                text.clear();

            return text;
        }
        else
        {
            std::cerr << "FILE READ ERROR! Could not open file: " << path + file_name << std::endl;
            throw std::ios_base::failure("Failed to open file: " + std::string(file_name));
        }
    }

    void FileIO::writeBlockToFile( Block& block, const char* file_name, std::string path)
    {
        if (!std::filesystem::exists(path + file_name))
        {
            std::cerr << "FILE WRITE ERROR! File does not exist: " << file_name << std::endl;
            throw std::ios_base::failure("File does not exist: " + std::string(file_name));
        }

        std::ofstream out(file_name, std::ios::app);

        if(out.is_open())
        {
            out << block.getAttributeToString() << std::endl;

            for (const auto& prop : block.getProps())
            {
                out << prop.first << prop.second << std::endl;
            }

            out << std::endl;
        }

        out.close();
    }

    bool FileIO::createFile(const std::string& file_name, std::string path)
    {
        std::ofstream out(path + file_name, std::ios::out);

        if (!out)
        {
            std::cerr << "Error: Unable to create file: " << path + file_name << std::endl;
            return false;
        }

        out.close();
        return true;
    }

    bool FileIO::deleteDirectory(const std::string& path)
    {
        if(!std::filesystem::exists(path))
        {
            std::cerr << "Error: Directory not found! Files not deleted.";
            return false;
        }

        std::filesystem::remove_all(path);
        return true;
    }

    bool FileIO::isFileExists(const std::string& file_name, std::string path)
    {
        return std::filesystem::exists(path + file_name);
    }

    bool FileIO::renameFile(const std::string& old_name, const std::string& new_name, const std::string& path)
    {
        if(std::rename((path + old_name).c_str(), (path + new_name).c_str()) == 0)
            return true;
        else
        {
            std::cout << "pATH to old_file_name -> " + path + old_name << std::endl;
            perror("Error: File is not renamed!" );
            return false;
        }
    }

    bool FileIO::renameDirectory(const std::string& old_name, const std::string& new_name, const std::string& path)
    {
        if(!std::filesystem::exists(path + old_name))
        {
            std::cerr << "Error: Directory not found! Files not deleted.";
            return false;
        }

        std::filesystem::rename(path + old_name, path + new_name);
        return true;
    }
}
