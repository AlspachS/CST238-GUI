#ifndef TUNERDIAL_H
#define TUNERDIAL_H

#include <QDial>

class TunerDial : public QDial
{
    Q_OBJECT
public:
    TunerDial(QWidget * parent = Q_NULLPTR);
    
//signals:
//    void changeTuner(int newValue);
    
};

#endif // TUNERDIAL_H
