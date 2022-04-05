#include <iostream>

#include "fonctions.h"

using namespace std;

string nomJoueur1;
string nomJoueur2;

bool gameOver{false};

int main()
{
    Bienvenue(nomJoueur1, nomJoueur2);
    MiseEnPlace(1);
    MiseEnPlace(2);
    RAZTableau();

    do {
        Tir(1);
        Tir(2);
    } while (!gameOver);

    return 0;
}
