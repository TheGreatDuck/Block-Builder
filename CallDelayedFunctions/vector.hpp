#ifndef __VECTOR_H__
#define __VECTOR_H__

struct vector
{
    /** \brief
     *
     */
    double x;

    /** \brief
     *
     */
    double y;

    /** \brief
     *
     */
    double z;
};

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int operator==(vector v1, vector v2);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator*(double c, vector v);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator*(vector v, double c);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator/(vector v, double c);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator+(vector v1, vector v2);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator-(vector v);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector operator-(vector v1, vector v2);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double operator*(vector v1, vector v2);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector crossProduct(vector v1,vector v2);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double signedVolume(vector a, vector b, vector c, vector d);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
vector norm(vector v);

#endif // __VECTOR_H__
