#pragma once

#include <string>
#include <vector>

namespace PFSWireGuardGeneratorCore
{
    class Client
    {
        public:
            Client();

            std::string getUserName() const;

            std::string getPrivateKey() const;
            std::string getPublicKey() const;

            std::vector<std::string> getAllowedIps();
            std::string getDNS() const;

            std::string getEndpoint() const;
            std::string getPersistentKeepalive() const;

        private:
            std::string _user_name;

            std::string _private_key;
            std::string _public_key;

            std::vector<std::string> _allowed_ips;
            std::string _DNS;

            std::string _endpoint;
            std::string _persistent_keepalive;
    };
}

