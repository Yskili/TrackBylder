#ifndef STATEVECTORS_H
#define STATEVECTORS_H

#include <QDateTime>
#include <QDate>
#include <efemeridsorbit.h>

// Класс для получения векторов состояний
// Можно модифицировать и записать в БД
class StateVectors
{
public:
    StateVectors(orbital_vectors::ASKVectors _vec, uint _timeOfCalculation);
    void RungeKuttaForASK(); // Интегрирование для получения векторов состояний
    void GetASKVectors(QVector<orbital_vectors::ASKVectors>& _vec);
    void GetLastVectors(orbital_vectors::ASKVectors& last_vectors);
    void SetTimeOfCalculation(uint& _timeOfCalculation);
    double StarTime(uint t); // Звездное время
    void GSKcoordinate(); // Переход в Гринвичскую систему координат
    void GeographicCoordinate(); // Переход из ГСК в долготу, широту и высоту полета
    QVector<orbital_vectors::GegraphicCoordinate> GetCoordinate();

private:
    // Функция атмосферы Земли ГОСТ 25645.101-83 для средней солнечной активности  F0 = 175
    inline double AtmosphereFunc(const double heigh);
    inline double Integration_coefficient(double x, double z, double r) const; // Функция рассчета коэффициента для метода Рунге-Кутта
    void HideCoordinateOfiterations(const double& coordinate, const double velocity,
                                    const double& z_coordinate,const double& r, double& q, double& k); // Рассчет суммарных коэффициентов для метода Рунге-Кутта

private:
    QVector<orbital_vectors::ASKVectors> vec;  // Вектор для координат и скоростей КА
    QVector<orbital_vectors::GSKvectors> vecGSK; // вектор координат в ГСК
    QVector<orbital_vectors::GegraphicCoordinate> earth_coordinate; // вектор координат долготы и широты
    uint timeOfCalculation;         // Время интегрирования
    const double mu = 398600.0;               // Гравитационный параметр
    const double ae = 6378.136;             // Экваториальный радиус Земли

};

#endif // STATEVECTORS_H
