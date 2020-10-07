#ifndef __VECTOR_H__
#define __VECTOR_H__

struct vector
{
    double x;
    double y;
    double z;
};

int operator==(vector v1, vector v2);
vector operator*(double c, vector v);
vector operator*(vector v, double c);
vector operator/(vector v, double c);
vector operator+(vector v1, vector v2);
vector operator-(vector v);
vector operator-(vector v1, vector v2);
double operator*(vector v1, vector v2);

vector crossProduct(vector v1,vector v2);
double signedVolume(vector a, vector b, vector c, vector d);

#endif // __VECTOR_H__
