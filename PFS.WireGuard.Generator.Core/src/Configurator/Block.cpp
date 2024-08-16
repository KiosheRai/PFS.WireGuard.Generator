#include "Configurator/Block.hpp"

namespace PFSWireGuardGeneratorCore
{
    Block::Block() :
        _attribute(Attribute::Undefined), _props({{"", ""}})
    {

    }

    Block::Block(Attribute attribute, Props props) :
        _attribute(attribute), _props(std::move(props))
    {

    }

    Attribute Block::getAttribute() const { return _attribute; }

    std::string Block::getAttributeToString() { return AttributeToString.at(_attribute); }

    Props Block::getProps() const { return _props; }

    void Block::setAttribut(Attribute attribute)
    {
        _attribute = attribute;
    }

    void Block::setProps(Props &props)
    {
        _props = props;
    }
}
