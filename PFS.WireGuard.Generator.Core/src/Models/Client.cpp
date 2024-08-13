#include "Models/Client.hpp"

namespace PFSWireGuardGeneratorCore
{
    Client::Client()
    {
        _user_name = "";

        _private_key = "";
        _public_key = "";

        _allowed_ips = {"10.8.0.0/24"};
        _DNS = "8.8.8.8";

        _endpoint = "pfs-solutions.ddns.net:51820";
        _persistent_keepalive = 20;
    }
}
