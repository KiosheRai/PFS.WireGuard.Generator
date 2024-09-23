#pragma once

#include "CommandAdapter/BashCommand.hpp"
#include "CommandAdapter/CmdCommand.hpp"
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API AdapterAPI
    {
        public:
            AdapterAPI() = delete;

            static const Client configure(const Client& client);
            static const Server configure(const Server& server);
        private:
    };
}
