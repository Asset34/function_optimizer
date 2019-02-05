#include "vector.hpp"

#include <sstream>

Vector::Vector(int size, double value)
    : m_values(size, value)
{
}

Vector::Vector(const std::vector<double> &values)
    : m_values(values)
{
}

double Vector::operator[](int index) const
{
    return m_values[index];
}

double &Vector::operator[](int index)
{
    return m_values[index];
}

int Vector::getSize() const
{
    return m_values.size();
}

void Vector::setSize(int size)
{
    m_values.resize(size);
}

std::string Vector::toString() const
{
    std::ostringstream ss;
    ss << "(";
    for (double value : m_values) {
        ss << value << ", ";
    }
    ss << ")";

    return ss.str();
}
