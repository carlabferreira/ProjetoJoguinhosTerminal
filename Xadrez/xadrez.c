#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 30

/* Peças disponiveis
* 0 - Nada
* p - Peao
* t - Torre
* c - CAVALO
* b - Bisbo
* r - rei 
* d - dama
*/

/* Cores
* b - branco 
* p - preto
*/

/* Funções necessárias de jogabilidade padrao
 - se tá em cheque (pode ser no inicio da rodada)
 - se vai entrar em cheque como movimento

*/

/*Passant possivel
    variavel que vai guardar a posição do peao vuneravel
*/

/*Roque
    roque direiro branco - 
    roque direiro preto - 
    roque esquerdo branco - 
    roque esquerdo preto - 

    se movimentar rei - ambos roques não possiveis
*/

/* MOVIMNENTOS NAO PADROES
 - roque do rei
 - primeiro mov peao
 - En passant
 - Promoção do Peão

*/

//Declarações das funções:
int movPeao ();
int movCavalo ();
int jogando ();
struct Peca{
    char tipo;
    char cor; 
};

struct Posicao{
    int linha;
    int coluna;
};

int main(){
    //Menu
    char jogador1[MAX];
    char jogador2[MAX];
    int opcao = 0;

    printf("Insira o nome do primeiro jogador:");
    scanf("%s", jogador1);
    printf("Insira o nome do segundo jogador:");
    scanf("%s", jogador2);
    system("cls");


    printf("Quem jogará de brancas?\n1- %s\n2- %s\n3- Aleatório",jogador1, jogador2);
    scanf("%i", &opcao);
    while(opcao != 1 && opcao != 2 && opcao != 3){
        printf("Ta lendo com a bunda porra?\nDigita direito\n");
        printf("Quem jogará de brancas?\n1- %s\n2- %s\n3- Aleatório",jogador1, jogador2);
        scanf("%i", &opcao);

    }


    switch(opcao){
        case 1:
            jogando(jogador1, jogador2);
            break;
        case 2:
            jogando(jogador2, jogador1);
            break;
        case 3:
            srand(time(NULL));
            if(rand() % 2 == 1) jogando(jogador1, jogador2);
            else jogando(jogador2, jogador1);
            break;
        default:
            printf("Como diabos você chegou nessa parte do programa?????\nIsso nem deveria ser possível");
    }
    return (0);

    //movPeao (posicao, Peca.cor)
    
}




/*variavel posição:
    pos = {linha, coluna}
    na vida real = A2
    no programa = {1, 2}
*/
int *movPeao (Posicao pos, char cor){
    //só move 1 pra frente
    //primeiro mov permite mover 2
    //captura em diagonal
    /*    
    if (cor == 'b'){ //muda apenas a coluna
        pos[2] = pos[2]--;
    }
    else if (cor == 'p'){
        pos[2] = pos++;
    } 
*/


}

int movCavalo (){
    //move e captura em 'L'
}

int movTorre (){
    //move e captura reto
}

int movRei (){
    //move e captura 1 casa em cada direção
    
}

int movRainha (){
    //move e captura em todas as direções
    
}

int movBispo (){
    //move e captura diagonais
    
}