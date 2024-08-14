#include "Models/Client.hpp"

namespace PFSWireGuardGeneratorCore
{
    Client::Client() :
        _user_name(""), _private_key("") , _public_key(""),
        _allowed_ips{"10.8.0.0/24"}, _DNS("8.8.8.8"),
        _endpoint("pfs-solutions.ddns.net:51820"),_persistent_keepalive("20")
    {

    }

    std::string Client::getUserName() const { return _user_name; }

    std::string Client::getPrivateKey() const {return _private_key; }
    std::string Client::getPublicKey() const {return _public_key; }

    std::vector<std::string> Client::getAllowedIps() { return _allowed_ips; }
    std::string Client::getDNS() const {return _DNS; }

    std::string Client::getEndpoint() const {return _endpoint; }
    std::string Client::getPersistentKeepalive() const { return _persistent_keepalive; }
}
