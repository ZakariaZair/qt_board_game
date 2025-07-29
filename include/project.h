#pragma once

#include <QtWidgets/QMainWindow>
#include <QtGui/QMouseEvent>
#include <QLabel>
#include <vector>
#include "ui_project.h"
#include "chess_definition.h"
using namespace chess;


class Project : public QMainWindow
{
    Q_OBJECT

public:
    Project(Player& playerWhite, Player& playerBlack, Board board, QWidget* parent = Q_NULLPTR);
    ~Project();
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

    void couleurBoardNormal();
    void couleurBoardEchec();


    void option1();
    void option2();
    void option3();
    void option();

private slots:
    void miseEnJeu();

    void stopJeu();

    void miseEnMenu();

    void changeOption1();
    void changeOption2();
    void changeOption3();


private:
    Board* board = nullptr;
    Player* playerWhite = nullptr;
    Player* playerBlack = nullptr;
    bool gameStarted = false;
    std::optional<std::pair<int, int>> tileClicked;
    QLabel* arrayLabel[8][8];
    Ui::ProjetFinalEchecClass ui;
};
