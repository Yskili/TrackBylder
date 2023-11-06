#ifndef PLOTMAP_H
#define PLOTMAP_H

#include "qcustomplot.h"
#include "calculationmap.h"

class PlotMap: public QCustomPlot
{
    Q_OBJECT
public:
    PlotMap(QCustomPlot *_customPlot); // Настраиваем параметры графика
    ~PlotMap();
    void plotMap(QVector<orbital_vectors::GegraphicCoordinate> &_coordinate); // Отстраеваем трассу и первоначальное положение КА
    uint GetCounter(); // Текущее местоположение КА
    void SetLabel(QLabel *Time, QLabel *Latitude, QLabel *Longitude, QLabel *_Height); // Указатели на элементы UI
    void ClearCoordinate(); // Очистить данные с графиков

signals:
    void StartReplot();

public slots:
    void Replot(QVector<orbital_vectors::GegraphicCoordinate> &_coordinate); // Перестраиваем трассу
    void ReplotSattelite(); // Переопределяем положение КА по таймеру

private:
    QCPCurve *newCurve; // Трасса для КА
    QCustomPlot *customPlot;
    QCPCurve *newSattelitePoint; // Текущее положение КА
    QLabel *Time;
    QLabel *Latitude;
    QLabel *Longitude;
    QLabel *Height;
    QVector<double>la, fi, hg;
    double laSattelite, fiSattelite;
    uint counter;
};

#endif // PLOTMAP_H
