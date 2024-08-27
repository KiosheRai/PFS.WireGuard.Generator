#pragma once

#include <string>
#include <vector>

namespace PFSWireGuardGeneratorCore
{
    std::string formatString(const std::string& source, const std::vector<std::string>& args);
    std::string trimString(const std::string& source);
}