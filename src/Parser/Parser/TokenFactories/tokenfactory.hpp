#ifndef TOKENFACTORY_HPP
#define TOKENFACTORY_HPP

#include "../Tokens/token.hpp"
#include "../../Entities/position.hpp"

class TokenFactory
{
public:
    virtual ~TokenFactory();
    virtual bool check(const Position &pos) const = 0;
    virtual Token *takeToken(Position &pos) const = 0;
};

#endif // TOKENFACTORY_HPP
