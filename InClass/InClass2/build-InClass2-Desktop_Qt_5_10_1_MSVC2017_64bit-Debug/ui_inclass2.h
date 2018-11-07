/********************************************************************************
** Form generated from reading UI file 'inclass2.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCLASS2_H
#define UI_INCLASS2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InClass2
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InClass2)
    {
        if (InClass2->objectName().isEmpty())
            InClass2->setObjectName(QStringLiteral("InClass2"));
        InClass2->resize(400, 300);
        centralWidget = new QWidget(InClass2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 75));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_3->addWidget(checkBox_2);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_3->addWidget(checkBox);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 75));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        horizontalLayout->addWidget(groupBox_2);

        InClass2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InClass2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        InClass2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InClass2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InClass2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InClass2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InClass2->setStatusBar(statusBar);

        retranslateUi(InClass2);
        QObject::connect(pushButton, SIGNAL(clicked()), InClass2, SLOT(SetText()));

        QMetaObject::connectSlotsByName(InClass2);
    } // setupUi

    void retranslateUi(QMainWindow *InClass2)
    {
        InClass2->setWindowTitle(QApplication::translate("InClass2", "InClass2", nullptr));
        pushButton->setText(QApplication::translate("InClass2", "PUSH", nullptr));
        groupBox->setTitle(QApplication::translate("InClass2", "CheckBoxes", nullptr));
        checkBox_2->setText(QApplication::translate("InClass2", "Option 1", nullptr));
        checkBox->setText(QApplication::translate("InClass2", "Option 2", nullptr));
        groupBox_2->setTitle(QApplication::translate("InClass2", "RadioButtons", nullptr));
        radioButton->setText(QApplication::translate("InClass2", "AM", nullptr));
        radioButton_2->setText(QApplication::translate("InClass2", "FM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InClass2: public Ui_InClass2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCLASS2_H
