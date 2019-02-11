#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <vector>

#include <parser/Utility/vector.hpp>

class Chromosome;
class FitnessFunction;

class GeneticAlgorithm::Population
{
public:
    Population(int size, int chromosomeSize = 0);

    const Chromosome &operator[](int index) const;
    Chromosome &operator[](int index);

    int getSize() const;
    std::vector<Vector> getData() const;

    const Chromosome &findMin(const FitnessFunction &f) const;
    const Chromosome &findMin(const std::vector<int> indexes, const FitnessFunction &f) const;

    void generate(double min, double max);

    void select(int size, int tournamentSize, const FitnessFunction &f);
    void reproduce(int size);
    void mutate(double chance, double min, double max);

private:
    std::vector<Chromosome> m_chromosomes;

};

#endif // POPULATION_HPP
