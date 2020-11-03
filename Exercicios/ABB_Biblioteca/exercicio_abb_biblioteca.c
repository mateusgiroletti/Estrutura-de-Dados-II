#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sElemento{
    struct sElemento* esquerda;
    struct sElemento* direita;
    int dado;
} Elemento;

Elemento* inserir(Elemento*, int);
int deletar(Elemento*, int);
Elemento* procurar(Elemento*, int);
void imprimirEmOrdem(Elemento*);

Elemento* inserir(Elemento* elemento, int dado){
    if(elemento == NULL){
        elemento = (Elemento*) malloc(sizeof(Elemento));
        elemento->dado = dado;
        elemento->direita = NULL;
        elemento->esquerda = NULL;
    }else if(dado < elemento->dado){
        elemento->esquerda = inserir(elemento->esquerda, dado);
    }else if(dado > elemento->dado){
        elemento->direita = inserir(elemento->direita, dado);
    }

    return elemento;
}

void imprimirEmOrdem(Elemento *elemento){
	if(elemento!=NULL){
		imprimirEmOrdem(elemento->esquerda);
		printf("%i \n",elemento->dado);
		imprimirEmOrdem(elemento->direita);
	}
}

int main(){

    Elemento* arvore = NULL;
    arvore = inserir(arvore, 10);
    arvore = inserir(arvore, 5);
    arvore = inserir(arvore, 1);
    arvore = inserir(arvore, 2);

    imprimirEmOrdem(arvore);


    
}