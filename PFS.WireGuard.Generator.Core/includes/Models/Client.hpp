#pragma once

#include <string>
#include <vector>

namespace PFSWireGuardGeneratorCore
{
    class Client
    {
        public:
            Client();

            std::string getUserName() const { return _user_name; }

            std::string getPrivateKey() const {return _private_key; }
            std::string getPublicKey() const {return _public_key; }

            std::vector<std::string> getAllowedIps() const { return _allowed_ips; }
            std::string getDNS() const {return _DNS; }

            std::string getEndpoint() const {return _endpoint; }
            short int getPersistentKeepalive() const { return _persistent_keepalive; }

        private:
            std::string _user_name;

            std::string _private_key;
            std::string _public_key;

            std::vector<std::string> _allowed_ips;
            std::string _DNS;

            std::string _endpoint;
            short int _persistent_keepalive;
    };
}

