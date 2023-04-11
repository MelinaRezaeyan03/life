#include "Cell.h"
#include <iostream>
using namespace std;

Cell::Cell(int numChromosomes, vector<Genome> chromosomes)
{
	this->numChromosomes = numChromosomes;
	this->chromosomes = chromosomes;
}

void Cell::death()
{
	for (int i = 0; i < numChromosomes; i++) {
		if (!isValidChromosome(chromosomes[i])) {
			cout << "Cell [" << i << "] has died due to chromosomal abnormalities." << endl;
		}
	}
}

void Cell::largeMutation(string s1, int n, string s2, int m)
{
	cout << "Before largeMutation:" << endl;
	chromosomes[n].printDNA();
	chromosomes[m].printDNA();

	string* dnaS1 = chromosomes[n].getDNA();
	string* dnaS2 = chromosomes[m].getDNA();

	int pos1 = (dnaS1[0] + dnaS1[1]).find(s1);
	int pos2 = (dnaS2[0] + dnaS2[1]).find(s2);
	if (pos1 < 0 || pos2 < 0) {
		cout << "Substring not found." << endl;
		return;
	}
	chromosomes[n].largeMutation(s1, s2);
	chromosomes[m].largeMutation(s2, s1);

	cout << "After largeMutation:" << endl;
	chromosomes[n].printDNA();
	chromosomes[m].printDNA();
}

void Cell::smallMutation(char find, char replace, int n, int m)
{
	cout << "Before smallMutation:" << endl;
	chromosomes[m].printDNA();

	string* dna = chromosomes[m].getDNA();
	int pos = (dna[0] + dna[1]).find(find);
	if (pos < 0) {
		cout << "Substring not found in " << m << endl;
		return;
	}
	chromosomes[m].smallMutation(find, replace, n);

	cout << "After smallMutation:" << endl;
	chromosomes[m].printDNA();
}

void Cell::reverse(string s1, int n)
{
	cout << "Before reverse:" << endl;
	chromosomes[n].printDNA();

	string* dna = chromosomes[n].getDNA();
	int pos = (dna[0] + dna[1]).find(s1);
	if (pos < 0) {
		cout << "Substring not found in " << n << endl;
		return;
	}
	chromosomes[n].reverse(s1);

	cout << "After reverse:" << endl;
	chromosomes[n].printDNA();
}

void Cell::findComplementPalindromes()
{
	for (int i = 0; i < chromosomes.size(); i++) {
		cout << "chromosome " << i << endl;

		string geneContent = chromosomes[i].getDNA()[0];
		int len = geneContent.length();
		for (int j = 2; j <= len; j += 1) {
			for (int k = 0; k <= len - j; k++) {
				string sub = geneContent.substr(k, j);
				if (isPalindrome(sub)) {
					string revComplement = reverseComplement(sub);
					cout << k << ", " << j << ":" << sub << ":" << revComplement << endl;
				}
			}
		}
	}
}

int Cell::getNumChromosomes()
{
	return this->numChromosomes;
}

vector<Genome> Cell::getChromosomes()
{
	return this->chromosomes;
}

bool Cell::isPalindrome(string str) {
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			return false;
		}
	}
	return true;
}

string Cell::reverseComplement(string str) {
	string result = "";
	int len = str.length();
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if (c == 'A') {
			result = 'T' + result;
		}
		else if (c == 'T') {
			result = 'A' + result;
		}
		else if (c == 'C') {
			result = 'G' + result;
		}
		else if (c == 'G') {
			result = 'C' + result;
		}
	}
	return result;
}

bool Cell::isValidChromosome(Genome chromosome)
{
	string* DNA = chromosome.getDNA();
	int invalidChromosomes = 0;
	for (int i = 0; i < DNA[0].length(); i++)
	{
		if (chromosome.getComplementChar(DNA[0][i]) != DNA[1][i])
			invalidChromosomes++;
	}

	if (invalidChromosomes > 5)
		return false;
		
	return true;
}
