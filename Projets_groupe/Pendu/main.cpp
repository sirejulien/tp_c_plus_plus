#include <iostream>
#include <vector>
#include <cctype>
#include "fonctions.h"

#include <chrono>
#include <ctime>

using namespace std;

int main()
{
    auto start = std::chrono::system_clock::now();
    Bienvenue();

    // Initialisation des variables

    string MotATrouver = GetMotATrouver();
    string Reponse;
    for (int i = 0; i<MotATrouver.length(); i++)
    {
        Reponse = Reponse +"_";
    }
    int Echecs = 0;
    vector<char> incorrect;
    bool LettreTrouve = false;
    char lettre;

    // Boucle tant que le mot n'a pas été trouvé
    while (Reponse!=MotATrouver && Echecs < 7)
    {
        // On affiche le pendu et les lettres mauvaises en-dessous
        afficher_echecs(Echecs);
        afficher_etat(incorrect, Reponse);

        // On demande la lettre que le joueur veut essayer
        cout<<"\n\nTu souhaites essayer la lettre : ";
        cin>>lettre;

        // on vérifie pour chaque lettre du mot si le lettre est contenue dans le mot.
        for(int i = 0; i<MotATrouver.length(); i++)
        {
            if(toupper(lettre)==MotATrouver[i])
            {
                Reponse[i] = toupper(lettre);
                LettreTrouve = true;
            }
        }

        //Si au moins 1 lettre est dedans, on affiche "Correct", sinon le pendu se dessine.
        if(LettreTrouve)
        {
            cout<<"\nCorrect !\n";
        }
        else
        {
            cout<<"\nIncorrect ! Le pendu se dessine de + en +.\n";
            incorrect.push_back(lettre);
            Echecs++;
        }
        LettreTrouve = false;
    }
    // texte de fin de partie qui affiche quelque chose de différent si le mot a été trouvé ou non.
    FinPartie(Reponse, MotATrouver);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Temps écoulé: " << elapsed_seconds.count() << "s\n";

    return 0;
}
