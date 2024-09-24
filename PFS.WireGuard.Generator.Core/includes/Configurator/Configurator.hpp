#pragma once

#include <memory>
#include <string>

#include "ExportLibrary/PFSWGGeneratorCoreExport.hpp"

namespace PFSWireGuardGeneratorCore
{
    class Client;
    class Server;

    class PFSWGGENERATORCORE_API Configurator
    {
        public:
            Configurator() = delete;

            static bool configureClientToFile(const Client& client, const std::string& file_name, const std::string& path = "");
            static bool configureServerToFile(const Server& server, const std::string& file_name, const std::string& path = "");

            static const Client getClient(const std::string& file_name, const std::string& path = "");
            static const Server getServer(const std::string& file_name, const std::string& path = "");

        private:
            struct Impl;
            static std::unique_ptr<Impl> _impl;
    };
}
