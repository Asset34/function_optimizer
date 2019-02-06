#ifndef FITNESSFUNCTION_HPP
#define FITNESSFUNCTION_HPP

#include <parser/function.hpp>

class Chromosome;

class GeneticAlgorithm::FitnessFunction
{
public:
    FitnessFunction(const Function &function);
    double operator()(const Chromosome &ch) const;

private:
    const Function &m_function;

};

#endif // FITNESSFUNCTION_HPP
