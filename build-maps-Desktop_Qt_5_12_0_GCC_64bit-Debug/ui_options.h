/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *inputLayaut;
    QLineEdit *longitudeOfAscendine;
    QLineEdit *argumentOfpereparis;
    QLineEdit *inc;
    QLineEdit *trueAnomaly;
    QLineEdit *perigeeAltiude;
    QLineEdit *apogeeAltiude;
    QLineEdit *timeOfcalculation;
    QPushButton *Accept;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QCheckBox *checkBox;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(640, 480);
        QFont font;
        font.setPointSize(13);
        Options->setFont(font);
        gridLayout_3 = new QGridLayout(Options);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        inputLayaut = new QVBoxLayout();
        inputLayaut->setObjectName(QString::fromUtf8("inputLayaut"));
        longitudeOfAscendine = new QLineEdit(Options);
        longitudeOfAscendine->setObjectName(QString::fromUtf8("longitudeOfAscendine"));
        QFont font1;
        font1.setPointSize(14);
        longitudeOfAscendine->setFont(font1);

        inputLayaut->addWidget(longitudeOfAscendine);

        argumentOfpereparis = new QLineEdit(Options);
        argumentOfpereparis->setObjectName(QString::fromUtf8("argumentOfpereparis"));
        argumentOfpereparis->setFont(font1);

        inputLayaut->addWidget(argumentOfpereparis);

        inc = new QLineEdit(Options);
        inc->setObjectName(QString::fromUtf8("inc"));
        inc->setFont(font1);

        inputLayaut->addWidget(inc);

        trueAnomaly = new QLineEdit(Options);
        trueAnomaly->setObjectName(QString::fromUtf8("trueAnomaly"));
        trueAnomaly->setFont(font1);

        inputLayaut->addWidget(trueAnomaly);

        perigeeAltiude = new QLineEdit(Options);
        perigeeAltiude->setObjectName(QString::fromUtf8("perigeeAltiude"));
        perigeeAltiude->setFont(font1);

        inputLayaut->addWidget(perigeeAltiude);

        apogeeAltiude = new QLineEdit(Options);
        apogeeAltiude->setObjectName(QString::fromUtf8("apogeeAltiude"));
        apogeeAltiude->setFont(font1);

        inputLayaut->addWidget(apogeeAltiude);

        timeOfcalculation = new QLineEdit(Options);
        timeOfcalculation->setObjectName(QString::fromUtf8("timeOfcalculation"));
        timeOfcalculation->setFont(font1);

        inputLayaut->addWidget(timeOfcalculation);


        gridLayout_2->addLayout(inputLayaut, 0, 0, 1, 1);

        Accept = new QPushButton(Options);
        Accept->setObjectName(QString::fromUtf8("Accept"));
        Accept->setFont(font1);

        gridLayout_2->addWidget(Accept, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(Options);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(Options);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label = new QLabel(Options);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        label->setFont(font2);

        verticalLayout->addWidget(label);

        label_4 = new QLabel(Options);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(Options);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(Options);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(Options);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        verticalLayout->addWidget(label_7);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        checkBox = new QCheckBox(Options);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font1);
        checkBox->setAcceptDrops(false);

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Dialog", nullptr));
        longitudeOfAscendine->setText(QApplication::translate("Options", "140.29", nullptr));
        argumentOfpereparis->setText(QApplication::translate("Options", "249.23", nullptr));
        inc->setText(QApplication::translate("Options", "97.66", nullptr));
        trueAnomaly->setText(QApplication::translate("Options", "95.64", nullptr));
        perigeeAltiude->setText(QApplication::translate("Options", "564.7", nullptr));
        apogeeAltiude->setText(QApplication::translate("Options", "576.3", nullptr));
        timeOfcalculation->setText(QApplication::translate("Options", "5000", nullptr));
        Accept->setText(QApplication::translate("Options", "Accept", nullptr));
        label_2->setText(QApplication::translate("Options", "Longitude of ascending node, deg", nullptr));
        label_3->setText(QApplication::translate("Options", "Argument of periapsis, deg", nullptr));
        label->setText(QApplication::translate("Options", "Inclination, deg", nullptr));
        label_4->setText(QApplication::translate("Options", "True anomaly, deg", nullptr));
        label_5->setText(QApplication::translate("Options", "Perigee altitude, km", nullptr));
        label_6->setText(QApplication::translate("Options", "Apogee altitude, km", nullptr));
        label_7->setText(QApplication::translate("Options", "Time of calculation, s", nullptr));
        checkBox->setText(QApplication::translate("Options", "Change only time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
