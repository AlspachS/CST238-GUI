/********************************************************************************
** Form generated from reading UI file 'radio.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADIO_H
#define UI_RADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <radiotuner.h>
#include "stationbutton.h"
#include "volumedial.h"

QT_BEGIN_NAMESPACE

class Ui_Radio
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    VolumeDial *volume_dial;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    RadioTuner *tuner;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    StationButton *preset_1;
    StationButton *preset_2;
    StationButton *preset_3;
    StationButton *preset_4;
    StationButton *preset_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QDial *tuner_dial;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Radio)
    {
        if (Radio->objectName().isEmpty())
            Radio->setObjectName(QStringLiteral("Radio"));
        Radio->setEnabled(true);
        Radio->resize(541, 145);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Radio->sizePolicy().hasHeightForWidth());
        Radio->setSizePolicy(sizePolicy);
        Radio->setMinimumSize(QSize(541, 145));
        Radio->setMaximumSize(QSize(541, 145));
        Radio->setDocumentMode(false);
        centralWidget = new QWidget(Radio);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 517, 101));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        volume_dial = new VolumeDial(horizontalLayoutWidget);
        volume_dial->setObjectName(QStringLiteral("volume_dial"));
        volume_dial->setWrapping(false);
        volume_dial->setNotchesVisible(true);

        horizontalLayout_4->addWidget(volume_dial);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tuner = new RadioTuner(horizontalLayoutWidget);
        tuner->setObjectName(QStringLiteral("tuner"));
        tuner->setEnabled(false);
        tuner->setFocusPolicy(Qt::StrongFocus);
        tuner->setMaximum(399);
        tuner->setSingleStep(1);
        tuner->setValue(0);
        tuner->setTracking(false);
        tuner->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(tuner);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        preset_1 = new StationButton(horizontalLayoutWidget);
        preset_1->setObjectName(QStringLiteral("preset_1"));
        sizePolicy.setHeightForWidth(preset_1->sizePolicy().hasHeightForWidth());
        preset_1->setSizePolicy(sizePolicy);
        preset_1->setFlat(false);

        horizontalLayout_5->addWidget(preset_1);

        preset_2 = new StationButton(horizontalLayoutWidget);
        preset_2->setObjectName(QStringLiteral("preset_2"));
        sizePolicy.setHeightForWidth(preset_2->sizePolicy().hasHeightForWidth());
        preset_2->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(preset_2);

        preset_3 = new StationButton(horizontalLayoutWidget);
        preset_3->setObjectName(QStringLiteral("preset_3"));
        sizePolicy.setHeightForWidth(preset_3->sizePolicy().hasHeightForWidth());
        preset_3->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(preset_3);

        preset_4 = new StationButton(horizontalLayoutWidget);
        preset_4->setObjectName(QStringLiteral("preset_4"));
        sizePolicy.setHeightForWidth(preset_4->sizePolicy().hasHeightForWidth());
        preset_4->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(preset_4);

        preset_5 = new StationButton(horizontalLayoutWidget);
        preset_5->setObjectName(QStringLiteral("preset_5"));
        sizePolicy.setHeightForWidth(preset_5->sizePolicy().hasHeightForWidth());
        preset_5->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(preset_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_3);

        tuner_dial = new QDial(horizontalLayoutWidget);
        tuner_dial->setObjectName(QStringLiteral("tuner_dial"));
        tuner_dial->setMaximum(99);
        tuner_dial->setTracking(true);
        tuner_dial->setWrapping(true);

        horizontalLayout_4->addWidget(tuner_dial);

        Radio->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Radio);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Radio->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Radio);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Radio->setStatusBar(statusBar);

        retranslateUi(Radio);
        QObject::connect(tuner_dial, SIGNAL(valueChanged(int)), tuner, SLOT(onChangeTuner(int)));
        QObject::connect(volume_dial, SIGNAL(valueChanged(int)), volume_dial, SLOT(setValue(int)));
        QObject::connect(volume_dial, SIGNAL(switchedOn()), tuner, SLOT(powerOn()));
        QObject::connect(volume_dial, SIGNAL(switchedOff()), tuner, SLOT(powerOff()));

        QMetaObject::connectSlotsByName(Radio);
    } // setupUi

    void retranslateUi(QMainWindow *Radio)
    {
        Radio->setWindowTitle(QApplication::translate("Radio", "Steven Alspach", nullptr));
        preset_1->setText(QString());
        preset_2->setText(QString());
        preset_3->setText(QString());
        preset_4->setText(QString());
        preset_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Radio: public Ui_Radio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADIO_H
