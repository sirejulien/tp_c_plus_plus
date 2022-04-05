#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <iostream>


using namespace std;

void Bienvenue(string &nomJoueur1, string &nomJoueur2);
void MiseEnPlace(int numJoueur);
void ModificationLigne(int numJoueur, char colonne, char ligne, char modeModif);
void Tir(int numJoueur);
bool TestTouche (int numJoueur,char colonneTir,char ligneTir);
void RAZTableau (void);

#endif // FONCTIONS_H_INCLUDED
