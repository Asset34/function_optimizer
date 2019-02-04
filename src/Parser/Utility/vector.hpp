#ifndef VECTORHPP_HPP
#define VECTORHPP_HPP

#include <vector>
#include <string>
#include <random>

class Vector
{
public:
    explicit Vector(int size, double value = 0.0);
    explicit Vector(const std::vector<double> &values);

    double operator[](int index) const;
    double &operator[](int index);

    int getSize() const;
    void setSize(int size);

    const std::vector<double> getData() const;

    void generate(double min, double max);
    void generateAt(int index, double min, double max);

    std::string toString() const;

private:
    std::vector<double> m_values;

    static std::default_random_engine m_engine;

};

#endif // VECTORHPP_HPP
