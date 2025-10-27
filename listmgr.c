/****************************
* Name: listmgr.c
* Desc: manager of vector array
* Auth: Holly Raetz
* Date: Sept 30, 2025
****************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"
#include "calc.h"
#include "llist.h"

void assign(list *vectors, char n, char *nx, char *ny, char *nz)
{
    float fx = atof(nx);
    float fy = atof(ny);
    float fz = atof(nz);
    vector v = {n, fx, fy, fz};
    ll_update_make(vectors, n, &v);
}

void addres(list *vectors, char vecta, char vectb, char edit)
{
    vector *a = ll_get(vectors, vecta);
    vector *b = ll_get(vectors, vectb);
    vector result = add(a, b);
    printf("Result: %3.3f %3.3f %3.3f\n", result.x, result.y, result.z);
    if(edit != ' ')
    {
        ll_update_make(vectors, edit, &result);
    }
}
void subtractres(list *vectors, char vecta, char vectb, char edit)
{
    vector *a = ll_get(vectors, vecta);
    vector *b = ll_get(vectors, vectb);
    vector result = subtract(a, b);
    printf("Result: %3.3f %3.3f %3.3f\n", result.x, result.y, result.z);
    if(edit != ' ')
    {
        ll_update_make(vectors, edit, &result);
    }
}
void multres(list *vectors, float scalar, char vectb, char edit)
{
    vector *b = ll_get(vectors, vectb);
    vector result = multiply(scalar, b);
    printf("Result: %3.3f %3.3f %3.3f\n", result.x, result.y, result.z);
    if(edit != ' ')
    {
        ll_update_make(vectors, edit, &result);
    }
}
void dotres(list *vectors, char vecta, char vectb)
{
    vector *a = ll_get(vectors, vecta);
    vector *b = ll_get(vectors, vectb);
    float result = dot(a, b);
    printf("Result: %f\n", result);
}
void crossres(list *vectors, char vecta, char vectb, char edit)
{
    vector *a = ll_get(vectors, vecta);
    vector *b = ll_get(vectors, vectb);
    vector result = cross(a, b);
    printf("Result: %3.3f %3.3f %3.3f\n", result.x, result.y, result.z);
    if(edit != ' ')
    {
        ll_update_make(vectors, edit, &result);
    }
}
