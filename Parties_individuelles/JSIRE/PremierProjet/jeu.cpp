#include <iostream>
#include <stdlib.h>

#include "jeu.h"
#include "constantes.h"

using namespace std;

void Proposition (int &refProposition) {    //fonction pour r�cup�rer la proposition de prix
    int saisieProposition;
    cin >> saisieProposition;
    refProposition=saisieProposition;
}

void Jouer(void) {  //fonction consistuant le coeur du jeu

    int aDeviner{rand() % BORNE_MAX + BORNE_MIN}; //nbre al�atoire entre 1 et 1000
    int proposition{0};
    bool partieGagnee {false};

    for (int nbrTentative = 1; nbrTentative <= 10; nbrTentative++ ){ //boucle limitant le nombre de tentatives
        cout << "Faites une proposition" << endl;

        Proposition(proposition);

        if (aDeviner==proposition) {    //conditions de victoire
            cout << "Exact! Vous avez trouv� en " << nbrTentative << " tentatives" << endl;
            partieGagnee=true;
            break;
        } else if (proposition>aDeviner){
            cout << "C'est moins!" << endl;
        } else {
            cout << "C'est plus!" << endl;
        }
    }

    if (partieGagnee) {
        cout << "Bravo, vous avez gagn�!" << endl;
    } else {
        cout << "Dommage vous avez d�pass� le nombre de tentatives... le juste prix �tait "<< aDeviner << endl;
    }
}
