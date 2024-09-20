#pragma once

#include "Block.hpp"

namespace PFSWireGuardGeneratorCore
{
    class FileIO
    {
        public:
            static std::string getTextFromFile(const char* file_name);
            static void writeBlockToFile(const char* file_name, Block& block);

            static void createFile(std::string file_name, std::string path = "");

        private:
    };
}
