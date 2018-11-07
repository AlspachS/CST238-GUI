#ifndef RADIOTUNER_H
#define RADIOTUNER_H

#include <QSlider>

class RadioTuner : public QSlider
{
    Q_OBJECT
public:
    RadioTuner(QWidget * parent = Q_NULLPTR);

protected slots:
    void onChangeTuner(int newValue);
    void powerOn();
    void powerOff();

protected:
    int mPreviousValue;
};

#endif // RADIOTUNER_H
