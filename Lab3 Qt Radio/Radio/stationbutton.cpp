#include "stationbutton.h"

StationButton::StationButton(QWidget *parent):
    QPushButton(parent)
{}

void StationButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        mTuner->setValue(mChannel);
        mTuner->setSliderPosition(mChannel);
    }
    else if(e->button() == Qt::RightButton)
    {
        mChannel = mTuner->value();
    }
}

void StationButton::SetTuner(QSlider * tuner)
{
    mTuner = tuner;
}
