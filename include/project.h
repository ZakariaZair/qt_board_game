#pragma once

#include <QtWidgets/QMainWindow>
#include <QtGui/QMouseEvent>
#include <memory>
#include <vector>
#include "ui_project.h"
#include "chess_definition.h"
using namespace chess;

enum LobbyOption {
    DEFAULT = 0,
    RANDOM = 1,
    ENDGAME = 2
};

class Project : public QMainWindow
{
    Q_OBJECT

public:
    Project(QWidget* parent = Q_NULLPTR);
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
    void setUp();
    void start();
    void stop();
    void changeOption(int in);

private:
    std::vector<std::shared_ptr<Tile>> board_;
    std::shared_ptr<Player> playerWhite_;
    std::shared_ptr<Player> playerBlack_;
    std::vector<std::shared_ptr<Piece>> piecesWhite_;
    std::vector<std::shared_ptr<Piece>> piecesBlack_;
    int lobbyOption_ = LobbyOption::DEFAULT;
    bool gameStarted_ = false;
    std::optional<std::pair<int, int>> tileClicked_;

    Ui::ProjetFinalEchecClass ui;
};
