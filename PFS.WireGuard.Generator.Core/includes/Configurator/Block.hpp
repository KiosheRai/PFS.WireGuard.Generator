#pragma once

#include <vector>
#include <string>
#include <unordered_map>

using Props = std::vector<std::pair<std::string, std::string>>;

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
            std::string getDescription();

            void setAttribut(Attribute attribute);
            void setProps(Props props);
            void setDescription(std::string description);

        private:
            Attribute _attribute;
            Props _props;
            std::string _description;
    };
}
