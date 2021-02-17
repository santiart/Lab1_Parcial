#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Envio.h"
#include "input.h"

int parser_fromText(FILE* pFile,LinkedList* lista)
{
    char buffer[4][40];
    int retorno=0;
    eEnvio* envio=envio_new();
    int cant;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    while(!feof(pFile))
        {
        cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant==4)
            {
            envio=envio_newParametros(buffer[0],buffer[1],buffer[2], buffer[3]);
            ll_add(lista,envio);
            retorno=1;
            }else
                {
                retorno=-1;
                }
        }
    return retorno;
}
