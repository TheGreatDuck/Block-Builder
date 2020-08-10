#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"

GMEXPORT double scr_changeBlock()
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

argument[1] = argument[1] mod 1000000;
argument[2] = argument[2] mod 1000000;
argument[3] = argument[3] mod 1000000;
argument[4] = argument[4] mod 1000000;

channel = (argument[1] == 1) || (argument[2] == 1) || (argument[3] == 1) || (argument[4] == 1);
water = (argument[1] == 2) || (argument[2] == 2) || (argument[3] == 2) || (argument[4] == 2);
lava = (argument[1] == 3) || (argument[2] == 3) || (argument[3] == 3) || (argument[4] == 3);
dirt = (argument[1] == 4) || (argument[2] == 4) || (argument[3] == 4) || (argument[4] == 4);
ice = (argument[1] == 5) || (argument[2] == 5) || (argument[3] == 5) || (argument[4] == 5);
grass = (argument[1] == 6) || (argument[2] == 6) || (argument[3] == 6) || (argument[4] == 6);
poison = (argument[1] == 7) || (argument[2] == 7) || (argument[3] == 7) || (argument[4] == 7);
sand = (argument[1] == 8) || (argument[2] == 8) || (argument[3] == 8) || (argument[4] == 8);
wetSand = (argument[1] == 9) || (argument[2] == 9) || (argument[3] == 9) || (argument[4] == 9);
glass = (argument[1] == 10) || (argument[2] == 10) || (argument[3] == 10) || (argument[4] == 10);
tree = (argument[1] == 11) || (argument[2] == 11) || (argument[3] == 11) || (argument[4] == 11);
petrifiedTree = (argument[1] == 12) || (argument[2] == 12) || (argument[3] == 12) || (argument[4] == 12);
waterEyeSwitch = (argument[1] == 13) || (argument[2] == 13) || (argument[3] == 13) || (argument[4] == 13);
lavaEyeSwitch = (argument[1] == 14) || (argument[2] == 14) || (argument[3] == 14) || (argument[4] == 14);
poisonEyeSwitch = (argument[1] == 15) || (argument[2] == 15) || (argument[3] == 15) || (argument[4] == 15);



pushable = (argument[1] == 19) || (argument[2] == 19) || (argument[3] == 19) || (argument[4] == 19);
metal = (argument[1] == 20) || (argument[2] == 20) || (argument[3] == 20) || (argument[4] == 20);
hotMetal = (argument[1] == 21) || (argument[2] == 21) || (argument[3] == 21) || (argument[4] == 21);
hole = (argument[1] == 22) || (argument[2] == 22) || (argument[3] == 22) || (argument[4] == 22);
underworldFlame = (argument[1] == 23) || (argument[2] == 23) || (argument[3] == 23) || (argument[4] == 23);
bomb = (argument[1] == 24) || (argument[2] == 24) || (argument[3] == 24) || (argument[4] == 24);
explosion = (argument[1] == 25) || (argument[2] == 25) || (argument[3] == 25) || (argument[4] == 25);
electricalSource = (argument[1] == 26) || (argument[2] == 26) || (argument[3] == 26) || (argument[4] == 26);
pitdoorOpen = (argument[1] == 27) || (argument[2] == 27) || (argument[3] == 27) || (argument[4] == 27);
pitdoorShut = (argument[1] == 28) || (argument[2] == 28) || (argument[3] == 28) || (argument[4] == 28);
wood = (argument[1] == 29) || (argument[2] == 29) || (argument[3] == 29) || (argument[4] == 29);
burningWood = (argument[1] == 30) || (argument[2] == 30) || (argument[3] == 30) || (argument[4] == 30);
sandstone = (argument[1] == 31) || (argument[2] == 31) || (argument[3] == 31) || (argument[4] == 31);
stoneBrick = (argument[1] == 32) || (argument[2] == 32) || (argument[3] == 32) || (argument[4] == 32);
prism = (argument[1] == 33) || (argument[2] == 33) || (argument[3] == 33) || (argument[4] == 33);

//if we try to have multiple directions power a
//shadow at once then we can get infinite propogation
darknessBaseN = (argument[1] == 34);
darknessBaseW = (argument[2] == 34);
darknessBaseE = (argument[3] == 34);
darknessBaseS = (argument[4] == 34);
darknessSpreadN = (floor(argument[1]/1000) != 4)*(floor(argument[1]/1000) != 0)*(floor(argument[1]/1000000) == 0);
darknessSpreadW = (floor(argument[2]/1000) != 3)*(floor(argument[2]/1000) != 0)*(floor(argument[2]/1000000) == 0);
darknessSpreadE = (floor(argument[3]/1000) != 2)*(floor(argument[3]/1000) != 0)*(floor(argument[3]/1000000) == 0);
darknessSpreadS = (floor(argument[4]/1000) != 1)*(floor(argument[4]/1000) != 0)*(floor(argument[4]/1000000) == 0);

light = (argument[1] == 35) || (argument[2] == 35) || (argument[3] == 35) || (argument[4] == 35);



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
