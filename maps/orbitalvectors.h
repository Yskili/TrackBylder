#ifndef ORBITALVECTORS_H
#define ORBITALVECTORS_H

namespace orbital_vectors
{
    // Вектора состояний в AСК
    struct ASKVectors
    {
        double x;
        double y;
        double z;
        double Vx;
        double Vy;
        double Vz;
        ASKVectors(double _x = 0, double _y = 0, double _z = 0, double _Vx = 0, double _Vy = 0, double _Vz = 0):
            x(_x),y(_y),z(_z),Vx(_Vx),Vy(_Vy),Vz(_Vz){}
        ASKVectors(const ASKVectors& other);
        ASKVectors& operator = (const ASKVectors& other);
        ~ASKVectors(){}
    };

    // Вектор координат в ГСК
    struct GSKvectors
    {
        double xg;
        double yg;
        double zg;
        GSKvectors(double _xg = 0, double _yg = 0, double _zg = 0): xg(_xg), yg(_yg), zg(_zg){}
    };

    // Долгота и широта
    struct GegraphicCoordinate
    {
        double la;
        double fi;
        double hg; // Высота полета
        GegraphicCoordinate(double _la = 0, double _fi = 0, double _hg = 0) : la(_la), fi(_fi), hg(_hg){}
    };
}

#endif // ORBITALVECTORS_H
