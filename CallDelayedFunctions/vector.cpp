#include <math.h>
#include "vector.hpp"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int operator==(vector v1, vector v2)
{
    return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator*(double c, vector v)
{
    vector result;
    result.x = c * v.x;
    result.y = c * v.y;
    result.z = c * v.z;
    return result;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator*(vector v, double c)
{
    return c * v;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator/(vector v, double c)
{
    return (1/c) * v;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator+(vector v1, vector v2)
{
    vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator-(vector v)
{
    return (-1)*v;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator-(vector v1, vector v2)
{
    return v1 + (-v2);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double operator*(vector v1, vector v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector crossProduct(vector v1, vector v2)
{
    vector result;
    result.x = (v1.y * v2.z) - (v1.z * v2.y);
    result.y = (v1.z * v2.x) - (v1.x * v2.z);
    result.z = (v1.x * v2.y) - (v1.y * v2.x);
    return result;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double signedVolume(vector a, vector b, vector c, vector d)
{
    return (1.0/6.0)*(crossProduct(b-a,c-a) * (d-a));
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector norm(vector v)
{
    return (1/sqrt(v*v))*v;
}
