#ifndef CHARPREDICATE_HPP
#define CHARPREDICATE_HPP

#include <QChar>

class CharPredicate
{
public:
    virtual ~CharPredicate();

    virtual bool execute(QChar ch) const = 0;
};

#endif // CHARPREDICATE_HPP
