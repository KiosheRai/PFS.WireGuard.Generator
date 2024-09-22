#include "Common/StringExtentions.hpp"

#include <string>
#include <vector>
#include <regex>

namespace PFSWireGuardGeneratorCore
{
    std::string StringExtention::formatString(const std::string& source, const std::vector<std::string>& args)
    {
        std::string result = source;
        for (size_t i = 0; i < args.size(); ++i) {
            std::string placeholder = "\\{" + std::to_string(i) + "\\}";
            result = std::regex_replace(result, std::regex(placeholder), args[i]);
        }
        return result;
    }

    std::string StringExtention::trimString(const std::string& source)
    {
        std::string result = source;
        result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) {
            return !std::isspace(ch);
            }));

        result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
            }).base(), result.end());

        return result;
    }
}
