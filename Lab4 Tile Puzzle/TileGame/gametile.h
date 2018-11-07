#ifndef GAMETILE_H
#define GAMETILE_H

#include <QPushButton>
#include <QMouseEvent>

class GameTile : public QPushButton
{
    Q_OBJECT
public:
    GameTile();
//    GameTile(QWidget * parent = Q_NULLPTR);
    int getRow();
    int getColumn();
    void setPosition(int row, int column);

signals:
    void location(int row, int column);

protected:
    void mousePressEvent(QMouseEvent *e) override;

private:
    int mRow;
    int mColumn;
};

#endif // GAMETILE_H
