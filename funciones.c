#include "pilaDinamica.h"

void crearPila(t_pila *pila)
{
    *pila = NULL;
}

int pilaLlena(const t_pila *pila,unsigned tam)
{
    t_nodo *aux = (t_nodo*)malloc(sizeof(t_nodo));
    void *info = malloc(tam);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}
int ponerEnPila(t_pila *pila,const void *d,unsigned tam)
{
    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
    nue->info = malloc(tam);
    if(*nue == NULL || *(nue->info) == NULL)
    {
        free(nue->info);
        return 0;
    }
    memcpy(nue->info,d,tam);
    nue->tamInfo = tam;
    nue->sig = *pila;
    *pila = nue;///tiene que apuntar al primero
    return 1;
}
int sacarDePila(t_pila *pila,void *d,unsigned tam)
{
    t_nodo *aux = *pila;
    if(*aux == NULL)
        return 0;
    *pila = aux->sig;
    memcpy(d,aux->info,minimo(tam,aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}
int pilaVacia(const t_pila *pila)
{
    return *pila == NULL;
}
int verTope(const t_pila *pila,void *d,unsigned tam)
{
    if(*pila == NULL)
        return -1;
    memcpy(d,(*pila)->info,minimo(tam,(*pila)->tamInfo));
    return 1;
}
void vaciarPila(t_pila *pila)
{
    while(*pila)
    {
        t_nodo *aux = *pila;
        *pila = aux->sig;
        free(aux->info);
        free(aux);
    }
}
