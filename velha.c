#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testando_ganhou.c"
#define MAX 20

void printaespaco(){
    printf("\n%c%c%c %c%c%c %c%c%c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196);
}


void printatabuleiro(int tabuleiro[9]){
    for(int i = 0; i < 9; i++){
    printf(" ");
    switch(tabuleiro[i]){
        case 0:
            printf("%d", i + 1);
            break;
        case 1:
            printf("o");
            break;
        case 2:
            printf("x");
    }
    if(i % 3 != 2) printf(" |");
    if(i % 3 == 2 && i != 8) printaespaco();
    }
    printf("\n");
}

int main(){
    int terminou = 1, escolha, opcao, tabuleiro[9] = {0, 1, 1, 2, 2, 1, 0, 0, 0};
    char primeirojogador[MAX],  segundojogador[MAX];
    printf("\n---------------------------------");
    printf("\n|  BEM-VINDO AO JOGO DA VELHA   |");
    printf("\n| Escolha sua opcao:            |");
    printf("\n| (1) 'o' começa                |");
    printf("\n| (2) 'x' começa                |");
    printf("\n| (3) Sair                      |");
    printf("\n              by Carla and Victor");
    printf("\n---------------------------------");

    printf("\n\n->");
    scanf("%i", &opcao);
    //printf("\nA opcao escolhida foi %i", opcao);
    //printf("1 - o | 2 - x\n");
    switch (opcao){
        case 1:
            escolha = 1;
            printf("\n'o' comeca. \nQual seu nome?");
            scanf("%s", primeirojogador);
            printf("\n e do 'x'?");
            scanf("%s", segundojogador);
            break;
        case 2:
            escolha = 2;
            printf("\n'x' comeca. \nQual seu nome?");
            scanf("%s", primeirojogador);
            printf("\n e da 'o'?");
            scanf("%s", segundojogador);
            break;
        case 3:
            printf("Saindo...\n");
            system("pause");
            break;
        default:
        printf("Opcao invalida, saindo...\n");
        system("pause");
    }
    printatabuleiro(tabuleiro);
    while(terminou){
        printf("");
    }
    return (0);

}