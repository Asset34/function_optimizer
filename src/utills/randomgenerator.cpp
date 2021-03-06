#include "randomgenerator.hpp"

#include <algorithm>
#include <numeric>
#include <chrono>

//std::default_random_engine RandomGenerator::m_engine(
//        std::chrono::system_clock::now().time_since_epoch().count()
//        );
std::default_random_engine RandomGenerator::m_engine;
std::uniform_int_distribution<int> RandomGenerator::m_boolDistr(0, 1);

bool RandomGenerator::generateBool()
{
    return m_boolDistr(m_engine);
}

int RandomGenerator::generateInt(int min, int max)
{
    return std::uniform_int_distribution<int>{min, max}(m_engine);
}

double RandomGenerator::generateDouble(double min, double max)
{
    std::uniform_real_distribution<double> distr(min, max);

    return distr(m_engine);
}

int RandomGenerator::generateRoulette(const std::vector<double> &sectors)
{
    // Compute sum of sectors
    double sum = 0;
    for (double value : sectors) {
        sum += value;
    }

    double value = generateDouble(0.0, sum);

    // Choose sector
    double border = 0.0;
    int sector = -1;
    while (value > border)
    {
        sector++;
        border += sectors[sector];
    }

    return sector;
}

std::vector<int> RandomGenerator::generateSet(int count, int min, int max)
{
    std::vector<int> values(max - min + 1);

    std::iota(values.begin(), values.end(), min);
    std::shuffle(values.begin(), values.end(), m_engine);
    values.resize(count);

    return values;
}

bool RandomGenerator::generateAction(double chance)
{
    double result = generateDouble(0.0, 1.0);
    if (result <= chance) {
        return true;
    }

    return false;
}
