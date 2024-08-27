#pragma once

#include "Command.hpp"

namespace PFSWireGuardGeneratorCore
{
	class CmdCommand : public Command
	{
	public:
		CmdCommand();

		CmdCommand(bool isSudoer);

		std::string executeCommand(std::string& command) override;
		std::string generatePublicKey(std::string& username) override;
		std::string generatePrivateKey(std::string& username) override;

		std::string getDirectory() const;
		void setDirectory(std::string& path) const;
	};
}
