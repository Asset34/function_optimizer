#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include "optimizealgorithm.hpp"

class GeneticAlgorithm : public OptimizeAlgorithm
{
public:
    virtual Result run(const Function &func, const Parameters &p) override;

private:


};

#endif // GENETICALGORITHM_HPP
