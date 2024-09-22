#pragma once

#include <string>
#include <iostream>

#include "Configurator/FileIO.hpp"
#include "Configurator/Parser.hpp"
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API Configurator
    {
        public:
            Configurator() = delete;

            static bool configureClientToFile(const std::string& file_name,const Client& client);
            static bool configureServerToFile(const std::string& file_name,const Server& server);

            static bool getBlocksFromClientFile();
            static bool getBlocksFromServerFile();

        private:
    };
}
