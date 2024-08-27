#pragma once

#include <string>

namespace PFSWireGuardGeneratorCore
{
    class Command
    {
        public:
            virtual std::string executeCommand(std::string &command) = 0;
            virtual std::string generatePublicKey(std::string &username) = 0;
            virtual std::string generatePrivateKey(std::string &username) = 0;
    };
}
