#include "Genome.h"
#include "Cell.h"
#include "Animal.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
        cout << "Melina Rezaeyan" << endl;
	cout << "Stn : 401441228" << endl;
	cout << "---------------\n\n";
	
	Genome genome = Genome("AATCCGATCCGCCTTA", "AATCCGATCCGCCTTA", "TTAGGCTAGGCGGAAT");
	genome.createDNAFromRNA();

	genome = Genome("ATCGATCG", "ACGGCCTAA", "TGCCGGATT");
	cout << "Small" << endl;

	genome.smallMutation('A', 'C', 2);
	genome.printRNA();
	genome.printDNA();

	genome = Genome("AAGTCTCAGT", "AAGTCTCAGT", "TTCAGAGTCA");
	cout << "Large" << endl;

	genome.largeMutation("TCAG", "ATC");
	genome.printRNA();
	genome.printDNA();

	genome = Genome("AAGTCTCAGT", "AAGTCTCAGT", "TTCAGAGTCA");
	cout << "Reverse" << endl;
	genome.reverse("GTC");
	genome.printRNA();
	genome.printDNA();
	
	vector<Genome> genomes = { Genome("AATCCGATCCGCCTTA", "TTAGGCTAGGCGGAAT"), Genome("AAGTCTCAGT", "TTCAGAGTCA"), Genome("AATTAAGCTC", "TTCAGAGTCA") };
	Cell cell = Cell(3, genomes);
	cell.largeMutation("TCCG", 0, "GTCT", 1);

	cell.smallMutation('A', 'C', 1, 1);

	cell.reverse("GTC", 1);

	cell.findComplementPalindromes();

	vector<Genome> genomes1 = { Genome("AATCCGATCCGCCTTA", "TTAGGCTAGGCGGAAT"), Genome("AAGTCTCAGT", "TTCAGAGTCA"), Genome("AATTAAGCTC", "TTCAGAGTCA") };
	vector<Genome> genomes2 = { Genome("AATCCGATCCGC", "TTAGGCTAGGCG"), Genome("CTCAGT", "GAGTCA"), Genome("CTCAGTGG", "GAGTCACC") };
	vector<Genome> genomes3 = { Genome("AATCCGATCCGCCTTA", "TTAGGCTAGGCGGAAT"), Genome("CTCAGTC", "GAGTCAG"), Genome("CTCAGTCCC", "GAGTCAGGG") };
	vector<Cell> cells1 = { Cell(3, genomes1), Cell(3, genomes2) };
	vector<Cell> cells2 = { Cell(3, genomes3), Cell(3, genomes1) };
	Animal animal1 = Animal(cells1);
	Animal animal2 = Animal(cells2);
	cout << animal1.calculateGeneticSimilarity(animal2) << endl;

	Animal newAnimal1 = animal1.asexualReproduction();
	cout << animal1.calculateGeneticSimilarity(newAnimal1) << endl;
	Animal newAnimal2 = animal1 + animal2;
	cout << animal1.calculateGeneticSimilarity(newAnimal2) << endl;
	cout << animal2.calculateGeneticSimilarity(newAnimal2) << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
