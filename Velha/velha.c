#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int testando_ganhou(int vetor[]);
void printaespaco();
void printatabuleiro(int vetor[]);
int testando_velha(int vetor[]);

int main(){
    int terminou = 1, escolha, lugar, opcao, tabuleiro[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char primeirojogador[MAX],  segundojogador[MAX], simbolo1, simbolo2;
    printf("\n%c--------------------------------%c", 176, 176);
    printf("\n|  BEM-VINDO AO JOGO DA VELHA    |");
    printf("\n|       versao passiva-agressiva |");
    printf("\n| Escolhe ai:                    |");
    printf("\n| (1) 'o' comeca                 |");
    printf("\n| (2) 'x' comeca                 |");
    printf("\n| (3) Sair                       |");
    printf("\n|            by Carla and Victor |");
    printf("\n%c--------------------------------%c", 176, 176);

    printf("\n\n->");
    scanf("%i", &opcao);
    //printf("1 - o | 2 - x\n");

    switch (opcao){
        case 1:
            escolha = 1;
            printf("\n'o' comeca. \nQual o nome do primeiro trouxa?");
            scanf("%s", primeirojogador);
            printf("\n e do segundo, vulgo 'x'?");
            scanf("%s", segundojogador);
            break;
        case 2:
            escolha = 2;
            printf("\n'x' comeca. \nQual o nome do primeiro trouxa?");
            scanf("%s", primeirojogador);
            printf("\n e do segundo, vulgo 'o'?");
            scanf("%s", segundojogador);
            break;
        case 3:
            printf("\nComecou por que entao caralho?\n");
            printf("Saindo...\n");
            system("pause");
            return(0);
            break;
        default:
        printf("Opcao invalida, saindo...\n");
        system("pause");
    }

    if(escolha == 1){
        simbolo1 = 'o';
        simbolo2 = 'x';
    }
    else{
        simbolo1 = 'x';
        simbolo2 = 'o';
    }

    while(1){
        //Execuçao para o primeiro jogador 
        system("cls");
        printatabuleiro(tabuleiro);
        printf("Onde deseja colocar %c, %s?", simbolo1, primeirojogador);
        scanf("%d", &lugar);
        while(tabuleiro[lugar-1] != 0){
            printf("Sabe jogar jogo da velha nao %s?\nEscolha um lugar diferente para colocar %c: ",primeirojogador, simbolo1);
            scanf("%d", &lugar);
        }

        if(escolha == 1) tabuleiro[lugar-1] = 1;
        else tabuleiro[lugar-1] = 2;

        if(testando_ganhou(tabuleiro) != 0){
            system("cls");
            printatabuleiro(tabuleiro);
            if(testando_ganhou(tabuleiro) == escolha) printf("%s ganhou", primeirojogador);
            else printf("%s ganhou", segundojogador);
            break;
        } 
        if(testando_velha(tabuleiro)){
            printf("Caralho, ce eh muito ruim %s, comecou e nao venceu KKKKKK", primeirojogador);
            break;
        }


        //Execuçao para o segundo jogador
        system("cls");
        printatabuleiro(tabuleiro);
        printf("Onde deseja colocar %c, %s?", simbolo2, segundojogador);
        scanf("%d", &lugar);
        while(tabuleiro[lugar-1] != 0){
            printf("Sabe jogar jogo da velha nao %s?\nEscolha um lugar diferente para colocar %c: ", segundojogador, simbolo2);
            scanf("%d", &lugar);
        }

        if(escolha == 1) tabuleiro[lugar-1] = 2;
        else tabuleiro[lugar-1] = 1;

        if(testando_ganhou(tabuleiro) != 0){
            system("cls");
            printatabuleiro(tabuleiro);
            if(testando_ganhou(tabuleiro) == escolha) printf("%s ganhou", primeirojogador);
            else printf("%s ganhou", segundojogador);
            break;
        }
        if(testando_velha(tabuleiro)){
            printf("Caralho, ce eh muito ruim %s, comecou e nao venceu KKKKKK", primeirojogador);
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
    //Considera as 8 possibiidades de vitoria (3 vertical, 3 horizontal, 2 diagonal)
    if (vetor[0] == vetor[3] && vetor[3] == vetor[6]) return(vetor[0]);
    else if(vetor[1] == vetor[4] && vetor[4] == vetor[7]) return(vetor[1]);
    else if(vetor[2] == vetor[5] && vetor[5] == vetor[8]) return(vetor[2]);
    else if(vetor[0] == vetor[1] && vetor[1] == vetor[2]) return(vetor[0]);
    else if(vetor[3] == vetor[4] && vetor[4] == vetor[5]) return(vetor[3]);
    else if(vetor[6] == vetor[7] && vetor[7] == vetor[8]) return(vetor[6]);
    else if(vetor[0] == vetor[4] && vetor[4] == vetor[8]) return(vetor[0]);
    else if(vetor[2] == vetor[4] && vetor[4] == vetor[6]) return(vetor[2]);
    else return(0);
}

int testando_velha(int vetor[]){
    for(int i = 0; i < 9; i++) if(vetor[i] == 0) return 0;
    return 1;
}
