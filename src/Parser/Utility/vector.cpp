#include "vector.hpp"

#include <sstream>

//std::default_random_engine Vector::m_engine(
//        std::chrono::system_clock::now().time_since_epoch().count()
//        );
std::default_random_engine Vector::m_engine;

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

void Vector::generate(double min, double max)
{
    std::uniform_real_distribution<double> distr(min, max);
    for (double &value : m_values) {
        value = distr(m_engine);
    }
}

void Vector::generateAt(int index, double min, double max)
{
    std::uniform_real_distribution<double> distr(min, max);
    m_values[index] = distr(m_engine);
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
