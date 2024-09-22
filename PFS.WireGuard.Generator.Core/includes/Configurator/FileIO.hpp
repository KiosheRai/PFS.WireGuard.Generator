#pragma once

#include "Block.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API FileIO
    {
        public:
            static std::string getTextFromFile(const char* file_name);
            static void writeBlockToFile(const char* file_name, Block& block);

            static bool createFile(const std::string& file_name, std::string path = "");

        private:
    };
}
