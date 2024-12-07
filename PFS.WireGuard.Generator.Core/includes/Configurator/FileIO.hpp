#pragma once

#include "Block.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API FileIO
    {
        public:
            static std::string getTextFromFile(const char* file_name, std::string path = "");
            static void writeBlockToFile( Block& block, const char* file_name, std::string path = "");

            static bool createFile(const std::string& file_name, std::string path = "");
            static bool deleteFile(const std::string& file_name, std::string path = "");
            static bool renameClientFile(const std::string& old_name, const std::string& new_name, const std::string& path = "");
        private:
    };
}
