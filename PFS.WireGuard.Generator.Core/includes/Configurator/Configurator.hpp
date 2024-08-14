#pragma once

#include <string>

#include "Configurator/Block.hpp"

namespace PFSWireGuardGeneratorCore
{
    class Configurator
    {
        public:
            Configurator();


        private:
            std::vector<Block> _blocks;
    };
}
