#pragma once

#include <string>
#include <vector>

#include "ExportLibrary/PFSWGGeneratorCoreExport.hpp"

namespace PFSWireGuardGeneratorCore
{
    class StringExtention
    {
        public:
            StringExtention() = delete;

            static std::string formatString(const std::string& source, const std::vector<std::string>& args);
            static std::string trimString(const std::string& source);

        private:
    };
}
