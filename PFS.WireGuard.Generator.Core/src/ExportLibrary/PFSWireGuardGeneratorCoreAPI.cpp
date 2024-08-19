#include "ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp"

namespace PFSWireGuardGeneratorCoreAPI
{
	void writeBlockToFile(const char* file_name, PFSWireGuardGeneratorCore::Block& block)
	{
		PFSWireGuardGeneratorCore::FileIO::writeBlockToFile(file_name, block);
	}

	std::string getTextFromFile(const char* file_name)
	{
		return PFSWireGuardGeneratorCore::FileIO::getTextFromFile(file_name);
	}
}