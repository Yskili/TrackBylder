#include "calculationmap.h"

void CalculationMap::StartChecout()
{
    QStringList vectorsString;
    orbital_vectors::ASKVectors start_vectors;
    qint64 timeOfbacklog;
    if (QFile::exists("log.txt"))
    {
        QFile file("log.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            QTextStream output_file(&file);
            QString read_data = output_file.readLine();
            file.close();
            dateOflastWrite = QDateTime::fromString(read_data.left(25));
            timeOfbacklog = dateOflastWrite.secsTo(QDateTime::currentDateTimeUtc())-14400; // Тк считывание
                                                        //  из файла идет в локальном формате вычтем разницу UTC and Local
            vectorsString = read_data.split(u' ');
            for (uint8_t var = 0; var < 5; ++var)
            {
                vectorsString.pop_front();
            }
            if (timeOfbacklog < 256000) // Костыль тк нет подтяжки к постоянному обновлению времени
            {
                status = fileWithData;
            }
            else
            {
                status = fileIsEmpty;
            }
        } else
        {
            qCritical() << file.errorString();
        }
    } else
    {
        status = fileIsEmpty;
    }
    switch (status) {
        case fileWithData:
        {
            start_vectors = orbital_vectors::ASKVectors(vectorsString[0].toDouble(), vectorsString[1].toDouble(),
                        vectorsString[2].toDouble(), vectorsString[3].toDouble(), vectorsString[4].toDouble(),
                                                    vectorsString[5].toDouble());
            StateVectors vecOfbacklog(start_vectors, timeOfbacklog);
            vecOfbacklog.RungeKuttaForASK();
            vecOfbacklog.GetLastVectors(start_vectors);               // Приводим вектора состояний к текущему времени
            dateOflastWrite = dateOflastWrite.addSecs(timeOfbacklog);
            SaveLogs(start_vectors,dateOflastWrite);
            BaseFunc(start_vectors, askvectors, coordinate);
            break;
        }
        case fileIsEmpty:
        {
            EfemeridsOrbit parametersOfOrbit(140.29,249.23,97.66,95.64,564.7,576.3);
            parametersOfOrbit.ConvertEfemeridsToStateVectors(start_vectors);
            dateOflastWrite = dateOflastWrite.currentDateTimeUtc();
            SaveLogs(start_vectors,dateOflastWrite);
            BaseFunc(start_vectors, askvectors, coordinate);
            break;
        }
    }
}

inline QString CalculationMap::WriteStringCreator(const orbital_vectors::ASKVectors& _start_vectors,
                                                  const QDateTime& dateOflastWrite)
{
    return dateOflastWrite.toString("ddd MMM d hh:mm:ss yyyy")+" "+QString::number(_start_vectors.x, 'g', 8)+
                          " "+QString::number(_start_vectors.y, 'g', 8)+
                          " "+QString::number(_start_vectors.z, 'g', 8)+
                          " "+QString::number(_start_vectors.Vx, 'g', 8)+
                          " "+QString::number(_start_vectors.Vy, 'g', 8)+
           " "+QString::number(_start_vectors.Vz, 'g', 8);
}

void CalculationMap::BaseFunc(orbital_vectors::ASKVectors& _start_vectors,
        QVector<orbital_vectors::ASKVectors>& _askvectors,
                              QVector<orbital_vectors::GegraphicCoordinate>& _coordinate)
{
    StateVectors vec(_start_vectors, timeOfCalculation);
    vec.RungeKuttaForASK();
    vec.GetASKVectors(_askvectors);
    vec.GSKcoordinate();
    vec.GeographicCoordinate();
    _coordinate = vec.GetCoordinate();
}

void CalculationMap::UpdateVectors(double& _delta, double& _w,
                                   double& _inc, double& _vi, double& _hp, double& _ha)
{
    orbital_vectors::ASKVectors start_vectors;
    Q_ASSERT_X(_delta <= 360 && _delta >= 0, "calculationmap","Longitude of ascending node >360 or <0");
    Q_ASSERT_X(_w <= 360 && _w >= 0, "calculationmap","Argument of peiapsis >360 or <0");
    Q_ASSERT_X(_inc <= 180 && _inc >= 0, "calculationmap","Inclination >180 or <0");
    Q_ASSERT_X(_vi <= 180 && _vi >= 0, "calculationmap","True anomaly >180 or <0");
    Q_ASSERT_X(_hp <= 35768 && _hp >= 120, "calculationmap","Incorrect perigee altiude");
    Q_ASSERT_X(_ha <= 35768 && _ha >= 120, "calculationmap","Incorrect apogee altiude");
    EfemeridsOrbit parametersOfOrbit(_delta, _w, _inc, _vi, _hp, _ha);
    parametersOfOrbit.ConvertEfemeridsToStateVectors(start_vectors);
    dateOflastWrite = dateOflastWrite.currentDateTimeUtc();
    SaveLogs(start_vectors,dateOflastWrite);
    BaseFunc(start_vectors, askvectors, coordinate);
}

void CalculationMap::Recalculate()
{
    BaseFunc(askvectors[askvectors.size()-1], askvectors, coordinate);
    dateOflastWrite = dateOflastWrite.addSecs(timeOfCalculation);
    SaveLogs(askvectors[0], dateOflastWrite);
    emit RecalculateIsReady(coordinate);
}

void CalculationMap::SaveLogs(const orbital_vectors::ASKVectors _start_vectors,
                              const QDateTime _dateOflastWrite)
{
    QFile file("log.txt");
    QString write_data = WriteStringCreator(_start_vectors, _dateOflastWrite);
    if (file.open(QIODevice::WriteOnly) )
    {
            file.write(write_data.toUtf8());
            file.flush();
            file.seek(0);
            file.close();
    }
    else
    {
            qCritical() << file.errorString();
    }
}
