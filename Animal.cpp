#include "Animal.h"
using namespace std;

Animal::Animal(vector<Cell> cells)
{
	this->cells = cells;
}

double Animal::calculateGeneticSimilarity(Animal otherAnimal)
{
	double similarity = 0;
	int cellCount = cells.size();

	for (int i = 0; i < cellCount; i++) {
		int commonGenes = 0;
		int geneCount = cells[i].getNumChromosomes();
		for (int j = 0; j < geneCount; j++) {
			if (i < otherAnimal.cells.size() && j < otherAnimal.cells[i].getChromosomes().size())
				if (cells[i].getChromosomes()[j].getDNA()[0] == otherAnimal.cells[i].getChromosomes()[j].getDNA()[0]) {
					commonGenes++;
				}
		}

		similarity += (double)commonGenes / geneCount;
	}

	return similarity / cellCount * 100;

}

Animal Animal::asexualReproduction()
{
	int num_cells = cells.size();
	vector<Cell> new_cells;
	for (int i = 0; i < num_cells; i++) {
		if (i % 7 != 0) {
			new_cells.push_back(cells[i]);
		}
	}
	int remainedSize = num_cells - new_cells.size();

	for (int i = 0; i < remainedSize; i++) {
		new_cells.push_back(Cell(1, {}));
	}
	return Animal(new_cells);
}

Animal Animal::operator+(Animal otherAnimal)
{
	if (cells.size() % 2 == 1 || otherAnimal.cells.size() % 2 == 1) {
		cout << "Cannot perform sexual reproduction with odd number of chromosomes" << endl;
		return Animal({});
	}
	vector<Cell> new_cells;
	int num_chromosomes = cells.size();
	for (int i = 0; i < num_chromosomes; i++) {
		if (i % 2 == 0) {
			new_cells.push_back(cells[i]);
		}
		else {
			new_cells.push_back(otherAnimal.cells[i]);
		}
	}

	return Animal(new_cells);
}

void Animal::cellularDeath()
{
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].death();
	}
}
