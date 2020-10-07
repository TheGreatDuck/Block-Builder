#include "vector.hpp"

int operator==(vector v1, vector v2)
{
    return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);
}

vector operator*(double c, vector v)
{
    vector result;
    result.x = c * v.x;
    result.y = c * v.y;
    result.z = c * v.z;
    return result;
}

vector operator*(vector v, double c)
{
    return c * v;
}

vector operator/(vector v, double c)
{
    return (1/c) * v;
}

vector operator+(vector v1, vector v2)
{
    vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

vector operator-(vector v)
{
    return (-1)*v;
}

vector operator-(vector v1, vector v2)
{
    return v1 + (-v2);
}

double operator*(vector v1, vector v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

vector crossProduct(vector v1, vector v2)
{
    vector result;
    result.x = (v1.y * v2.z) - (v1.z * v2.y);
    result.y = (v1.z * v2.x) - (v1.x * v2.z);
    result.z = (v1.x * v2.y) - (v1.y * v2.x);
    return result;
}

double signedVolume(vector a, vector b, vector c, vector d)
{
    return (1.0/6.0)*(crossProduct(b-a,c-a) * (d-a));
}
