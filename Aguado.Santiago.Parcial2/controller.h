#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"

int controller_listExist(LinkedList* lista);
int controller_loadFromText(char* path,LinkedList* lista);
int controller_ListEnvios(LinkedList* lista);
int controller_saveAsText(char* path, LinkedList* lista);
int controller_map(LinkedList* pArrayListeDominio);
int controller_ListCostos(LinkedList* lista);

#endif // CONTROLLER_H_INCLUDED
