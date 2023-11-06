/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MapOfSattelite
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *Latitude;
    QCustomPlot *plotMap;
    QLabel *Longitude;
    QPushButton *Update;
    QLabel *Height;
    QLabel *Time;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MapOfSattelite)
    {
        if (MapOfSattelite->objectName().isEmpty())
            MapOfSattelite->setObjectName(QString::fromUtf8("MapOfSattelite"));
        MapOfSattelite->resize(1243, 579);
        centralwidget = new QWidget(MapOfSattelite);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Latitude = new QLabel(centralwidget);
        Latitude->setObjectName(QString::fromUtf8("Latitude"));
        QFont font;
        font.setPointSize(14);
        Latitude->setFont(font);

        gridLayout->addWidget(Latitude, 1, 1, 1, 1);

        plotMap = new QCustomPlot(centralwidget);
        plotMap->setObjectName(QString::fromUtf8("plotMap"));

        gridLayout->addWidget(plotMap, 0, 0, 1, 6);

        Longitude = new QLabel(centralwidget);
        Longitude->setObjectName(QString::fromUtf8("Longitude"));
        Longitude->setFont(font);

        gridLayout->addWidget(Longitude, 1, 2, 1, 1);

        Update = new QPushButton(centralwidget);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setFont(font);
        Update->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Update, 1, 4, 1, 2);

        Height = new QLabel(centralwidget);
        Height->setObjectName(QString::fromUtf8("Height"));
        Height->setFont(font);

        gridLayout->addWidget(Height, 1, 3, 1, 1);

        Time = new QLabel(centralwidget);
        Time->setObjectName(QString::fromUtf8("Time"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        Time->setFont(font1);

        gridLayout->addWidget(Time, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MapOfSattelite->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MapOfSattelite);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1243, 22));
        MapOfSattelite->setMenuBar(menubar);

        retranslateUi(MapOfSattelite);

        QMetaObject::connectSlotsByName(MapOfSattelite);
    } // setupUi

    void retranslateUi(QMainWindow *MapOfSattelite)
    {
        MapOfSattelite->setWindowTitle(QApplication::translate("MapOfSattelite", "MapOfSattelite", nullptr));
        Latitude->setText(QApplication::translate("MapOfSattelite", "Latitude:", nullptr));
        Longitude->setText(QApplication::translate("MapOfSattelite", "Longitude:", nullptr));
        Update->setText(QApplication::translate("MapOfSattelite", "Change Parameters", nullptr));
        Height->setText(QApplication::translate("MapOfSattelite", "Height:", nullptr));
        Time->setText(QApplication::translate("MapOfSattelite", "Time UTC:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapOfSattelite: public Ui_MapOfSattelite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
