#ifndef OPTIMIZATIONALGORITHM_HPP
#define OPTIMIZATIONALGORITHM_HPP

#include <vector>

#include <parser/function.hpp>
#include <parameterized_algorithm_qt/core/algorithm.hpp>

struct OptimizationResult
{
    int iterations;
    std::vector<double> value;
};

class OptimizationAlgorithm : public Algorithm
{
public:
    virtual OptimizationResult execute(const Function &f) = 0;

};

#endif // OPTIMIZATIONALGORITHM_HPP
