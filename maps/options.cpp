#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    setWindowTitle("Options");
    setStyleSheet("background-color: white;");
    setFixedSize(420, 300);
    ui->checkBox->setChecked(true);
    on_checkBox_clicked(true);
    QRegExp regex("[0-9.]+");
    validator = new QRegExpValidator(regex, this);
    for (int i = 0; i < ui->inputLayaut->count(); ++i) {
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(ui->inputLayaut->itemAt(i)->widget())) {
            lineEdit->setValidator(validator);
            lineEdit->setAlignment(Qt::AlignCenter);
        }
    }
    connect(ui->checkBox, &QCheckBox::clicked, this, &Options::on_checkBox_clicked);
}

Options::~Options()
{
    delete validator;
    delete ui;
}

void Options::on_checkBox_clicked(bool checked)
{
    if (checked)
    {
        for (int i = 0; i < ui->inputLayaut->count()-1; ++i) {
            if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(ui->inputLayaut->itemAt(i)->widget())) {
                lineEdit->setReadOnly(true);
            }
        }
    } else
    {
        for (int i = 0; i < ui->inputLayaut->count()-1; ++i) {
            if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(ui->inputLayaut->itemAt(i)->widget())) {
                lineEdit->setReadOnly(false);
            }
        }
    }
}


void Options::on_Accept_clicked()
{
    QVector<double> params;
    params.reserve(ui->inputLayaut->count()-2);
    for (int i = 0; i < ui->inputLayaut->count()-1; ++i) {
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(ui->inputLayaut->itemAt(i)->widget())) {
            params.append(lineEdit->text().toDouble());
        }
    }
    int timeOfCalculation = ui->timeOfcalculation->text().toInt();
    bool statusOfClic = ui->checkBox->isChecked();
    emit sendOptions(params[0], params[1], params[2], params[3], params[4], params[5], timeOfCalculation, statusOfClic);
}

