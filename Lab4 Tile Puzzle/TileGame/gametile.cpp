#include "gametile.h"


GameTile::GameTile() : mRow(0), mColumn(0)
{
    setFixedSize(50, 50);
}

void GameTile::setPosition(int row, int column)
{
    mRow = row;
    mColumn = column;
}

void GameTile::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        emit location(mRow, mColumn);
    }
}
