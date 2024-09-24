#include <errno.h>
#include <fstream>
#include <iostream>

#include "Configurator/Configurator.hpp"
#include "Configurator/FileIO.hpp"
#include "Configurator/Parser.hpp"
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    struct Configurator::Impl
    {
        bool configureClientToFileImpl(const Client& client, const std::string& file_name,  const std::string& path)
        {
            FileIO::createFile(file_name, path);

            auto client_blocks = Parser::serialize(client);

            for (auto& block : client_blocks)
            {
                try
                {
                    FileIO::writeBlockToFile( block, (path + file_name).c_str());
                }
                catch(const std::ios_base::failure& e)
                {
                    std::cerr << "Exception: " << e.what() << std::endl;
                    return false;
                }
            }

            return true;
        }

        bool configureServerToFileImpl(const Server& server, const std::string& file_name,  const std::string& path)
        {
            FileIO::createFile(file_name, path);

            auto server_blocks = Parser::serialize(server);

            for (auto& block : server_blocks)
            {
                try
                {
                    FileIO::writeBlockToFile( block, (path + file_name).c_str());
                }
                catch(const std::ios_base::failure& e)
                {
                    std::cerr << "Exception: " << e.what() << std::endl;
                    return false;
                }
            }

            return true;
        }

        Client getClientImpl(const std::string& file_name, const std::string& path)
        {
            std::string text = FileIO::getTextFromFile(file_name.c_str(), path);

            std::vector<Block> client_blocks = Parser::deserialize(text);
            auto [interface_block, peer_block] = std::tie(client_blocks[0], client_blocks[1]);

            Client client("");

            if(client_blocks.size() == 2)
            {
                client.setUserName(interface_block.getProps()[0].second);
                client.setPrivateKey(interface_block.getProps()[1].second);
                client.setAddress(interface_block.getProps()[2].second);
                client.setDNS(interface_block.getProps()[3].second);

                client.setPublicKey(peer_block.getProps()[0].second);
                std::vector<std::string> allowed_ips = {peer_block.getProps()[1].second};
                client.setAllowedIps(allowed_ips);
                client.setEndpoint(peer_block.getProps()[2].second);
                client.setPersistentKeepalive(peer_block.getProps()[3].second);
            }
            else
                throw std::runtime_error("CLIENT FILE IS CORRUPTED!");

            return client;
        }

        Server getServerImpl(const std::string& file_name, const std::string& path)
        {
            std::string text = FileIO::getTextFromFile(file_name.c_str(), path);

            std::vector<Block> server_blocks = Parser::deserialize(text);
            Block interface_block = server_blocks.front();

            Server server("");

            if(server_blocks.size() >= 1)
            {
                server.setName(interface_block.getProps()[0].second);
                server.setPrivateKey(interface_block.getProps()[1].second);
                server.setAddress(interface_block.getProps()[2].second);
                server.setListenPort(interface_block.getProps()[3].second);

                std::vector<std::string> post_ups = {interface_block.getProps()[4].second,
                                                        interface_block.getProps()[5].second};
                std::vector<std::string> pre_downs = {interface_block.getProps()[6].second,
                                                        interface_block.getProps()[7].second};
                server.setPostUps(post_ups);
                server.setPretDowns(pre_downs);

                for(size_t i = 1; i < server_blocks.size(); i++)
                {
                    std::string file_name = server_blocks[i].getProps()[0].second + "Config.txt";
                    Client temp = getClient(file_name);

                    server.addClient(temp);
                }

            }
            else
                throw std::runtime_error("CLIENT FILE IS CORRUPTED!");

            return server;
        }
    };

    std::unique_ptr<Configurator::Impl> Configurator::_impl = std::make_unique<Configurator::Impl>();

    bool Configurator::configureClientToFile(const Client& client, const std::string& file_name,  const std::string& path)
    {
        return _impl->configureClientToFileImpl(client, file_name, path);
    }

    bool Configurator::configureServerToFile(const Server& server, const std::string& file_name,  const std::string& path)
    {
        return _impl->configureServerToFileImpl(server, file_name, path);
    }

    const Client Configurator::getClient(const std::string& file_name, const std::string& path)
    {
        return _impl->getClientImpl(file_name, path);
    }

    const Server Configurator::getServer(const std::string& file_name, const std::string& path)
    {
        return _impl->getServerImpl(file_name, path);
    }
}
