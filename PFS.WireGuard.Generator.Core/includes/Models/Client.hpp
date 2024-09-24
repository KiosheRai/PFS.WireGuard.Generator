#pragma once

#include <string>
#include <vector>

#include "asio/ip/address_v4.hpp"
#include "ExportLibrary/PFSWGGeneratorCoreExport.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API Client
    {
        public:
            Client() = delete;

            Client(const std::string user_name);

            std::string getUserName() const;
            void setUserName(const std::string& user_name);

            std::string getPrivateKey() const;
            void setPrivateKey(const std::string& private_key);

            std::string getPublicKey() const;
            void setPublicKey(const std::string& public_key);

            std::string getServerPublicKey() const;
            void setServerPublicKey(const std::string& server_public_key);

            std::string getAddress() const;
            void setAddress(const std::string& address);

            const std::vector<std::string>& getAllowedIps() const;
            void setAllowedIps(std::vector<std::string>& allowed_ips);

            std::string getDNS() const;
            void setDNS(const std::string& DNS);

            std::string getEndpoint() const;
            void setEndpoint(const std::string& endpoint);

            std::string getPersistentKeepalive() const;
            void setPersistentKeepalive(const std::string& persistent_keepalive);

            void show();

        private:
            std::string _user_name;

            std::string _private_key;
            std::string _public_key;
            std::string _server_public_key;

            std::string _address;
            std::vector<std::string> _allowed_ips;
            std::string _DNS;

            std::string _endpoint;
            std::string _persistent_keepalive;
    };
}

