#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo((x),(y))  ((x)<(y)?(x):(y))
typedef struct s_nodo{
    void *info;
    unsigned tamInfo;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_pila;

///primitivas de pila dinamica
void crearPila(t_pila *pila);
int pilaLlena(const t_pila *pila,unsigned tam);
int ponerEnPila(t_pila *pila,const void *d,unsigned tam);
int sacarDePila(t_pila *pila,void *d,unsigned tam);
int pilaVacia(const t_pila *pila);
int verTope(const t_pila *pila,void *d,unsigned tam);
void vaciarPila(t_pila *pila);

#endif // PILADINAMICA_H_INCLUDED
