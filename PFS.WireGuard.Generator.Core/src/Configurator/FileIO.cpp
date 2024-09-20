#include "Configurator/FileIO.hpp"

#include <fstream>
#include <iostream>
#include <filesystem>

namespace PFSWireGuardGeneratorCore
{
    std::string FileIO::getTextFromFile(const char* file_name)
    {
        std::ifstream in(file_name, std::ios::binary);

        if (in.is_open())
        {
            std::string text;
            in.seekg(0, std::ios::end);
            text.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&text[0], text.size());
            in.close();
            return text;
        }
        else
        {
            std::cerr << "FILE READ ERROR! Could not open file: " << file_name << std::endl;
            throw std::ios_base::failure("Failed to open file: " + std::string(file_name));
        }
    }

    void FileIO::writeBlockToFile(const char* file_name, Block& block)
    {
        if (!std::filesystem::exists(file_name))
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

    void FileIO::createFile(std::string file_name, std::string path)
    {
        std::ofstream out(path + file_name, std::ios::out);
        out.close();
    }
}
