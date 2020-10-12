#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 30

void facil (char a [MAX]);
void medio (char a [MAX]);
void dificil (char a [MAX]);
void personalizado (char a [MAX]);

void printacabecalho(int ncoluna);
void printaespaco(int ncoluna);
void printatabuleiro(int nlinha, int ncoluna, int matriz[nlinha][ncoluna], int resposta[nlinha][ncoluna]);
void conteudocasa(int nlinha, int ncoluna, int tabuleiro[nlinha][ncoluna], int tabuleirodescoberto[nlinha][ncoluna], int linhaatual, int colunaatual);
void printatabuleiro(int nlinha, int ncoluna, int tabuleiro[nlinha][ncoluna], int tabuleirodescoberto[nlinha][ncoluna]);


int main(){
    int opcao;
    char jogador[MAX];

    printf("\n----------------------------------");
    printf("\n|   BEM-VINDO AO CAMPO MINADO    |");
    printf("\n| Escolha sua opcao:             |");
    printf("\n| (1) Facil (9x9)                |");
    printf("\n| (2) Medio (16x16)              |");
    printf("\n| (3) Dificil (16x28)            |");
    printf("\n| (4) Personalizado              |");
    printf("\n| (5) Sair                       |");
    printf("\n----------------------------------");
    printf("\n             by Carla and Victor | ");

    printf("\n\n->");
    scanf("%i", &opcao);
    printf("\nDigite seu nome: ");
    scanf("%s", jogador);
    //printf("\nA opcao escolhida foi %i", opcao);

    switch (opcao){
    case 1:
        facil(jogador);
        break;
    case 2:
        medio(jogador);
        break;
    case 3:
        dificil(jogador);
        break;
    case 4:
        personalizado(jogador);
        break;
    case 5:
        printf("Saindo...\n");
        system("pause");
    default:
        printf("Opcao invalida, saindo...\n");
        system("pause");
    }

    return (0);
}

void facil (char jogador [MAX]){ // 9 x 9
    int nlinhas = 9, ncolunas = 9;
    // -1 = bomba
    int nbombas = 10, linha, coluna, i, j;
    int resposta[nlinhas][ncolunas], matriz[nlinhas][ncolunas];
    srand(time(NULL));

    for (i = 0; i< nlinhas; i++){
        for (j = 0; j< ncolunas; j++ ){
            matriz[i][j] = 1;
            resposta[i][j] = 0;
        }
    }

    for ( i = 0; i<nbombas; i++){
        linha = rand() % nlinhas;
        coluna = rand() % ncolunas;
        if(resposta[linha][coluna] == -1){//se numeros ja foram
            i --;
        }else{
            //printf("%d %d\n", linha, coluna);
            resposta[linha][coluna] = -1;  
        }   // -1 = bomba
    }
    
    /*for (i = 0; i<nlinhas; i++){
        for (j = 0; j< ncolunas; j++ ){
            printf("%i ", resposta[i][j]);
        }
        printf("\n");
    }*/

    printatabuleiro (nlinhas, ncolunas, resposta, matriz);    
}

void medio (char jogador [MAX]){//
    int nlinhas = 16, ncolunas = 16;
    // -1 = bomba
    int nbombas = 40, linha, coluna, i, j;
    int resposta[nlinhas][ncolunas], matriz[nlinhas][ncolunas];
    srand(time(NULL));

    for (i = 0; i< nlinhas; i++){
        for (j = 0; j< ncolunas; j++ ){
            matriz[i][j] = 1;
            resposta[i][j] = 0;
        }
    }

    for ( i = 0; i<nbombas; i++){
        linha = rand() % nlinhas;
        coluna = rand() % ncolunas;
        if(resposta[linha][coluna] == -1){//se numeros ja foram
            i --;
        }else{
            //printf("%d %d\n", linha, coluna);
            resposta[linha][coluna] = -1;  
        }   // -1 = bomba
    }

    printatabuleiro (nlinhas, ncolunas, resposta, matriz);
}
void dificil (char jogador [MAX]){
    int nlinhas = 16, ncolunas = 28;
    // -1 = bomba
    int nbombas = 95, linha, coluna, i, j;
    int resposta[nlinhas][ncolunas], matriz[nlinhas][ncolunas];
    srand(time(NULL));

    for (i = 0; i< nlinhas; i++){
        for (j = 0; j< ncolunas; j++ ){
            matriz[i][j] = 1;
            resposta[i][j] = 0;
        }
    }

    for ( i = 0; i<nbombas; i++){
        linha = rand() % nlinhas;
        coluna = rand() % ncolunas;
        if(resposta[linha][coluna] == -1){//se numeros ja foram
            i --;
        }else{
            //printf("%d %d\n", linha, coluna);
            resposta[linha][coluna] = -1;  
        }   // -1 = bomba
    }

    printatabuleiro (nlinhas, ncolunas, resposta, matriz);
}
void personalizado (char jogador [MAX]){
    int nlinhas, ncolunas;
    int nbombas, linha, coluna, i, j;
    int ** resposta, ** matriz;
    srand(time(NULL));
    
    //Conseguindo valores de tamanhos e bombas
    printf("\nDigite quantas linhas voce deseja, %s: ", jogador);
    scanf("%i", &nlinhas);
    if(nlinhas <= 0){ //Verificando se é um numero válido
        do{
            printf("\nDigite um valor valido: ");
            scanf("%i", &nlinhas);
        }while(nlinhas <= 0);
    }

    printf("\nDigite quantas colunas voce deseja(max 28): " );
    scanf("%i", &ncolunas);
    if(ncolunas>28 || ncolunas <= 0){//Verificando se é um numero válido
        do{
            printf("\nDigite um valor valido: ");
            scanf("%i", &ncolunas);
        }while(ncolunas>28 || ncolunas < 0);
    }

    printf("\nDigite quantas bombas voce deseja: ");
    scanf("%i", &nbombas);
    if(nbombas <= 0){ //Verificando se é um numero válido
        do{
            printf("\nDigite um valor valido: ");
            scanf("%i", &nlinhas);
        }while(nlinhas <= 0);
    }

    //Alocando memoria para as matrizes do tabuleiro
    matriz = (int **) malloc(sizeof(int) * nlinhas * ncolunas);
    resposta = (int **) malloc(sizeof(int) * nlinhas * ncolunas);

}

void printacabecalho(int ncoluna){
    printf("   ");
    for(int l = 1; l <= ncoluna; l++){
        if(l<10) printf("  %d   ",l);
        else printf(" %d %d  ", l/10, l%10);
    }
    printf("\n   ");
    for(int k = 0; k < ncoluna; k++){
        printf("%c%c%c%c%c ", 196, 196, 196, 196, 196);
    }
    printf("\n");
}

void printaespaco(int ncoluna){
    printf("\n   ");
    for(int k = 0; k < ncoluna; k++){
        printf("%c%c%c%c%c ", 196, 196, 196, 196, 196);
    }
    printf("\n");
}

void conteudocasa(int nlinha, int ncoluna, int tabuleiro[nlinha][ncoluna], int tabuleirodescoberto[nlinha][ncoluna], int linhaatual, int colunaatual){
    if(tabuleirodescoberto[linhaatual][colunaatual] == 1){
        switch (tabuleiro[linhaatual][colunaatual]){
        case -1:
            printf("  X  ");
            break;
        case 0:
            printf("%c%c%c%c%c", 176, 176, 176, 176, 176);
            break;
        default:
            break;
        }
    }
    else{
        printf("%c%c%c%c%c", 178, 178, 178, 178, 178, 178);
    }
}

void printatabuleiro(int nlinha, int ncoluna, int tabuleiro[nlinha][ncoluna], int tabuleirodescoberto[nlinha][ncoluna]){
    printacabecalho(ncoluna);
    for(int i = 0; i < nlinha; i++){
        printf("%c |", (i + 65));
        for(int j = 0; j < ncoluna; j++){
            conteudocasa(nlinha, ncoluna, tabuleiro, tabuleirodescoberto, i, j);
            printf("|");
        }
        printaespaco(ncoluna);
    }
}