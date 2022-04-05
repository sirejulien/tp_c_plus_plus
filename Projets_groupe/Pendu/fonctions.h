#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

// déclarations des fonctions
void Bienvenue();
void afficher_echecs(int Echecs);
void afficher_etat(vector<char> incorrect, string Reponse);
void FinPartie(string Reponse, string MotATrouver);
string GetMotATrouver();


#endif // FONCTIONS_H_INCLUDED
