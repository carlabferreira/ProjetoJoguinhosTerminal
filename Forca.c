/* ---------
Carla Beatriz Ferreira
2020.04.28

Descrição:
Jogo da forca em C com menu para escolher o tipo de jogo
------------- */
//Incuindo as bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX 20

//#include <dos.h>

//Declaração das funções:
void menu();
void multiplayer();
void pessoa_pc();
void AdicionarPalavras();

//------

int main(){
  //MENU
  int opcao;

  printf("\n----------------------------------");
  printf("\n|  BEM-VINDO AO JOGO DE FORCA    |");
  printf("\n| Escolha sua opcao:             |");
  printf("\n| (1) Multiplayer local          |");
  printf("\n| (2) Contra a maquina           |");
  printf("\n| (3) Adicionar palavras ao jogo |");
  printf("\n| (4) Sair                       |");
  printf("\n----------------------------------");
  printf("\n             by Carla and Victor | ");

  printf("\n\n->");
  scanf("%i", &opcao);
  //printf("\nA opcao escolhida foi %i", opcao);

  switch (opcao){
  case 1:
    multiplayer();
    break;
  case 2:
    pessoa_pc();
    break;
  case 3:
    AdicionarPalavras();
    break;
  case 4:
    printf("Saindo...\n");
    system("pause");
    break;
  default:
    printf("Opcao invalida, saindo...\n");
    system("pause");
  }

  return (0);
}

//---------------

void multiplayer(){ 
  char Jogador1[MAX], Jogador2[MAX], palavra[MAX], letra[1];
  char *preencher;
  int certo = 0;

  int tamanho, tentativas;
  system("cls"); //Limpa a tela, mas funciona só no windows

  //Introdução
  printf("\nNome do Primeiro Jogador: ");
  scanf("%s", Jogador1);
  printf("\nNome do Segundo Jogador: ");
  scanf("%s", Jogador2);
  printf("\n%s, digite a palavra a ser acertada (sem espacos): ", Jogador1);
  scanf("%s", palavra);
  printf("\nA palavra foi %s", palavra);
  printf("\nDigite o numero de tentativas (recomendado = 10): ");
  scanf("%i", &tentativas);
  tamanho = strlen(palavra);
  scanf("%c", letra);
  system("cls");

  preencher = malloc(sizeof(char) * tamanho);

  //Execução das tentativas
  for (int i = 0; i < (tamanho); i++){
    preencher[i] = '-';
  }

  while (tentativas > 0 && certo != tamanho){
    system("cls");
    printf("\n");
    for (int i = 0; i < (tamanho); i++){
      printf("%c", preencher[i]);
    }
    printf("\nDigite a letra que voce quer chutar: ");
    fflush(stdin);
    scanf("%c", letra);
    for (int i = 0; i < tamanho; i++){
      if (palavra[i] == letra[0])
      {
        preencher[i] = letra[0];
        tentativas = tentativas +1;
        certo ++;
      }
    }
    if (certo == tamanho){
      printf("\nPARABENS, VOCE VENCEU!!!");
      printf("\nA palavra era \"");
      printf("%s\"", palavra);
      break;
    }
    tentativas = tentativas - 1;
    printf("\nrestam %d tentativas", tentativas);
  }
  free(preencher);
}

//---------------
void pessoa_pc(){  
    FILE* fptr = fopen("palavras2.txt", "r");
    FILE* fp = fopen("palavras2.txt", "r");
    if(fptr == NULL) {
        fprintf(stderr, "Erro ao abrir o palavras2.txt.");
    }
    int i = 1, linhas = 0, certo = 0, tamanho, tentativas = 10, chutes = 0, repetido;
    char linha[50], linha2[50];
    char c, letra[1], chutadas[50],  *preencher;

    for(i = 0; i < 50; i++){
        chutadas[i] = '1';
    }

    while(fgets(linha2, sizeof(linha2), fp) != NULL) {
        linhas++;
    }

    srand(time(NULL));
    while(i <= rand() % linhas) {
        fgets(linha, sizeof(linha), fptr);
        i++;
    }

    //------------------------------------------
    
    tamanho = strlen(linha);
    tamanho --;
    linha[tamanho] = ' ';
    printf("\nTamanho da palavra: %d", tamanho);
    printf("\nDigite o numero de tentativas (recomendado = 10): ");
    scanf("%i", &tentativas);

    for (i= 0; i < (tamanho); i++) linha[i] = tolower(linha[i]);

    preencher = malloc(sizeof(char) * tamanho);

    
    for (i = 0; i < (tamanho); i++) preencher[i] = '-';
    //for (i = 0; i < (tamanho); i++) printf("%c", preencher[i]);
    
    while (tentativas > 0 && certo != tamanho){
        //system("cls");
        printf("\nrestam %d tentativas\n", tentativas);
        for (i = 0; i < (tamanho); i++) printf("%c", preencher[i]);
        
        printf("\nDigite a letra que voce quer chutar: ");
        fflush(stdin);
        scanf("%c", letra);
        letra[0] = tolower(letra[0]);

        for(i = 0; i <= chutes; i++){
            if(letra[0] == chutadas[i]){
                repetido = 1;
                while(repetido){
                    //system("cls");
                    printf("\nrestam %d tentativas\n", tentativas);
                    for (i = 0; i < (tamanho); i++) printf("%c", preencher[i]);
                    printf("\nAlguma que nao foi ne imbecil.\nDigite a letra que voce quer chutar: ");
                    fflush(stdin);
                    scanf("%c", letra);
                    repetido = 0;
                    for(i = 0; i <= chutes; i++) if(letra[0] == chutadas[i]) repetido = 1;
                }
            }
        }
        chutadas[chutes] = letra[0];
        chutes++;

        for (int i = 0; i < tamanho; i++){
            if (linha[i] == letra[0]){
                preencher[i] = letra[0];
                certo ++;
            }
        }

        for (int i = 0; i < tamanho; i++){
            if (linha[i] == letra[0]){
                tentativas = tentativas +1;
                break;
            }
        }
        printf("%d,%d", certo, tamanho);
        if (certo == tamanho){
            printf("\nPARABENS, VOCE VENCEU!!!");
            printf("\nA palavra era \" %s\"", linha);
            break;
        }
        tentativas = tentativas - 1;
    }
     free(preencher);
    /*
    printf("\nTecle 1 para parar ou outro para continuar: ");
    printf("\nO numero de vitorias foi: %d", vitorias);
    printf("\nO numero de derrotas foi: %d", derrotas);*/
    fclose(fptr);
    fclose(fp);
}
//----------------
void AdicionarPalavras(){
  char palavra [MAX];
  FILE *fptr;

  fptr = fopen("palavras.txt", "a");;
  //Abrindo o aquivo 
  if (fptr == NULL){
        printf("Erro ao abrir arquivo palavras.txt\n");
        exit(1);
  }
  printf("\nQual palavra deseja adicionar ao banco de dados?\n");
  fflush(stdin);
  scanf("%s", palavra);
  fprintf(fptr, "\n%s", palavra);
  fclose(fptr);
}
