#include "jeu.h"
#include <iostream>
#include "constantes.h"
using namespace std;

void demanderProposition(int &proposition)
{
    cin >> proposition;
}

void jouerPartie(int leJustePrix, int max)
// type pour le paramètre, pas auto, on remplace les occurrences de aDeviner par leJustePrix
{
    auto proposition{0};
    auto nombreTentatives{0};
    do
    {
        // comme dans tous les langages l'intérêt des fonctions est de pouvoir réutiliser le code
        cout << "Proposition? ";
        demanderProposition(proposition);

        cout << proposition;

        if (proposition >= BORNE_MIN && proposition < max)
        {
            nombreTentatives++;
            if (proposition == leJustePrix)
            {
                cout << "Bravo! " << endl;
            }
            else if (proposition > leJustePrix)
            {
                cout << "C'est moins ! " << endl;
            }
            else
            {
                cout << "C'est plus ! " << endl;
            }
        }
    } while (proposition != leJustePrix && proposition >= BORNE_MIN);

    if (proposition == leJustePrix)
    {
        cout << "partie terminée! "
             << "en " << nombreTentatives << " tentatives" << endl;
    }
    else
    {
        cout << "partie abandonnée ";
    }
}

// ici on ne souhaite pas retourner de valeur on utilise void
void jouerTroisParties()
{
    cout << "C'est parti ! " << endl;
    for (auto aDeviner : {208, 42, 1984})
    {
        // on veut la paramétrer avec le nombre a deviner
        jouerPartie(aDeviner, BORNE_MAX);
    }
}