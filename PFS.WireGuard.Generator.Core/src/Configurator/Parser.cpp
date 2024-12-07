#include <sstream>
#include <iostream>

#include "Configurator/Parser.hpp"

namespace PFSWireGuardGeneratorCore
{
    std::vector<Block> Parser::deserialize(const std::string& text)
    {
        std::vector<Block> blocks;
        std::istringstream stream(text);
        std::string line;

        Attribute currentAttribute;
        Block currentBlock;
        Props currentProps;

        while (std::getline(stream, line))
        {
            if (line.empty() || line[0] == '#')
            {
                if (!line.empty() && line[0] == '#')
                {
                    std::string key = "#";
                    std::string value = line.substr(1);

                    currentProps.push_back({key, value});
                }
                continue;
            }

            if (line == "[Interface]")
            {
                if (!currentProps.empty())
                {
                    currentBlock.setProps(currentProps);
                    blocks.push_back(currentBlock);
                    currentProps.clear();
                }
                currentAttribute = Attribute::Interface;
                currentBlock = {currentAttribute, {}};
            }
            else if (line == "[Peer]")
            {
                if (!currentProps.empty())
                {
                    currentBlock.setProps(currentProps);
                    blocks.push_back(currentBlock);
                    currentProps.clear();
                }
                currentAttribute = Attribute::Peer;
                currentBlock = {currentAttribute, {}};
            }
            else
            {
                size_t pos = line.find('=');
                if (pos != std::string::npos)
                {
                    std::string key = line.substr(0, pos);
                    std::string value = line.substr(pos + 1);

                    key.erase(0, key.find_first_not_of(" \t"));
                    key.erase(key.find_last_not_of(" \t") + 1);
                    value.erase(0, value.find_first_not_of(" \t"));
                    value.erase(value.find_last_not_of(" \t") + 1);

                    currentProps.push_back({key, value});
                }
            }
        }

        if (!currentProps.empty())
        {
            currentBlock.setProps(currentProps);
            blocks.push_back(currentBlock);
        }

        return blocks;
    }

    std::vector<Block> Parser::serialize(const Client& client)
    {
        Block interface_block =
        {
            Attribute::Interface,
            {
                {"#", client.getUserName()},
                {"PrivateKey = ", client.getPrivateKey()},
                {"Address = ", client.getAddress()},
                {"DNS = ", client.getDNS()}
            }
        };

        Block peer_block =
        {
            Attribute::Peer,
            {
                {"PublicKey = ", client.getServerPublicKey()},
                {"AllowedIPs = ", client.getAllowedIps().back()},
                {"Endpoint = ", client.getEndpoint()},
                {"PersistentKeepalive = ", client.getPersistentKeepalive()}
            }
        };

        return {interface_block, peer_block};
    }

    std::vector<Block> Parser::serialize(const Server& server)
    {
        std::vector<Block> blocks;

        Block interface_block =
        {
            Attribute::Interface,
            {
                {"#", server.getName()},
                {"PrivateKey = ", server.getPrivateKey()},
                {"Address = ", server.getAddress()},
                {"ListenPort = ", server.getListenPort()},
                {"PostUp = ","ufw route allow in on wg0 out on enp1s0"},
                {"PostUp = ","iptables -t nat -I POSTROUTING -o enp1s0 -j MASQUERADE"},
                {"PreDown = ","ufw route delete allow in on wg0 out on enp1s0"},
                {"PreDown = ","iptables -t nat -D POSTROUTING -o enp1s0 -j MASQUERADE"}
            }
        };

        blocks.push_back(interface_block);
        auto clients = server.getClients();

        for(const auto& client : clients)
        {
            Block peer_block =
            {
                Attribute::Peer,
                {
                    {"#", client.getUserName()},
                    {"PublicKey = ", client.getPublicKey()},
                    {"AllowedIps = ", client.getAddress()}
                }
            };

            blocks.push_back(peer_block);
        }

        return blocks;
    }

}
