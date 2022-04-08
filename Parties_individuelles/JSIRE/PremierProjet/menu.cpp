#include <iostream>

#include "menu.h"
#include "constantes.h"

using namespace std;

ChoixMenu SelectionMenu(void) { //fonction renvoyant le choix menu de l'utilisateur
    char saisieChoixMenu;

    cout << "Bienvenu au Juste Prix!" << endl;
        cout << static_cast<char>(ChoixMenu::JOUER) << " - Jouer" << endl;  //affichage des proposition
        cout << static_cast<char>(ChoixMenu::QUITTER) << " - Quitter" << endl;
        cout << "Que voulez-vous faire?" << endl;
        cin >> saisieChoixMenu; //recuperation de la saisie

         if (saisieChoixMenu == static_cast<char>(ChoixMenu::JOUER) || saisieChoixMenu == static_cast<char>(ChoixMenu::QUITTER)) { //test si la saisie est valide
            return static_cast<ChoixMenu>(saisieChoixMenu);
        } else {
            return ChoixMenu::INCORRECT;
        }

}
