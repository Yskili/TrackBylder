#include "orbitalvectors.h"

orbital_vectors::ASKVectors& orbital_vectors::ASKVectors::operator = (const ASKVectors& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    Vx = other.Vx;
    Vy = other.Vy;
    Vz = other.Vz;
}

orbital_vectors::ASKVectors::ASKVectors(const ASKVectors &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    Vx = other.Vx;
    Vy = other.Vy;
    Vz = other.Vz;
}
