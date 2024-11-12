#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trab2.h"

int main(){
    cliente a;
    struct lista_cliente minhaLista1, minhaLista2, minhaLista3;
    int caso, erro, abfecaixa1 = 1, abfecaixa2 = 1, abfecaixa3 = 1, tam11 = 0, tam12 = 0, tam13 = 0, tam14 = 0, tam21 = 0, tam22 = 0, tam23 = 0, tam24 = 0, tam31 = 0, tam32 = 0, tam33 = 0, tam34 = 0;
    criarLista1(&minhaLista1);
    criarLista2(&minhaLista2);
    criarLista3(&minhaLista3);

    do{
        printf("[ 0 ] encerrar o programa\n[ 1 ] Inserir um cliente com preferencia\n[ 2 ] Inserir um cliente sem preferencia\n[ 3 ] Atender um cliente\n[ 4 ] Abrir/fechar um caixa\n[ 5 ] Imprimir os dados dos clientes\n[ 6 ] Imprimir as filas dos caixas\nDigite uma opcao: ");
        scanf("%d", &caso);
        while(getchar() != '\n');
        switch(caso){
            case 0:{
                return 0;
                break;
            }
            case 1:{
                do{
                    do{
                        printf("Digite o nivel de preferencia do cliente(1-3): ");
                        scanf("%d", &a.pref);
                        while(getchar() != '\n');
                        if(a.pref < 1 || a.pref > 3){
                            printf("Nivel de preferencia invalido. Por favor, tente novamente.\n");
                        }
                    }while(a.pref < 1 || a.pref > 3);
                    printf("Digite o nome do cliente: ");
                    fgets(a.nome, TAM1, stdin);
                    a.nome[strcspn(a.nome, "\n")] = 0;
                    printf("Digite o cpf de %s(apenas os numeros): ", a.nome);
                    scanf("%lf", &a.cpf);
                    while(getchar() != '\n');
                    printf("Agora, digite a quantidade de itens no carrinho de compras do cliente: ");
                    scanf("%d", &a.itens);
                    while(getchar() != '\n');
                    printf("Por fim, digite o caixa no qual tal cliente sera destinado: ");
                    scanf("%d", &a.caixa);
                    while(getchar() != '\n');
                    if(a.caixa == 1){
                        if(abfecaixa1 == 1){
                            inserirIni1(&minhaLista1, a.pref, a.nome, a.cpf, a.itens);
                            if(a.pref == 1){
                                tam11++;
                            }
                            else if(a.pref == 2){
                                tam12++;
                            }
                            else if(a.pref == 3){
                                tam13++;
                            }
                            erro = 0;
                        }
                        else if(abfecaixa1 == 2){
                            erro = 1;
                        }
                    }
                    else if(a.caixa == 2){
                        if(abfecaixa2 == 1){
                            inserirIni2(&minhaLista2, a.pref, a.nome, a.cpf, a.itens);
                            if(a.pref == 1){
                                tam21++;
                            }
                            else if(a.pref == 2){
                                tam22++;
                            }
                            else if(a.pref == 3){
                                tam23++;
                            }
                            erro = 0;
                        }
                        else if(abfecaixa2 == 2){
                            erro = 1;
                        }
                    }
                    else if(a.caixa == 3){
                        if(abfecaixa3 == 1){
                            inserirIni3(&minhaLista3, a.pref, a.nome, a.cpf, a.itens);
                            if(a.pref == 1){
                                tam31++;
                            }
                            else if(a.pref == 2){
                                tam32++;
                            }
                            else if(a.pref == 3){
                                tam33++;
                            }
                            erro = 0;
                        }
                        else if(abfecaixa3 == 2){
                            erro = 1;
                        }
                    }
                    if(erro == 1){
                        printf("Tal caixa e invalido ou esta fechado. Por favor, tente novamente.\n");
                    }
                }while(erro == 1);
                break;
            }
            case 2:{
                do{
                    printf("Digite o nome da pessoa: ");
                    fgets(a.nome, TAM1, stdin);
                    a.nome[strcspn(a.nome, "\n")] = 0;
                    printf("Digite o cpf de %s(apenas os numeros): ", a.nome);
                    scanf("%lf", &a.cpf);
                    while(getchar() != '\n');
                    printf("Agora, digite a quantidade de itens no carrinho de compras do cliente: ");
                    scanf("%d", &a.itens);
                    printf("Por fim, digite o caixa no qual tal cliente sera destinado(1-3): ");
                    scanf("%d", &a.caixa);
                    if(a.caixa == 1){
                        if(abfecaixa1 == 1){
                            inserirFin1(&minhaLista1, a.nome, a.cpf, a.itens);
                            tam14++;
                            erro = 0;
                        }
                        else if(abfecaixa1 == 2){
                            erro = 1;
                        }
                    }
                    else if(a.caixa == 2){
                        if(abfecaixa2 == 1){
                            inserirFin2(&minhaLista2, a.nome, a.cpf, a.itens);
                            tam24++;
                            erro = 0;
                        }
                        else if(abfecaixa2 == 2){
                            erro = 1;
                        }
                    }
                    else if(a.caixa == 3){
                        if(abfecaixa3 == 1){
                            inserirFin3(&minhaLista3, a.nome, a.cpf, a.itens);
                            tam34++;
                            erro = 0;
                        }
                        else if(abfecaixa3 == 2){
                            erro = 1;
                        }
                    }
                    else{
                        printf("Tal caixa e invalido ou esta fechado. Por favor, tente novamente.\n");
                        erro = 1;
                    }
                }while(erro == 1);
                break;
            }
            case 3:{
                int atendercaixa;

                printf("Qual caixa voce deseja atender?(1-3)\n");
                scanf("%d", &atendercaixa);
                switch(atendercaixa){
                    case 1:{
                        if(abfecaixa1 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa1 == 1){
                            desenfileirar1(&minhaLista1);
                            int total1 = tam11 + tam12 + tam13 +tam14;

                            if(total1 > 0){
                                if(tam11 > 0){
                                    tam11--;
                                }
                                else if(tam11 == 0 && tam12 > 0){
                                    tam12--;
                                }
                                else if(tam11 == 0 && tam12 == 0 && tam13 > 0){
                                    tam13--;
                                }
                                else if(tam11 == 0 && tam12 == 0 && tam13 == 0 && tam14 > 0){
                                    tam14--;
                                }
                            }
                        }
                        break;
                    }
                    case 2:{
                        if(abfecaixa2 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa2 == 1){
                            desenfileirar2(&minhaLista2);
                            int total2 = tam21 + tam22 + tam23 +tam24;

                            if(total2 > 0){
                                if(tam21 > 0){
                                    tam21--;
                                }
                                else if(tam21 == 0 && tam22 > 0){
                                    tam22--;
                                }
                                else if(tam21 == 0 && tam22 == 0 && tam23 > 0){
                                    tam23--;
                                }
                                else if(tam21 == 0 && tam22 == 0 && tam23 == 0 && tam24 > 0){
                                    tam24--;
                                }
                            }
                        }
                        break;
                    }
                    case 3:{
                        if(abfecaixa3 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa3 == 1){
                            desenfileirar3(&minhaLista3);
                            int total3 = tam31 + tam32 + tam33 +tam34;

                            if(total3 > 0){
                                if(tam31 > 0){
                                    tam31--;
                                }
                                else if(tam31 == 0 && tam32 > 0){
                                    tam32--;
                                }
                                else if(tam31 == 0 && tam32 == 0 && tam33 > 0){
                                    tam33--;
                                }
                                else if(tam31 == 0 && tam32 == 0 && tam33 == 0 && tam34 > 0){
                                    tam34--;
                                }
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 4:{
                int statuscaixa;

                printf("Qual caixa voce deseja abrir/fechar?(1-3)\n");
                scanf("%d", &statuscaixa);
                printf("Digite 1 para abrir o caixa ou 2 para fecha-lo: ");
                switch(statuscaixa){
                    case 1:{
                        do{
                            scanf("%d", &a.abfecaixa1);
                            if(a.abfecaixa1 < 1 || a.abfecaixa1 > 2){
                                printf("O numero digitado e invalido. Por favor, tente novamente.\n");
                            }
                        }while(a.abfecaixa1 < 1 || a.abfecaixa1 > 2);
                        if(a.abfecaixa1 == 2){
                            int total1;
                            
                            total1 = tam11 + tam12 + tam13 + tam14;
                            if(total1 > 0){
                                if((abfecaixa2 == 1 && abfecaixa3 == 2) || (abfecaixa2 == 1 && abfecaixa3 == 1)){
                                    statusCaixa11(&minhaLista1, &minhaLista2);
                                }
                                else if(abfecaixa2 == 2 && abfecaixa3 == 1){
                                    statusCaixa12(&minhaLista1, &minhaLista3);
                                }
                                else if(abfecaixa2 == 2 && abfecaixa3 == 2){
                                    printf("Todos os caixas estao fechados.\n");
                                }
                            }
                        }
                        else if(a.abfecaixa1 == 1){
                            criarLista1(&minhaLista1);
                        }
                        if(a.abfecaixa1 == 1){
                            abfecaixa1 = 1;
                        }
                        else if(a.abfecaixa1 == 2){
                            abfecaixa1 = 2;
                        }
                        break;
                    }
                    case 2:{
                        do{
                            scanf("%d", &a.abfecaixa2);
                            if(a.abfecaixa2 < 1 || a.abfecaixa2 > 2){
                                printf("O numero digitado e invalido. Por favor, tente novamente.\n");
                            }
                        }while(a.abfecaixa2 < 1 || a.abfecaixa2 > 2);
                        if(a.abfecaixa2 == 2){
                            int total2;
                            
                            total2 = tam21 + tam22 + tam23 + tam24;
                            if(total2 > 0){
                                if((abfecaixa1 == 1 && abfecaixa3 == 2) || (abfecaixa1 == 1 && abfecaixa3 == 1)){
                                    statusCaixa21(&minhaLista2, &minhaLista1);
                                }
                                else if(abfecaixa1 == 2 && abfecaixa3 == 1){
                                    statusCaixa22(&minhaLista2, &minhaLista3);
                                }
                                else if(abfecaixa1 == 2 && abfecaixa3 == 2){
                                    printf("Todos os caixas estao fechados.\n");
                                }
                            }
                        }
                        else if(a.abfecaixa2 == 1){
                            criarLista2(&minhaLista2);
                        }
                        if(a.abfecaixa2 == 1){
                            abfecaixa2 = 1;
                        }
                        else if(a.abfecaixa2 == 2){
                            abfecaixa2 = 2;
                        }
                        break;
                    }
                    case 3:{
                        do{
                            scanf("%d", &a.abfecaixa3);
                            if(a.abfecaixa3 < 1 || a.abfecaixa3 > 2){
                                printf("O numero digitado e invalido. Por favor, tente novamente.\n");
                            }
                        }while(a.abfecaixa3 < 1 || a.abfecaixa3 > 2);
                        if(a.abfecaixa3 == 2){
                            int total3;
                            
                            total3 = tam31 + tam32 + tam33 + tam34;
                            if(total3 > 0){
                                if((abfecaixa1 == 1 && abfecaixa2 == 2) || (abfecaixa1 == 1 && abfecaixa2 == 1)){
                                    statusCaixa31(&minhaLista3, &minhaLista1);
                                }
                                else if(abfecaixa1 == 2 && abfecaixa2 == 1){
                                    statusCaixa32(&minhaLista3, &minhaLista2);
                                }
                                else if(abfecaixa1 == 2 && abfecaixa2 == 2){
                                    printf("Todos os caixas estao fechados.\n");
                                }
                            }
                        }
                        else if(a.abfecaixa3 == 1){
                            criarLista3(&minhaLista3);
                        }
                        if(a.abfecaixa3 == 1){
                            abfecaixa3 = 1;
                        }
                        else if(a.abfecaixa3 == 2){
                            abfecaixa3 = 2;
                        }
                        break;
                    }
                }
                break;
            }
            case 5:{
                int clientescaixa;
                
                printf("Digite qual e o caixa no qual estao os clientes que deseja consultar(1-3): ");
                scanf("%d", &clientescaixa);
                switch(clientescaixa){
                    case 1:{
                        if(abfecaixa1 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa1 == 1){
                            mostrarLista1(&minhaLista1);
                        }
                        break;
                    }
                    case 2:{
                        if(abfecaixa2 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa2 == 1){
                            mostrarLista2(&minhaLista2);
                        }
                        break;
                    }
                    case 3:{
                        if(abfecaixa3 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa3 == 1){
                            mostrarLista3(&minhaLista3);
                        }
                        break;
                    }
                }
                break;
            }
            case 6:{
                int mostrarcaixa;

                printf("Qual fila de caixa voce deseja consultar?(1-3)\n");
                scanf("%d", &mostrarcaixa);
                switch(mostrarcaixa){
                    case 1:{
                        if(abfecaixa1 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa1 == 1){
                            filaCaixa1(&minhaLista1);
                        }
                        break;
                    }
                    case 2:{
                        if(abfecaixa2 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa2 == 1){
                            filaCaixa2(&minhaLista2);
                        }
                        break;
                    }
                    case 3:{
                        if(abfecaixa3 == 2){
                            printf("Esse caixa esta fechado. Por favor, tente novamente.\n");
                        }
                        else if(abfecaixa3 == 1){
                            filaCaixa3(&minhaLista3);
                        }
                        break;
                    }
                }
                break;
            }
        }
    }while(caso != 0);

    return 0;
}