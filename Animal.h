#pragma once
#include "Cell.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Animal {
private:
    vector<Cell> cells;

public:
    // constructor
    Animal(vector<Cell> cells);

    // methods
    double calculateGeneticSimilarity(Animal otherAnimal);
    Animal asexualReproduction();
    Animal operator+(Animal otherAnimal);
    void cellularDeath();
};
