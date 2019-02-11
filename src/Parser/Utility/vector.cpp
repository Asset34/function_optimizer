#include "vector.hpp"

#include <sstream>

//std::default_random_engine RandomGenerator::m_engine(
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

Vector Vector::operator+(const Vector &vec) const
{
    Vector result(getSize());
    for (int i = 0; i < getSize(); i++) {
        result[i] = m_values[i] + vec[i];
    }

    return result;
}

Vector Vector::operator-(const Vector &vec) const
{
    Vector result(getSize());
    for (int i = 0; i < getSize(); i++) {
        result[i] = m_values[i] - vec[i];
    }

    return result;
}

Vector Vector::operator*(const Vector &vec) const
{
    Vector result(getSize());
    for (int i = 0; i < getSize(); i++) {
        result[i] = m_values[i] * vec[i];
    }

    return result;
}

Vector Vector::operator*(double scalar) const
{
    Vector result(getSize());
    for (int i = 0; i < getSize(); i++) {
        result[i] = scalar * m_values[i];
    }

    return result;
}

Vector Vector::operator/(double scalar) const
{
    Vector result(getSize());
    for (int i = 0; i < getSize(); i++) {
        result[i] = m_values[i] / scalar;
    }

    return result;
}

Vector &Vector::operator+=(const Vector &vec)
{
    for (int i = 0; i < getSize(); i++) {
        m_values[i] += vec[i];
    }

    return *this;
}

Vector &Vector::operator-=(const Vector &vec)
{
    for (int i = 0; i < getSize(); i++) {
        m_values[i] -= vec[i];
    }

    return *this;
}

std::string Vector::toString() const
{
    std::ostringstream ss;

    if (getSize()) {
        ss << "(";

        ss << m_values[0];
        for (int i = 1; i < getSize(); i++) {
            ss << ", ";
            ss << m_values[i];
        }

        ss << ")";
    }

    return ss.str();
}

Vector operator*(double scalar, const Vector &vec)
{
    return vec * scalar;
}
