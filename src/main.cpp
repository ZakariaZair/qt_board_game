/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   main.cpp
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Cree le 9 avril 2022
*/

// 1. Namespace. L'un regroupe les classes suivantes: Joueur, Piece, Jeux et Case. L'autre est defini dans ProjetFinalEchec.cpp
// 2. Exception lancee dans le constructeur du Roi donc dans Roi.cpp. Exception levee dans main.cpp
// 3. Utilisation d'un vecteur de unique_ptr dans Joueur.h (La memoire se desalloue automatiquement)

#include "ProjetFinalEchec.h"
#include "Jeux.h"
#include "Cavalier.h"
#include "Roi.h"
#include "Tour.h"
#include "Joueur.h"
#include "Piece.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Creation des joueurs
    classejeux::Joueur blanc("Alexis");
    classejeux::Joueur noir("Zak");

    // Creation du jeu
    classejeux::Jeux jeux;


    ProjetFinalEchec echec(blanc, noir, jeux);
    echec.show();

    return app.exec();
}
