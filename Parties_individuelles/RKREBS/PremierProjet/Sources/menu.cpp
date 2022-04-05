#include "menu.h"
#include <iostream>
#include "constantes.h"
using namespace std;

void ChoixMenu demanderChoixMenu()
{
    char saisieChoix;
    cin >> saisieChoix;
    // on met a jour la condition demander choix menu
    if (saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_FACILE) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        return static_cast<ChoixMenu>(saisieChoix);
    }
    else
    {
        return ChoixMenu::INCORRECT;
    }
}

// il faut passer une référence
enum class ChoixMenu
{
    JOUER = 'a',
    JOUER_FACILE = 'b',
    JOUER_TROIS_PARTIES = 'c',
    QUITTER = 'q',
    INCORRECT
};

void afficherMenu()
{
    cout << static_cast<char>(ChoixMenu::JOUER) << ": jouer" << endl;
    // on ajoute les choix possible à l'affichage
    cout << static_cast<char>(ChoixMenu::JOUER_FACILE) << ": jouer" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) << ": jouer" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << ": quitter" << endl;
}