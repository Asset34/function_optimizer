#include "particleswarm.hpp"

#include <utills/randomgenerator.hpp>
#include <parser/Utility/vector.hpp>

ParticleSwarm::ParticleSwarm()
    : m_iterations("Iterations", 0, 1e9, 10),
      m_swarmSize("Swarm size", 0, 1e9, 10),
      m_leftBound("Left bound", -1e9, 1e9, -10),
      m_rightBound("Right bound", -1e9, 1e9, 10),
      m_cognitiveFactor("Cognitive factor", -1e9, 1e9, 1.0),
      m_socialFactor("Social factor", -1e9, 1e9, 1.0)
{
}

std::string ParticleSwarm::getName() const
{
    return "Particle Swarm";
}

std::vector<Parameter*> ParticleSwarm::getParameters()
{
    return {
        &m_iterations,
        &m_swarmSize,
        &m_leftBound,
        &m_rightBound,
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
        positions[i].generate(m_leftBound, m_rightBound);
        velocities[i].generate(m_leftBound - m_rightBound, m_rightBound - m_leftBound);

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

    Vector r1(m_swarmSize);
    Vector r2(m_swarmSize);
    for (int i = 0; i < m_iterations; i++) {
        for (int j = 0; j < m_swarmSize; j++) {
            // Update velocity
            r1.generate(0.0, 1.0);
            r2.generate(0.0, 1.0);
            velocities[j] += m_cognitiveFactor * r1 * (bestPositions[j] - positions[j])
                          +  m_socialFactor * r2 * (swarmBestPosition - positions[j]);

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
        .iterations = m_iterations,
        .leftBound = m_leftBound,
        .rightBound = m_rightBound,
        .argument = swarmBestPosition,
        .value = f(swarmBestPosition),
        .data = data
    };
}
