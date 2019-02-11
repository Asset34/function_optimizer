#include "particleswarm.hpp"

#include <utills/randomgenerator.hpp>
#include <parser/Utility/vector.hpp>

ParticleSwarm::ParticleSwarm()
    : m_searchSpace("Search space"),
      m_min("Min", -1e9, 1e9, -10),
      m_max("Max", -1e9, 1e9, 10),
      m_iterations("Iterations", 0, 1e9, 10),
      m_swarmSize("Swarm size", 0, 1e9, 10),
      m_inertiaFactor("Inertia factor", 0.0, 1e9, 1.0),
      m_cognitiveFactor("Cognitive factor", -1e9, 1e9, 1.0),
      m_socialFactor("Social factor", -1e9, 1e9, 1.0)
{
    m_searchSpace.addParameter(&m_min);
    m_searchSpace.addParameter(&m_max);
}

std::string ParticleSwarm::getName() const
{
    return "Particle Swarm";
}

std::vector<Parameter*> ParticleSwarm::getParameters()
{
    return {
        &m_searchSpace,
        &m_iterations,
        &m_swarmSize,
        &m_inertiaFactor,
        &m_cognitiveFactor,
        &m_socialFactor
    };
}

OptimizationResult ParticleSwarm::execute(const Function &f)
{
    OptimizationData data;
    data.reserve(m_iterations + 1);

    // Initialize
    std::vector<Vector> positions(m_swarmSize, Vector(f.getSize()));
    std::vector<Vector> velocities(m_swarmSize, Vector(f.getSize()));
    std::vector<Vector> bestPositions(m_swarmSize, Vector(f.getSize()));
    for (int i = 0; i < m_swarmSize; i++) {
        positions[i].generate(m_min, m_max);
        velocities[i].generate(m_min - m_max, m_max - m_min);

        bestPositions[i] = positions[i];
    }
    data.push_back(positions);

    // Find initial swarm best solution
    Vector swarmBestPosition = *std::min_element(
        bestPositions.begin(),
        bestPositions.end(),
        [&f](const Vector &vec1, const Vector &vec2) -> bool
        {
            if (f(vec1) < f(vec2)) {
                return true;
            }
            else {
                return false;
            }
        }
    );

    double r1, r2;
    for (int i = 0; i < m_iterations; i++) {
        r1 = RandomGenerator::generateDouble(0.0, 1.0);
        r2 = RandomGenerator::generateDouble(0.0, 1.0);
        for (int j = 0; j < m_swarmSize; j++) {
            // Update velocity
            velocities[j] = m_inertiaFactor * velocities[j]
                          + m_cognitiveFactor * r1 * (bestPositions[j] - positions[j])
                          + m_socialFactor * r2 * (swarmBestPosition - positions[j]);

            // Update position
            positions[j] += velocities[j];

            // Update best local and global positions
            if (f(positions[j]) < f(bestPositions[j])) {
                bestPositions[j] = positions[j];
                if (f(bestPositions[j]) < f(swarmBestPosition)) {
                    swarmBestPosition = bestPositions[j];
                }
            }
        }

        data.push_back(positions);
    }

    return OptimizationResult {
        .searchSpace_min = m_min,
        .searchSpace_max = m_max,
        .iterations = m_iterations,
        .argument = swarmBestPosition,
        .value = f(swarmBestPosition),
        .data = data
    };
}
