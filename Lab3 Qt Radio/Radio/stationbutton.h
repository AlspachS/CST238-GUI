#ifndef STATIONBUTTON_H
#define STATIONBUTTON_H

#include <QPushButton>
#include <QSlider>
#include <QMouseEvent>

class StationButton : public QPushButton
{
    Q_OBJECT

public:
    explicit StationButton(QWidget *parent = 0);
//    StationButton();
    void SetTuner(QSlider *tuner);

protected:
    void mousePressEvent(QMouseEvent *e) override;

private:
    int mChannel;
    QSlider * mTuner;
};

#endif // STATIONBUTTON_H
