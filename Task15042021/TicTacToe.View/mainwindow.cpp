#include <QPushButton>
#include <QObject>
#include <QRegularExpression>
#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "figure.h"
#include "game.h"

char figureToChar(TicTacToe::Figure figure)
{
    if (figure == TicTacToe::Cross)
        return 'X';
    else if (figure == TicTacToe::Nought)
        return 'O';
    return 'E';
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(640, 480);

    TicTacToe::Game* game = TicTacToe::Game::create();

    QMessageBox* messageBox = new QMessageBox();

    QWidget* mainPage = findChild<QWidget*>("mainPage");
    QWidget* figureChoosePage = findChild<QWidget*>("figureChoosePage");
    QWidget* gamePage = findChild<QWidget*>("gamePage");

    QStackedWidget* stackedWidget = findChild<QStackedWidget*>("stackedWidget");

    QPushButton* playButton = findChild<QPushButton*>("playButton");
    QPushButton* exitButton = findChild<QPushButton*>("exitButton");

    QPushButton* chooseXButton = findChild<QPushButton*>("chooseXButton");
    QPushButton* chooseOButton = findChild<QPushButton*>("chooseOButton");

    QPushButton* cell00Button = findChild<QPushButton*>("cell00Button");
    QPushButton* cell01Button = findChild<QPushButton*>("cell01Button");
    QPushButton* cell02Button = findChild<QPushButton*>("cell02Button");
    QPushButton* cell10Button = findChild<QPushButton*>("cell10Button");
    QPushButton* cell11Button = findChild<QPushButton*>("cell11Button");
    QPushButton* cell12Button = findChild<QPushButton*>("cell12Button");
    QPushButton* cell20Button = findChild<QPushButton*>("cell20Button");
    QPushButton* cell21Button = findChild<QPushButton*>("cell21Button");
    QPushButton* cell22Button = findChild<QPushButton*>("cell22Button");

    connect(playButton, &QPushButton::clicked, stackedWidget, [figureChoosePage, stackedWidget]() {
        stackedWidget->setCurrentWidget(figureChoosePage);
    });
    connect(exitButton, &QPushButton::clicked, this, &QMainWindow::close);

    connect(chooseOButton, &QPushButton::clicked, game, [game, stackedWidget, gamePage]() {
        game->start(TicTacToe::Nought, TicTacToe::Cross, TicTacToe::Nought);
        stackedWidget->setCurrentWidget(gamePage);
    });

    connect(chooseXButton, &QPushButton::clicked, game, [game, stackedWidget, gamePage]() {
        game->start(TicTacToe::Cross, TicTacToe::Nought, TicTacToe::Cross);
        stackedWidget->setCurrentWidget(gamePage);
    });

    connect(cell00Button, &QPushButton::clicked, game, [game, cell00Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(0, 0) && !game->isEnd())
            cell00Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell00Button, [cell00Button]() { cell00Button->setText(""); });

    connect(cell01Button, &QPushButton::clicked, game, [game, cell01Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(0, 1) && !game->isEnd())
            cell01Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell01Button, [cell01Button]() { cell01Button->setText(""); });

    connect(cell02Button, &QPushButton::clicked, game, [game, cell02Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(0, 2) && !game->isEnd())
            cell02Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell02Button, [cell02Button]() { cell02Button->setText(""); });

    connect(cell10Button, &QPushButton::clicked, game, [game, cell10Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(1, 0) && !game->isEnd())
            cell10Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell10Button, [cell10Button]() { cell10Button->setText(""); });

    connect(cell11Button, &QPushButton::clicked, game, [game, cell11Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(1, 1) && !game->isEnd())
            cell11Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell11Button, [cell11Button]() { cell11Button->setText(""); });

    connect(cell12Button, &QPushButton::clicked, game, [game, cell12Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(1, 2) && !game->isEnd())
            cell12Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell12Button, [cell12Button]() { cell12Button->setText(""); });

    connect(cell20Button, &QPushButton::clicked, game, [game, cell20Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(2, 0) && !game->isEnd())
            cell20Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell20Button, [cell20Button]() { cell20Button->setText(""); });

    connect(cell21Button, &QPushButton::clicked, game, [game, cell21Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(2, 1) && !game->isEnd())
            cell21Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell21Button, [cell21Button]() { cell21Button->setText(""); });

    connect(cell22Button, &QPushButton::clicked, game, [game, cell22Button]() {
        TicTacToe::Figure currentPlayerFigure = game->currentPlayerFigure();
        if (game->makeTurn(2, 2) && !game->isEnd())
            cell22Button->setText(QString(figureToChar(currentPlayerFigure)));
    });

    connect(game, &TicTacToe::Game::gameIsEnd, cell22Button, [cell22Button]() { cell22Button->setText(""); });

    connect(game, &TicTacToe::Game::gameIsEnd, this, [game, messageBox, mainPage, stackedWidget](TicTacToe::Figure winnerPlayerFigure) {
        if(winnerPlayerFigure == game->firstPlayerFigure())
            messageBox->setText("You win!");
        else
            messageBox->setText("You lose!");

        messageBox->show();
        game->clear();
        stackedWidget->setCurrentWidget(mainPage);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

