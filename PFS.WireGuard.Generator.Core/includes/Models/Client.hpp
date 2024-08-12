#pragma once

#include <string>
#include <vector>

class Client
{
    public:

        Client(){};


    private:
        std::string _user_name;

        std::string _private_key;
        std::string _public_key;

        std::vector<std::string> _allowed_ips;
        std::string _DNS;

        std::string _endpoint;
        short int _persistent_keepalive = 20;
};
