#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <options.h>
#include <QTimer>
#include "calculationmap.h"
#include "plotmap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MapOfSattelite; }
QT_END_NAMESPACE

class MapOfSattelite : public QMainWindow
{
    Q_OBJECT

public:
    MapOfSattelite(QWidget *parent = nullptr);
    ~MapOfSattelite();
    void StartFcn();
    void SetTimer();

signals:
    void timeInput(uint &timeOfCalculation);

private slots:
    void on_Update_clicked();
    void getOptions(double _delta, double _w, double _inc, double _vi,
                     double _hp, double _ha, int _timeOfCalculation, bool checkClicked);

private:
    void SetOptions();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MapOfSattelite *ui;
    Options options;
    PlotMap *map;
    bool startFlag;
    QTimer *timeOfReload;
    uint timeOfCalculation;
    CalculationMap *calculationOfVectors;
    QVector<orbital_vectors::ASKVectors> askvectors;
    QVector<orbital_vectors::GegraphicCoordinate> coordinate;

};
#endif // MAINWINDOW_H
