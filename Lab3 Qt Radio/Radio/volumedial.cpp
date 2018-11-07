#include "volumedial.h"
#include <QDebug>

VolumeDial::VolumeDial(QWidget *parent) : QDial(parent), mPrevValue(0)
{}

void VolumeDial::setValue(int newValue)
{
    int diff = newValue - mPrevValue;

    if ( abs(diff) > 10)
    {
        QDial::setValue(mPrevValue);
    }
    else
    {
        mPrevValue = newValue;
        if(value() > minimum())
        {
            emit switchedOn();
        }
        else
        {
            emit switchedOff();
        }
    }
}
