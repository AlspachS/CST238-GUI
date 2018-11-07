#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionStyle1, &QAction::triggered,
            this, &MainWindow::style1);
    connect(ui->actionStyle2, &QAction::triggered,
            this, &MainWindow::style2);
    connect(ui->actionStyle3, &QAction::triggered,
            this, &MainWindow::style3);
    connect(ui->actionDefault, &QAction::triggered,
            this, &MainWindow::restoreDefault);
}

void MainWindow::style1()
{
    setStyleSheet("QMainWindow {"
                    "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 mediumblue, stop:.5 khaki);"
                  "}"
                  "QPushButton {"
                    "color: mediumblue;"
                    "background-color: khaki;"
                    "border-width: 2px;"
                    "border-style: solid;"
                    "border-radius: 10px;"
                    "border-color: mediumblue;"
                  "}"
                  "QRadioButton {"
                    "color: khaki;"
                    "background-color: mediumblue;"
                    "border-width: 2px;"
                    "border-style: solid;"
                    "border-radius: 8px;"
                    "border-color: mediumblue;"
                  "}"
                  "QTextEdit {"
                    "color: khaki;"
                    "background-color: mediumblue;"
                    "border-top-left-radius: 20px;"
                    "border-top-right-radius: 6px;"
                    "border-bottom-left-radius: 9px;"
                    "border-bottom-right-radius: 12px;"
                    "border-width: 1px;"
                    "border-style: inset;"
                    "border-color: mediumblue;"
                  "}"
                  "QCheckBox {"
                    "color: mediumblue;"
                    "background-color: khaki;"
                    "border-width: 2px;"
                    "border-style: solid;"
                    "border-radius: 8px;"
                    "border-color: mediumblue;"
                  "}"
                  "QSlider {"
                    "color: mediumblue;"
                    "background: qlineargradient(x1:0, y1:1, x2:1, y2:1, stop:0 mediumblue, stop:.5 khaki);"
                  "}"
                    "QSlider::handle {"
                      "background: qlineargradient(x1:0, y1:1, x2:1, y2:1, stop:0 mediumblue, stop:.3 khaki, stop:.7 khaki, stop:1 mediumblue);"
                    "}"
                    "QSlider::add-page:horizontal {"
                      "background: qlineargradient(x1:0, y1:1, x2:1, y2:1, stop:0 mediumblue, stop:1 khaki);"
                    "}"
                    "QSlider::sub-page:horizontal {"
                       "background: qlineargradient(x1:0, y1:1, x2:1, y2:1, stop:0 khaki, stop:1 mediumblue);"
                    "}"
                  );
}

void MainWindow::style2()
{
    //green: r190g219b111 #bedb6f
    //pink: r232g172b200 #e8acc8
    //dark green: #252700;

    setStyleSheet("QMainWindow {"
                    "background-image: url(:images/sakura_trees.jpg);"
                    "background-color: #e8acc8;"
                    "border-width: 2px;"
                    "border-style: solid;"
                  "}"
                  "QPushButton {"
                    "background-color: #bedb6f;"
                    "border-color: #e8acc8;"
                    "color: #252700;"
                    "border-width: 2px;"
                    "border-style: solid;"
                  "}"
                  "QRadioButton {"
                    "background-color: #bedb6f;"
                    "border-color: #e8acc8;"
                    "color: #252700;"
                    "border-width: 2px;"
                    "border-style: solid;"
                  "}"
                  "QTextEdit {"
                    "background-color: #bedb6f;"
                    "border-color: #e8acc8;"
                    "color: #252700;"
                    "border-width: 2px;"
                    "border-style: solid;"
                  "}"
                  "QCheckBox {"
                    "background-color: #bedb6f;"
                    "border-color: #e8acc8;"
                    "color: #252700;"
                    "border-width: 2px;"
                    "border-style: solid;"
                  "}"
                  "QSlider {"
                    "background-color: #252700;"
                    "border-color: #e8acc8;"
                    "color: #252700;"
                    "border-width: 2px;"
                    "border-style: solid;"
                  "}"
                    "QSlider::handle {"
                      "background: #e8acc8;"
                      "border-color: #e8acc8;"
                      "border-width: 2px;"
                      "border-style: solid;"
                      "border-top-left-radius: 5px;"
                      "border-top-right-radius: 5px;"
                      "border-bottom-left-radius: 5px 17px;"
                      "border-bottom-right-radius: 5px 17px;"
                  "}");
}

void MainWindow::style3()
{
    setStyleSheet("QMainWindow {"
                    "background: yellow;"
                    "color: blue;"
                  "}"
                  "QPushButton {"
                    "background: blue;"
                    "color: yellow;"
                  "}"
                  "QRadioButton {"
                    "background: blue;"
                    "color: yellow;"
                  "}"
                  "QTextEdit {"
                    "background: blue;"
                    "color: yellow;"
                  "}"
                  "QCheckBox {"
                    "background: blue;"
                    "color: yellow;"
                  "}"
                  "QSlider {"
                    "background: blue;"
                    "color: yellow;"
                  "}"
                    "QSlider::handle {"
                      "background: yellow;"
                      "border: 1px solid blue;"
                "}");
}

void MainWindow::restoreDefault()
{
    setStyleSheet("");
}

MainWindow::~MainWindow()
{
    delete ui;
}
