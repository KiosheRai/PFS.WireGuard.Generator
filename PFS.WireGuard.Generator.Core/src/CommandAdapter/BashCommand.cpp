#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#include "CommandAdapter/BashCommand.hpp"

namespace PFSWireGuardGeneratorCore
{
    BashCommand::BashCommand() :
        _is_sudoer(false), _path("")
    { }

    BashCommand::BashCommand(const bool is_sudoer) :
        _is_sudoer(is_sudoer)
    { }

    std::string BashCommand::executeCommand(const std::string& command)
    {
        std::array<char, 128> buffer;
        std::string result;

        std::unique_ptr<FILE, int(*)(FILE*)> pipe(popen(command.c_str(), "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }

        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }

        if (!result.empty() && result.back() == '\n')
            result.pop_back();

        return result;
    }

    std::string BashCommand::generatePublicKey(const std::string& username)
    {
        std::string sudo = _SUDOER_PREFIX;

        if (_is_sudoer)
            sudo = "";

        std::string command = StringExtention::formatString(_GENERATE_PUBLIC_KEY, { sudo, username });
        std::string key = executeCommand(command);

        return key;
    }

    std::string BashCommand::generatePrivateKey(const std::string& username)
    {
        std::string sudo = _SUDOER_PREFIX;

        if (_is_sudoer)
            sudo = "";

        std::string command = StringExtention::formatString(_GENERATE_PRIVATE_KEY, { sudo, username });
        std::string key = executeCommand(command);

        return key;
    }
}
