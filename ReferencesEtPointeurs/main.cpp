#include <iostream>

using namespace std;

int main()
{
    //VARIABLES
    auto maVariable1{42}, maVariable2{48}, maVariable3{12};
    auto maVariable4{459l};
    //Réservation d'une zone mémoire ds laquelle la valeur C++ sera stockée, le PC y met une etiquette "maVariable"

    //REFERENCES
    //poser une 2e etiquette "maReference" sur l'emplacement memoire d'une variable
    //on ne peut pas changer de variable référencée après l'initialisation de la référence
    //une référence renvoi la valeur située sur l'emplacement mémoire
    auto &maReference{maVariable3};
    maReference=2;
    cout << maVariable3 << endl;
    maReference=maVariable2;
    cout << maVariable3 << endl;

    //POINTEURS
    //un pointeur renvoi l'adresse de l'emplacement mémoire de la variable
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

    monPointeur = nullptr; //pointe vers l'adresse "null", désassigne le pointeur

    return 0;
}
