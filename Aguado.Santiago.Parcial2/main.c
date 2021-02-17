#include <stdio.h>
#include <stdlib.h>
#include "Envio.h"
#include "controller.h"
#include "input.h"

int main()
{
    int opcion;
    char path[22];
    LinkedList* listaEnvios = ll_newLinkedList();
         do
    {
        menu();
        opcion=getInt("\nPor favor ingrese una opcion <1-4> :");

        switch(opcion)
        {
        case 1:

            getString("\nIngrese el nombre del archivo a cargar, sin olvidarse de poner al final '.csv'\n:",path);

            if(controller_loadFromText(path,listaEnvios))
            {
                printf("\n archivo cargado correctamente (modo texto)\n\n");
            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }

            break;


        case 2:
            if(controller_listExist(listaEnvios))
            {
                if(controller_map(listaEnvios)==1)
                {
                }
                controller_ListEnvios(listaEnvios);
            }
            break;

        case 3:
            if(controller_listExist(listaEnvios)==1)
            {
                if(controller_map(listaEnvios)==1)
                {
                    printf("\n elementos mapeados correctamente\n\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudieron mapear a los elementos\n\n");
                }

                if(controller_saveAsText("EnviosMapeados.csv",listaEnvios))
                {
                    printf("\nArchivo EnviosMapeados.csv guardado\n");
                    controller_ListCostos(listaEnvios);
                }
                else
                {
                    printf("\n\nERROR...No se pudo guardar el archivo\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de guardar\n");
            }

            break;
        case 4:
            printf("\n\nSALIENDO DEL PROGRAMA\n\n");
            break;

        default:
            printf("\n\nERROR...Ingrese una opcion correcta <1-5>\n\n");
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion != 4);

    ll_deleteLinkedList(listaEnvios);

}
