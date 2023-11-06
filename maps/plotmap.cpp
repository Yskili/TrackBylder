#include "plotmap.h"

PlotMap::PlotMap(QCustomPlot *_customPlot): customPlot(_customPlot), counter(0)
{
    customPlot->axisRect()->setBackground(QPixmap(":/recource/img/earth.jpg"));
    newCurve = new QCPCurve (customPlot->xAxis, customPlot->yAxis);
    newCurve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 1));
    newSattelitePoint = new QCPCurve (customPlot->xAxis, customPlot->yAxis);
    newSattelitePoint->setScatterStyle(QCPScatterStyle(QPixmap(":/recource/img/sattelite.png")));
    newCurve->setLineStyle(QCPCurve::lsNone);
    customPlot->xAxis->setRange(-180, 180);
    customPlot->xAxis->setTickLabelFont(QFont("Alegreya Black",14));
    customPlot->yAxis->setRange(-90, 90);
    customPlot->yAxis->setTickLabelFont(QFont("Alegreya Black",14));
}

void PlotMap::plotMap(QVector<orbital_vectors::GegraphicCoordinate> &_coordinate)
{
    for(uint16_t i = 0; i < _coordinate.size(); ++i)
    {
        la.append(_coordinate[i].la);
        fi.append(_coordinate[i].fi);
        hg.append(_coordinate[i].hg);
    }
    customPlot->addGraph();
    newCurve->setData(la, fi);
    laSattelite = la[counter];
    fiSattelite = fi[counter];
    newSattelitePoint->addData(laSattelite, fiSattelite);
    customPlot->replot();
    counter++;
}

uint PlotMap::GetCounter()
{
    return counter;
}

void PlotMap::SetLabel(QLabel *_Time, QLabel *_Latitude, QLabel *_Longitude, QLabel *_Height)
{
    Time = _Time;
    Latitude = _Latitude;
    Longitude = _Longitude;
    Height = _Height;
}

PlotMap::~PlotMap()
{
    delete Time;
    delete Height;
    delete Latitude;
    delete Longitude;
    delete newCurve;
    delete newSattelitePoint;
}

void PlotMap::Replot(QVector<orbital_vectors::GegraphicCoordinate> &_coordinate)
{
    ClearCoordinate();
    plotMap(_coordinate);
}

void PlotMap::ClearCoordinate()
{
    la.clear();
    fi.clear();
    hg.clear();
    counter = 0;
    newCurve->data()->clear();
    newSattelitePoint->data()->remove(0);
    customPlot->replot();
}

void PlotMap::ReplotSattelite()
{
    if (counter==la.size()-1)
    {
        emit StartReplot();
    }
    newSattelitePoint->data()->remove(0);
    laSattelite = la[counter];
    fiSattelite = fi[counter];
    Time->setText("Time: "+QTime::currentTime().toString());
    Latitude->setText("Latitude: "+QString::number(fiSattelite));
    Longitude->setText("Longitude: "+QString::number(laSattelite));
    Height->setText("Height: "+QString::number(hg[counter]));
    newSattelitePoint->addData(laSattelite, fiSattelite);
    customPlot->replot();
    counter++;
}
