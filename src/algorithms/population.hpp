#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <vector>

class Chromosome;
class Function;

class GeneticAlgorithm::Population
{
public:
    Population(int size, int chromosomeSize);

    const Chromosome &operator[](int index) const;
    Chromosome &operator[](int index);

    int getSize() const;
    std::vector<std::vector<double>> getData() const;

    const Chromosome &findMin(const Function &f) const;

    void generate(double min, double max);

    Population selection(int size, int tournamentSize, const Function &f) const;
    Population reproduction(int size) const;
    void mutation(double chance, double min, double max);

private:
    std::vector<Chromosome> m_chromosomes;

};

#endif // POPULATION_HPP
