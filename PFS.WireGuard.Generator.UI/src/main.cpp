#include <iostream>
#include <sys/stat.h>
#include <filesystem>

#include "ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp"

using namespace PFSWireGuardGeneratorCore;

int main(int argc, char* argv[])
{
    Client client0, client1,client2,client3,client4,client5;

    Server server;
    server.addClient(client1);
    server.addClient(client2);
    server.addClient(client3);
    server.addClient(client4);
    server.addClient(client5);

    Configurator::configureServerToFile("MainServerConfig.txt", server);
    Configurator::configureClientToFile("Client_1.txt", client1);
    Configurator::configureClientToFile("Client_2.txt", client2);
    Configurator::configureClientToFile("Client_3.txt", client3);

    BashCommand command;
    std::cout << "Comand result: " << command.executeCommand("echo \"Hello World\"") << std::endl;

    return 0;
 }
