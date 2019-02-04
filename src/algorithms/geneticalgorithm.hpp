#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include "optimizationalgorithm.hpp"

#include <parameterized_algorithm_qt/core/parameters/intparameter.hpp>
#include <parameterized_algorithm_qt/core/parameters/realparameter.hpp>

class GeneticAlgorithm : public OptimizationAlgorithm
{
public:
    GeneticAlgorithm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual OptimizationResult execute(const Function &f) override;

private:
    class Chromosome;
    class Population;

    IntParameter m_iterations;
    IntParameter m_populationSize;
    IntParameter m_tournamentSize;
    RealParameter m_survivalFactor;
    RealParameter m_mutationFactor;
    RealParameter m_leftBound;
    RealParameter m_rightBound;

};

#include "chromosome.hpp"
#include "population.hpp"

#endif // GENETICALGORITHM_HPP
