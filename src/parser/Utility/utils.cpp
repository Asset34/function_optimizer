#include "utils.hpp"

namespace Utils {

bool check(const Position &pos, const CharPredicate &pr)
{
    return !pos.isEnd()   &&
           !pos.isBegin() &&
            pr.execute(pos.getChar());
}

bool check(const QStack<Token*> &tokens, TokenPredicate &pr)
{
    return !tokens.empty() && pr.execute(*tokens.top());
}

bool check(Token &t, const QStack<Token*> &tokens, TokenComparePredicate &pr)
{
    return !tokens.empty() && pr.execute(t, *tokens.top());
}

const Position &moveWhile(Position &pos, const CharPredicate &pr)
{
    while (check(pos, pr)) {
        pos++;
    }

    return pos;
}

QList<Token*> moveWhile(QStack<Token*> &tokens, TokenPredicate &pr)
{
    QList<Token*> result;

    while (check(tokens, pr)) {
        result.append(tokens.pop());
    }

    return result;
}

QList<Token*> moveWhile(Token &t, QStack<Token*> &tokens, TokenComparePredicate &pr)
{
    QList<Token*> result;

    while (check(t, tokens, pr)) {
        result.append(tokens.pop());
    }

    return result;
}

QList<Token*> moveUntil(QStack<Token*> &tokens, TokenPredicate &pr)
{
    QList<Token*> result;

    while (!check(tokens, pr)) {
        result.append(tokens.pop());
    }

    return result;
}

} // Utils
