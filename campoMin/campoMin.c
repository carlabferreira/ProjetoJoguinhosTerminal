#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void facil (void);
void medio (void);
void dificil (void);
void personalizado (void);

void printaespaco(int ncoluna);
void printatabuleiro(int nlinha, int ncoluna, int matriz[nlinha][ncoluna], int resposta[nlinha][ncoluna]);
void conteudocasa(int nlinha, int ncoluna, int tabuleiro[nlinha][ncoluna], int tabuleirodescoberto[nlinha][ncoluna], int linhaatual, int colunaatual);
void printatabuleiro(int nlinha, int ncoluna, int tabuleiro[nlinha][ncoluna], int tabuleirodescoberto[nlinha][ncoluna]);


int main(){
    int opcao;

    printf("\n----------------------------------");
    printf("\n|   BEM-VINDO AO CAMPO MINADO    |");
    printf("\n| Escolha sua opcao:             |");
    printf("\n| (1) Facil                      |");
    printf("\n| (2) Medio                      |");
    printf("\n| (3) Dificil                    |");
    printf("\n| (4) Personalizado              |");
    printf("\n| (5) Sair                       |");
    printf("\n----------------------------------");
    printf("\n             by Carla and Victor | ");

    printf("\n\n->");
    scanf("%i", &opcao);
    //printf("\nA opcao escolhida foi %i", opcao);

    switch (opcao){
    case 1:
        facil();
        break;
    case 2:
        medio();
        break;
    case 3:
        dificil();
        break;
    case 4:
        personalizado();
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

void facil (void){ // 9 x 9
    int nlinhas = 9, ncolunas = 9;
    // -1 = bomba
    int x, nbombas = 10, linha, coluna, i, j;
    int resposta[nlinhas][ncolunas], matriz[nlinhas][ncolunas];
    srand(time(NULL));

    for (i = 0; i< nlinhas; i++){
        for (j = 0; j< ncolunas; j++ ){
            matriz[i][j] = 1;
            resposta[i][j] = 0;
        }
    }

    for ( i = 0; i<nbombas; i++){
        linha = rand() % 9;
        coluna = rand() % 9;
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

    //printatabuleiro (8, 8, matriz, resposta);    
}

void medio (void){//
    int nlinhas = 16, ncolunas = 16;
    // -1 = bomba
    int x, nbombas = 40, linha, coluna, i, j;
    int resposta[nlinhas][ncolunas], matriz[nlinhas][ncolunas];
    srand(time(NULL));

    for (i = 0; i< nlinhas; i++){
        for (j = 0; j< ncolunas; j++ ){
            matriz[i][j] = 1;
            resposta[i][j] = 0;
        }
    }

    for ( i = 0; i<nbombas; i++){
        linha = rand() % 9;
        coluna = rand() % 9;
        if(resposta[linha][coluna] == -1){//se numeros ja foram
            i --;
        }else{
            //printf("%d %d\n", linha, coluna);
            resposta[linha][coluna] = -1;  
        }   // -1 = bomba
    }

}
void dificil (void){

}
void personalizado (void){

}

void printaespaco(int ncoluna){
    printf("\n ");
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
    printaespaco(ncoluna);
    for(int i = 0; i < nlinha; i++){
        printf("|");
        for(int j = 0; j < ncoluna; j++){
            conteudocasa(nlinha, ncoluna, tabuleiro, tabuleirodescoberto, i, j);
            printf("|");
        }
        printaespaco(ncoluna);
    }
}