#pragma once

#include <string>
#include <iostream>

#include "Configurator/Block.hpp"
#include "Configurator/FileIO.hpp"
#include "Configurator/Parser.hpp"

#include "Models/Client.hpp"
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    class Configurator
    {
        public:
            Configurator() = delete;

            static bool configureClientToFile(std::string file_name,const Client& client);
            static bool configureServerToFile(std::string file_name,const Server& server);

            static bool getBlocksFromClientFile();
            static bool getBlocksFromServerFile();

        private:
    };
}
