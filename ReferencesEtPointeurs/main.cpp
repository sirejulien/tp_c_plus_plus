#include <iostream>

using namespace std;

int main()
{
    //VARIABLES
    auto maVariable1{42}, maVariable2{48}, maVariable3{12};
    auto maVariable4{459l};
    //R�servation d'une zone m�moire ds laquelle la valeur C++ sera stock�e, le PC y met une etiquette "maVariable"

    //REFERENCES
    //poser une 2e etiquette "maReference" sur l'emplacement memoire d'une variable
    //on ne peut pas changer de variable r�f�renc�e apr�s l'initialisation de la r�f�rence
    //une r�f�rence renvoi la valeur situ�e sur l'emplacement m�moire
    auto &maReference{maVariable3};
    maReference=2;
    cout << maVariable3 << endl;
    maReference=maVariable2;
    cout << maVariable3 << endl;

    //POINTEURS
    //un pointeur renvoi l'adresse de l'emplacement m�moire de la variable
    // monPointeur contenant (adresse)
    // *monPointeur contenu (valeur)
    int *monPointeur(&maVariable1);
    cout << monPointeur << endl;
    monPointeur=&maVariable2;
    cout << monPointeur << endl;
    cout << *monPointeur << endl;

    *monPointeur=0;
    cout << monPointeur << endl;
    cout << *monPointeur << endl;
    cout << maVariable2 << endl;

    //variable temporaire au sein d'un bloc
    {
        auto maVariableTemp{98};
        monPointeur= &maVariableTemp;
    }

    cout << *monPointeur << endl;

    monPointeur = nullptr; //pointe vers l'adresse "null", d�sassigne le pointeur

    return 0;
}
