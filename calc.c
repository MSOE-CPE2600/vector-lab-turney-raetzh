/****************************
* Name: calc.c
* Desc: calculator for vectors
* Auth: Holly Raetz
* Date: Sept 30, 2025
****************************/

#include "vector.h"

vector add(vector a, vector b)
{
    vector c;
    c.x = a->x + b->x;
    c.y = a->y + b->y;
    c.z = a->z + b->z;

    return c;
}

vector subtract(vector a, vector b)
{
    vector c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    c.z = a->z - b->z;

    return c;
}

