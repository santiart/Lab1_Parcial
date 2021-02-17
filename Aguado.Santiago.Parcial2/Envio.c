#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Envio.h"

eEnvio* envio_new()
{
    eEnvio* envio = (eEnvio*)malloc(sizeof(eEnvio));
    if(envio != NULL)
    {
        envio->id_envio = 0;
        strcpy(envio->nombre_producto, "");
        envio->km_recorridos = 0;
        strcpy(envio->tipo_entrega, "");
        envio->costo_envio = 0;
    }
    return envio;
}

int envio_setId(eEnvio* this, int id)
{
    int setted = 0;

    if(this != NULL){
        this->id_envio = id;
        setted = 1;
    }

    return setted;
}

int envio_getId(eEnvio* this,int* id)
{
    int getted = 0;

    if(this != NULL && id != NULL){
        *id = this->id_envio;
        getted = 1;
    }

    return getted;
}

int envio_setNombre(eEnvio* this, char* nombre)
{
    int setted = 0;

    if(this != NULL&&nombre!=NULL){
        strcpy(this->nombre_producto, nombre);
        setted = 1;
    }

    return setted;
}

int envio_getNombre(eEnvio* this, char* nombre)
{
    int getted = 0;

    if(this != NULL && nombre != NULL){
        strcpy(nombre,this->nombre_producto);
        getted = 1;
    }

    return getted;
}

int envio_setKm(eEnvio* this, int km)
{
     int setted = 0;

    if(this != NULL){
        this->km_recorridos = km;
        setted = 1;
    }

    return setted;
}

int envio_getKm(eEnvio* this, int* km)
{
    int getted = 0;

    if(this != NULL && km != NULL){
        *km = this->km_recorridos;
        getted = 1;
    }

    return getted;
}

int envio_setEntrega(eEnvio* this, char* entrega)
{
    int setted = 0;

    if(this != NULL&&entrega!=NULL){
        strcpy(this->tipo_entrega, entrega);
        setted = 1;
    }

    return setted;
}

int envio_getEntrega(eEnvio* this, char* entrega)
{
    int getted = 0;

    if(this != NULL && entrega != NULL){
        strcpy(entrega,this->tipo_entrega);
        getted = 1;
    }

    return getted;
}

int envio_setCosto(eEnvio* this, int costo)
{
     int setted = 0;

    if(this != NULL){
        this->costo_envio = costo;
        setted = 1;
    }

    return setted;
}
int envio_getCosto(eEnvio* this, int* costo)
{
    int getted = 0;

    if(this != NULL && costo != NULL){
        *costo= this->costo_envio;
        getted = 1;
    }

    return getted;
}

eEnvio* envio_newParametros(char* idStr, char* nombre, char* kmStr, char* entrega)
{
    eEnvio* envio = envio_new();
    int retorno = 0;

    if(envio != NULL)
    {
        if(envio_setId(envio, atoi(idStr)))
        {
            if(envio_setNombre(envio, nombre))
            {
                if(envio_setKm(envio, atoi(kmStr)))
                {
                    if(envio_setEntrega(envio, entrega))
                    {
                        retorno = 1;
                    }
                }
            }
        }
    }

    if(retorno == 0)
    {
        free(envio);
        envio = NULL;
    }
    return envio;
}

int envio_mapearCostos(void* pElement)
{
    eEnvio* envio;
    int auxKM;
    char auxEntrega[50];
    int costo;
    if(pElement != NULL)
    {
        envio = (eEnvio*)pElement;
        envio_getKm(envio, &auxKM);

        if(auxKM <= 45)
        {
            costo = 77 * auxKM;
        }
        else
        {
            costo = 90 * auxKM;
        }

        envio_getEntrega(envio,auxEntrega);

        if(auxEntrega == "normal")
        {
            costo += 350;
        }
        else if(auxEntrega == "express")
        {
            costo += 580;
        }
        else if(auxEntrega == "segun disponibilidad")
        {
            costo += 90;
        }

        envio_setCosto(envio,costo);

    }
    return 0;
}
