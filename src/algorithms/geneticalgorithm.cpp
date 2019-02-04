#include "geneticalgorithm.hpp"

#include <QDebug>

GeneticAlgorithm::GeneticAlgorithm()
    : m_iterations("Iterations", 0, 1e9, 10),
      m_populationSize("Population size", 0, 1e9, 10),
      m_tournamentSize("Tournament size", 0, 1e9, 2),
      m_survivalFactor("Survival factor", 0.0, 1.0, 0.8),
      m_mutationFactor("Mutation factor", 0.0, 1.0, 0.1),
      m_leftBound("Left bound", -1e9, 1e9, -100.0),
      m_rightBound("Right bound", -1e9, 1e9, 100.0)
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
        &m_tournamentSize,
        &m_survivalFactor,
        &m_mutationFactor,
        &m_leftBound,
        &m_rightBound
    };
}

OptimizationResult GeneticAlgorithm::execute(const Function &f)
{
    int survivalSize = m_populationSize * m_survivalFactor;

    Population cur(m_populationSize, f.getSize());
    cur.generate(m_leftBound, m_rightBound);

    Population next(m_populationSize, f.getSize());
    for (int i = 0; i < m_iterations; i++) {
        next = cur.selection(survivalSize, m_tournamentSize, f);
        next = next.reproduction(m_populationSize);
        next.mutation(m_mutationFactor, m_leftBound, m_rightBound);

        cur = next;
    }

    Chromosome min = cur.findMin(f);

    qDebug() << min.getData();
    Vector vec(min.getData());
    std::string test = vec.toString();
    QString str = QString::fromStdString(test);
    qDebug() << str;

    return OptimizationResult {
        .iterations = m_iterations,
        .argument = Vector(min.getData()),
        .value = f(min.getData())
    };
}
