#ifndef POSITION_HPP
#define POSITION_HPP

#include <QString>

class Position
{
public:
    explicit Position(const QString &data, int index = 0);

    const Position &operator++();
    const Position &operator++(int d);
    const Position &operator--();
    const Position &operator--(int d);
    Position operator+(int d) const;
    Position operator-(int d) const;

    QChar getChar() const;
    int getNumber() const;
    bool isBegin() const;
    bool isEnd() const;

    static QString makeString(const Position &pos1, const Position &pos2);

private:
    QString m_data;
    int m_index;
};

#endif // POSITION_HPP
