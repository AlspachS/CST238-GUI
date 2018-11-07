#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <qdebug.h>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->statusBar()->setSizeGripEnabled(false);

    mGame = new cPuzzle();
    mGame->SetErrorFunc(ErrorFunc);

    connect(ui->actionShuffle, &QAction::triggered,
            this, &GameWindow::Reset);
    connect(ui->actionDefault, &QAction::triggered,
            [this]() { Resize(4); });
    connect(ui->action6x6, &QAction::triggered,
            [this]() { Resize(6); });

    ui->GameBoard->setSpacing(0);
    FitToGame();
    MakeGameBoard();
}

void GameWindow::Reset()
{
    mGame->Reset();
    delete[] mTiles;
    MakeGameBoard();
}

GameWindow::~GameWindow()
{
    delete[] mTiles;
    delete mGame;
    delete ui;
}

void GameWindow::ErrorFunc(const string &msg)
{
    qDebug(msg.c_str());
}

void GameWindow::MakeGameBoard()
{
    mTiles = new GameTile[pow(mGame->Size(), 2)];
    for( int i = 0; i < mGame->Size(); ++i)
    {
        for( int j = 0; j < mGame->Size(); ++j)
        {
            int index = i*mGame->Size()+j;
            int value = mGame->GetAt(i, j);
            if(value)
            {
                connect(&mTiles[index], SIGNAL(location(int, int)), SLOT(MoveTile(int, int)));
                mTiles[index].setText(QString("%0").arg(value));
                mTiles[index].setPosition(i, j);
                ui->GameBoard->addWidget(&mTiles[index],i,j);
            }
        }
    }
}

void GameWindow::FitToGame()
{
    int newWindowHeight = mGame->Size() * 50 + 62;
    int newWindowWidth = mGame->Size() * 50 + 20;
    this->setFixedSize(newWindowWidth, newWindowHeight);
}

void GameWindow::Resize(int newSize)
{
    delete[] mTiles;
    delete mGame;
    mGame = new cPuzzle(newSize);
    mGame->SetErrorFunc(ErrorFunc);
    ui->GameBoard->setSpacing(0);
    FitToGame();
    MakeGameBoard();
}

void GameWindow::MoveTile(int row, int column)
{
    mGame->Move(row, column);
    delete[] mTiles;
    MakeGameBoard();
}


