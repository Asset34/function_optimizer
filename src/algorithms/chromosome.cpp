#include "geneticalgorithm.hpp"

#include <assert.h>

#include <utills/randomgenerator.hpp>

GeneticAlgorithm::Chromosome::Chromosome(int size)
    : m_gens(size)
{
}

double GeneticAlgorithm::Chromosome::operator[](int index) const
{
    return m_gens[index];
}

double &GeneticAlgorithm::Chromosome::operator[](int index)
{
    return m_gens[index];
}

int GeneticAlgorithm::Chromosome::getSize() const
{
    return m_gens.size();
}

const std::vector<double> GeneticAlgorithm::Chromosome::getData() const
{
    return m_gens;
}

void GeneticAlgorithm::Chromosome::generate(double min, double max)
{
    for (double &gen : m_gens) {
        gen = RandomGenerator::generateDouble(min, max);
    }
}

void GeneticAlgorithm::Chromosome::mutation(double chance, double min, double max)
{
    for (double &gen : m_gens) {
        if (RandomGenerator::generateAction(chance)) {
            gen = RandomGenerator::generateDouble(min, max);
        }
    }
}

GeneticAlgorithm::Chromosome GeneticAlgorithm::Chromosome::crossover(
        const Chromosome &c1,
        const Chromosome &c2
        )
{
    assert(c1.getSize() == c2.getSize());

    Chromosome result(c1.getSize());
    for (int i = 0; i < c1.getSize(); i++) {
        if (c1[i] < c2[i]) {
            result[i] = RandomGenerator::generateDouble(c1[i], c2[i]);
        }
        else {
            result[i] = RandomGenerator::generateDouble(c2[i], c1[i]);
        }
    }

    return result;
}
