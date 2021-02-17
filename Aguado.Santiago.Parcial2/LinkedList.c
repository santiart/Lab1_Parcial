#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Envio.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i=0;
    Node* pNode=NULL;
    if(this!=NULL && nodeIndex<ll_len(this) && nodeIndex>=0){
        pNode=this->pFirstNode;
        for(i=0;i<nodeIndex;i++)
            pNode=pNode->pNextNode;
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex){
    return getNode(this,nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* aux=NULL;
    Node* newNode;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this)){
       newNode=(Node*)malloc(sizeof(Node));//creamos el nuevo nodo
       newNode->pNextNode=NULL;//seteamos el valor por default
       newNode->pElement=pElement;//seteamos el pElement que nos pasaron como parametro al nodo creado dinamicamente
       if(nodeIndex==0 && ll_len(this)==0)//si el LinkedList no tiene ningún nodo, enganchamos el nodo creado dinamicamente a la locomotora
            this->pFirstNode=newNode;
       else if(nodeIndex==0){//si el linkedlist tiene nodos pero quiero agregar otro en la posición 0, enganchamos el nodo creado dinamicamente a la locomotora y al nuevo nodo le enganchamos los demas vagones(el vagon cero pasa a ser el vagon 1)
            aux=getNode(this,0);
            newNode->pNextNode=aux;
            this->pFirstNode=newNode;
       }
       else if(nodeIndex>0 && ll_len(this)>0){//agregar un nodo en cualquier posicion del tren, por ejemplo si pasamos como parametro el index 4, conectamos el nuevo nodo al vagon 3, y el que era vagon 4 pasa a ser vagon 5 y se conecta al nuevo nodo
            aux=getNode(this,nodeIndex-1);
            newNode->pNextNode=aux->pNextNode;
            aux->pNextNode=newNode;
       }
       this->size++;
       returnAux=0;
    }
    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
        return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL){
        addNode(this,ll_len(this),pElement);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        pNode=getNode(this, index);
        returnAux=pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux=-1;
    Node* pNode;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        if((pNode=getNode(this, index))!=NULL){
            pNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* pAux;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        if((pNode=getNode(this, index))!=NULL){
            if(index==0){
                this->pFirstNode=pNode->pNextNode;
            }
            else if(index>0){
                pAux=getNode(this, index-1);
                pAux->pNextNode=pNode->pNextNode;
            }
            this->size--;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1, i;
    if(this!=NULL){
        this->pFirstNode=NULL;
        for(i=0;i<ll_len(this);i++){
            ll_remove(this,i);
            this->size--;
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement){
    int i;
    Node* pNode;
    int returnAux = -1;
    if(this!=NULL){
        for(i=0; i<ll_len(this); i++){
            pNode=getNode(this,i);
            if(pNode->pElement==pElement){
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        if(ll_len(this)>0)
            returnAux=0;
        else
            returnAux=1;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int push;

    if(this != NULL){
        if(index >= 0 && index <=ll_len(this)){
            push = addNode(this, index, pElement);
            if(!push)
                returnAux =0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        pNode=getNode(this, index);
        ll_remove(this,index);
        returnAux=pNode->pElement;
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1, i;
    Node* pNode;
    if(this!=NULL){
        returnAux=0;
        for(i=0; i<ll_len(this); i++){
            pNode=getNode(this,i);
            if(pNode->pElement==pElement){
                returnAux=1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1, i;
    Node* pNodeThis2;
    if(this!=NULL && this2!=NULL){
        returnAux=1;
        for(i=0; i<ll_len(this); i++){
            pNodeThis2=getNode(this2,i);
            if(ll_contains(this,pNodeThis2->pElement)==0){
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL && (from>=0 && from<ll_len(this)) && (to>=from && to<=ll_len(this))){
        cloneArray=ll_newLinkedList();
        for(;from<to;from++)
            ll_add(cloneArray, ll_get(this,from));
    }
    return cloneArray;
 }



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL){
        cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
/*
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux=-1;
    int i;
    int j;
    void* aux;
    void* auxB;
    void* auxA;

    if(this!=NULL&&pFunc!=NULL)
    {
    for(i=0;i<ll_len(this)-1;i++)
        {
        for(j=i+1;j<ll_len(this);j++)
            {
            auxA=ll_get(this,i);
            auxB=ll_get(this,j);
            if((pFunc(auxA,auxB)<0 && order==0)||(pFunc(auxA,auxB)>0&&order==1))
                {
                aux=auxA;
                ll_set(this,i,auxB);
                ll_set(this,j,aux);
                returnAux=0;
                }
            }
        }
    }
return returnAux;
}*/
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    int i;
    int j;

    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i=0; i< (ll_len(this)-1) ; i++)
        {
            for(j= i+1; j < ll_len(this); j++)
            {
                if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
            }
        }

        returnAux = 0;
    }

    return returnAux;
}


/** \brief
 *
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio que devuelve un 1 si se debe guardar en la nueva lista
 * \return int ll_map(LinkedList* this, int
 *
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno=0;
    int i;
    int len;
    len=ll_len(this);
    if(this!=NULL && pFunc!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(pFunc(ll_get(this,i)))
            {

              retorno=1;

            }
        }
    }
    return retorno;
}



/** \brief Filtra los elementos de una LinkedList y guarda en una nueva los que cumplen con el criterio indicado
 *
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio que devuelve un 1 si se debe guardar en la nueva lista
 * \return LinkedList* ll_filter(LinkedList* this,
 *
 */
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{

    LinkedList* listaF = NULL;
    int i;

    if(this != NULL && ll_len(this) > 0 && pFunc != NULL)
    {
        listaF = ll_newLinkedList();

        for(i=0; i<ll_len(this); i++)
        {

            if((*pFunc)(ll_get(this,i)) ==1)
            {
                ll_add(listaF, ll_get(this,i));
            }
        }
    }
    return listaF;
}
