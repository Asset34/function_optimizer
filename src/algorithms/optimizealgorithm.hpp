#ifndef OPTIMIZEALGORITHM_HPP
#define OPTIMIZEALGORITHM_HPP

#include <Parser/Functions/function.hpp>

class OptimizeAlgorithm
{
public:
    struct Result
    {
        double value;
        int iterations;
    };

    struct Parameters
    {
        int maxIterations;
        int size;
    };

    virtual ~OptimizeAlgorithm() = default;

    virtual Result run(const Function *func, const Parameters &p) = 0;

};

#endif // OPTIMIZEALGORITHM_HPP
