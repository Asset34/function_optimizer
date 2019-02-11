#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include "../optimizationalgorithm.hpp"

#include <parameterized_algorithm_qt/core/parameters/intparameter.hpp>
#include <parameterized_algorithm_qt/core/parameters/realparameter.hpp>
#include "parameterized_algorithm_qt/core/parameters/compositeparameter.hpp"

class GeneticAlgorithm : public OptimizationAlgorithm
{
public:
    GeneticAlgorithm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual OptimizationResult execute(const Function &f) override;

private:
    class FitnessFunction;
    class Chromosome;
    class Population;

    CompositeParameter m_searchSpace;
    RealParameter m_min;
    RealParameter m_max;

    IntParameter m_iterations;
    IntParameter m_populationSize;
    IntParameter m_selectionSize;
    IntParameter m_tournamentSize;
    RealParameter m_mutationFactor;

};

#include "fitnessfunction.hpp"
#include "chromosome.hpp"
#include "population.hpp"

#endif // GENETICALGORITHM_HPP
