#pragma once

#include <vector>
#include <string>
#include <unordered_map>

using Props = std::vector<std::pair<std::string, std::string>>;

#ifdef PFSWGGENERATORCORE_EXPORTS
#define PFSWGGENERATORCORE_API __declspec(dllexport)
#else
#define PFSWGGENERATORCORE_API __declspec(dllimport)
#endif

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
            std::string getAttributeToString();
            Props getProps() const;

            void setAttribut(Attribute attribute);
            void setProps(Props props);

        private:
            Attribute _attribute;
            Props _props;
    };
}