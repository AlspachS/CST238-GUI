#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gametile.h"
#include "cpuzzle.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
protected slots:
    void MoveTile(int row, int column);

private:
    void Reset();
    void MakeGameBoard();
    void FitToGame();
    void Resize(int newSize);
    void static ErrorFunc(const string &msg);
    Ui::GameWindow *ui;
    cPuzzle *mGame;
    GameTile *mTiles;
};

#endif // MAINWINDOW_H
