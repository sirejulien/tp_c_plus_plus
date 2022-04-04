#include <iostream>

#include "jeu.h"
#include "menu.h"

using namespace std;

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



