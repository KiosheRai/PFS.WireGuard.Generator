#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "ExportLibrary/PFSWGGeneratorCoreExport.hpp"

using Props = std::vector<std::pair<std::string, std::string>>;

namespace PFSWireGuardGeneratorCore
{
    enum class PFSWGGENERATORCORE_API Attribute
    {
        Interface,
        Peer,
        Undefined
    };

    static const std::unordered_map<Attribute, std::string> AttributeToString
    {
        {Attribute::Interface, "[Interface]"},
        {Attribute::Peer, "[Peer]"},
        {Attribute::Undefined, "[Undefined]"}
    };

    class PFSWGGENERATORCORE_API Block
    {
        public:
            Block();
            Block(Attribute attribute, Props props);

            Attribute getAttribute() const;
            std::string getAttributeToString() const;
            Props getProps() const;
            std::string getDescription() const;

            void setAttribut(const Attribute attribute);
            void setProps(const Props props);
            void setDescription(const std::string& description);

        private:
            Attribute _attribute;
            Props _props;
            std::string _description;
    };
}
