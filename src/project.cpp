// QT Lib
#include <QWidget>
#include <QMainWindow>
#include <QFontComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QtGui/QFont>
#include <QGraphicsScene>
#include <QButtonGroup>
#include <QRadioButton>
#include <QMessageBox>
#include <QBoxLayout>

// C++ Lib
#include <memory>
#include <utility>


// ../include path
#include "project.h"
#include "chess_definition.h"
#include "manager.h"
#include "rook.h"

namespace graphicsInterface {
    int spaceBetweenTiles = 0;
    std::pair<int, int> sizeWindow(400, 300);
    int sizeGameWidget = 900; // square format, size_x = size_y
    int lenBoardByTile = 8;
}
namespace gi = graphicsInterface;

Project::Project(QWidget* parent) : QMainWindow(parent)
{
    setUp();
    manager_ = std::make_unique<Manager>(Manager({
        {Color::WHITE, "Zakaria"},
        {Color::BLACK, "Airakaz"}
    }));
    for (int i = 0; i < (gi::lenBoardByTile*gi::lenBoardByTile); i++) {
        std::shared_ptr<Tile> tile = std::make_shared<Tile>();
        tile->setPos(floor((float)i/gi::lenBoardByTile), i%gi::lenBoardByTile);
        board_.push_back(tile);
    }

    King whiteKing = King(Color::WHITE);
    King blackKing = King(Color::BLACK);
    Knight whiteKnight = Knight(Color::WHITE);
    Knight blackKnight = Knight(Color::BLACK);
    Knight whiteKnight2 = Knight(Color::WHITE);
    Knight blackKnight2 = Knight(Color::BLACK);
    Rook whiteRook = Rook(Color::WHITE);
    Rook blackRook = Rook(Color::BLACK);
    Rook whiteRook2 = Rook(Color::WHITE);
    Rook blackRook2 = Rook(Color::BLACK);
    // King
    std::unique_ptr<Piece> currentPiece = std::make_unique<Piece>(whiteKing);
    manager_->addPieceToTile(3, 7, currentPiece, board_);
    currentPiece = std::make_unique<Piece>(blackKing);
    manager_->addPieceToTile(4, 0, currentPiece, board_);
    // Knight
    currentPiece = std::make_unique<Piece>(whiteKnight);
    manager_->addPieceToTile(1, 7, currentPiece, board_);
    currentPiece = std::make_unique<Piece>(blackKnight);
    manager_->addPieceToTile(1, 0, currentPiece, board_);
    currentPiece = std::make_unique<Piece>(whiteKnight2);
    manager_->addPieceToTile(6, 7, currentPiece, board_);
    currentPiece = std::make_unique<Piece>(blackKnight2);
    manager_->addPieceToTile(6, 0, currentPiece, board_);
    // Rook
    currentPiece = std::make_unique<Piece>(whiteRook);
    manager_->addPieceToTile(0, 7, currentPiece, board_);
    currentPiece = std::make_unique<Piece>(blackRook);
    manager_->addPieceToTile(0, 0, currentPiece, board_);
    currentPiece = std::make_unique<Piece>(whiteRook2);
    manager_->addPieceToTile(7, 7, currentPiece, board_);
    currentPiece = std::make_unique<Piece>(blackRook2);
    manager_->addPieceToTile(7, 0, currentPiece, board_);

    for (std::shared_ptr<Tile> tile : board_) {
        tile->refreshRepresentation();
    }

};

void Project::setUp() {
    QWidget* menu = new QWidget;
    QMainWindow::setFixedSize(gi::sizeWindow.first, gi::sizeWindow.second);
    menu->setFixedSize(gi::sizeWindow.first, gi::sizeWindow.second);
    QPushButton* startButton = new QPushButton(menu);
    startButton->setText(tr("Appuyer pour démarrer la partie"));

    QVBoxLayout* buttons = new QVBoxLayout(menu);
    buttons->addWidget(startButton);
    startButton->setFixedHeight(50);

    QRadioButton* option1 = new QRadioButton(menu);
    option1->setText(tr("Default"));
    buttons->addWidget(option1);
    // QRadioButton* option2 = new QRadioButton(menu);
    // option2->setText(tr("Random"));
    // buttons->addWidget(option2);
    // QRadioButton* option3 = new QRadioButton(menu);
    // option3->setText(tr("Endgame"));
    // buttons->addWidget(option3);

    connect(option1, SIGNAL(pressed()), this, SLOT(defaulting()));
    // connect(option2, SIGNAL(pressed()), this, SLOT(changeOption2()));
    // connect(option3, SIGNAL(pressed()), this, SLOT(changeOption3()));
    connect(startButton, SIGNAL(pressed()), this, SLOT(start()));

    setCentralWidget(menu);
};

void Project::defaulting() {
    lobbyOption_ = LobbyOption::DEFAULT;
}

void Project::start() {
    QMainWindow::setFixedSize(gi::sizeGameWidget, gi::sizeGameWidget);
    QWidget* prinFenetre = new QWidget;
    prinFenetre->setFixedSize(gi::sizeGameWidget, gi::sizeGameWidget);
    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->setSpacing(gi::spaceBetweenTiles);

    for (int i = 0; i < (gi::lenBoardByTile*gi::lenBoardByTile); i++) {
        int x = floor((float)i/gi::lenBoardByTile), y = (i%gi::lenBoardByTile);
        gridLayout->addWidget(board_[i]->getLabel(), y, x);
    }

    prinFenetre->setLayout(gridLayout);
    setCentralWidget(prinFenetre);
    gameStarted_ = true;
};

void Project::mousePressEvent(QMouseEvent* event) {
    if (event->button() != Qt::LeftButton) return;

    int tailleCaseX = width();
    int tailleCaseY = height();

    int clicX = ceil(event->x() / (tailleCaseX / 8));
    int clicY = ceil(event->y() / (tailleCaseY / 8));

    switch (manager_->getState()) {
        case ClickState::SELECTION:
            manager_->selectTile(board_, {clicX, clicY});
            break;
        case ClickState::NORMAL_MOVE:
            manager_->moveToTarget(board_, {clicX, clicY});
            break;
        case ClickState::RISKKING:
            // manager_->selectRescueTiles(board_, {clicX, clicY});
            break;
        case ClickState::CAREFUL_MOVE:
            // manager_->rescueKing(board_, {clicX, clicY});
            break;
    }
}

void Project::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_R) {
        manager_->toggleValidMoves(board_);
    } else if (event->key() == Qt::Key_W) {
        manager_->toggleValidMoves(board_, Color::WHITE);
    } else if (event->key() == Qt::Key_B) {
        manager_->toggleValidMoves(board_, Color::BLACK);
    }
}

void Project::keyReleaseEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_R || event->key() == Qt::Key_B || event->key() == Qt::Key_W) {
        manager_->resetToggles(board_);
    }
}

void Project::stop() {

//     gameStarted_ = false;

//     for (auto&& p : j1.avoirPieces()) {
//         j1.retirerPiece(p);
//     }
//     for (auto&& p : j2.avoirPieces()) {
//         j2.retirerPiece(p);
//     }

//     QWidget* menu = new QWidget;
//     menu->setFixedSize(500, 200);
//     QMainWindow::setFixedSize(500, 200);

//     QVBoxLayout* centralBox = new QVBoxLayout(menu);

//     QLabel* finished = new QLabel(menu);
//     finished->setText(tr("!!!   Partie Terminé    !!!"));
//     finished->setAlignment(Qt::AlignCenter);

//     centralBox->addWidget(finished);

//     QLabel* winner = new QLabel();
//     winner->setText(QString::fromStdString("GAGNANT    ::   ") + QString::fromStdString(autreJoueur->avoirNom()));
//     winner->setAlignment(Qt::AlignCenter);
//     winner->setStyleSheet(tr("QLabel { background-color : gray ;}"));
//     winner->setFrameStyle(QFrame::Panel | QFrame::Sunken);

//     centralBox->addWidget(winner);

//     setCentralWidget(menu);
}
