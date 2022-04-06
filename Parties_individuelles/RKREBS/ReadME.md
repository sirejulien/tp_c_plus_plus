
# Cours de C++ Mounir Avril 2022 

## Premier jour (Lundi)

> Cours

    Installation de Code::Blocks pour coder dessus

C++ est une amélioration du C, date de 1970. Il y en a partout, mais on ne le voit pas. C++ reprend tous les concepts du C en rajoutant le polymorphisme, ...

    Configuration de Code::Blocks

Ajouter un .gitignore pour le C++ et essayer de trouver de quoi il est rempli.
Montrer les bugs qu'on a eu en compilant et expliquer comment on les as resolues.

Code pour revoir les bases du C++ :

    #include  <iostream>
    
      
    
    // un entier non-signé a des valeurs forcément positives
    
    // un buffer overflow est quand un entier dépasse la limite allouée par le langage
    
      
    
    int  main ()
    
    {
    
      
    
    // un entier = 4 octets = 32 bits, de - 2 milliards ... à 2 milliards ... .
    
    int  entier1 (4);
    
      
    
    // un long = 4 octets
    
    long  entier2 (2);
    
      
    
    long  long  entier3(2);
    
      
    
    short  entier4 (2);
    
      
    
    // nombres à virgule
    
    double  numAVirgule (3.14);
    
      
      
    
    float  numAVirgule2 (3.14);
    
      
    
    long  double  numAVirgule3 (3.14);
    
      
    
    // caractères
    
      
    
    char  caractere ('a'); //c++ n'impose aucun encodage
    
    wchar_t  caractere2 ('b'); // utf-8
    
    char16_t  caractere3 ('c'); // utf-16
    
    char32_t  caractere4 ('d'); // utf-32
    
      
    
    // booléen
    
    bool  booleen(true); // true (Vrai) ou faux (false)
    
      
    
    // Par défaut, les nombres peuvent être négatifs, pour s'assurer qu'ils soient positifs
    
    // on utilise le mot-clé "unsigned"
    
    unsigned  int  entier5 (2);
    
    unsigned  long  entier6 (2);
    
    unsigned  long  long  entier7 (2);
    
    unsigned  short  entier8 (2);
    
      
    
    // entiers
    
    auto  entier9 (2); // int
    
    auto  entier10 (21); // long
    
    auto  entier11 (211); // long long
    
    auto  entier12 (2); // pas de littéral pour les short
    
      
    
    // les entiers non-signés
    
    auto  entier14 (2u); // un
    
    auto  entier15 (2ul);
    
    auto  entier16 (2ull);
    
    unsigned  short  entier17 (2u);
    
      
    
    // nombres à virgules
    
    auto  numAVirgule4 (3.); // double
    
    auto  numAVirgule5 (3.f); // float
    
    auto  numAVirgule6 (3.1); // long double
    
      
    
    // caractère
    
    auto  caractere5 ('a'); // char caractère ('a');
    
    auto  caractere6 (L'b'); // wchar_t caractere 2 ('b'); // utf-8
    
    auto  caractere7 (u'a'); // char16_t caractere3 ('c'); // utf-16
    
    auto  caractere8 (U'd'); //char32_t caractere4 ('d'); // utf-32
    
      
    
    // auto avec les short ...
    
    auto  petitEntier (static_cast<short>(2));
    
      
    
    // le static_cast
    
    std::cout << static_cast<int>(numAVirgule2) << std::endl;
    
      
    
    std::cout << static_cast<int>(caractere5) <<std::endl;
    
      
    
    std:cout << static_cast<char>(65) <<std::endl;
    
    return  0;
    }

> Exercice du juste prix

ce que j'ai codé :

    #include  <iostream>
    
      
    
    int  main ()
    
    {
    
    cout << "Bienvenue au juste prix" << endl;
    
    auto  aDeviner(3'784);
    
    auto  proposition(0);
    
      
    
    for (i=10; i>1; i=i+1)
    
    {
    
      
    
    cout << "Saisissez votre proposition. Il vous reste " + i + "essais." << endl;
    
      
    
    cin >> proposition;
    
      
    
    switch (proposition) {
    
    case (proposition < aDeviner) :
    
    cout << "C'est plus" << endl;
    
    case (proposition > aDeviner) :
    
    cout << "C'est moins" << endl;
    
    case (proposition == aDeviner) :
    
    cout << "C'est la bonne réponse" << endl;
    
      
    
    }
    
    i = i - 1;
    
    }
    
      
    
    return  0;
    
      
    
    }
Le corrigé : 

    #include  <iostream>
    
      
    
    int  main ()
    
    {
    
    cout << "Bienvenue au juste prix" << endl;
    
    auto  aDeviner(3'784);
    
    auto  proposition(0);
    
      
    
    while ( proposition != aDeviner)
    
    {
    
      
    
    cin >> proposition;
    
      
    
    if (proposition < aDeviner)
    
    {
    
    cout << "C'est plus" << endl;
    
    }
    
    else  if (proposition > aDeviner)
    
    {
    
    cout << "C'est moins" << endl;
    
    }
    
    else
    
    {
    
    cout << "C'est la bonne réponse" << endl;
    
    }
    
    }
    
      
    
    return  0;
    
      
    
    }
Si on veut rajouter un compteur d'essais, on ajoute un i qui s'incrémente à chaque passage dans while et on l'affiche avec un :

    "cout << i tentatives << endl;
Pour limiter le nombre de partie, on fait quelque chose de similaire au premier code que j'ai mis dans ce CR en rajoutant un SI à la fin du while de la manière suivante 

    if (i = 0)(
    
    cout << "La réponse était " <<aDeviner<< ". Perdu !" << endl;
    
    );
On voit les références. Une référence est une étiquette qui n'alloue pas de mémoire supplémentaire car elle reprend le contenu d'une autre variable grâce à son emplacement mémoire. Une référence est fixe.

On voit les pointeurs. un pointeur est l'adresse ou se trouve l'étiquette. Le pointeur va se comporter comme une variable.

La différence entre un pointeur et une référence ne contient que le contenu de la variable. Le pointeur récupère l'adresse et la référence.

    Avancée du TP du juste prix
fonction qui prend une variable déjà déclarée dans le main

Optimisation du jeu du juste prix avec de nouveaux dossiers.
Tests effectués et disponibles dans le GitHub.

## Deuxième jour (Mardi)
Objectif pour jeudi : créer un jeu assez complexe avec menu, rejouabilité, high score, ...
Avec Julien, on a fait un pendu complet avec des commentaires et un touché-coulé.
## Troisième jour (Mercredi)
Installation de SFML pour CodeBlocks. Jeu du pendu fait et touché-coulé fait sans code pour gérer le cas ou un béta-testeur de jeu viendrait essayer notre jeu.
Différence entre const et constexpr.
Différence entre struct et class.

