#pragma once

#include "Command.hpp"

namespace PFSWireGuardGeneratorCore
{
	class PFSWGGENERATORCORE_API CmdCommand : public Command
	{
		public:
			CmdCommand();

			CmdCommand(const bool is_sudoer);

			std::string executeCommand(const std::string& command) override;
			std::string generatePublicKey(const std::string& username) override;
			std::string generatePrivateKey(const std::string& username) override;

			std::string getDirectory() const;
			void setDirectory(const std::string& path);

		private:
	};
}
