#include <iostream>

#include "menu.h"
#include "constantes.h"

using namespace std;

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
