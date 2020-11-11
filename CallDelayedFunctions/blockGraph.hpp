#include "vector.hpp"

#ifndef BLOCKGRAPH_H
#define BLOCKGRAPH_H
typedef struct block3D
{
    /** \brief
     *
     */
    int type;

    /** \brief
     *
     */
    int entityID;


    /** \brief
     *
     */
    vector v[4];

    /** \brief
     *
     */
    vector n[4];


    /** \brief
     *
     */
    vector position;

    /** \brief
     *
     */
    vector side[4];

    /** \brief
     *
     */
    vector motionPoints[4][5];

    /** \brief
     *
     */
    vector axisX[4];

    /** \brief
     *
     */
    vector dir[4];

    /** \brief
     *
     */
    vector normal;


    /** \brief
     *
     */
    int removable;


    /** \brief
     *
     */
    int adj[4];

    /** \brief
     *
     */
    int adjSide[4];
} block3D;

typedef struct blockGraph
{
    /** \brief
     *
     */
    unsigned int numberOfBlockModels;

    /** \brief
     *
     */
    block3D* blockGraph;

    /** \brief
     *
     */
    int surfaceModel;

    /** \brief
     *
     */
    int  fillerModel;

    /** \brief
     *
     */
    int* blockGraphDirtyBit;

    /** \brief
     *
     */
    unsigned int blockUpdateListLength;

    /** \brief
     *
     */
    unsigned int* blockUpdateList;

    /** \brief
     *
     */
    unsigned int blockUpdateListTempLength;

    /** \brief
     *
     */
    unsigned int* blockUpdateListTemp;

    /** \brief
     *
     */
    int spr_blockTexture;

    /** \brief
     *
     */
    int tex_blockTexture;
} blockGraph;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void blockGraph_initBlockModelAssets(const char* program_directory, const char* worldName);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void blockGraph_create3DModel();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void blockGraph_setUpBlockGraphList();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void blockGraph_addToBlockUpdateList(int blockID);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void blockGraph_updateBlockGraphWithList();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void blockGraph_loadFromFile(const char* fileName);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void blockGraph_drawEvent();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_transform_add_block_matrix(int blockID, int sideFacing, int motion, int movingSide);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int blockGraph_getAdjacentID(int blockID, int side);

extern blockGraph* blkGph;
#endif
