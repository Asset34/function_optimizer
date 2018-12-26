#include "geneticalgorithm.hpp"

#include <algorithm>

#include <utills/randomgenerator.hpp>

#include <QDebug>

OptimizeAlgorithm::Result GeneticAlgorithm::run(const Function &func, const Parameters &p)
{
//    qDebug() << p.populationSize;

//    double val;

//    // Generate initial population
//    Population curPopulation(p.populationSize, Chromosome(func.getSize()));
//    for (int i = 0; i < p.populationSize; i++) {
//        for (int j = 0; j < func.getSize(); j++) {
//            val = RandomGenerator::generateDouble(p.initMin, p.initMax);
//            curPopulation[i][j] = val;
//        }
//    }
//    qDebug() << "INITIAL_POPULATION:";
//    qDebug() << curPopulation;

//    Population nextPopulation(p.populationSize, Chromosome(func.getSize()));
//    Chromosome parent1, parent2, descendant;
//    for (int i = 0; i < p.maxIterations; i++) {
//        qDebug() << "ITERATON " << i << " --------------------------------------";
//        for (int j = 0; j < curPopulation.size(); j++) {
//            parent1 = chooseParent(curPopulation, func);
//            parent2 = chooseParent(curPopulation, func);

//            descendant = crossover(parent1, parent2, func, p);
//            if (RandomGenerator::generateAction(p.pmut)) {
//                mutation(descendant, p);
//            }

//            nextPopulation[j] = descendant;
//        }
//        qDebug() << "NEXT_POPULATION:";
//        qDebug() << nextPopulation;

//        curPopulation = nextPopulation;
//    }

//    // Find best chromosome in last population
//    Chromosome min = *std::min_element(curPopulation.begin(), curPopulation.end(),
//                     [&func](const Chromosome &c1, const Chromosome &c2) -> bool{
//        if (func(Vector(c1)) < func(Vector(c2))) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    });

//    return {min, p.maxIterations};
}

std::string GeneticAlgorithm::getName() const
{
    return "Genetic algorithm";
}

const GeneticAlgorithm::Chromosome &GeneticAlgorithm::chooseParent(
        const Population &population,
        const Function &func) const
{
    // Compute sum
    double sum = 0.0;
    for (Chromosome chromosome : population) {
        sum += 1.0 / func(Vector(chromosome));
    }

    // Compute sectors
    std::vector<double> chances(population.size());
    for (int i = 0; i < chances.size(); i++) {
        chances[i] = (1.0 / func(Vector(population[i]))) / sum;
    }

    // Choose index
    int n = RandomGenerator::generateRoulette(chances);

    return population[n];
}

GeneticAlgorithm::Chromosome GeneticAlgorithm::crossover(
        const Chromosome &p1,
        const Chromosome &p2,
        const Function &func,
        const Parameters &p
        ) const
{
    Chromosome result1(p1.size());
    Chromosome result2(p1.size());
    for (int i = 0; i < p1.size(); i++) {
        result1[i] = p.crossoverFactor * p1[i] + (1.0 - p.crossoverFactor) * p2[i];
        result2[i] = p.crossoverFactor * p2[i] + (1.0 - p.crossoverFactor) * p1[i];
    }

    if (func(Vector(result1)) < func(Vector(result2))) {
        return result1;
    }
    else {
        return result2;
    }
}

void GeneticAlgorithm::mutation(Chromosome &chromosome, const Parameters &p)
{
    double value;
    for (double &gen : chromosome) {
        value = RandomGenerator::generateDouble(0.0, p.mutationMax);
        if (RandomGenerator::generateBool()) {
            gen += value;
        }
        else {
            gen -= value;
        }
    }
}
