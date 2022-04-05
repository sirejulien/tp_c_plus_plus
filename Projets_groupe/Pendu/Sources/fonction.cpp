#include <iostream>
#include <vector>
#include "fonctions.h"
using namespace std;

#define fonctions

//définition des fonctions

//Message de bienvenue
void Bienvenue()
{
    cout << "===================\n";
    cout << "Jeu du pendu\n";
    cout << "===================\n";
    cout << "But du jeu : deviner le mot ou une personne sera pendue.\n";
}

//Affichage du pendu en fonction du nombre d'echecs
void afficher_echecs(int Echecs)
{
    if(Echecs==0)
    {
        cout <<"  ______\n";
        cout <<"  |/\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"__|__\n";
    }
    else if (Echecs==1)
    {
        cout <<"  ______\n";
        cout <<"  |/   |\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"__|__\n";
    }
    else if (Echecs==2)
    {
        cout <<"  ______\n";
        cout <<"  |/   |\n";
        cout <<"  |    o\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"__|__\n";
    }
    else if (Echecs==3)
    {
        cout <<"  ______\n";
        cout <<"  |/   |\n";
        cout <<"  |    o\n";
        cout <<"  |    |\n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"__|__\n";
    }
    else if (Echecs==4)
    {
        cout <<"  ______\n";
        cout <<"  |/   |\n";
        cout <<"  |    o\n";
        cout <<"  |   /|\\ \n";
        cout <<"  |\n";
        cout <<"  |\n";
        cout <<"__|__\n";
    }
    else if (Echecs==5)
    {
        cout <<"  ______\n";
        cout <<"  |/   |\n";
        cout <<"  |    o\n";
        cout <<"  |   /|\\ \n";
        cout <<"  |   /\n";
        cout <<"  |\n";
        cout <<"__|__\n";
    }
    else if (Echecs==6)
    {
        cout <<"  ______\n";
        cout <<"  |/   |\n";
        cout <<"  |    o\n";
        cout <<"  |   /|\\ \n";
        cout <<"  |   / \\ \n";
        cout <<"  |\n";
        cout <<"__|__\n";
    }

}

// afficher les lettres mauvaises
void afficher_etat(vector<char> incorrect, string Reponse)
{
    cout<<"Lettres mauvaises : \n";

    for (int i = 0; i<incorrect.size(); i++)
    {
        cout << incorrect[i]<<" ";
    }

    cout <<"\nMot à trouver :\n";

    for (int i = 0; i<Reponse.length(); i++)
    {
        cout<<Reponse[i]<<" ";
    }
}

//afficher le message de fin de partie selon si le mot a été trouvé ou non
void FinPartie(string Reponse, string MotATrouver)
{
    if(Reponse==MotATrouver)
    {
        cout<<"Vous avez gagné en + d'avoir sauvé une vie numérique !\n";
    }
    else
    {
        cout<<"Ah ! Une personne est morte et c'est entièrement de votre faute !\n";
    }
}