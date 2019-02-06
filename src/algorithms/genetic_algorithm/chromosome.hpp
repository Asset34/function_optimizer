#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <vector>

#include <parser/Utility/vector.hpp>

class GeneticAlgorithm::Chromosome
{
public:
    explicit Chromosome(int size = 0);

    double operator[](int index) const;
    double &operator[](int index);

    int getSize() const;

    void generate(double min, double max);
    void generateGen(int index, double min, double max);

    void mutate(double chance, double min, double max);
    void mutateGen(int index, double min, double max);
    static Chromosome crossover(const Chromosome &c1, const Chromosome &c2);

    Vector toVector() const;

private:
    std::vector<double> m_gens;

};

#endif // CHROMOSOME_HPP
