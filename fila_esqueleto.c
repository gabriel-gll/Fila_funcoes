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