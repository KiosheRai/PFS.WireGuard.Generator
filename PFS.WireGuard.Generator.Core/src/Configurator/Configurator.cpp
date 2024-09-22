#include <errno.h>
#include <fstream>

#include "Configurator/Configurator.hpp"

namespace PFSWireGuardGeneratorCore
{
    bool Configurator::configureClientToFile(const std::string& file_name,const Client& client)
    {
        FileIO::createFile(file_name);

        auto client_blocks = Parser::serialize(client);

        for (auto& block : client_blocks)
        {
            try
            {
                FileIO::writeBlockToFile(file_name.c_str(), block);
            }
            catch(const std::ios_base::failure& e)
            {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        }

        return 1;
    }

    bool Configurator::configureServerToFile(const std::string& file_name,const Server& server)
    {
        FileIO::createFile(file_name);

        auto server_blocks = Parser::serialize(server);

        for (auto& block : server_blocks)
        {
            try
            {
                FileIO::writeBlockToFile(file_name.c_str(), block);
            }
            catch(const std::ios_base::failure& e)
            {
                std::cerr << "Exception: " << e.what() << std::endl;
                return 0;
            }
        }

        return 1;
    }

    bool Configurator::getBlocksFromClientFile()
    {
        return 1;
    }

    bool Configurator::getBlocksFromServerFile()
    {
        return 1;
    }
}
