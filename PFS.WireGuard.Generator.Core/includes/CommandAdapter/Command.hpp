#pragma once

#include <string>

#include "Common/StringExtentions.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API Command
    {
        public:
            virtual ~Command() = default;

            virtual std::string executeCommand(const std::string& command) = 0;
            virtual std::string generatePublicKey(const std::string& username) = 0;
            virtual std::string generatePrivateKey(const std::string& username) = 0;

        private:
    };
}
