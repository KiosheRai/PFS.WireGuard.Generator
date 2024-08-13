#include <iostream>

#include <Models/Client.hpp>

int main(int argc, char* argv[])
{
    PFSWireGuardGeneratorCore::Client client;

    std::cout << "User name -> "<< client.getUserName() << std::endl;
    std::cout << "Private key -> "<<  client.getPrivateKey() << std::endl;
    std::cout << "Public key -> "<< client.getPublicKey() << std::endl;

    for( auto &a : client.getAllowedIps())
    {
        std::cout << "Allowed ip-> " << a << std::endl;
    }

    std::cout << "DNS -> " << client.getDNS() << std::endl;
    std::cout << "Endpoint -> " << client.getEndpoint() << std::endl;
    std::cout << "Persistent keepalive -> " << client.getPersistentKeepalive() << std::endl;

    std::cin.get();
    return 0;
 }
