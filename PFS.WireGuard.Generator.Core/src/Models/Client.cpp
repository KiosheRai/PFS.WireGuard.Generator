#include "Models/Client.hpp"

namespace PFSWireGuardGeneratorCore
{
    Client::Client() :
        _user_name(""), _private_key("") , _public_key(""),
        _allowed_ips{"10.8.0.0/32"}, _DNS("8.8.8.8"),
        _endpoint("pfs-solutions.ddns.net:51820"),_persistent_keepalive("20")
    { }

    std::string Client::getUserName() const
    {
        return _user_name;
    }

    std::string Client::getPrivateKey() const
    {
        return _private_key;
    }

    std::string Client::getPublicKey() const
    {
        return _public_key;
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

    std::string Client::getEndpoint() const
    {
        return _endpoint;
    }
    std::string Client::getPersistentKeepalive() const
    {
        return _persistent_keepalive;
    }
}
