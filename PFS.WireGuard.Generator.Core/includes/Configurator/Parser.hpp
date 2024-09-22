#pragma once

#include "Configurator/Block.hpp"
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API Parser
    {
        public:
            Parser() = delete;

            static std::vector<Block> deserialize(const std::string& text);
            static std::vector<Block> serialize(const Client& client);
            static std::vector<Block> serialize(const Server& server);

        private:
    };
}
