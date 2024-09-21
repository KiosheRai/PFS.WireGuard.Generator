#pragma once

#include "Configurator/Configurator.hpp"

#ifndef PFSWGGENERATORCORE_API
    #ifdef _WIN32
        #ifdef PFSWGGENERATORCORE_EXPORTS
            #define PFSWGGENERATORCORE_API __declspec(dllexport)
        #else
            #define PFSWGGENERATORCORE_API __declspec(dllimport)
        #endif
    #else
        #define PFSWGGENERATORCORE_API
    #endif
#endif

namespace PFSWireGuardGeneratorCoreAPI
{
    extern "C"
    {

    }
}
