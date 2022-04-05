#include <iostream>
#include "constantes.h"
#include "jeu.h"
#include "menu.h"
#include "menu.cpp"
#include "jeu.cpp"

using namespace std;
/************************************************************************************************************************************************/

int main()
{

    cout << "Bienvenue au juste prix" << endl;

    // on créé un booléen continuer
    bool continuer(true);
    // ici on insert la boucle while
    while (continuer)
    {
        afficherMenu();
        // ici lorsqu'on initialise une var avec le result d'un func on utilise =
        auto choix = demanderChoixMenu();
        switch (choix)
        {
            // on met à jour le switch aussi
        case ChoixMenu::JOUER:
            jouerPartie(3000, BORNE_MAX);
            break;
        case ChoixMenu::JOUER_FACILE:
            jouerPartie(250, BORNE_MAX_FACILE);
            break;
        case ChoixMenu::JOUER_TROIS_PARTIES:
            jouerTroisParties();
            break;
        case ChoixMenu::QUITTER:
            cout << "Au revoir " << endl;
            // on met variable continuer a false afin de pouvoir sortir de la boucle
            continuer = false;
            break;
        case ChoixMenu::INCORRECT:
        default:
            return EXIT_FAILURE;
        }
    }
    // rigoureusement on devrait ajouter ceci
    return EXIT_SUCCESS;
}

/******/

// créer un fichier constantes.h et cocher debug et release
// et enregistrer le projet !!! très important pour la compilation
// création de trois lignes par défaut directives préprocesseur, ici on évite de déclare plusieurs fois le contenu de notre fichier

// à cet endroit le nom de la constante que nous allons utiliser doit être unique dans l'ensemble de tout notre programme

// #pragma once on verra plus tard

// on passe au dossier !!