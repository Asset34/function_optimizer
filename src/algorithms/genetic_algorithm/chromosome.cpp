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
    return m_gens.getSize();
}

void GeneticAlgorithm::Chromosome::generate(double min, double max)
{
    m_gens.generate(min, max);
}

void GeneticAlgorithm::Chromosome::mutate(double chance, double min, double max)
{
    for (int i = 0; i < m_gens.getSize(); i++) {
        if (RandomGenerator::generateAction(chance)) {
            m_gens.generateAt(i, min, max);
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
            result.m_gens.generateAt(i, c1[i], c2[i]);
        }
        else {
            result.m_gens.generateAt(i, c2[i], c1[i]);
        }
    }

    return result;
}

const Vector &GeneticAlgorithm::Chromosome::toVector() const
{
    return m_gens;
}
