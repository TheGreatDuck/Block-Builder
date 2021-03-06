#include "blockGraph.hpp"
#include "hand_render.hpp"
#include <stdio.h>
#include <algorithm>

extern vector cam_m[4];

#define height 512
#define width  640

int    renderedBlockGraph_ID[640*512];
double renderedBlockGraph_z[640*512];

static int ceil(double x)
{
    if (x > (int)x)
        return ((int)x)+1;
    else
        return (int)x;
}

static void render_block(int blockID, vector v0, vector v1, vector v2)
{
    v0 = v0 - cam_m[3];
    v1 = v1 - cam_m[3];
    v2 = v2 - cam_m[3];

    // Mutate each Vertex object so that it contains the view coordinates.
    double temp_x = v0*cam_m[0];
    double temp_y = v0*cam_m[2];
    double temp_z = v0*cam_m[1];
    v0.x = temp_x;
    v0.y = temp_y;
    v0.z = temp_z;

    temp_x = v1*cam_m[0];
    temp_y = v1*cam_m[2];
    temp_z = v1*cam_m[1];
    v1.x = temp_x;
    v1.y = temp_y;
    v1.z = temp_z;

    temp_x = v2*cam_m[0];
    temp_y = v2*cam_m[2];
    temp_z = v2*cam_m[1];
    v2.x = temp_x;
    v2.y = temp_y;
    v2.z = temp_z;

    // Mutate each Vertex object so that it contains the projected coordinates.
    v0.x = -v0.x/v0.z;
    v0.y = -v0.y/v0.z;

    v1.x = -v1.x/v1.z;
    v1.y = -v1.y/v1.z;

    v2.x = -v2.x/v2.z;
    v2.y = -v2.y/v2.z;

    // 8. Apply the viewport transformation.
    // Get the viewport dimensions.
    int w = width;
    int h = height;

    v0.x = w * (v0.x + 0.5);
    v0.y = h * ((1.25)*v0.y + 0.5);

    v1.x = w * (v1.x + 0.5);
    v1.y = h * ((1.25)*v1.y + 0.5);

    v2.x = w * (v2.x + 0.5);
    v2.y = h * ((1.25)*v2.y + 0.5);

    // Get the coordinates from the three vertices.
    double x0 = v0.x,  y0 = v0.y,  z0 = v0.z;
    double x1 = v1.x,  y1 = v1.y,  z1 = v1.z;
    double x2 = v2.x,  y2 = v2.y,  z2 = v2.z;

    // Find the greatest integer less than or equal to x0, x1, and x2.
    int xMin = std::min((int)x0, (int)x1, (int)x2);
    if (xMin <= -1)
        xMin = 0;

    // Find the greatest integer less than or equal to y0, y1, and y2.
    int xMin = std::min((int)x0, (int)x1, (int)x2);
    int yMin = (int)y0;
    if (y1 < yMin) yMin = (int)y1;
    if (y2 < yMin) yMin = (int)y2;
    if (yMin <= -1) yMin = 0;

    // Find the least integer greater than or equal to x0, x1, and x2.
    int xMax = std::max(ceil(x0), ceil(x1), ceil(x2));
    if (xMax >= w)
        xMax = w-1;

    // Find the least integer greater than or equal to y0, y1, and y2.
    int yMax = std::max(ceil(y0), ceil(y1), ceil(y2));
    if (yMax >= h)
        yMax = h-1;

    for (int y = yMax-1; y >= yMin; y--) // top to bottom
    {
        for (int x = xMin; x < xMax; x++)  /// left to right
        {
            double alpha = ( (y1-y2)*(x)  + (x2-x1)*(y)  + x1*y2 - x2*y1 )
                         / ( (y1-y2)*(x0) + (x2-x1)*(y0) + x1*y2 - x2*y1 );
            double beta  = ( (y2-y0)*(x)  + (x0-x2)*(y)  + x2*y0 - x0*y2 )
                         / ( (y2-y0)*(x1) + (x0-x2)*(y1) + x2*y0 - x0*y2 );
            double gamma = ( (y0-y1)*(x)  + (x1-x0)*(y)  + x0*y1 - x1*y0 )
                         / ( (y0-y1)*(x2) + (x1-x0)*(y2) + x0*y1 - x1*y0 );

            if (alpha >= 0 && beta >= 0 && gamma >= 0)
            {
                double zCoord = (alpha * z0) + (beta * z1) + (gamma * z2);
                double zBuff = renderedBlockGraph_z[w*(h - y) + x - 1];

                if ((zCoord > zBuff && zCoord < 0) || zBuff > 0)
                {
                    renderedBlockGraph_z[w*(h - y) + x - 1]  = zCoord;
                    renderedBlockGraph_ID[w*(h - y) + x - 1] = blockID;
                }
            }
        }
    }
}

void render()
{
    for (unsigned int i = 0; i < width*height; i++)
    {
        renderedBlockGraph_ID[i] = -1;
        renderedBlockGraph_z[i]  = 1.0;
    }

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i++)
    {
        render_block(i, blkGph->blockGraph[i].v[0], blkGph->blockGraph[i].v[2], blkGph->blockGraph[i].v[3]);
        render_block(i, blkGph->blockGraph[i].v[0], blkGph->blockGraph[i].v[3], blkGph->blockGraph[i].v[1]);
    }
}
