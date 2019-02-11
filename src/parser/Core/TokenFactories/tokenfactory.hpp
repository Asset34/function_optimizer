#ifndef TOKENFACTORY_HPP
#define TOKENFACTORY_HPP

#include <Core/Tokens/token.hpp>
#include <Utility/position.hpp>

class TokenFactory
{
public:
    virtual ~TokenFactory() = default;
    virtual bool check(const Position &pos) const = 0;
    virtual Token *takeToken(Position &pos) const = 0;

};

#endif // TOKENFACTORY_HPP
