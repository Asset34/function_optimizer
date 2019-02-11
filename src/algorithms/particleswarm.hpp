#ifndef PARTICLESWARM_HPP
#define PARTICLESWARM_HPP

#include "optimizationalgorithm.hpp"

#include <parameterized_algorithm_qt/core/parameters/intparameter.hpp>
#include <parameterized_algorithm_qt/core/parameters/realparameter.hpp>
#include <parameterized_algorithm_qt/core/parameters/compositeparameter.hpp>

class ParticleSwarm : public OptimizationAlgorithm
{
public:
    ParticleSwarm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual OptimizationResult execute(const Function &f) override;

private:
    CompositeParameter m_searchSpace;
    RealParameter m_min;
    RealParameter m_max;

    IntParameter m_iterations;
    IntParameter m_swarmSize;
    RealParameter m_cognitiveFactor;
    RealParameter m_socialFactor;

};

#endif // PARTICLESWARM_HPP
