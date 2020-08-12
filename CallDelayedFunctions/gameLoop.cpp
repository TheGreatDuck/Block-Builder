#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"
#include "gameLoop.h"
#include "player.h"

GMEXPORT double gameLoopInit()
{
    player.currentSpace = 240;

    return 1.0;
}

GMEXPORT double gameLoopStep()
{
    blockGraph_updateBlockGraphWithList();
    player3D_stepEvent();

    return 1.0;
}

GMEXPORT double gameLoopDraw()
{
    blockGraph_drawEvent();
    player3D_drawEvent();
    return 1.0;
}
