#include "ApiCommands/BashCommand.hpp"
#include "Common/StringExtentions.hpp"
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <iostream>
#include <cstdio>
#include <memory>
#include <array>


namespace PFSWireGuardGeneratorCore
{
    BashCommand::BashCommand(bool isSudoer)
    {
        _isSudoer = isSudoer;
    }

    std::string BashCommand::executeCommand(std::string& command) 
    {
        //TODO: Implement here
    }

    std::string BashCommand::generatePublicKey(std::string& username)
    {
        std::string sudo = _sudoerPrefix;

        if (_isSudoer)
            sudo = "";

        std::string command = formatString(_generatePublicKey, { sudo, username });
        std::string key = executeCommand(command);

        return key;
    }

    std::string BashCommand::generatePrivateKey(std::string& username)
    {
        std::string sudo = _sudoerPrefix;

        if (_isSudoer)
            sudo = "";

        std::string command = formatString(_generatePrivateKey, { sudo, username });
        std::string key = executeCommand(command);

        return key;
    }
}
