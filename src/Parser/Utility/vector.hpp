#ifndef VECTORHPP_HPP
#define VECTORHPP_HPP

#include <vector>
#include <string>
#include <random>

class Vector
{
public:
    explicit Vector(int size = 0, double value = 0.0);
    explicit Vector(const std::vector<double> &values);

    double operator[](int index) const;
    double &operator[](int index);

    int getSize() const;
    void setSize(int size);

    void generate(double min, double max);

    Vector operator+(const Vector &vec) const;
    Vector operator-(const Vector &vec) const;
    Vector operator*(const Vector &vec) const;
    Vector operator*(double scalar) const;
    Vector operator/(double scalar) const;
    Vector &operator+=(const Vector &vec);
    Vector &operator-=(const Vector &vec);

    std::string toString() const;

private:
    std::vector<double> m_values;

    static std::default_random_engine m_engine;

};

Vector operator*(double scalar, const Vector &vec);

#endif // VECTORHPP_HPP
