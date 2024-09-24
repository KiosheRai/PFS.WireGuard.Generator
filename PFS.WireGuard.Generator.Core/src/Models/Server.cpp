#include <iostream>
#include "Models/Server.hpp"

namespace PFSWireGuardGeneratorCore
{
    Server::Server(const std::string server_name) :
        _server_name(server_name), _private_key(""), _public_key(""), _address("10.8.0.1/24"),
        _last_ip(asio::ip::address_v4::from_string("10.8.0.1")), _listen_port("51820"),
        _post_ups {"ufw route allow in on wg0 out on enp1s0",
            "iptables -t nat -I POSTROUTING -o enp1s0 -j MASQUERADE"},
        _pre_downs {"ufw route delete allow in on wg0 out on enp1s0",
            "iptables -t nat -D POSTROUTING -o enp1s0 -j MASQUERADE"},
        _clients{}
    { }

    std::string Server::getName() const
    {
        return _server_name;
    }

    void Server::setName(const std::string& server_name)
    {
        _server_name = server_name;
    }

    std::string Server::getPrivateKey() const
    {
        return _private_key;
    }

    void Server::setPrivateKey(const std::string& private_key)
    {
        _private_key = private_key;
    }

    std::string Server::getPublicKey() const
    {
        return _public_key;
    }

    void Server::setPublicKey(const std::string& public_key)
    {
        _public_key = public_key;
    }

    std::string Server::getAddress() const
    {
        return _address;
    }

    void Server::setAddress(const std::string address)
    {
        _address = address;
    }

    std::string Server::getListenPort() const
    {
        return _listen_port;
    }

    void Server::setListenPort(const std::string& listen_port)
    {
        _listen_port = std::move(listen_port);
    }

    std::vector<std::string> Server::getPostUps() const
    {
        return _post_ups;
    }

    void Server::setPostUps(const std::vector<std::string>& post_ups)
    {
        _post_ups = std::move(post_ups);
    }

    std::vector<std::string> Server::getPreDowns() const
    {
        return _pre_downs;
    }

    void Server::setPretDowns(const std::vector<std::string>& pre_downs)
    {
        _pre_downs = std::move(pre_downs);
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
        uint32_t ip_num = _last_ip.to_uint();
        ip_num++;
        asio::ip::address_v4 new_ip(ip_num);
        _last_ip = new_ip;

        return new_ip.to_string();
    }

    void Server::addClient(Client& client)
    {
        client.setServerPublicKey(_public_key);
        client.setAddress(incrementIP() + "/32");
        _clients.push_back(client);
    }

    asio::ip::address_v4 Server::getLastIp() const
    {
        return _last_ip;
    }

    std::string Server::getLastIpToString() const
    {
        return _last_ip.to_string();
    }

    void Server::setSLastIp(const std::string& last_ip)
    {
        asio::ip::address_v4 new_last_ip  = asio::ip::address_v4::from_string(last_ip);
        _last_ip = new_last_ip;
    }

    void Server::show()
    {
        std::cout << "----------------------------------SERVER------------------------------------------" << std::endl;
        std::cout << "ServerName-> " << getName() << std::endl;
        std::cout << "PrivateKey-> " << getPrivateKey() << std::endl;
        std::cout << "Address-> " << getAddress() << std::endl;
        std::cout << "ListenPort-> " << getListenPort() << std::endl;
        std::cout << "PostUp-> " << getPostUps().front() << std::endl;
        std::cout << "PostUp-> " << getPostUps().back() << std::endl;
        std::cout << "PreDowns-> " << getPreDowns().front() << std::endl;
        std::cout << "PreDowns-> " << getPreDowns().back() << std::endl;
        std::cout << "----------------------------------CLIENTS------------------------------------------" << std::endl;
        for(const auto& client : getClients())
        {
            std::cout << "UserName-> " << client.getUserName() << std::endl;
            std::cout << "PublicKey-> " << client.getPublicKey() << std::endl;
            std::cout << "PrivateKey-> " << client.getPrivateKey() << std::endl;
            std::cout << "Address-> " << client.getAddress() << std::endl;
            std::cout << "DNS-> " << client.getDNS() << std::endl;
            std::cout << "AllowedIPs-> " << client.getAllowedIps().back() << std::endl;
            std::cout << "Endpoint-> " << client.getEndpoint() << std::endl;
            std::cout << "PersistentKeepalive-> " << client.getPersistentKeepalive() << std::endl << std::endl;
        }
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    }
}
