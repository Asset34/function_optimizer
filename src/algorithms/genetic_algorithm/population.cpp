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

std::vector<Vector> GeneticAlgorithm::Population::getData() const
{
    std::vector<Vector> data(getSize());
    for (int i = 0; i < getSize(); i++) {
        data[i] = m_chromosomes[i].toVector();
    }

    return data;
}

const GeneticAlgorithm::Chromosome &GeneticAlgorithm::Population::findMin(const FitnessFunction &f) const
{
    return *std::min_element(
        m_chromosomes.begin(),
        m_chromosomes.end(),
        [&f](const Chromosome &ch1, const Chromosome &ch2) -> bool
        {
            if (f(ch1) < f(ch2)) {
                return true;
            }
            else {
                return false;
            }
        }
    );
}

const GeneticAlgorithm::Chromosome &GeneticAlgorithm::Population::findMin(
        const std::vector<int> indexes,
        const FitnessFunction &f
        ) const
{
    int index = *std::min_element(
        indexes.begin(),
        indexes.end(),
        [this, &f](int index1, int index2) -> bool
        {
            if (f(m_chromosomes[index1]) < f(m_chromosomes[index2])) {
                return true;
            }
            else {
                return false;
            }
        }
    );

    return m_chromosomes[index];
}

void GeneticAlgorithm::Population::generate(double min, double max)
{
    for (Chromosome &ch : m_chromosomes) {
        ch.generate(min, max);
    }
}

void GeneticAlgorithm::Population::select(int size, int tournamentSize, const FitnessFunction &f)
{
    std::vector<Chromosome> result(size);
    std::vector<int> indexes;
    for (int i = 0; i < size; i++) {
        indexes = RandomGenerator::generateSet(tournamentSize, 0, getSize() - 1);
        result[i] = findMin(indexes, f);
    }

    m_chromosomes = result;
}

void GeneticAlgorithm::Population::reproduce(int size)
{
    assert(!m_chromosomes.empty());

    std::vector<Chromosome> result(size);
    std::vector<int> indexes;
    for (int i = 0; i < size; i++) {
        indexes = RandomGenerator::generateSet(2, 0, getSize() - 1);
        result[i] = Chromosome::crossover(
                        m_chromosomes[ indexes[0] ],
                        m_chromosomes[ indexes[1] ]
                    );
    }

    m_chromosomes = result;
}

void GeneticAlgorithm::Population::mutate(double chance, double min, double max)
{
    for (Chromosome &ch : m_chromosomes) {
        ch.mutate(chance, min, max);
    }
}
