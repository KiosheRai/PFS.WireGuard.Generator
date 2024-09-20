#include <iostream>
#include <sys/stat.h>
#include <filesystem>

#include "ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp"
#include "Configurator/Parser.hpp"
#include "Configurator/Configurator.hpp"

using namespace PFSWireGuardGeneratorCore;

int main(int argc, char* argv[])
{
    // try
    // {
    //     auto client = PFSWireGuardGeneratorCoreAPI::getTextFromFile("Client.txt");
    //     auto blocks = Parser::deserialize(client);
    //
    //     for(size_t i = 0; i < blocks.size(); i++)
    //     {
    //         std::cout << blocks[i].getAttributeToString() << std::endl;
    //
    //         for(const auto& prop : blocks[i].getProps())
    //         {
    //             std::cout << prop.first << " = " << prop.second << std::endl;
    //         }
    //
    //     }
    // }
    // catch (const std::ios_base::failure& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    //
    //
    // std::cout << std::endl;
    //
    // try
    // {
    //     auto server = PFSWireGuardGeneratorCoreAPI::getTextFromFile("Server.txt");
    //     auto blocks = Parser::deserialize(server);
    //
    //     for(size_t i = 0; i < blocks.size(); i++)
    //     {
    //         std::cout << blocks[i].getAttributeToString() << std::endl;
    //
    //         for(const auto& prop : blocks[i].getProps())
    //         {
    //             std::cout << prop.first << " = " << prop.second << std::endl;
    //         }
    //
    //     }
    // }
    // catch (const std::ios_base::failure& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    Client client0, client1,client2,client3,client4,client5;


    Server server;

    server.addClient(client1);
    server.addClient(client2);
    server.addClient(client3);
    server.addClient(client4);
    server.addClient(client5);

    Configurator::configureServerToFile("MainServerConfig.txt", server);
    Configurator::configureClientToFile("Client_PIDORAS.txt", client1);
    Configurator::configureClientToFile("Client_PIDORAS2.txt", client2);
    Configurator::configureClientToFile("Client_PIDORAS3.txt", client3);



    return 0;
 }
