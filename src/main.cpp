#include "project.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Creation of Players
    // classejeux::Joueur blanc("Alexis");
    // classejeux::Joueur noir("Zak");

    // Creation du jeu
    // classejeux::Jeux jeux;

    //
    Project echec(blanc, noir, jeux);
    echec.show();

    return app.exec();
}
