#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    Server::Server() :
        _private_key(""), _public_key(""), _address("10.8.0.1/24"),
        _start_ip(boost::asio::ip::address_v4::from_string("10.8.0.1")), _listen_port("51820"),
        _post_ups {"ufw route allow in on wg0 out on enp1s0",
            "iptables -t nat -I POSTROUTING -o enp1s0 -j MASQUERADE"},
        _pre_downs {"ufw route delete allow in on wg0 out on enp1s0",
            "iptables -t nat -D POSTROUTING -o enp1s0 -j MASQUERADE"},
        _clients{}
    { }

    std::string Server::getPrivateKey() const
    {
        return _private_key;
    }

    std::string Server::getPublicKey() const
    {
        return _public_key;
    }

    std::string Server::getAdress() const
    {
        return _address;
    }

    std::string Server::getListenPort() const
    {
        return _listen_port;
    }

    std::vector<std::string> Server::getPostUps() const
    {
        return _post_ups;
    }

    std::vector<std::string> Server::getPreDowns() const
    {
        return _pre_downs;
    }

    const std::vector<Client>& Server::getClients() const
    {
        return _clients;
    }

    void Server::setClients(std::vector<Client>& clietns)
    {
        _clients = std::move(clietns);
    }

    std::string Server::incrementIP()
    {
        uint32_t ip_num = _start_ip.to_uint();
        ip_num++;
        boost::asio::ip::address_v4 new_ip(ip_num);
        _start_ip = new_ip;

        return new_ip.to_string();
    }

    void Server::addClient(Client& client)
    {
        client.setServerPublicKey(_public_key);
        client.setAddress(incrementIP() + "/32");
        _clients.push_back(client);
    }
}
