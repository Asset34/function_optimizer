#ifndef VECTORHPP_HPP
#define VECTORHPP_HPP

#include <vector>
#include <string>

class Vector
{
public:
    explicit Vector(int size, double value = 0.0);
    explicit Vector(const std::vector<double> &values);

    double operator[](int index) const;
    double &operator[](int index);

    int getSize() const;
    void setSize(int size);

    std::string toString() const;

private:
    std::vector<double> m_values;

};

#endif // VECTORHPP_HPP
