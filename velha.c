#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "testando_ganhou.c"
#define MAX 20

int testando_ganhou(int vetor[]);
void printaespaco();
void printatabuleiro(int vetor[]);

int main(){
    int terminou = 1, escolha, lugar, opcao, tabuleiro[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char primeirojogador[MAX],  segundojogador[MAX];
    printf("\n---------------------------------");
    printf("\n|  BEM-VINDO AO JOGO DA VELHA   |");
    printf("\n| Escolha sua opcao:            |");
    printf("\n| (1) 'o' comeca                |");
    printf("\n| (2) 'x' comeca                |");
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

    while(1){   

        printatabuleiro(tabuleiro);
        printf("Onde deseja colocar seu simbolo %s?", primeirojogador);
        scanf("%d", &lugar);
        if(escolha == 1) tabuleiro[lugar-1] = 1;
        else tabuleiro[lugar-1] = 2;

        printf("\n%d\n",testando_ganhou(tabuleiro));
        if(testando_ganhou(tabuleiro) != 0){
            if(testando_ganhou(tabuleiro) == escolha) printf("%s ganhou", primeirojogador);
            else printf("%s ganhou", segundojogador);
            break;
        } 

        printatabuleiro(tabuleiro);
        printf("Onde deseja colocar seu simbolo %s?", segundojogador);
        scanf("%d", &lugar);
        if(escolha == 1) tabuleiro[lugar-1] = 2;
        else tabuleiro[lugar-1] = 1;

        printf("\n%d\n",testando_ganhou(tabuleiro));
        if(testando_ganhou(tabuleiro) != 0){
            if(testando_ganhou(tabuleiro) == escolha) printf("%s ganhou", primeirojogador);
            else printf("%s ganhou", segundojogador);
            break;
        } 
    }

    return (0);

}

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

int testando_ganhou(int vetor[]){
    //1 = 'o' e 2 = 'x'
    if (vetor[1] == vetor[4] && vetor[4] == vetor[7] && vetor[1]!=0){ //vetor[1] == vetor[4] && vetor[4] == vetor[7]
        return(vetor[1]);
    }else 
    if(vetor[2] == vetor[5] && vetor[5] == vetor[8] && vetor[2]!=0){
        return(vetor[2]);
    }else 
    if(vetor[3] == vetor[6] && vetor[6] == vetor[9] && vetor[3]!=0){
        return(vetor[3]);
    }else 
    if(vetor[1] == vetor[2] && vetor[2] == vetor[3] && vetor[1]!=0){
        return(vetor[1]);
    }else 
    if(vetor[4] == vetor[5] && vetor[5] == vetor[6] && vetor[4]!=0){
        return(vetor[4]);
    }else 
    if(vetor[7] == vetor[8] && vetor[8] == vetor[9] && vetor[7]!=0){
        return(vetor[7]);
    }else 
    if(vetor[1] == vetor[5] && vetor[5] == vetor[9] && vetor[1]!=0){
        return(vetor[1]);
    }else 
    if(vetor[3] == vetor[5] && vetor[5] == vetor[7] && vetor[3]!=0){
        return(vetor[3]);
    }else{
        return(0);
    }
}