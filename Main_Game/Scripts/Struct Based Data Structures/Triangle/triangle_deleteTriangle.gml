if (triangle_getPointOne(argument[0]) != -1)
{
    mm_free(triangle_getPointOne(argument[0]));
}

if (triangle_getPointTwo(argument[0]) != -1)
{
    mm_free(triangle_getPointTwo(argument[0]));
}

if (triangle_getPointThree(argument[0]) != -1)
{
    mm_free(triangle_getPointThree(argument[0]));
}

mm_free(argument[0]);
