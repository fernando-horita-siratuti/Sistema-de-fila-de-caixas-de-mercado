#ifndef TRAB2_H
#define TRAB2_H

#define TAM1 100

    typedef struct cliente{
        char nome[TAM1];
        double cpf;
        int itens;
        int caixa;
        int abfecaixa1;
        int abfecaixa2;
        int abfecaixa3;
        int pref;
        struct cliente *prox;
    }cliente;
    typedef struct Nodo{
        struct Nodo *prox;
    }Nodo;
    typedef struct lista_cliente{
        struct Nodo *prim;
        int tam11;
        int tam12;
        int tam13;
        int tam14;
        int tam21;
        int tam22;
        int tam23;
        int tam24;
        int tam31;
        int tam32;
        int tam33;
        int tam34;
    }lista_cliente;

    void criarLista1(struct lista_cliente *pList);
    void mostrarLista1(struct lista_cliente *pList);
    void filaCaixa1(struct lista_cliente *pList);
    void statusCaixa11(struct lista_cliente *pList1, struct lista_cliente *pList2);
    void statusCaixa12(struct lista_cliente *pList1, struct lista_cliente *pList2);
    void inserirIni1(struct lista_cliente *pList, int pref, char nome[TAM1], double cpf, int itens);
    void inserirFin1(struct lista_cliente *pList, char nome[TAM1], double cpf, int itens);
    void desenfileirar1(struct lista_cliente *pList);
    void criarLista2(struct lista_cliente *pList);
    void mostrarLista2(struct lista_cliente *pList);
    void filaCaixa2(struct lista_cliente *pList);
    void statusCaixa21(struct lista_cliente *pList1, struct lista_cliente *pList2);
    void statusCaixa22(struct lista_cliente *pList1, struct lista_cliente *pList2);
    void inserirIni2(struct lista_cliente *pList, int pref, char nome[TAM1], double cpf, int itens);
    void inserirFin2(struct lista_cliente *pList, char nome[TAM1], double cpf, int itens);
    void desenfileirar2(struct lista_cliente *pList);
    void criarLista3(struct lista_cliente *pList);
    void mostrarLista3(struct lista_cliente *pList);
    void filaCaixa3(struct lista_cliente *pList);
    void statusCaixa31(struct lista_cliente *pList1, struct lista_cliente *pList2);
    void statusCaixa32(struct lista_cliente *pList1, struct lista_cliente *pList2);
    void inserirIni3(struct lista_cliente *pList, int pref, char nome[TAM1], double cpf, int itens);
    void inserirFin3(struct lista_cliente *pList, char nome[TAM1], double cpf, int itens);
    void desenfileirar3(struct lista_cliente *pList);

#endif