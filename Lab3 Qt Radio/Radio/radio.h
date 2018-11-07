#ifndef RADIO_H
#define RADIO_H

#include <QMainWindow>

namespace Ui {
class Radio;
}

class Radio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Radio(QWidget *parent = 0);
    ~Radio();


private:
    Ui::Radio *ui;
};

#endif // RADIO_H
