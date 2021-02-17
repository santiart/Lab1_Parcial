#ifndef ENVIO_H_INCLUDED
#define ENVIO_H_INCLUDED

typedef struct
{
    int id_envio;
    char nombre_producto[50];
    int km_recorridos;
    char tipo_entrega[50];
    int costo_envio;
}eEnvio;

eEnvio* envio_new();
int envio_setId(eEnvio* this, int id);
int envio_getId(eEnvio* this,int* id);
int envio_setNombre(eEnvio* this, char* nombre);
int envio_getNombre(eEnvio* this, char* nombre);
int envio_setKm(eEnvio* this, int km);
int envio_getKm(eEnvio* this, int* km);
int envio_setEntrega(eEnvio* this, char* entrega);
int envio_getEntrega(eEnvio* this, char* entrega);
int envio_setCosto(eEnvio* this, int costo);
int envio_getCosto(eEnvio* this, int* costo);
eEnvio* envio_newParametros(char* idStr, char* nombre, char* kmStr, char* entrega);
int envio_mapearCostos(void* pElement);
#endif // ENVIO_H_INCLUDED
