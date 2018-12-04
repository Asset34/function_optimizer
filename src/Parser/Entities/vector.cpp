#include "vector.hpp"

Vector::Vector(double coord)
{
    m_coords.append(coord);
}

Vector::Vector(const QVector<double> &coords)
    :m_coords(coords)
{
}

Vector::Vector(int size, double *coords)
    :m_coords(size)
{
    for (int i = 0; i < size; i++) {
        m_coords[i] = coords[i];
    }
}

Vector::Vector(const Vector &vec)
    :m_coords(vec.m_coords)
{
}

int Vector::getSize() const
{
    return m_coords.size();
}

double Vector::operator[](int pos) const
{
    checkIndex(pos);
    return m_coords[pos];
}

double &Vector::operator[](int pos)
{
    checkIndex(pos);
    return m_coords[pos];
}

Vector Vector::operator+(const Vector &vec) const
{
    checkSizes(vec);

    Vector result(vec);
    for (int i = 0; i < getSize(); i++) {
        result.m_coords[i] = m_coords[i] + vec.m_coords[i];
    }

    return result;
}

Vector Vector::operator-(const Vector &vec) const
{
    checkSizes(vec);

    Vector result(vec);
    for (int i = 0; i < getSize(); i++) {
        result.m_coords[i] = m_coords[i] - vec.m_coords[i];
    }

    return result;
}

double Vector::operator*(const Vector &vec) const
{
    checkSizes(vec);

    double result = 0;
    for (int i = 0; i < getSize(); i++) {
        result += m_coords[i] * vec.m_coords[i];
    }

    return result;
}

Vector Vector::operator*(double scalar) const
{
    Vector result(this->m_coords);
    for (int i = 0; i < m_coords.size(); i++) {
        result.m_coords[i] = scalar * m_coords[i];
    }

    return result;
}

Vector Vector::operator/(double scalar) const
{
    // Check for zero scalar
    if (scalar == 0) {
        throw std::invalid_argument("Zero scalar");
    }

    Vector result(this->m_coords);
    for (int i = 0; i < m_coords.size(); i++) {
        result.m_coords[i] = m_coords[i]/scalar;
    }

    return result;
}

QString Vector::toString() const
{
    QString str;

    str.append('(');
    for (int i = 0; i < m_coords.size() - 1; i++) {
        str.append(QString::number(m_coords[i]));
        str.append("; ");
    }
    str.append(QString::number(m_coords[m_coords.size() - 1]));
    str.append(')');

    return str;
}

void Vector::checkIndex(int pos) const
{
    if (pos < 0 || pos >= m_coords.size()) {
        throw std::out_of_range("Index out of range");
    }
}

void Vector::checkSizes(const Vector &vec) const
{
    if (m_coords.size() != vec.m_coords.size()) {
        throw std::invalid_argument("Operation with unequal vectors");
    }
}


Vector operator*(double scalar, const Vector &vec)
{
    return vec.operator *(scalar);
}

double norm(const Vector &vec)
{
    double sum = 0;

    for (int i = 0; i < vec.getSize(); i++) {
        sum += vec[i]*vec[i];
    }

    return sqrt(sum);
}

Vector normalize(const Vector &vec)
{
    return vec / norm(vec);
}

Vector zeroVector(int size)
{
    return Vector(QVector<double>(size));
}
