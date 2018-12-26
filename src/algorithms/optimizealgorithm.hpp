#ifndef OPTIMIZEALGORITHM_HPP
#define OPTIMIZEALGORITHM_HPP

#include <Parser/Functions/function.hpp>

#include <string>

class OptimizeAlgorithm
{
public:
    struct Result
    {
        std::vector<double> values;
        int iterations;
    };

    struct Parameters
    {
        // General parameters
        int maxIterations;

        // Genetic algorithm parameters
        int populationSize;
        double initMin;
        double initMax;
        double crossoverFactor;
        double mutationMax;
        double pmut;
    };

    virtual ~OptimizeAlgorithm() = default;

    virtual Result run(const Function &func, const Parameters &p) = 0;

    virtual std::string getName() const = 0;

};

#endif // OPTIMIZEALGORITHM_HPP
