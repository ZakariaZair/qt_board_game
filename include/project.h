#pragma once

#include <QtWidgets/QMainWindow>
#include <QtGui/QMouseEvent>
#include <memory>
#include <vector>
#include "ui_project.h"
#include "chess_definition.h"
#include "manager.h"
#include "king.h"
#include "rook.h"
#include "knight.h"
#include "tile.h"
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
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void keyReleaseEvent(QKeyEvent* event) override;

    void nextTurn();

private slots:
    void setUp();
    void start();
    void stop();
    void defaulting();

private:
    Tiles board_;
    std::unique_ptr<Manager> manager_;
    LobbyOption lobbyOption_;
    Ui::ProjetFinalEchecClass ui;
};
