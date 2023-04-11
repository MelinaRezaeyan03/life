#pragma once
#include <string>
#include <vector>
using namespace std;

class Genome {
private:
    string DNA[2];
    string RNA;

    string getComplement(string value);

public:
    Genome(string rna, string dna1, string dna2);
    Genome(string dna1, string dna2);
    void createDNAFromRNA();
    void smallMutation(char find, char replace, int n);
    void largeMutation(string subString, string replace);
    void reverse(string subString);
    string reverseString(string value);
    void printRNA();
    void printDNA();
    string* getDNA();
    char getComplementChar(char value);
};
