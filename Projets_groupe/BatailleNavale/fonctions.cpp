#include <iostream>

#include "fonctions.h"
#include "variables.h"

using namespace std;

//d�finition des fonctions

//Message de bienvenue
void Bienvenue(string &nomJoueur1, string &nomJoueur2)
{
    cout <<"                                  )___(\n";
    cout <<"                           _______/__/_\n";
    cout <<"                  ___     /===========|   ___\n";
    cout <<" ____       __   [\\\\\\]___/____________|__[///]   __\n";
    cout <<" \\   \\_____[\\\\]__/___________________________\\__[//]___\n";
    cout <<"  \\40A                                                 |\n";
    cout <<"   \\                                                  /\n";
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "===================\n";
    cout << "Bataille Navale\n";
    cout << "===================\n";
    cout << "But du jeu : couler les navires de l'adversaire avant de s'�tre fait couler les siens.\n";
    cout << "Nom du 1er joueur?\n";
    cin >> nomJoueur1;
    cout << "Nom du 2e joueur?\n";
    cin >> nomJoueur2;
    cout << "Bienvenus " << nomJoueur1 <<" et "<< nomJoueur2 <<", la partie va commencer!" <<endl;
    cout << nomJoueur1 <<" sera la joueur 1 et "<< nomJoueur2 <<" sera le joueur 2." <<endl;
}

void affichageTableau(string ligne0, string ligne1, string ligne2, string ligne3,string ligne4, string ligne5, string ligne6) {
    cout << "=================" << endl;
    cout << ligne0 << endl;
    cout << ligne1 << endl;
    cout << ligne2 << endl;
    cout << ligne3 << endl;
    cout << ligne4 << endl;
    cout << ligne5 << endl;
    cout << ligne6 << endl;
}

void MiseEnPlace(int numJoueur) {
    int nbreNaviresAPlacer{6};
    char colonnePlacement;
    char lignePlacement;
    while (nbreNaviresAPlacer>0) {
            if (numJoueur==1)
            {
                affichageTableau(ligne0_J1,ligne1_J1,ligne2_J1,ligne3_J1,ligne4_J1,ligne5_J1,ligne6_J1);
                cout << "selectionner la colonne o� vous voulez placer un navire:" <<endl;
                cin >> colonnePlacement;
                cout << "selectionner la ligne o� vous voulez placer un navire:" <<endl;
                cin >> lignePlacement;
                ModificationLigne(1,colonnePlacement,lignePlacement,'X');
                string s;
                s.push_back(toupper(colonnePlacement));
                s.push_back(toupper(lignePlacement));
                PlacementsJ1.push_back(s);
            }
            else if (numJoueur==2)
            {
                affichageTableau(ligne0_J2,ligne1_J2,ligne2_J2,ligne3_J2,ligne4_J2,ligne5_J2,ligne6_J2);
                cout << "selectionner la colonne o� vous voulez placer un navire:" <<endl;
                cin >> colonnePlacement;
                cout << "selectionner la ligne o� vous voulez placer un navire:" <<endl;
                cin >> lignePlacement;
                ModificationLigne(2,colonnePlacement,lignePlacement,'X');
                string s;
                s.push_back(toupper(colonnePlacement));
                s.push_back(toupper(lignePlacement));
                PlacementsJ2.push_back(s);
            }
            nbreNaviresAPlacer--;
    }
}

void ModificationLigne(int numJoueur, char colonne, char ligne, char charToWrite) {
    int numColonne = static_cast<int>(toupper(colonne))-64;
    if (numJoueur==1) {
        switch (ligne) {
        case '1':
            ligne1_J1[2*numColonne]=charToWrite;
            break;
        case '2':
            ligne2_J1[2*numColonne]=charToWrite;
            break;
        case '3':
            ligne3_J1[2*numColonne]=charToWrite;
            break;
        case '4':
            ligne4_J1[2*numColonne]=charToWrite;
            break;
        case '5':
            ligne5_J1[2*numColonne]=charToWrite;
            break;
        case '6':
            ligne6_J1[2*numColonne]=charToWrite;
            break;
        }
    } else if (numJoueur==2) {
        switch (ligne) {
        case '1':
            ligne1_J2[2*numColonne]=charToWrite;
            break;
        case '2':
            ligne2_J2[2*numColonne]=charToWrite;
            break;
        case '3':
            ligne3_J2[2*numColonne]=charToWrite;
            break;
        case '4':
            ligne4_J2[2*numColonne]=charToWrite;
            break;
        case '5':
            ligne5_J2[2*numColonne]=charToWrite;
            break;
        case '6':
            ligne6_J2[2*numColonne]=charToWrite;
            break;
        }
    }
}

void Tir(int numJoueur) {
    char colonneTir;
    char ligneTir;
    bool touche;

    cout << "Joueur "<<numJoueur<<" selectionnez la colonne o� vous voulez tirer:" <<endl;
    cin >> colonneTir;
    cout << "Joueur "<<numJoueur<<" selectionnez la ligne o� vous voulez tirer:" <<endl;
    cin >> ligneTir;

    touche=TestTouche(numJoueur,colonneTir,ligneTir);

    if (numJoueur==1) {
        if (touche) {
        ModificationLigne(numJoueur,colonneTir,ligneTir,'X');
        affichageTableau(ligne0_J1,ligne1_J1,ligne2_J1,ligne3_J1,ligne4_J1,ligne5_J1,ligne6_J1);
        cout<< "Touch�!"<<endl;
    } else {
        ModificationLigne(numJoueur,colonneTir,ligneTir,'O');
        affichageTableau(ligne0_J1,ligne1_J1,ligne2_J1,ligne3_J1,ligne4_J1,ligne5_J1,ligne6_J1);
        cout<< "Rat�!"<<endl;
    }
    } else if (numJoueur==2) {
        if (touche) {
        ModificationLigne(numJoueur,colonneTir,ligneTir,'X');
        affichageTableau(ligne0_J2,ligne1_J2,ligne2_J2,ligne3_J2,ligne4_J2,ligne5_J2,ligne6_J2);
        cout<< "Touch�!"<<endl;
    } else {
        ModificationLigne(numJoueur,colonneTir,ligneTir,'O');
        affichageTableau(ligne0_J2,ligne1_J2,ligne2_J2,ligne3_J2,ligne4_J2,ligne5_J2,ligne6_J2);
        cout<< "Rat�!"<<endl;
    }
    }
}

bool TestTouche (int numJoueur,char colonneTir,char ligneTir) {
    bool touche{false};
    string s;
    s.push_back(toupper(colonneTir));
    s.push_back(toupper(ligneTir));

    if (numJoueur==1) {
            for (int i=0; i<PlacementsJ2.size(); i++) {
                    if (PlacementsJ2[i]== s) {
                            touche=true;
                            }
            }

    } else if (numJoueur==2) {
        for (int i=0; i<PlacementsJ1.size(); i++) {
                    if (PlacementsJ1[i]== s) {
                            touche=true;
                            }
            }
    }
    return touche;
}

void RAZTableau (void) {
ligne0_J1= "  A B C D E F G";
ligne1_J1= "1| | | | | | | |";
ligne2_J1= "2| | | | | | | |";
ligne3_J1= "3| | | | | | | |";
ligne4_J1= "4| | | | | | | |";
ligne5_J1= "5| | | | | | | |";
ligne6_J1= "6| | | | | | | |";

ligne0_J2= "  A B C D E F G";
ligne1_J2= "1| | | | | | | |";
ligne2_J2= "2| | | | | | | |";
ligne3_J2= "3| | | | | | | |";
ligne4_J2= "4| | | | | | | |";
ligne5_J2= "5| | | | | | | |";
ligne6_J2= "6| | | | | | | |";
}
