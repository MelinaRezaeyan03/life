#pragma once
#include "Genome.h"
#include <string>

class Cell {
public:
    Cell(int numChromosomes, vector<Genome> chromosomes);
    void death();
    void largeMutation(string s1, int n, string s2, int m);
    void smallMutation(char find, char replace, int n, int m);
    void reverse(string s1, int n);
    void findComplementPalindromes();
    int getNumChromosomes();
    vector<Genome> getChromosomes();

private:
    int numChromosomes;
    vector<Genome> chromosomes;
    bool isValidChromosome(Genome chromosome);
    bool isPalindrome(string str);
    string reverseComplement(string str);
};
