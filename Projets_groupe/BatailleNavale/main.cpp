#include <iostream>

#include "fonctions.h"

using namespace std;

string nomJoueur1;
string nomJoueur2;

int numJoueurGagnant{0};

int main()
{
    Bienvenue(nomJoueur1, nomJoueur2);
    MiseEnPlace(1);
    AffichageTableau(1);
    system("pause");
    system("CLS");
    MiseEnPlace(2);
    AffichageTableau(2);
    system("pause");
    system("CLS");
    RAZTableau();

    do {
        AffichageTableau(1);
        Tir(1);
        AffichageTableau(2);
        Tir(2);
        numJoueurGagnant=TestVictoire();
    } while (numJoueurGagnant==0);

    if (numJoueurGagnant==1) {
        cout << "F�licitations " << nomJoueur1<< ", tu as gagn�!" << endl;
    } else if (numJoueurGagnant==2) {
        cout << "F�licitations " << nomJoueur2<< ", tu as gagn�!" << endl;
    }

    return 0;
}
