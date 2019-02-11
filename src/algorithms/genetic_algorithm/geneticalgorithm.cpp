#include "geneticalgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm()
    : m_searchSpace("Search space"),
      m_min("Min", -1e9, 1e9, -10),
      m_max("Max", -1e9, 1e9, 10),
      m_iterations("Iterations", 0, 1e9, 10),
      m_populationSize("Population size", 0, 1e9, 10),
      m_selectionSize("Selection size", 0, 1e9, 10),
      m_tournamentSize("Tournament size", 0, 1e9, 3),
      m_mutationFactor("Mutation factor", 0.0, 1.0, 0.01)
{
    m_searchSpace.addParameter(&m_min);
    m_searchSpace.addParameter(&m_max);
}

std::string GeneticAlgorithm::getName() const
{
    return "Genetic Algorithm";
}

std::vector<Parameter*> GeneticAlgorithm::getParameters()
{
    return {
        &m_searchSpace,
        &m_iterations,
        &m_populationSize,
        &m_selectionSize,
        &m_tournamentSize,
        &m_mutationFactor
    };
}

OptimizationResult GeneticAlgorithm::execute(const Function &f)
{
    FitnessFunction fitnessFunc(f);

    OptimizationData data;
    data.reserve(m_iterations + 1);

    Population population(m_populationSize, f.getSize());
    population.generate(m_min, m_max);
    data.push_back(population.getData());

    for (int i = 0; i < m_iterations; i++) {
        population.select(m_selectionSize, m_tournamentSize, fitnessFunc);
        population.reproduce(m_populationSize);
        population.mutate(m_mutationFactor, m_min, m_max);

        data.push_back(population.getData());
    }

    const Chromosome &min = population.findMin(fitnessFunc);

    return OptimizationResult {
        .searchSpace_min = m_min,
        .searchSpace_max = m_max,
        .iterations = m_iterations,
        .argument = min.toVector(),
        .value = f(min.toVector()),
        .data = data
    };
}
