#ifndef EFEMERIDSORBIT_H
#define EFEMERIDSORBIT_H

#include <QtMath>
#include <QVector>
#include <orbitalvectors.h>

// Можно модифицировать добавив пересчет по оскулирующим элементам орбиты
// Добавить перевод из векторов состояний в параметры орбиты
// Эфемериды орбиты объявлены как поля класса для возможности записи в БД при необходимости
class EfemeridsOrbit
{
public:
    EfemeridsOrbit(double _delta, double _w, double _inc, double _vi,
                   double _hp, double _ha): delta(_delta*M_PI/180.0), w(_w*M_PI/180.0),
                        inc(_inc*M_PI/180.0), vi(_vi*M_PI/180.0), hp(_hp), ha(_ha), u(w+vi){}
    void ConvertEfemeridsToStateVectors(orbital_vectors::ASKVectors& _vec);

private:
    double delta; // Долгота восходящего узла, рад
    double eps;   // Эксцентриситет
    double w;     // Аргумент перицентра, рад
    double inc;   // Наклонение, рад
    double vi;    // Угол истинной аномалии, рад
    double u;     // Аргумент широты, рад
    double hp;    // Высота перигея, км
    double ha;    // Высота апогея, км

};

#endif // EFEMERIDSORBIT_H
