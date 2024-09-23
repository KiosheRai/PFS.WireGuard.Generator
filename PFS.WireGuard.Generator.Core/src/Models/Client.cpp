#include <iostream>
#include "Models/Client.hpp"

namespace PFSWireGuardGeneratorCore
{
    Client::Client(const std::string user_name) :
        _user_name(user_name), _private_key("") , _public_key(""),
        _allowed_ips{"10.8.0.0/32"}, _DNS("8.8.8.8"),
        _endpoint("pfs-solutions.ddns.net:51820"),_persistent_keepalive("20")
    { }

    std::string Client::getUserName() const
    {
        return _user_name;
    }

    void Client::setUserName(const std::string& user_name)
    {
        _user_name = user_name;
    }

    std::string Client::getPrivateKey() const
    {
        return _private_key;
    }

    void Client::setPrivateKey(const std::string& private_key)
    {
        _private_key = private_key;
    }

    std::string Client::getPublicKey() const
    {
        return _public_key;
    }

    void Client::setPublicKey(const std::string& public_key)
    {
        _public_key = public_key;
    }

    std::string Client::getServerPublicKey() const
    {
       return _server_public_key;
    }

    void Client::setServerPublicKey(const std::string& server_public_key)
    {
        _server_public_key = server_public_key;
    }

    std::string Client::getAddress() const
    {
        return _address;
    }

    void Client::setAddress(const std::string& address)
    {
        _address = address;
    }

    const std::vector<std::string>& Client::getAllowedIps() const
    {
        return _allowed_ips;
    }

    void Client::setAllowedIps(std::vector<std::string>& allowed_ips)
    {
        _allowed_ips = std::move(allowed_ips);
    }

    std::string Client::getDNS() const
    {
        return _DNS;
    }

    void Client::setDNS(const std::string& DNS)
    {
        _DNS = DNS;
    }

    std::string Client::getEndpoint() const
    {
        return _endpoint;
    }

    void Client::setEndpoint(const std::string& endpoint)
    {
        _endpoint = endpoint;
    }

    std::string Client::getPersistentKeepalive() const
    {
        return _persistent_keepalive;
    }

    void Client::setPersistentKeepalive(const std::string& persistent_keepalive)
    {
        _persistent_keepalive = persistent_keepalive;
    }

    void Client::show()
    {
        std::cout << "----------------------------------CLIENT------------------------------------------" << std::endl;
        std::cout << "UserName-> " << getUserName() << std::endl;
        std::cout << "PublicKey-> " << getPublicKey() << std::endl;
        std::cout << "PrivateKey-> " << getPrivateKey() << std::endl;
        std::cout << "Address-> " << getAddress() << std::endl;
        std::cout << "DNS-> " << getDNS() << std::endl;
        std::cout << "AllowedIPs-> " << getAllowedIps().back() << std::endl;
        std::cout << "Endpoint-> " << getEndpoint() << std::endl;
        std::cout << "PersistentKeepalive-> " << getPersistentKeepalive() << std::endl << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    }

}
