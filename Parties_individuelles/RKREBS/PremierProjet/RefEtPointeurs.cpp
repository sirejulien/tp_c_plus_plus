#include <iostream>

using namespace std;

int main()
{
    auto maVariable1{42}, maVariable2{43}, maVariable3{44};
    auto maVariable4{451};
    // réservation d'une zone mémoire dans laquelle la valeur
    // C++ sera placée à cet emplacement mémoire le pc va 
    // coller une étiquette appelée maVariable1

    //poser une seconde étiquette à l'emplacement mémoire d'une variable
    // existante
    auto monPointeur{&maVariable1};
    
    cout << monPointeur << endl;
    cout << *monPointeur << endl;
    {
        auto maVariableTemporaire{55};
        monPointeur = &maVariableTemporaire;
    }

    cout << monPointeur << endl;

}