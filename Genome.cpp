#include "Genome.h"
#include <iostream>
#include <string>
using namespace std;

string Genome::getComplement(string value) {
    string complement = "";

    for (int i = 0; i < value.length(); i++) {
        complement += getComplementChar(value[i]);
    }
    return complement;
}

char Genome::getComplementChar(char value) {
    if (value == 'A') {
        return 'T';
    }
    else if (value == 'T') {
        return 'A';
    }
    else if (value == 'C') {
        return 'G';
    }
    else if (value == 'G') {
        return 'C';
    }
    return '?';
}

// Constructor
Genome::Genome(string rna, string dna1, string dna2) {
    RNA = rna;
    DNA[0] = dna1;
    DNA[1] = dna2;
}

Genome::Genome(string dna1, string dna2)
{
    DNA[0] = dna1;
    DNA[1] = dna2;
}

// Method to create DNA from RNA and print it
void Genome::createDNAFromRNA() {
    cout << RNA << endl << getComplement(RNA) << endl;
}

void Genome::smallMutation(char find, char replace, int n) {
    int temp = n;
    for (int i = 0; RNA.length() > 0 && i < RNA.length() && temp > 0; i++) {
        if (RNA[i] == find) {
            temp--;
            RNA[i] = replace;
        }
    }

    temp = n;
    for (int i = 0; i < DNA[0].length() && temp > 0; i++) {
        if (DNA[0][i] == find) {
            temp--;
            DNA[0][i] = replace;
            DNA[1][i] = getComplementChar(replace);
        }
        else if (DNA[1][i] == find) {
            temp--;
            DNA[0][i] = getComplementChar(replace);
            DNA[1][i] = replace;
        }
    }
}

void Genome::largeMutation(string subString, string replace) {
    for (int i = 0; RNA.length() > 0 && i < RNA.length() - subString.length(); i++)
    {
        if (RNA.substr(i, subString.length()) == subString) {
            RNA.replace(i, subString.length(), replace);
            break;
        }
    }
    for (int i = 0; i < DNA[0].length() - subString.length(); i++)
    {
        if (DNA[0].substr(i, subString.length()) == subString) {
            DNA[0].replace(i, subString.length(), replace);
            DNA[1].replace(i, subString.length(), getComplement(replace));
            break;
        }
        else if (DNA[1].substr(i, subString.length()) == subString) {
            DNA[1].replace(i, subString.length(), replace);
            DNA[0].replace(i, subString.length(), getComplement(replace));
            break;
        }
    }
}

void Genome::reverse(string subString) {
    string reversedValue = reverseString(subString);
    for (int i = 0; i < RNA.length() > 0 && RNA.length() - subString.length(); i++)
    {
        if (RNA.substr(i, subString.length()) == subString) {
            RNA.replace(i, subString.length(), reversedValue);
            break;
        }
    }

    for (int i = 0; i < DNA[0].length() - subString.length(); i++)
    {
        if (DNA[0].substr(i, subString.length()) == subString) {
            DNA[0].replace(i, subString.length(), reversedValue);
            DNA[1].replace(i, subString.length(), getComplement(reversedValue));
            break;
        }
        else if (DNA[1].substr(i, subString.length()) == subString) {
            DNA[0].replace(i, subString.length(), getComplement(reversedValue));
            DNA[1].replace(i, subString.length(), reversedValue);
            break;
        }
    }
}

string Genome::reverseString(string value) {
    string reversedValue = "";
    for (int i = value.length() - 1; i >= 0; i--)
    {
        reversedValue += value[i];
    }
    return reversedValue;
}
void Genome::printRNA() {
    cout << "RNA:" << endl << RNA << endl;
}

void Genome::printDNA() {
    cout << "DNA:" << endl << DNA[0] << endl << DNA[1] << endl;
}

string* Genome::getDNA()
{
    return DNA;
}
