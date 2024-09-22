#pragma once

#include "Command.hpp"

namespace PFSWireGuardGeneratorCore
{
	class PFSWGGENERATORCORE_API BashCommand : public Command
	{
		public:
			BashCommand();

			BashCommand(const bool is_sudoer);

			std::string executeCommand(const std::string& command) override;
			std::string generatePublicKey(const std::string& username) override;
			std::string generatePrivateKey(const std::string& username) override;

			std::string getDirectory() const;
			void setDirectory(std::string& path) const;

		private:
			bool _is_sudoer;
			std::string _path;

			const std::string _SUDOER_PREFIX = "sudo";
			const std::string _GENERATE_PRIVATE_KEY = "{0} wg genkey | {0} tee /etc/wireguard/{1}/private.key\n{0} chmod go= /etc/wireguard/{1}/private.key";
			const std::string _GENERATE_PUBLIC_KEY = "{0} cat /etc/wireguard/{1}/private.key | wg pubkey | {0} tee /etc/wireguard/{1}/public.key";
	};
}
