#include "geneticalgorithm.hpp"

GeneticAlgorithm::FitnessFunction::FitnessFunction(const Function &function)
    : m_function(function)
{
}

double GeneticAlgorithm::FitnessFunction::operator()(const Chromosome &ch) const
{
    return m_function(ch.toVector());
}
