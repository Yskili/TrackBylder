#ifndef CALCULATIONMAP_H
#define CALCULATIONMAP_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include "statevectors.h"

enum StatusOfExecution
{
    fileIsEmpty = 1,
    fileWithData = 2
};

class CalculationMap: public QObject
{
    Q_OBJECT

public:
    CalculationMap(uint _timeOfCalculation, QObject *parent = nullptr): QObject(parent),
        timeOfCalculation(_timeOfCalculation) {}
    ~CalculationMap(){}
    void StartChecout();
    inline QString WriteStringCreator(const orbital_vectors::ASKVectors& _start_vectors,
                                      const QDateTime &dateOflastWrite); // Создание пакета для записи данных в файл
    void UpdateVectors(double &_delta, double &_w, double &_inc, double &_vi, double &_hp, double &_ha); // Обновление вектора при изменении параметров
    void SaveLogs(const orbital_vectors::ASKVectors _start_vectors, const QDateTime dateOflastWrite); // Сохраняет логи последнего вектора в АСК и дату и время
    void GetStateVectors(QVector<orbital_vectors::ASKVectors>& _askvectors) {_askvectors = askvectors;}
    void GetCoordinate(QVector<orbital_vectors::GegraphicCoordinate> &_coordinate) {_coordinate = coordinate;} // По ссылке для исключения перевыделения памяти
    QDateTime GetLastDate() {return dateOflastWrite;}


public slots:
    void Recalculate(); // Пересчет данных при проходе всех значений координат

signals:
    void RecalculateIsReady(QVector<orbital_vectors::GegraphicCoordinate> &_coordinate); // Вызов сигнала на передачу пересчитанных данных для перестройки трассы

private:
    void BaseFunc(orbital_vectors::ASKVectors& start_vectors,
                  QVector<orbital_vectors::ASKVectors>& _askvectors,
                    QVector<orbital_vectors::GegraphicCoordinate>& _coordinate);  // Набор функций для вычесления координат и веторов

private:
    StatusOfExecution status;
    QDateTime dateOflastWrite;
    uint timeOfCalculation;
    QVector<orbital_vectors::ASKVectors> askvectors; // Необходимо сохранять весь вектор, а не последнее значение, тк при завершении программы должно сохранится последнее состояние
    QVector<orbital_vectors::GegraphicCoordinate> coordinate; // Долгота и широта

};

#endif // CALCULATIONMAP_H
