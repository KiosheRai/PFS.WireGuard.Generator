#pragma once

#include "Command.hpp"

namespace PFSWireGuardGeneratorCore
{
	class BashCommand : public Command
	{
		public:
			BashCommand();

			BashCommand(bool isSudoer);

			std::string executeCommand(std::string &command) override;
			std::string generatePublicKey(std::string &username) override;
			std::string generatePrivateKey(std::string &username) override;

			std::string getDirectory() const;
			void setDirectory(std::string& path) const;

		private:
			bool _isSudoer;
			std::string _path;

			const std::string _sudoerPrefix = "sudo";
			const std::string _generatePrivateKey = "{0} wg genkey | {0} tee /etc/wireguard/{1}/private.key\n{0} chmod go= /etc/wireguard/{1}/private.key";
			const std::string _generatePublicKey = "{0} cat /etc/wireguard/{1}/private.key | wg pubkey | {0} tee /etc/wireguard/{1}/public.key";
	};
}
