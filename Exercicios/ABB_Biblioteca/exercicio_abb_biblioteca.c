#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sNodo{
    struct sNodo* esqueda;
    struct sNodo* direita;
    int dado;
} Nodo;

void inserir(Nodo*, int);
int deletar(Nodo*, int);
Nodo* procurar(Nodo*, int);


int main(){

    
}