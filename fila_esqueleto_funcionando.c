#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int valor;
    struct no *proximo;
};

typedef struct fila Fila;

struct fila{
    struct no *ini;
    struct no *fim;
    int tam;
};

void inicializar_fila(Fila *fila);

void inserir_no_fim(Fila *fila, int num);

No* remover_no_inicio(Fila *fila);

void imprimir_fila(Fila *fila);

int main(){
    Fila *fila=(Fila*)malloc(sizeof(Fila));
    int n=0,num=0;
    No *removido=NULL;
    inicializar_fila(fila);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir no final da Fila\n\t2 - Remover no inicio da Fila\n\t3 - Imprimir\n");
        scanf("%d",&n);

        switch(n){
            case 0:
                printf("Essa e a saida do programa\n");
                break;
            case 1:
                printf("Insercao no inicio da Fila, digite o valor: \n");
                scanf("%d",&num);
                inserir_no_fim(fila,num);
                break;
            case 2:
                removido=remover_no_inicio(fila);
                if(removido != NULL){
                    printf("Foi removido o elemento com o valor %d\n",removido->valor);
                }
                break;
            case 3:
                imprimir_fila(fila);
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(n != 0);
    return 0;
}

void inicializar_fila(Fila *fila){
    fila->ini=NULL;
    fila->fim=NULL;
    fila->tam=0;
}

void inserir_no_fim(Fila *fila, int num){
    No *novo_no=(No*)malloc(sizeof(No));
    if(novo_no){
        novo_no->valor=num;
        if(fila->ini == NULL){
            fila->ini=novo_no;
            fila->fim=novo_no;
            novo_no->proximo=NULL;
            fila->tam++;
        }
        else{
            fila->fim->proximo=novo_no;
            fila->fim=novo_no;
            novo_no->proximo=NULL;
            fila->tam++;
        }
    }
}

No* remover_no_inicio(Fila *fila){
    No *remover=NULL;
    if(fila->ini){
        if(fila->ini == fila->fim){
            remover=fila->ini;
            fila->ini=NULL;
            fila->fim=NULL;
            fila->tam--;
        }
        else{
            remover=fila->ini;
            fila->ini=remover->proximo;
            fila->tam--;
        }
    }
    return remover;
}

void imprimir_fila(Fila *fila){
    No *aux;
    aux=fila->ini;
    printf("\n\tFila tam %d: ",fila->tam);
    if(aux){
        do{
            printf("| %d | ",aux->valor);
            aux=aux->proximo;
        }while(aux != NULL);
        printf("\nInicio da Fila: %d\n",fila->ini->valor);
        printf("Final da Fila: %d\n",fila->fim->valor);
    }
    printf("\n\n");
}