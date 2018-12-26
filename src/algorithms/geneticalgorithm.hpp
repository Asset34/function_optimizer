#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include "optimizealgorithm.hpp"

#include <vector>

class GeneticAlgorithm : public OptimizeAlgorithm
{
public:
    virtual Result run(const Function &func, const Parameters &p) override;

    virtual std::string getName() const override;

private:
    /* Aliases */
    using Chromosome = std::vector<double>;
    using Population = std::vector<Chromosome>;

    const Chromosome &chooseParent(const Population &population, const Function &func) const;

    /* Genetic operators */
    Chromosome crossover(
            const Chromosome &p1,
            const Chromosome &p2,
            const Function &func,
            const Parameters &p
            ) const;
    void mutation(Chromosome &chromosome, const Parameters &p);

};

#endif // GENETICALGORITHM_HPP
