#include <iostream>

#include <Models/Client.hpp>
#include <Configurator/FileIO.hpp>
#include <Configurator/Block.hpp>
#include <sys/stat.h>
#include <ApiCommands/BashCommand.hpp>

#include <Common/StringExtentions.hpp>

using namespace PFSWireGuardGeneratorCore;

int main(int argc, char* argv[])
{
    std::string format = "  {0} command, {0} tee {1}, {2}  ";

    std::string result = formatString(format, { "echo", "output.txt", "23"});

    std::cout << result << std::endl;

    result = trimString(format);

    std::cout << result << std::endl;

    BashCommand command(false);

    std::string s = "Gixal";
    std::cout << command.generatePrivateKey(s) << std::endl;

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
        auto kekes = FileIO::getTextFromFile("kekes.txt");
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
            FileIO::writeBlockToFile("kekes.txt", block);
        }
        catch(const std::ios_base::failure& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    return 0;
 }
