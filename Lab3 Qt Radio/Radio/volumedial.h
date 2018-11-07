#ifndef VOLUMEDIAL_H
#define VOLUMEDIAL_H

#include <QDial>

class VolumeDial : public QDial
{
    Q_OBJECT
public:
    VolumeDial(QWidget * parent = 0);
    VolumeDial();

protected slots:
    void setValue(int newValue);

signals:
    void switchedOn();
    void switchedOff();

private:
    int mPrevValue;
    bool mTurnedOn;
};

#endif // VOLUMEDIAL_H
