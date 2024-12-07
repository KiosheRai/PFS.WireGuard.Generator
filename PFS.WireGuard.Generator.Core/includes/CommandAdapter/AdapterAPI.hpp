#pragma once

#include <memory>

#include "ExportLibrary/PFSWGGeneratorCoreExport.hpp"

namespace PFSWireGuardGeneratorCore
{
    class Client;
    class Server;

    class PFSWGGENERATORCORE_API AdapterAPI
    {
        public:
            AdapterAPI() = delete;

            static const Client configure(const Client& client);
            static const Server configure(const Server& server);
        private:
            struct Impl;
            static std::unique_ptr<Impl> _impl;

    };
}
