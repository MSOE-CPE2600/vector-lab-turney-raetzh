/****************************
* Name: calc.c
* Desc: calculator for vectors
* Auth: Holly Raetz
* Date: Sept 30, 2025
****************************/

#include "vector.h"

vector add(vector *a, vector *b)
{
    vector c;
    c.x = a->x + b->x;
    c.y = a->y + b->y;
    c.z = a->z + b->z;

    return c;
}

vector subtract(vector *a, vector *b)
{
    vector c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    c.z = a->z - b->z;

    return c;
}
vector multiply(float a, vector *b)
{
    vector c;
    c.x = a * b->x;
    c.y = a * b->y;
    c.z = a * b->z;

    return c;
}
float dot(vector *a, vector *b)
{
    float c;

    c = a->x * b->x + a->y * b->y + a->z * b->z;

    return c;
}
vector cross(vector *a, vector *b)
{
    vector c;
    c.x = a->y * b->z - a->z * b->y;
    c.y = a->z * b->x - a->x * b->z;
    c.z = a->x * b->y - a->y * b->x;

    return c;
}

