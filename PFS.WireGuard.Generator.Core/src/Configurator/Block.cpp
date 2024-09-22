#include "Configurator/Block.hpp"

namespace PFSWireGuardGeneratorCore
{
    Block::Block() :
        _attribute(Attribute::Undefined), _props({{"", ""}})
    { }

    Block::Block(Attribute attribute, Props props) :
        _attribute(attribute), _props(std::move(props))
    { }

    Attribute Block::getAttribute() const
    {
        return _attribute;

    }

    std::string Block::getAttributeToString() const
    {
        return AttributeToString.at(_attribute);
    }

    Props Block::getProps() const
    {
        return _props;
    }

    std::string Block::getDescription() const
    {
        return _description;
    }

    void Block::setAttribut(const Attribute attribute)
    {
        _attribute = attribute;
    }

    void Block::setProps(const Props props)
    {
        _props = std::move(props);
    }

    void Block::setDescription(const std::string& description)
    {
        _description = description;
    }
}
