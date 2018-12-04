#ifndef UTILS_HPP
#define UTILS_HPP

#include "Entities/position.hpp"
#include "Parser/Tokens/token.hpp"
#include "Parser/Predicates/CharPredicates/charpredicate.hpp"
#include "Parser/Predicates/TokenPredicates/tokenpredicate.hpp"
#include "Parser/Predicates/TokenPredicates/tokencomparepredicate.hpp"
#include "Functions/function.hpp"

#include <QVector>
#include <QList>
#include <QStack>

namespace Utils {

/* Parser utills */
bool check(const Position &pos, const CharPredicate &pr);
bool check(const QStack<Token*> &tokens, TokenPredicate &pr);
bool check(Token &t, const QStack<Token*> &tokens, TokenComparePredicate &pr);

const Position &moveWhile(Position &pos, const CharPredicate &pr);
QList<Token*> moveWhile(QStack<Token*> &tokens, TokenPredicate &pr);
QList<Token*> moveWhile(Token &t, QStack<Token*> &tokens, TokenComparePredicate &pr);

QList<Token*> moveUntil(QStack<Token*> &tokens, TokenPredicate &pr);

} // Utils

#endif // UTILS_HPP
