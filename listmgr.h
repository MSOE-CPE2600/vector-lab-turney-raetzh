/****************************
* Name: listmgr.h
* Desc: manager of vector array
* Auth: Holly Raetz
* Date: Sept 30, 2025
****************************/

#include "llist.h"

void assign(list *vectors, char n, char *nx, char *ny, char *nz);

void addres(list *vectors, char vecta, char vectb, char edit);
void dotres(list *vectors, char vecta, char vectb);
void subtractres(list *vectors, char vecta, char vectb, char edit);
void multres(list *vectors, float scalar, char vectb, char edit);
void crossres(list *vectors, char vecta, char vectb, char edit);