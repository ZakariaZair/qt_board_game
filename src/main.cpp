#include "project.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Project game;
    game.show();
    return app.exec();
}
