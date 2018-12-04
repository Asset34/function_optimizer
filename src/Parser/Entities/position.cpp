#include "position.hpp"

Position::Position(const QString &data, int index)
    :m_data(data), m_index(index)
{
}

Position::Position(const Position &pos)
    :m_data(pos.m_data), m_index(pos.m_index)
{
}

const Position &Position::operator ++()
{
    m_index++;
    return *this;
}

const Position &Position::operator ++(int d)
{
    ++m_index;
    return *this;
}

const Position &Position::operator --()
{
    m_index--;
    return *this;
}

const Position &Position::operator --(int d)
{
    --m_index;
    return *this;
}

Position Position::operator +(int d) const
{
    return Position(m_data, m_index + d);
}

Position Position::operator -(int d) const
{
    return Position(m_data, m_index - d);
}

QChar Position::getChar() const
{
    if (m_index < 0 || m_index >= m_data.length()) {
        throw std::out_of_range("Invalid data position");
    }

    return m_data[m_index];
}

int Position::getNumber() const
{
    return m_index;
}

bool Position::isBegin() const
{
    return m_index == -1;
}

bool Position::isEnd() const
{
    return m_index == m_data.length();
}

QString Position::makeString(const Position &pos1, const Position &pos2)
{
    return pos1.m_data.mid(pos1.m_index, pos2.m_index - pos1.m_index);
}
