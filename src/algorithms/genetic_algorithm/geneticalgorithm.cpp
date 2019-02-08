#include "geneticalgorithm.hpp"

#include <QDebug>

GeneticAlgorithm::GeneticAlgorithm()
    : m_iterations("Iterations", 0, 1e9, 100),
      m_populationSize("Population size", 0, 1e9, 100),
      m_selectionSize("Selection size", 0, 1e9, 90),
      m_tournamentSize("Tournament size", 0, 1e9, 2),
      m_mutationFactor("Mutation factor", 0.0, 1.0, 0.1),
      m_leftBound("Left bound", -1e9, 1e9, -10.0),
      m_rightBound("Right bound", -1e9, 1e9, 10.0)
{
}

std::string GeneticAlgorithm::getName() const
{
    return "Genetic Algorithm";
}

std::vector<Parameter*> GeneticAlgorithm::getParameters()
{
    return {
        &m_iterations,
        &m_populationSize,
        &m_selectionSize,
        &m_tournamentSize,
        &m_mutationFactor,
        &m_leftBound,
        &m_rightBound
    };
}

OptimizationResult GeneticAlgorithm::execute(const Function &f)
{
    FitnessFunction fitnessFunc(f);

    OptimizationData data;
    data.reserve(m_iterations + 1);

    Population population(m_populationSize, f.getSize());
    population.generate(m_leftBound, m_rightBound);
    data.push_back(population.getData());

    for (int i = 0; i < m_iterations; i++) {
        population.select(m_selectionSize, m_tournamentSize, fitnessFunc);
        population.reproduce(m_populationSize);
        population.mutate(m_mutationFactor, m_leftBound, m_rightBound);

        data.push_back(population.getData());
    }

    const Chromosome &min = population.findMin(fitnessFunc);

    return OptimizationResult {
        .iterations = m_iterations,
        .argument = min.toVector(),
        .value = f(min.toVector()),
        .data = data
    };
}
