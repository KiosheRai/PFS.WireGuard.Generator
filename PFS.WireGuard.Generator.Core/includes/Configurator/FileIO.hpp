#pragma once

#include "Block.hpp"

namespace PFSWireGuardGeneratorCore
{
    class FileIO
    {
        public:
            static std::string getTextFromFile(const char* file_name);
            static void writeBlockToFile(const char* file_name, Block& block);

        private:
    };
}
