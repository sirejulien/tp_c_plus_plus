#include <iostream>
#include <stdlib.h>

using namespace std;

void jouer(void) {  //fonction consistuant le coeur du jeu
    int aDeviner{rand() % 1000 + 1}; //nbre aléatoire entre 1 et 1000
    int proposition{0};
    bool partieGagnee {false};

    for (int nbrTentative = 1; nbrTentative <= 10; nbrTentative++ ){ //boucle limitant le nombre de tentatives
        cout << "Faites une proposition" << endl;
        cin >> proposition;
        if (aDeviner==proposition) {
            cout << "Exact! Vous avez trouvé en " << nbrTentative << " tentatives" << endl;
            partieGagnee=true;
            break;
        } else if (proposition>aDeviner){
            cout << "C'est moins!" << endl;
        } else {
            cout << "C'est plus!" << endl;
        }
    }

    if (partieGagnee) {
        cout << "Bravo, vous avez gagné!" << endl;
    } else {
        cout << "Dommage vous avez dépassé le nombre de tentatives... le juste prix était "<< aDeviner << endl;
    }
}

int main()
{
    int choixMenu{0};
    bool exitProg {false};

    while (!exitProg) { //boucle permettant de faire plusieurs parties tant que l'utilisateur veut continuer
        cout << "Bienvenu au Juste Prix!" << endl;
        cout << "1-Nouvelle Partie" << endl;
        cout << "2-Quitter" << endl;
        cout << "Que voulez-vous faire?";
        cin >> choixMenu;

        switch ( choixMenu )    //switch pour donner le choix à l'utilisateur de jouer ou de quitter
      {
         case 1:
            jouer();
            break;
         case 2:
            exitProg=true;
            break;
         default:
            cout << "Erreur saisie" << endl;
            break;
      }
    }

    cout << "Au revoir" << endl;

    return 0;
}



