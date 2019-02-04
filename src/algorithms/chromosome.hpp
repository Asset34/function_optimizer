#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <vector>

class GeneticAlgorithm::Chromosome
{
public:
    explicit Chromosome(int size);

    double operator[](int index) const;
    double &operator[](int index);

    int getSize() const;
    const std::vector<double> getData() const;

    void generate(double min, double max);
    void mutation(double chance, double min, double max);
    static Chromosome crossover(const Chromosome &c1, const Chromosome &c2);

private:
    std::vector<double> m_gens;

};

#endif // CHROMOSOME_HPP
