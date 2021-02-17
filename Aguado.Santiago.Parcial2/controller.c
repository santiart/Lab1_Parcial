#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Envio.h"
#include "input.h"
#include "controller.h"

int controller_listExist(LinkedList* lista)
{
    int existe = -1;

    if(ll_len(lista)>0)
    {
        existe = 1;
    }

    return existe;
}

int controller_loadFromText(char* path,LinkedList* lista)
{

    int retorno=-1;
    FILE* pFile = fopen(path,"r");

    if(pFile!=NULL&& lista !=NULL)
    {
        if(parser_fromText(pFile,lista))
        {

            retorno=1;

        }

        else
        {
            retorno =-1;
        }

    }

    else
    {
        retorno =-1;
    }

    return retorno;
}

int controller_ListEnvios(LinkedList* lista)
{
    eEnvio* envio = envio_new();
    int idAuxiliar;
    char NombreAuxiliar[50];
    int kmAuxiliar;
    char entregaAuxiliar[50];
    int retorno=-1;
    int i;

    if(envio!=NULL && lista!=NULL)
    {
        system("cls");
        puts(" [ID]\t[NOMBRE]\t[KM RECORRIDOS]\t[TIPO ENTREGA]\n\n");

        for(i=0; i < ll_len(lista); i++)
        {
            envio = ll_get(lista, i);

            envio_getId(envio, &idAuxiliar);
            envio_getNombre(envio,NombreAuxiliar);
            envio_getKm(envio,&kmAuxiliar);
            envio_getEntrega(envio,entregaAuxiliar);

            printf("%5d  %10s %10d  %5s\n",idAuxiliar, NombreAuxiliar, kmAuxiliar, entregaAuxiliar);

        }

        retorno=1;
    }


    else
    {
        retorno=-1;
    }

    printf("\n\n");

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* lista)
{
    int retorno=-1;
    int len;
    int idAuxiliar;
    char NombreAuxiliar[50];
    int kmAuxiliar;
    char entregaAuxiliar[50];
    int costoAuxiliar;
    int i;
    FILE* pFile = fopen(path,"w+");
    eEnvio* envio=envio_new();

    if(pFile != NULL && lista != NULL && envio!=NULL )
    {
        len=ll_len(lista);
        fprintf(pFile, "id,Nombre Producto,km Recorridos,tipo Entrega, costo de envio\n");

        for(i=0; i<len; i++)
        {
            envio= ll_get(lista,i);

            envio_getId(envio, &idAuxiliar);
            envio_getNombre(envio,NombreAuxiliar);
            envio_getKm(envio,&kmAuxiliar);
            envio_getEntrega(envio,entregaAuxiliar);
            if(strcmp(entregaAuxiliar,"1")==0)
            {
                envio_setEntrega(envio, "normal");
            }
            else if(strcmp(entregaAuxiliar,"2")==0)
            {
                envio_setEntrega(envio,"express");
            }
            else if(strcmp(entregaAuxiliar,"3")==0)
            {
                envio_setEntrega(envio, "segun disponibilidad");
            }
            envio_getCosto(envio,&costoAuxiliar);

            fprintf(pFile,"%d,%s,%d,%s,%d\n",idAuxiliar, NombreAuxiliar, kmAuxiliar, entregaAuxiliar,costoAuxiliar);

        }

        retorno = 1;

    }
    else
    {
        retorno=-1;
    }

    fclose(pFile);

    return retorno;
}

int controller_map(LinkedList* lista)
{
    int retorno=1;

    if(lista!=NULL)
    {

        if(ll_map(lista,envio_mapearCostos))
        {
        retorno=1;

        }
        else
        {
            retorno=-1;
        }

    }
    else
    {
        retorno=-1;
    }

    return retorno;
}

int controller_ListCostos(LinkedList* lista)
{
    eEnvio* envio = envio_new();
    int idAuxiliar;
    char NombreAuxiliar[50];
    int kmAuxiliar;
    char entregaAuxiliar[50];
    int auxCostos;
    int retorno=-1;
    int i;

    if(envio!=NULL && lista!=NULL)
    {
        system("cls");
        puts(" [ID]\t[NOMBRE]\t[KM RECORRIDOS]\t[TIPO ENTREGA]\t[COSTOS DE ENTREGA]\n\n");

        for(i=0; i < ll_len(lista); i++)
        {
            envio = ll_get(lista, i);

            envio_getId(envio, &idAuxiliar);
            envio_getNombre(envio,NombreAuxiliar);
            envio_getKm(envio,&kmAuxiliar);
            envio_getEntrega(envio,entregaAuxiliar);
            if(strcmp(entregaAuxiliar,"1")==0)
            {
                envio_setEntrega(envio, "normal");
            }
            else if(strcmp(entregaAuxiliar,"2")==0)
            {
                envio_setEntrega(envio,"express");
            }
            else if(strcmp(entregaAuxiliar,"3")==0)
            {
                envio_setEntrega(envio, "segun disponibilidad");
            }
            envio_getCosto(envio,&auxCostos);

            printf("%5d  %10s %10d  %5s %5d\n",idAuxiliar, NombreAuxiliar, kmAuxiliar, entregaAuxiliar,auxCostos);

        }

        retorno=1;
    }

    else
    {
        retorno=-1;
    }

    printf("\n\n");

    return retorno;
}
