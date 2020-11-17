#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sElemento{
    struct sElemento* esquerda;
    struct sElemento* direita;
    int dado;
} Elemento;

Elemento* inserirElemento(Elemento*, int);
Elemento* buscaElemento(Elemento*, int);
Elemento* menorElemento(Elemento*);
Elemento* removeElemento(Elemento*, int);
void imprimirPreOrdem(Elemento*);
void imprimirEmOrdem(Elemento*);
void imprimirPosOrdem(Elemento*);

Elemento* inserirElemento(Elemento* elemento, int dado){
    if(elemento == NULL){
        elemento = (Elemento*) malloc(sizeof(Elemento));
        elemento->dado = dado;
        elemento->direita = NULL;
        elemento->esquerda = NULL;
    }else if(dado < elemento->dado){
        elemento->esquerda = inserirElemento(elemento->esquerda, dado);
    }else if(dado > elemento->dado){
        elemento->direita = inserirElemento(elemento->direita, dado);
    }
    return elemento;
}

Elemento* buscaElemento(Elemento* elemento, int dado){
    if(elemento != NULL){
        if(elemento->dado == dado) {
            return elemento;
        }else{
            if(dado > elemento->dado){
                return buscaElemento(elemento->direita, dado);
            }else{
                return buscaElemento(elemento->esquerda, dado);
            }
        }
    }
    return NULL;
}

Elemento* menorElemento(Elemento* elemento){
    if(elemento != NULL){
        Elemento* aux = elemento;
        while(aux->esquerda != NULL){
            aux = aux->esquerda;
        }
        return aux;
    }
    return NULL;
}

Elemento* removeElemento(Elemento* elemento, int dado){
    if(elemento != NULL){
        //faz a busca pelo elemento na arvore
        if(dado > elemento->dado){
            elemento->direita = removeElemento(elemento->direita, dado);
        }else if(dado < elemento->dado){
            elemento->esquerda = removeElemento(elemento->esquerda, dado);
        }else{ // Encontrou o elemento
            // Se o elemento não tiver filho 
            if(elemento->esquerda == NULL && elemento->direita == NULL){
                free(elemento);
                return NULL;
            }
            // Se tiver filho a direita
            else if(elemento->esquerda == NULL && elemento->direita != NULL){
                Elemento* aux = elemento->direita;
                free(elemento);
                return aux;
            }
            // Se tiver filho a esquerda
            else if(elemento->esquerda != NULL && elemento->direita == NULL){
                Elemento* aux = elemento->esquerda;
                free(elemento);
                return aux;
            }else{
                //Remove pela direita buscando o menor elemento a esquerda
                Elemento *aux = menorElemento(elemento->direita);
                int dadoAux = aux->dado;
                elemento = removeElemento(elemento, dadoAux);
                elemento->dado = dadoAux;
                return elemento;
            }
        }
        return elemento;
    } 
    return NULL;
}

void imprimirPreOrdem(Elemento *raiz){
	if(raiz!=NULL){
		printf("%i ",raiz->dado);
		imprimirPreOrdem(raiz->esquerda);
		imprimirPreOrdem(raiz->direita);
	}
}

void imprimirEmOrdem(Elemento *raiz){
	if(raiz!=NULL){
		imprimirEmOrdem(raiz->esquerda);
		printf("%i ",raiz->dado);
		imprimirEmOrdem(raiz->direita);
	}
}

void imprimirPosOrdem(Elemento *raiz){
	if(raiz!=NULL){
		imprimirPosOrdem(raiz->esquerda);		
		imprimirPosOrdem(raiz->direita);
		printf("%i ",raiz->dado);
	}
}

int main(){
    int op;
    
    Elemento* arvore = NULL;

    do{ 
        printf("\n----MENU----\n");
        printf("1 - Inserir\n");
        printf("2 - Excluir\n");
        printf("3 - Listar em Ordem\n");
        printf("4 - Listar em Pre-Ordem\n");
        printf("5 - Listar em Pos-Ordem\n");
        printf("6 - Buscar Elemento\n");
        printf("7 - Sair\n");
        printf("\nDigite uma das opções: ");
        scanf("%d",&op);
        if(op == 7){
            break;
        }else if(op == 1){
            int tamanho;

            printf("Digite o tamanho da arvore: ");
            scanf("%d", &tamanho);

            for (int i = 0; i < tamanho; i++){
                int dado;
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &dado);
                arvore = inserirElemento(arvore, dado);
            }
        }else if(op == 2){
            int elementoRemover;
            printf("Digite o elemento que deseja remover: ");
            scanf("%d", &elementoRemover);

            Elemento* elemento = buscaElemento(arvore, elementoRemover);
            
            if(elemento != NULL){
                printf("O elemento %d esta sendo removido!\n", elementoRemover);
                arvore = removeElemento(arvore, elementoRemover);
            }else{
               printf("Elemento não encontrado\n");
            }

        }else if(op == 3){
           imprimirEmOrdem(arvore);
            
        }else if(op == 4){
           imprimirPreOrdem(arvore);
            
        }else if(op == 5){
           imprimirPosOrdem(arvore);

        }else if(op == 6){
            int elementoProcurar;
            printf("Digite o elemento que deseja procurar: ");
            scanf("%d", &elementoProcurar);

            Elemento* elemento = buscaElemento(arvore, elementoProcurar);
            
            if(elemento != NULL){
                printf("O elemento %d foi encontrado!\n", elementoProcurar);
            }else{
               printf("Elemento  %d não foi encontrado\n", elementoProcurar);
            }
        }else{
            printf("Opção invalida!\n");
        }

    }while(op != 7);

  
}