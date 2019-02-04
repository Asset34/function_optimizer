#include "geneticalgorithm.hpp"

#include <assert.h>
#include <algorithm>

#include <utills/randomgenerator.hpp>

GeneticAlgorithm::Population::Population(int size, int chromosomeSize)
    : m_chromosomes(size, Chromosome(chromosomeSize))
{
}

const GeneticAlgorithm::Chromosome &GeneticAlgorithm::Population::operator[](int index) const
{
    return m_chromosomes[index];
}

GeneticAlgorithm::Chromosome &GeneticAlgorithm::Population::operator[](int index)
{
    return m_chromosomes[index];
}

int GeneticAlgorithm::Population::getSize() const
{
    return m_chromosomes.size();
}

std::vector<std::vector<double> > GeneticAlgorithm::Population::getData() const
{
    std::vector<std::vector<double>> data(getSize());
    for (int i = 0; i < getSize(); i++) {
        data[i] = m_chromosomes[i].getData();
    }

    return data;
}

const GeneticAlgorithm::Chromosome &GeneticAlgorithm::Population::findMin(const Function &f) const
{
    const Chromosome &min = *std::min_element(
                m_chromosomes.begin(),
                m_chromosomes.end(),
                [this, &f](const Chromosome &ch1, const Chromosome &ch2) -> bool
                {
                    if (f(ch1.getData()) < f(ch2.getData())) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                );

    return min;
}

void GeneticAlgorithm::Population::generate(double min, double max)
{
    for (Chromosome &ch : m_chromosomes) {
        ch.generate(min, max);
    }
}

GeneticAlgorithm::Population GeneticAlgorithm::Population::selection(
        int size,
        int tournamentSize,
        const Function &f
        ) const
{
    assert(!m_chromosomes.empty());

    Population result(size , m_chromosomes[0].getSize());
    std::vector<int> indexes;
    for (int i = 0; i < size; i++) {
        indexes = RandomGenerator::generateSet(tournamentSize, 0, getSize() - 1);
        int bestIndex = *std::min_element(
                        indexes.begin(),
                        indexes.end(),
                        [this, &f](int index1, int index2) -> bool
                        {
                            Chromosome ch1 = m_chromosomes[index1];
                            Chromosome ch2 = m_chromosomes[index2];

                            if (f(ch1.getData()) < f(ch2.getData())) {
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                        );
        result.m_chromosomes[i] = m_chromosomes[bestIndex];
    }

    return result;
}

GeneticAlgorithm::Population GeneticAlgorithm::Population::reproduction(int size) const
{
    assert(!m_chromosomes.empty());

    Population result(size, m_chromosomes[0].getSize());
    int index1, index2;
    for (int i = 0; i < size; i++) {
        index1 = RandomGenerator::generateInt(0, getSize() - 1);
        index2 = RandomGenerator::generateInt(0, getSize() - 1);

        const Chromosome &ch1 = m_chromosomes[index1];
        const Chromosome &ch2 = m_chromosomes[index2];

        result[i] = Chromosome::crossover(ch1, ch2);
    }

    return result;
}

void GeneticAlgorithm::Population::mutation(
        double chance,
        double min,
        double max
        )
{
    for (Chromosome &ch : m_chromosomes) {
        ch.mutation(chance, min, max);
    }
}
