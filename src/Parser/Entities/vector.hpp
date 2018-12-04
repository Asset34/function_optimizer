#ifndef VECTORHPP_HPP
#define VECTORHPP_HPP

#include <stdexcept>

#include <QtMath>
#include <QVector>

class Vector
{
public:
    explicit Vector(const QVector<double> &coords);
    Vector(int size, double *coords);
    Vector(double coord = 0); // "explicit" is missing intentionally
    Vector(const Vector &vec);

    int getSize() const;
    double operator[](int pos) const;
    double &operator[](int pos);

    Vector operator+(const Vector &vec) const;
    Vector operator-(const Vector &vec) const;
    Vector operator*(double scalar) const;
    Vector operator/(double scalar) const;
    double operator*(const Vector &vec) const;

    QString toString() const;

private:
    QVector<double> m_coords;

    void checkIndex(int pos) const;
    void checkSizes(const Vector &vec) const;

protected:
};

Vector operator*(double scalar, const Vector &vec);

// Norm of the vector
double norm(const Vector &vec);
// Get normalized vector
Vector normalize(const Vector &vec);
// Get zero vector
Vector zeroVector(int size);

#endif // VECTORHPP_HPP
