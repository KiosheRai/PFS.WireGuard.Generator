#pragma once

#include "Configurator/FileIO.hpp"
#include "Configurator/Parser.hpp"
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API Configurator
    {
        public:
            Configurator() = delete;

            static bool configureClientToFile(const Client& client, const std::string& file_name, const std::string& path = "");
            static bool configureServerToFile(const Server& server, const std::string& file_name, const std::string& path = "");

            static const Client getClient(const std::string& file_name, const std::string& path = "");
            static const Server getServer(const std::string& file_name, const std::string& path = "");

        private:
    };
}
