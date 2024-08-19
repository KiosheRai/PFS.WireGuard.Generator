#pragma once

#include "Configurator/FileIO.hpp"
#include "Models/Client.hpp"
#include "Models/Server.hpp"

#ifdef PFSWGGENERATORCORE_EXPORTS
#define PFSWGGENERATORCORE_API __declspec(dllexport)
#else
#define PFSWGGENERATORCORE_API __declspec(dllimport)
#endif

namespace PFSWireGuardGeneratorCoreAPI
{
    extern "C" {
        PFSWGGENERATORCORE_API void writeBlockToFile(const char* file_name, PFSWireGuardGeneratorCore::Block& block);
        PFSWGGENERATORCORE_API std::string getTextFromFile(const char* file_name);
    }
}
