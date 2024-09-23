#pragma once

#include <string>
#include <vector>

#include "Models/Client.hpp"
#include "asio/ip/address_v4.hpp"

namespace PFSWireGuardGeneratorCore
{
    class PFSWGGENERATORCORE_API Server
    {
        public:
            Server() = delete;
            Server(const std::string server_name);

            std::string getName() const;
            void setName(const std::string& server_name);

            std::string getPrivateKey() const;
            void setPrivateKey(const std::string& private_key);

            std::string getPublicKey() const;
            void setPublicKey(const std::string& public_key);

            std::string getAddress() const;
            void setAddress(const std::string address);

            std::string getListenPort() const;
            std::vector<std::string> getPostUps() const;
            std::vector<std::string> getPreDowns() const;

            const std::vector<Client>& getClients() const;
            void setClients(std::vector<Client>& clietns);
            void addClient(Client& client);

        private:
            std::string _server_name;
            std::string _private_key;
            std::string _public_key;

            std::string _address;

            asio::ip::address_v4 _start_ip;
            std::string incrementIP();

            std::string _listen_port;
            std::vector<std::string> _post_ups;
            std::vector<std::string> _pre_downs;

            std::vector<Client> _clients;
    };
}
