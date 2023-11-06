#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

signals:
    void sendOptions(double _delta, double _w, double _inc, double _vi,
                     double _hp, double _ha, int _timeOfCalculation, bool checkClicked); // Передача параметров в основную программу

private slots:
    void on_checkBox_clicked(bool checked); // Изменение всех параметров или только времени
    void on_Accept_clicked();

private:
    Ui::Options *ui;
    QValidator *validator;
};

#endif // OPTIONS_H
