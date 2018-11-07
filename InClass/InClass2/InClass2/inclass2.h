#ifndef INCLASS2_H
#define INCLASS2_H

#include <QMainWindow>

namespace Ui {
class InClass2;
}

class InClass2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit InClass2(QWidget *parent = 0);
    ~InClass2();

public slots:
    void SetText();

private:
    Ui::InClass2 *ui;
};

#endif // INCLASS2_H
