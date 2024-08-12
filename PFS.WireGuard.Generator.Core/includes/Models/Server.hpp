#pragma once

#include <string>
#include <vector>

class User;

class Server
{
    public:
        Server(){};

        unsigned int getListenPort() { return _listen_port; }

    private:
        std::string _private_key;
        std::string _public_key;
        std::string _address;

        unsigned int _listen_port;
        std::vector<std::string> _post_ups;
        std::vector<std::string> _pre_downs;

        std::vector<User> _users;
};
