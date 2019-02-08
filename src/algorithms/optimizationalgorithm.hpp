#ifndef OPTIMIZATIONALGORITHM_HPP
#define OPTIMIZATIONALGORITHM_HPP

#include <vector>

#include <parser/function.hpp>
#include <parser/Utility/vector.hpp>
#include <parameterized_algorithm_qt/core/algorithm.hpp>

using OptimizationData = std::vector<std::vector<Vector>>;

struct OptimizationResult
{
    int iterations;
    Vector argument;
    double value;
    OptimizationData data;
};

class OptimizationAlgorithm : public Algorithm
{
public:
    virtual OptimizationResult execute(const Function &f) = 0;

};

#endif // OPTIMIZATIONALGORITHM_HPP
