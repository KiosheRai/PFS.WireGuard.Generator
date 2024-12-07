#include <iostream>
#include <memory>

#include "CommandAdapter/AdapterAPI.hpp"
#include "CommandAdapter/BashCommand.hpp"
#include "CommandAdapter/CmdCommand.hpp"
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    struct AdapterAPI::Impl
    {
        Client configureImpl(const Client& client)
        {
            Client configurated_client(client);
            std::unique_ptr<Command> command;

            #if defined(_WIN32) || defined(_WIN64)
                command = std::make_unique<CmdCommand>();
            #else
                command = std::make_unique<BashCommand>();
            #endif

            configurated_client.setPrivateKey(command->generatePrivateKey(client.getUserName()));
            configurated_client.setPublicKey(command->generatePublicKey(client.getUserName()));

            if(configurated_client.getPrivateKey().size() == 0 ||
                configurated_client.getPublicKey().size() == 0 ||
                configurated_client.getUserName() == "")
                {
                    throw std::runtime_error("Failed to generate client.");
                }

            return configurated_client;
        }

        Server configureImpl(const Server& server)
        {
            Server configurated_server(server);
            std::unique_ptr<Command> command;

            #if defined(_WIN32) || defined(_WIN64)
                command = std::make_unique<CmdCommand>();
            #else
                command = std::make_unique<BashCommand>();
            #endif

            configurated_server.setPrivateKey(command->generatePrivateKey(server.getName()));
            configurated_server.setPublicKey(command->generatePublicKey(server.getName()));

            if(configurated_server.getPrivateKey().size() == 0||
                configurated_server.getPublicKey().size() == 0)
                throw std::runtime_error("Failed to generate server.");

            return configurated_server;
        }
    };

    std::unique_ptr<AdapterAPI::Impl> AdapterAPI::_impl = std::make_unique<AdapterAPI::Impl>();

    const Client AdapterAPI::configure(const Client& client)
    {
        return _impl->configureImpl(client);
    }

    const Server AdapterAPI::configure(const Server& server)
    {
        return _impl->configureImpl(server);
    }
}
