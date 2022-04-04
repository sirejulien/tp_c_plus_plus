#include <iostream>
#include <stdlib.h>

using namespace std;

void Jouer(void) {  //fonction consistuant le coeur du jeu
    const auto BORNE_MIN{1};
    const auto BORNE_MAX{1000};
    int aDeviner{rand() % BORNE_MAX + BORNE_MIN}; //nbre aléatoire entre 1 et 1000
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

enum class ChoixMenu
{
    JOUER='j',
    QUITTER='q',
    INCORRECT
};

ChoixMenu SelectionMenu(void) {
    char saisieChoixMenu;

    cout << "Bienvenu au Juste Prix!" << endl;
        cout << static_cast<char>(ChoixMenu::JOUER) << " - Jouer" << endl;
        cout << static_cast<char>(ChoixMenu::QUITTER) << " - Quitter" << endl;
        cout << "Que voulez-vous faire?" << endl;
        cin >> saisieChoixMenu;

         if (saisieChoixMenu == static_cast<char>(ChoixMenu::JOUER) || saisieChoixMenu == static_cast<char>(ChoixMenu::QUITTER)) {
            return static_cast<ChoixMenu>(saisieChoixMenu);
        } else {
            return ChoixMenu::INCORRECT;
        }

}

int main()
{
    auto choixMenu{ChoixMenu::JOUER};
    bool exitProg {false};

    while (!exitProg) { //boucle permettant de faire plusieurs parties tant que l'utilisateur veut continuer


       choixMenu=SelectionMenu();

        switch ( choixMenu )    //switch pour donner le choix à l'utilisateur de jouer ou de quitter
      {
         case ChoixMenu::JOUER:
            Jouer();
            break;
         case ChoixMenu::QUITTER:
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



