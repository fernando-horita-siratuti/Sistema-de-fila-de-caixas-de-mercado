#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trab2.h"

    void criarLista1(struct lista_cliente *pList){
        pList->prim = NULL;
        pList->tam11 = 0;
        pList->tam12 = 0;
        pList->tam13 = 0;
        pList->tam14 = 0;
    }
    void mostrarLista1(struct lista_cliente *pList){
        struct cliente *p;
        int i, total1;
        total1 = pList->tam11 + pList->tam12 + pList->tam13 + pList->tam14;
        if(total1 > 0){
            printf("Status da fila do caixa 1:\n");
            for(p = pList->prim, i = 0; p != NULL; p = p->prox, i++){
                printf("\nNome: %s. CPF: %.lf. Numero de itens no carrinho: %d. Posicao na fila: %d°.\n", p->nome, p->cpf, p->itens, i + 1);
            }
            printf("\n");
        }
        else{
            printf("A fila do caixa 1 esta vazia.\n");
        }
    }
    void statusCaixa11(struct lista_cliente *pList1, struct lista_cliente *pList2){
        int total1;
        struct cliente *p;
        
        for(p = pList1->prim; p != NULL; p = p->prox){
            if(p->pref == 1 || p->pref == 2 || p->pref == 3){
                inserirIni2(pList2, p->pref, p->nome, p->cpf, p-> itens);
            }
            else{
                inserirFin2(pList2, p->nome, p->cpf, p->itens);
            }
        }
        total1 = -1;
        return 0;
    }
    void statusCaixa12(struct lista_cliente *pList, struct lista_cliente *pList2){
        int total1;
        struct lista_cliente minhaLista1, minhaLista3;
        struct cliente *p = pList->prim;

        for(p = pList->prim; p != NULL; p = p->prox){
            if(p->pref == 1 || p->pref == 2 || p->pref == 3){
                inserirIni3(pList2, p->pref, p->nome, p->cpf, p-> itens);
            }
            else{
                inserirFin3(pList2, p->nome, p->cpf, p->itens);
            }
        }
        total1 = -1;
        return 0;
    }
    void filaCaixa1(struct lista_cliente *pList){
        int total1;
        total1 = pList->tam11 + pList->tam12 + pList->tam13 + pList->tam14;
        if(total1 >= 0){
            printf("O caixa 1 possui %d cliente(s) em sua fila.\n", total1);
        }
        else if(total1 == -1){
            printf("O caixa 1 esta fechado.\n");
        }
    }
    void inserirIni1(struct lista_cliente *pList, int pref, char nome[TAM1], double cpf, int itens){
        struct cliente *novo1, *aux;
        novo1 = (cliente*)malloc(sizeof(struct cliente));
        
        if(pref == 1){
            aux = pList->prim;
            if(pList->tam11 > 0){
                while(aux->prox != NULL && aux->prox->pref == 1){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else{
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam11++;
            return;
        }
        else if(pref == 2){
            aux = pList->prim;
            if(pList->tam11 > 0){
                while(aux->prox != NULL && (aux->prox->pref == 1 || aux->prox->pref == 2)){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else if(pList->tam11 == 0){
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam12++;
            return;
        }
        else if(pref == 3){
            aux = pList->prim;
            if(pList->tam11 > 0 || pList->tam12 > 0){
                while(aux->prox != NULL && (aux->prox->pref == 1 || aux->prox->pref == 2 || aux->prox->pref == 3)){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else if(pList->tam11 == 0 && pList->tam12 == 0){
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam13++;
            return;
        }
    }
    void inserirFin1(struct lista_cliente *pList, char nome[TAM1], double cpf, int itens){
        struct cliente *novo2, *no1;
        novo2 = (cliente*)malloc(sizeof(struct cliente));

        novo2->cpf = cpf;
        strcpy(novo2->nome, nome);
        novo2->itens = itens;
        novo2->prox = NULL;
        if(pList->prim == NULL){
            pList->prim = novo2;
        }
        else{
            no1 = pList->prim;
            while(no1->prox != NULL){
                no1 = no1->prox;
            }
            no1->prox = novo2;
        }
        pList->tam14++;
    }
    void desenfileirar1(struct lista_cliente *pList){
        struct cliente *pAux = pList->prim;
        int i, total1;
        total1 = pList->tam11 + pList->tam12 + pList->tam13 + pList->tam14;
        if(total1 == 0){
            printf("A fila do caixa 1 esta vazio. Por favor, tente novamente.\n");
        }
        else if(total1 > 0){
            printf("%s foi atendido/a no caixa 1. ", pAux);
            pList->prim = pAux->prox;
            free(pAux);
            if(pList->tam11 > 0){
                pList->tam11--;
            }
            else if(pList->tam11 == 0 && pList->tam12 > 0){
                pList->tam12--;
            }
            else if(pList->tam11 == 0 && pList->tam12 == 0 && pList->tam13 > 0){
                pList->tam13--;
            }
            else if(pList->tam11 == 0 && pList->tam12 == 0 && pList->tam13 == 0 && pList->tam14 > 0){
                pList->tam14--;
            }
            total1 = pList->tam11 + pList->tam12 + pList->tam13 + pList->tam14;
            printf("Logo, restam %d pessoa(s) na fila do caixa 1.\n", total1);
        }
    }

    // CAIXA 2

    void criarLista2(struct lista_cliente *pList){
        pList->prim = NULL;
        pList->tam21 = 0;
        pList->tam22 = 0;
        pList->tam23 = 0;
        pList->tam24 = 0;
    }
    void mostrarLista2(struct lista_cliente *pList){
        struct cliente *p;
        int i, total2;
        total2 = pList->tam21 + pList->tam22 + pList->tam23 + pList->tam24;
        if(total2 > 0){
            printf("Status da fila do caixa 2:\n");
            for(p = pList->prim, i = 0; p != NULL; p = p->prox, i++){
                printf("\nNome: %s. CPF: %.lf. Numero de itens no carrinho: %d. Posicao na fila: %d°.\n", p->nome, p->cpf, p->itens, i + 1);
            }
            printf("\n");
        }
        else{
            printf("A fila do caixa 2 esta vazia.\n");
        }
    }
    void statusCaixa21(struct lista_cliente *pList1, struct lista_cliente *pList2){
        int total2;
        struct lista_cliente minhaLista1, minhaLista2;
        struct cliente *p;
        
        for(p = pList1->prim; p != NULL; p = p->prox){
            if(p->pref == 1 || p->pref == 2 || p->pref == 3){
                inserirIni1(pList2, p->pref, p->nome, p->cpf, p-> itens);
            }
            else{
                inserirFin1(pList2, p->nome, p->cpf, p->itens);
            }
        }
        total2 = -1;
    }
    void statusCaixa22(struct lista_cliente *pList1, struct lista_cliente *pList2){
        int total2;
        struct lista_cliente minhaLista2, minhaLista3;
        struct cliente *p;

        for(p = pList1->prim; p != NULL; p = p->prox){
            if(p->pref == 1 || p->pref == 2 || p->pref == 3){
                inserirIni3(pList2, p->pref, p->nome, p->cpf, p-> itens);
            }
            else{
                inserirFin3(pList2, p->nome, p->cpf, p->itens);
            }
        }
        total2 = -1;
    }
    void filaCaixa2(struct lista_cliente *pList){
        int total2;
        total2 = pList->tam21 + pList->tam22 + pList->tam23 + pList->tam24;
        
       if(total2 >= 0){
            printf("O caixa 2 possui %d cliente(s) em sua fila.\n", total2);
        }
        else if(total2 == -1){
            printf("O caixa 2 esta fechado.\n");
        }
    }
    void inserirIni2(struct lista_cliente *pList, int pref, char nome[TAM1], double cpf, int itens){
        struct cliente *novo1, *aux;
        novo1 = (cliente*)malloc(sizeof(struct cliente));
        
        if(pref == 1){
            aux = pList->prim;
            if(pList->tam21 > 0){
                while(aux->prox != NULL && aux->prox->pref == 1){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else{
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam21++;
            return;
        }
        else if(pref == 2){
            aux = pList->prim;
            if(pList->tam21 > 0){
                while(aux->prox != NULL && (aux->prox->pref == 1 || aux->prox->pref == 2)){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else if(pList->tam21 == 0){
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam22++;
            return;
        }
        else if(pref == 3){
            aux = pList->prim;
            if(pList->tam21 > 0 || pList->tam22 > 0){
                while(aux->prox != NULL && (aux->prox->pref == 1 || aux->prox->pref == 2 || aux->prox->pref == 3)){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else if(pList->tam21 == 0 && pList->tam22 == 0){
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam23++;
            return;
        }
    }
    void inserirFin2(struct lista_cliente *pList, char nome[TAM1], double cpf, int itens){
        struct cliente *novo2, *no1;
        novo2 = (cliente*)malloc(sizeof(struct cliente));

        novo2->cpf = cpf;
        strcpy(novo2->nome, nome);
        novo2->itens = itens;
        novo2->prox = NULL;
        if(pList->prim == NULL){
            pList->prim = novo2;
        }
        else{
            no1 = pList->prim;
            while(no1->prox != NULL){
                no1 = no1->prox;
            }
            no1->prox = novo2;
        }
        pList->tam24++;
    }
    void desenfileirar2(struct lista_cliente *pList){
        struct cliente *pAux = pList->prim;
        int i, total2;
        total2 = pList->tam21 + pList->tam22 + pList->tam23 + pList->tam24;
        if(total2 == 0){
            printf("A fila do caixa 2 esta vazio. Por favor, tente novamente.\n");
        }
        else if(total2 > 0){
            printf("%s foi atendido/a no caixa 2. ", pAux);
            pList->prim = pAux->prox;
            free(pAux);
            if(pList->tam21 > 0){
                pList->tam21--;
            }
            else if(pList->tam21 == 0 && pList->tam22 > 0){
                pList->tam22--;
            }
            else if(pList->tam21 == 0 && pList->tam22 == 0 && pList->tam23 > 0){
                pList->tam23--;
            }
            else if(pList->tam21 == 0 && pList->tam22 == 0 && pList->tam23 == 0 && pList->tam24 > 0){
                pList->tam24--;
            }
            total2 = pList->tam21 + pList->tam22 + pList->tam23 + pList->tam24;
            printf("Logo, restam %d pessoa(s) na fila do caixa 2.\n", total2);
        }
    } 

    // CAIXA 3 

    void criarLista3(struct lista_cliente *pList){
        pList->prim = NULL;
        pList->tam31 = 0;
        pList->tam32 = 0;
        pList->tam33 = 0;
        pList->tam34 = 0;
    }
    void mostrarLista3(struct lista_cliente *pList){
        struct cliente *p;
        int i, total3;
        total3 = pList->tam31 + pList->tam32 + pList->tam33 + pList->tam34;
        if(total3 > 0){
            printf("Status da fila do caixa 3:\n");
            for(p = pList->prim, i = 0; p != NULL; p = p->prox, i++){
                printf("\nNome: %s. CPF: %.lf. Numero de itens no carrinho: %d. Posicao na fila: %d°.\n", p->nome, p->cpf, p->itens, i + 1);
            }
            printf("\n");
        }
        else{
            printf("A fila do caixa 3 esta vazia.\n");
        }
    }
    void statusCaixa31(struct lista_cliente *pList1, struct lista_cliente *pList2){
        int total3;
        struct lista_cliente minhaLista1, minhaLista3;
        struct cliente *p;
        
        for(p = pList1->prim; p != NULL; p = p->prox){
            if(p->pref == 1 || p->pref == 2 || p->pref == 3){
                inserirIni1(pList2, p->pref, p->nome, p->cpf, p-> itens);
            }
            else{
                inserirFin1(pList2, p->nome, p->cpf, p->itens);
            }
        }
        total3 = -1;
    }
    void statusCaixa32(struct lista_cliente *pList1, struct lista_cliente *pList2){
        int total3;
        struct lista_cliente minhaLista2, minhaLista3;
        struct cliente *p;

        for(p = pList1->prim; p != NULL; p = p->prox){
            if(p->pref == 1 || p->pref == 2 || p->pref == 3){
                inserirIni2(pList2, p->pref, p->nome, p->cpf, p-> itens);
            }
            else{
                inserirFin2(pList2, p->nome, p->cpf, p->itens);
            }
        }
        total3 = -1;
    }
    void filaCaixa3(struct lista_cliente *pList){
        int total3;
        total3 = pList->tam31 + pList->tam32 + pList->tam33 + pList->tam34;
        
        if(total3 >= 0){
            printf("O caixa 3 possui %d cliente(s) em sua fila.\n", total3);
        }
        else if(total3 == -1){
            printf("O caixa 3 esta fechado.\n");
        }
    }
    void inserirIni3(struct lista_cliente *pList, int pref, char nome[TAM1], double cpf, int itens){
        struct cliente *novo1, *aux;
        novo1 = (cliente*)malloc(sizeof(struct cliente));
        
        if(pref == 1){
            aux = pList->prim;
            if(pList->tam31 > 0){
                while(aux->prox != NULL && aux->prox->pref == 1){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else{
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam31++;
            return;
        }
        else if(pref == 2){
            aux = pList->prim;
            if(pList->tam31 > 0){
                while(aux->prox != NULL && (aux->prox->pref == 1 || aux->prox->pref == 2)){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else if(pList->tam31 == 0){
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam32++;
            return;
        }
        else if(pref == 3){
            aux = pList->prim;
            if(pList->tam31 > 0 || pList->tam32 > 0){
                while(aux->prox != NULL && (aux->prox->pref == 1 || aux->prox->pref == 2 || aux->prox->pref == 3)){
                    aux = aux->prox;
                }
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = aux->prox;
                aux->prox = novo1;
            }
            else if(pList->tam31 == 0 && pList->tam32 == 0){
                novo1->pref = pref;
                novo1->cpf = cpf;
                strcpy(novo1->nome, nome);
                novo1->itens = itens;
                novo1->prox = pList->prim;
                pList->prim = novo1;
            }
            pList->tam33++;
            return;
        }
    }
    void inserirFin3(struct lista_cliente *pList, char nome[TAM1], double cpf, int itens){
        struct cliente *novo2, *no1;
        novo2 = (cliente*)malloc(sizeof(struct cliente));

        novo2->cpf = cpf;
        strcpy(novo2->nome, nome);
        novo2->itens = itens;
        novo2->prox = NULL;
        if(pList->prim == NULL){
            pList->prim = novo2;
        }
        else{
            no1 = pList->prim;
            while(no1->prox != NULL){
                no1 = no1->prox;
            }
            no1->prox = novo2;
        }
        pList->tam34++;
    }
    void desenfileirar3(struct lista_cliente *pList){
        struct cliente *pAux = pList->prim;
        int i, total3;
        total3 = pList->tam31 + pList->tam32 + pList->tam33 + pList->tam34;
        if(total3 == 0){
            printf("A fila do caixa 3 esta vazio. Por favor, tente novamente.\n");
        }
        else if(total3 > 0){
            printf("%s foi atendido/a no caixa 3. ", pAux);
            pList->prim = pAux->prox;
            free(pAux);
            if(pList->tam31 > 0){
                pList->tam31--;
            }
            else if(pList->tam31 == 0 && pList->tam32 > 0){
                pList->tam32--;
            }
            else if(pList->tam31 == 0 && pList->tam32 == 0 && pList->tam33 > 0){
                pList->tam33--;
            }
            else if(pList->tam31 == 0 && pList->tam32 == 0 && pList->tam33 == 0 && pList->tam34 > 0){
                pList->tam34--;
            }
            total3 = pList->tam31 + pList->tam32 + pList->tam33 + pList->tam34;
            printf("Logo, restam %d pessoa(s) na fila do caixa 3.\n", total3);
        }
    }