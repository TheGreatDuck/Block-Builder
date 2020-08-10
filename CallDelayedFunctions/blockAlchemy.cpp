#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"

GMEXPORT double scr_changeBlock(double blockType, double north, double west, double east, double south)
{
    ///scr_changeBlock(a,b,c,d,e)
/* An ideal version of this would be a mathematical function.
 *
 * Control statements can be expensive as the processor will
 * attempt to 'predict' which path is taken and work ahead whilst
 * waiting for exact details. A bad predication wastes time. Therefore,
 * we will desire a version that uses explicit logic in a simple manner.
 *
 * While the graphics and everything are helpful, this function truly
 * defines each of the blocks. They each do different things and so there
 * is never any two blocks with the same properties.
 */

 /* argument 1 = north
  * argument 2 = west
  * argument 3 = east
  * argument 4 = south
  */

north = north mod 1000000;
west = west mod 1000000;
east = east mod 1000000;
south = south mod 1000000;

channel = (north == 1) || (west == 1) || (east == 1) || (south == 1);
water = (north == 2) || (west == 2) || (east == 2) || (south == 2);
lava = (north == 3) || (west == 3) || (east == 3) || (south == 3);
dirt = (north == 4) || (west == 4) || (east == 4) || (south == 4);
ice = (north == 5) || (west == 5) || (east == 5) || (south == 5);
grass = (north == 6) || (west == 6) || (east == 6) || (south == 6);
poison = (north == 7) || (west == 7) || (east == 7) || (south == 7);
sand = (north == 8) || (west == 8) || (east == 8) || (south == 8);
wetSand = (north == 9) || (west == 9) || (east == 9) || (south == 9);
glass = (north == 10) || (west == 10) || (east == 10) || (south == 10);
tree = (north == 11) || (west == 11) || (east == 11) || (south == 11);
petrifiedTree = (north == 12) || (west == 12) || (east == 12) || (south == 12);
waterEyeSwitch = (north == 13) || (west == 13) || (east == 13) || (south == 13);
lavaEyeSwitch = (north == 14) || (west == 14) || (east == 14) || (south == 14);
poisonEyeSwitch = (north == 15) || (west == 15) || (east == 15) || (south == 15);



pushable = (north == 19) || (west == 19) || (east == 19) || (south == 19);
metal = (north == 20) || (west == 20) || (east == 20) || (south == 20);
hotMetal = (north == 21) || (west == 21) || (east == 21) || (south == 21);
hole = (north == 22) || (west == 22) || (east == 22) || (south == 22);
underworldFlame = (north == 23) || (west == 23) || (east == 23) || (south == 23);
bomb = (north == 24) || (west == 24) || (east == 24) || (south == 24);
explosion = (north == 25) || (west == 25) || (east == 25) || (south == 25);
electricalSource = (north == 26) || (west == 26) || (east == 26) || (south == 26);
pitdoorOpen = (north == 27) || (west == 27) || (east == 27) || (south == 27);
pitdoorShut = (north == 28) || (west == 28) || (east == 28) || (south == 28);
wood = (north == 29) || (west == 29) || (east == 29) || (south == 29);
burningWood = (north == 30) || (west == 30) || (east == 30) || (south == 30);
sandstone = (north == 31) || (west == 31) || (east == 31) || (south == 31);
stoneBrick = (north == 32) || (west == 32) || (east == 32) || (south == 32);
prism = (north == 33) || (west == 33) || (east == 33) || (south == 33);

//if we try to have multiple directions power a
//shadow at once then we can get infinite propogation
darknessBaseN = (north == 34);
darknessBaseW = (west == 34);
darknessBaseE = (east == 34);
darknessBaseS = (south == 34);
darknessSpreadN = (floor(north/1000) != 4)*(floor(north/1000) != 0)*(floor(north/1000000) == 0);
darknessSpreadW = (floor(west/1000) != 3)*(floor(west/1000) != 0)*(floor(west/1000000) == 0);
darknessSpreadE = (floor(east/1000) != 2)*(floor(east/1000) != 0)*(floor(east/1000000) == 0);
darknessSpreadS = (floor(south/1000) != 1)*(floor(south/1000) != 0)*(floor(south/1000000) == 0);

light = (north == 35) || (west == 35) || (east == 35) || (south == 35);



if (argument[0] < 1000 && argument[0] != 34)
{
    if ((darknessBaseN || darknessSpreadN) && !light)
    {
        return argument[0] + 1000;
    }

    if ((darknessBaseW || darknessSpreadW) && !light)
    {
        return argument[0] + 2000;
    }

    if ((darknessBaseE || darknessSpreadE) && !light)
    {
        return argument[0] + 3000;
    }

    if ((darknessBaseS || darknessSpreadS) && !light)
    {
        return argument[0] + 4000;
    }
}

if (argument[0] >= 1000)
{
    if ((floor(argument[0]/1000) == 1) && !(darknessBaseN || darknessSpreadN))
    {
        return (argument[0] mod 1000) + 4000000;
    }

    if ((floor(argument[0]/1000) == 2) && !(darknessBaseW || darknessSpreadW))
    {
        return (argument[0] mod 1000) + 4000000;
    }

    if ((floor(argument[0]/1000) == 3) && !(darknessBaseE || darknessSpreadE))
    {
        return (argument[0] mod 1000) + 4000000;
    }

    if ((floor(argument[0]/1000) == 4) && !(darknessBaseS || darknessSpreadS))
    {
        return (argument[0] mod 1000) + 4000000;
    }
}

var shadowCounter;
shadowCounter = argument[0] - (argument[0] mod 1000000);
argument[0] = argument[0] mod 1000000;

if (argument[0] == 1)
{
    var returnValue;
    var waterSource;

    waterSource = (water || wetSand);

    if (waterSource && !lava && !poison)
    {
        return 2 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (!waterSource && lava && !poison)
    {
        return 3 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (poison && !lava)
    {
        return 7 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (lava && (waterSource || poison))
    {
        return 4 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (!waterSource && !lava && !poison)
    {
        return 1 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 2)
{
    if (lava)
    {
        return 4 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (grass || tree)
    {
        return 6 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (poison)
    {
        return 7 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 3)
{
    if (water || poison)
    {
        return 4 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 5)
{
    if (lava)
    {
        return 2 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 6)
{
    if (lava || poison)
    {
        return 4 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 7)
{
    if (lava)
    {
        return 4 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 8)
{
    if (lava)
    {
        return 10 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if ((water || poison) && !lava)
    {
        return 9 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 9)
{
    if (!water && !poison && !lava)
    {
        return 8 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (lava)
    {
        return 10 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 11)
{
    if (lava)
    {
        return 4 + (shadowCounter-1000000)*(shadowCounter > 0);
    }

    if (poison)
    {
        return 12 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 20)
{
    if (lava)
    {
        return 21 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

if (argument[0] == 21)
{
    if (water || poison || ice)
    {
        return 20 + (shadowCounter-1000000)*(shadowCounter > 0);
    }
}

return argument[0] + (shadowCounter-1000000)*(shadowCounter > 0);
}
