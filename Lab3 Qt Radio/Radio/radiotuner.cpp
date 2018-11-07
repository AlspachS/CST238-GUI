#include "radiotuner.h"

RadioTuner::RadioTuner(QWidget *parent) : QSlider(parent), mPreviousValue(0)
{}

void RadioTuner::onChangeTuner(int newValue)
{
    int diff = newValue - mPreviousValue;

    if (diff > 90)
    {
        diff -= 100;
    }
    else if (diff < -90)
    {
        diff += 100;
    }

    if( abs(diff) < 10)
    {
        mPreviousValue = newValue;
        setValue(value()+diff);
    }
}

void RadioTuner::powerOn()
{
    setStyleSheet("QSlider {"
                    "background-color: greenyellow;"
                  " }");
}

void RadioTuner::powerOff()
{
    setStyleSheet("QSlider {} ");
}
