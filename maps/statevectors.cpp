#include "statevectors.h"

StateVectors::StateVectors(orbital_vectors::ASKVectors _vec, uint _timeOfCalculation)
{
    timeOfCalculation = _timeOfCalculation;
    vec.reserve(timeOfCalculation);
    vec.append(std::move(_vec));
}

inline double StateVectors::AtmosphereFunc(const double heigh)
{
        double a0 = 0, a1 = 0, a2 = 0, a3 = 0;
        if (heigh >= 120 && heigh < 180)
        {
            a0 = 9.80665;
            a1 = -18.77083;
            a2 = 0.58133;
            a3 = 116.79483;
        } else if (heigh >= 180 && heigh < 600)
        {
            a0 = 9.80665;
            a1 = -18.99228;
            a2 = 0.54002;
            a3 = 113.48581;
        } else if (heigh >= 600 && heigh < 1500)
        {
            a0 = 9.80665;
            a1 = -23.32353;
            a2 = 0.40080;
            a3 = 243.19499;
        }
        return a0*exp(a1-a2*sqrt(heigh-a3));
}

inline double StateVectors::Integration_coefficient(double calculation_coordinate, double z, double r) const
{
    const double J2 = 1082.627*qPow(10,-6);
    return -mu/qPow(r,3)*calculation_coordinate+(1.5*J2*mu/qPow(r,2)*qPow((ae/r),2)*
                                              (5*qPow(z/r,2)-1))*calculation_coordinate/r;
}

void StateVectors::HideCoordinateOfiterations(const double& coordinate, const double velocity,
                                              const double& z_coordinate,const double& r, double& q, double& k)
{
    double q0, q1, q2, q3, k0, k1, k2, k3;
    const int h = 1;
    k0 = velocity;
    q0 = Integration_coefficient(coordinate, z_coordinate, r);
    k1 = velocity+q0*h/2.0;
    q1 = Integration_coefficient(coordinate+k0*h/2.0, z_coordinate+k0*h/2.0, r);
    k2 = velocity+q1*h/2.0;
    q2 = Integration_coefficient(coordinate+k1*h/2.0, z_coordinate+k1*h/2.0, r);
    k3 = velocity+q2*h;
    q3 = Integration_coefficient(coordinate+k2*h, z_coordinate+k2*h, r);
    k = (k0+2*k1+2*k2+k3)/6.0*h;
    q = (q0+2*q1+2*q2+q3)/6.0*h;
}

// Рассчет векторов состяний методом Рунге-Кутта (точность +- хорошая до 5000с)
void StateVectors::RungeKuttaForASK()
{
    uint start_time = 1;
    double r, k, q;
    orbital_vectors::ASKVectors iterations_vector;
    for (size_t i = 1; i < timeOfCalculation; ++i)
    {
        r = qSqrt(qPow(vec[i-1].x,2)+qPow(vec[i-1].y,2)+qPow(vec[i-1].z,2));
        // For X and Vx
        HideCoordinateOfiterations(vec[i-1].x, vec[i-1].Vx, vec[i-1].z, r, q, k);
        iterations_vector.x = vec[i-1].x + k;
        iterations_vector.Vx = vec[i-1].Vx + q;
        // For Y and Vy
        HideCoordinateOfiterations(vec[i-1].y, vec[i-1].Vy, vec[i-1].z, r, q, k);
        iterations_vector.y = vec[i-1].y + k;
        iterations_vector.Vy = vec[i-1].Vy + q;
        // For Z and Vz
        HideCoordinateOfiterations(vec[i-1].z, vec[i-1].Vz, vec[i-1].z, r, q, k);
        iterations_vector.z = vec[i-1].z + k;
        iterations_vector.Vz = vec[i-1].Vz + q;
        vec.append(std::move(iterations_vector));
    }
}

void StateVectors::GetASKVectors(QVector<orbital_vectors::ASKVectors>& _vec)
{
    _vec = vec;
}

void StateVectors::GetLastVectors(orbital_vectors::ASKVectors &last_vectors)
{
    last_vectors = vec[vec.size()-1];
}

void StateVectors::SetTimeOfCalculation(uint &_timeOfCalculation)
{
    this->timeOfCalculation = _timeOfCalculation;
}

inline double StateVectors::StarTime(uint t)
{
    QString dt = QDateTime::currentDateTimeUtc().toString("hh:mm:ss"); // Текущее время по гринвичу
    QStringList time = dt.split(u':'); // Текущее количество часов, минут, секунд
    double juliandate = QDate::currentDate().toJulianDay()-0.5; // Текущая юлианская дата
    double tt=(juliandate-2451545)/ 36525; // Поправочный коэффициент
    double ss=(6*60*60+41*60+50.54841+8640184.812866*tt+0.093104*pow(tt,2)-6.2*pow(tt,3)
                            +time[0].toDouble()*3600+time[1].toDouble()*60+time[2].toDouble()+t)*0.000277778*15.0; // Звездное время
    return (ss-(static_cast<int>(ss)/360*360))*M_PI/180.0; // Перевод в радианы
}

void StateVectors::GSKcoordinate()
{
    vecGSK.reserve(timeOfCalculation);
    orbital_vectors::GSKvectors iteration_gskvec;
    double s;
    for(uint i = 0; i < timeOfCalculation; ++i)
    {
        s = StarTime(i);
        iteration_gskvec.xg = vec[i].x*qCos(s)+vec[i].y*qSin(s);
        iteration_gskvec.yg = -vec[i].x*qSin(s)+vec[i].y*qCos(s);
        iteration_gskvec.zg = vec[i].z;
        vecGSK.append(std::move(iteration_gskvec));
    }
}

void StateVectors::GeographicCoordinate()
{
    earth_coordinate.reserve(timeOfCalculation);
    orbital_vectors::GegraphicCoordinate iteration_coordinate;
    double rz, rg, az = 1.0/298.257; // Высота полета в ГСК, коэффициент сжатия Земли
    for(uint i = 0; i < timeOfCalculation; ++i)
    {
        iteration_coordinate.fi = qRadiansToDegrees(qAtan2(vecGSK[i].zg, qSqrt(qPow(vecGSK[i].xg,2)
                                                                            +qPow(vecGSK[i].yg,2))));
        iteration_coordinate.la = qRadiansToDegrees(qAtan2(vecGSK[i].yg, vecGSK[i].xg));
        rg = qSqrt(qPow(vecGSK[i].xg,2)+qPow(vecGSK[i].yg,2)+qPow(vecGSK[i].zg,2));
        rz = ae*(1-az*qPow(qSin(qDegreesToRadians(iteration_coordinate.fi)),2));
        iteration_coordinate.hg = rg - rz;
        earth_coordinate.append(std::move(iteration_coordinate));
    }
}

QVector<orbital_vectors::GegraphicCoordinate> StateVectors::GetCoordinate()
{
    return earth_coordinate;
}
