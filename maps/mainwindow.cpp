#include "mainwindow.h"
#include "ui_mainwindow.h"

MapOfSattelite::MapOfSattelite(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MapOfSattelite)
{
    ui->setupUi(this);
    SetOptions();
    startFlag = true;
    map = new PlotMap(ui->plotMap);
    map->SetLabel(ui->Time, ui->Latitude, ui->Longitude, ui->Height);
    StartFcn();
    connect(&options, &Options::sendOptions, this, &MapOfSattelite::getOptions);
}

MapOfSattelite::~MapOfSattelite()
{
    delete timeOfReload;
    delete map;
    delete ui;
}

void MapOfSattelite::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
    if (calculationOfVectors != nullptr)
    {
        QDateTime lastDate = calculationOfVectors->GetLastDate().addSecs(map->GetCounter()+1);
        calculationOfVectors->GetStateVectors(askvectors);
        calculationOfVectors->SaveLogs(askvectors[map->GetCounter()],lastDate);
    }
}

void MapOfSattelite::StartFcn()
{
    if (startFlag)
    {
        timeOfCalculation = 5000;
        startFlag = false;
    }
    calculationOfVectors = new CalculationMap(timeOfCalculation);
    calculationOfVectors->StartChecout();
    calculationOfVectors->GetCoordinate(coordinate);
    map->plotMap(coordinate);
    SetTimer();
}

void MapOfSattelite::SetTimer()
{
    timeOfReload = new QTimer();
    connect(timeOfReload, &QTimer::timeout, map, &PlotMap::ReplotSattelite);
    timeOfReload->start(1000);
    connect(map, &PlotMap::StartReplot, calculationOfVectors, &CalculationMap::Recalculate);
    connect(calculationOfVectors, &CalculationMap::RecalculateIsReady, map, &PlotMap::Replot);
}

void MapOfSattelite::on_Update_clicked()
{
    options.setModal(true);
    options.exec();
}

void MapOfSattelite::getOptions(double _delta, double _w, double _inc, double _vi, double _hp, double _ha,
                                int _timeOfCalculation, bool checkClicked)
{
    options.accept();
    timeOfCalculation = _timeOfCalculation;
    delete calculationOfVectors;
    delete timeOfReload;
    map->ClearCoordinate();
    if (checkClicked)
    {
        StartFcn();
    } else
    {
        calculationOfVectors = new CalculationMap(timeOfCalculation);
        calculationOfVectors->UpdateVectors(_delta, _w, _inc, _vi, _hp, _ha);
        calculationOfVectors->GetCoordinate(coordinate);
        map->plotMap(coordinate);
        SetTimer();
    }
}

void MapOfSattelite::SetOptions()
{
    QDesktopWidget desktop;
    QRect desktopRect = desktop.availableGeometry(this);
    int x = desktopRect.x() + (desktopRect.width() - width()) / 2;
    int y = desktopRect.y() + (desktopRect.height() - height()) / 2;
    move(x, y);
    setStyleSheet("background-color: white;");
}

