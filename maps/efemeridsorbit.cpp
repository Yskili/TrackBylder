#include "efemeridsorbit.h"

void EfemeridsOrbit::ConvertEfemeridsToStateVectors(orbital_vectors::ASKVectors& _vec)
{
    const uint RZ = 6371;   // Радиус Земли
    const double MU = 398600; // Гравитационный параметр
    double rp, ra, p0, r0; // Радиусы перигея, апогея, фокальный параметр, радиус-вектор КА
    double vn, vr;         // Трансверсальная и радиальные скорости
    orbital_vectors::ASKVectors vec;
    rp = RZ + hp;
    ra = RZ + ha;
    eps = (ra-rp)/(ra+rp);
    p0 = 2*ra*rp/(ra+rp);
    r0 = p0/(1+eps*cos(vi));
    _vec.x = r0*(qCos(u)*qCos(delta)-qSin(u)*qCos(inc)*qSin(delta));
    _vec.y = r0*(qCos(u)*qSin(delta)+qSin(u)*qCos(inc)*qCos(delta));
    _vec.z = r0*qSin(u)*qSin(inc);
    vn = qSqrt(MU/p0)*(1+eps*qCos(vi));
    vr = eps*sqrt(MU/p0)*qSin(vi);
    _vec.Vx=vr*(qCos(u)*qCos(delta)-qSin(u)*qCos(inc)*qSin(delta))-vn*(qCos(delta)*qSin(u)+qSin(delta)*qCos(u)*qCos(inc));
    _vec.Vy=vr*(qCos(u)*qSin(delta)+qSin(u)*qCos(inc)*qCos(delta))-vn*(qSin(delta)*qSin(u)-qCos(delta)*qCos(u)*qCos(inc));
    _vec.Vz=vr*qSin(u)*qSin(inc)+vn*qCos(u)*qSin(inc);
}
