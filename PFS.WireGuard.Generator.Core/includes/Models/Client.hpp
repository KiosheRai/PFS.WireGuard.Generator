#pragma once

#include <string>
#include <vector>

#include "boost/asio/ip/address_v4.hpp"

#ifndef PFSWGGENERATORCORE_API
    #ifdef _WIN32
        #ifdef PFSWGGENERATORCORE_EXPORTS
            #define PFSWGGENERATORCORE_API __declspec(dllexport)
        #else
            #define PFSWGGENERATORCORE_API __declspec(dllimport)
        #endif
    #else
        #define PFSWGGENERATORCORE_API
    #endif
#endif

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API Client
    {
        public:
            Client();

            std::string getUserName() const;

            std::string getPrivateKey() const;
            std::string getPublicKey() const;

            std::string getServerPublicKey() const;
            void setServerPublicKey(const std::string server_public_key);

            std::string getAddress() const;
            void setAddress(std::string address);

            const std::vector<std::string>& getAllowedIps() const;
            void setAllowedIps(std::string);

            std::string getDNS() const;

            std::string getEndpoint() const;
            std::string getPersistentKeepalive() const;

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

