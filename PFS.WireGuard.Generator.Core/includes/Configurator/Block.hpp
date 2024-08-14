#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#define Props std::vector<std::pair<std::string, std::string>>

namespace PFSWireGuardGeneratorCore
{
    enum class Attribute
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

    class Block
    {
        public:
            Block();
            Block(Attribute attribute, Props props);

            Attribute getAttribute() const;
            std::string getAttributeToString();
            Props getProps() const;

            void setAttribut(Attribute attribute);
            void setProps(Props &props);

        private:
            Attribute _attribute;
            Props _props;
    };
}
