#include <iostream>

#include "ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp"

using namespace PFSWireGuardGeneratorCore;

int main(int argc, char* argv[])
{
    Client client0("User1"), client1("User2"), client2("User3");

    client0 = AdapterAPI::configure(client0);
    client1 = AdapterAPI::configure(client1);
    client2 = AdapterAPI::configure(client2);

    Server server("MainServer");
    server = AdapterAPI::configure(server);

    server.addClient(client0);
    server.addClient(client1);
    server.addClient(client2);

    if(Configurator::configureServerToFile(server.getName() + "Config.txt", server))
        std::cout << server.getName() + "Config.txt file created."<< std::endl;

    if(Configurator::configureClientToFile(client0.getUserName() + "Config.txt", client0))
        std::cout << client0.getUserName() + "Config.txt file created."<< std::endl;
    if(Configurator::configureClientToFile(client1.getUserName() + "Config.txt", client1))
        std::cout << client1.getUserName() + "Config.txt file created."<< std::endl;
    if(Configurator::configureClientToFile(client2.getUserName() + "Config.txt", client2))
        std::cout << client1.getUserName() + "Config.txt file created."<< std::endl;

    return 0;
 }
