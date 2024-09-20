#include <iostream>
#include <sys/stat.h>
#include <filesystem>

#include "ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp"

using namespace PFSWireGuardGeneratorCore;

int main(int argc, char* argv[])
{
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    Client client;

    std::cout << "User name -> "<< client.getUserName() << std::endl;
    std::cout << "Private key -> "<<  client.getPrivateKey() << std::endl;
    std::cout << "Public key -> "<< client.getPublicKey() << std::endl;

    for(const auto &a : client.getAllowedIps())
    {
        std::cout << "Allowed ip-> " << a << std::endl;
    }

    std::cout << "DNS -> " << client.getDNS() << std::endl;
    std::cout << "Endpoint -> " << client.getEndpoint() << std::endl;
    std::cout << "Persistent keepalive -> " << client.getPersistentKeepalive() << std::endl;

    std::cin.get();
    

    try
    {
        auto kekes = PFSWireGuardGeneratorCoreAPI::getTextFromFile("kekes.txt");
        std::cout << kekes << std::endl;
    }
    catch (const std::ios_base::failure& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    Block block0 =
    {
        Attribute::Peer,

        {
            {"PublicKey = ", "124345defertegfdg23423"},
            {"AllowedIPs = ","10.8.0.0/24"},
            {"Endpoint = ","pfs-solutions.ddns.net:51820"},
            {"PersistentKeepalive = ","20"}
        }
    };

    Block block1 =
    {
        Attribute::Peer,

        {
            {"PublicKey = ", "jklkdsfjglkdfjgkljdflkgjdlkfg"},
            {"AllowedIPs = ","10.8.0.0/24"},
            {"Endpoint = ","pfs-solutions.ddns.net:51820"},
            {"PersistentKeepalive = ","20"}
        }
    };

    std::vector<Block> blocks { block0, block1 };

    for (auto& block : blocks)
    {
        try
        {
            PFSWireGuardGeneratorCoreAPI::writeBlockToFile("kekes.txt", block);
        }
        catch(const std::ios_base::failure& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    return 0;
 }
