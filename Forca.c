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
#define MAX 20
//#include <dos.h>

//Declaração das funções:
void menu();
void multiplayer();
void pessoa_pc();
void pc_pessoa();
void AdicionarPalavras();

//------

int main(){
  //MENU
  int opcao;

  printf("\n---------------------------------");
  printf("\n|  BEM-VINDO AO JOGO DE FORCA   |");
  printf("\n| Escolha sua opcao:            |");
  printf("\n| (1) Multiplayer local         |");
  printf("\n| (2) Voce contra a maquina     |");
  printf("\n| (3) Maquina contra voce       |");
  printf("\n| (4) Sair                      |");
  printf("\n| (5) Adicionar palavras ao jogo|");
  printf("\n---------------------------------");
  printf("\n                by Carla Ferreira");

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
    pc_pessoa();
    break;
  case 4:
    printf("Saindo...\n");
    system("pause");
    break;
  case 5:
    AdicionarPalavras();
    break;
  default:
    printf("Opcao invalida, saindo...\n");
    system("pause");
  }

  return (0);
}

//---------------

void multiplayer(){ 
  //time_t t ;
  //srand (( unsigned ) time (&t ) );
  char Jogador1[MAX], Jogador2[MAX], palavra[MAX], letra[1];
  char *preencher;
  int certo = 0;

  //preencher deve ser mudado para alocação dinamica
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
  //printf("\nA palavra possui %i letras\n", tamanho);
  //printf("A palavra escolhida foi %s", palavra);
  scanf("%c", letra);
  system("cls");

  preencher = malloc(sizeof(char) * tamanho);

  //Execução das tentativas
  for (int i = 0; i < (tamanho); i++){
    preencher[i] = '-';
  }
  //printf("\n");
  /*for (int i = 0; i < (tamanho); i++)
  {
    printf("%c", preencher[i]);
  }*/
  //printf("\n%s", preencher);

  while (tentativas > 0 && certo != tamanho){
    //printf("\n%s", preencher);
    printf("\n");
    for (int i = 0; i < (tamanho); i++){
      printf("%c", preencher[i]);
    }
    printf("\nDigite a letra que voce quer chutar: ");
    scanf("%c", letra);
    for (int i = 0; i < tamanho; i++){
      if (palavra[i] == letra[0])
      {
        //printf("\n A palavra possui a letra sugerida!");
        preencher[i] = letra[0];
        tentativas = tentativas +1;
        certo ++;
      }
      else
      {
        //printf("A palavra não possui essa letra");
      }
    }
  if (certo == tamanho){
    printf("\nPARABENS, VOCE VENCEU!!!");
    printf("\nA palavra era \"");
    for (int i = 0; i < (tamanho); i++){
      printf("%c", preencher[i]);
    }
    printf("\"");
    break;
  }
  tentativas = tentativas - 1;
  printf("\nrestam %d tentativas", tentativas);
  }
  free(preencher);
}

//---------------

void pessoa_pc(){
  
  /*time_t t ;
  srand (( unsigned ) time (&t ) );

  int continuar = 0, vitorias = 0, derrotas = 0, x, Ntenta = 10, posi, certo=0;
  int tamarquivo, tamanho; //tamanho do arquivo e da palavra
  char palavra[MAX], chute[MAX];
  //Pdispo = leitura de arquivo
  FILE *fptr;
  if ((fptr = fopen("palavras.txt", "r")) == NULL){
    printf("Erro ao abrir arquivo palavras.txt\n");
    exit(1);
  }

  while(continuar!=1){
    x = rand() % tamarquivo;
    palavra = Pdispo(x,:);
    //printf(palavra)
    printf("\n");
    for (int i = 0; i < (tamanho); i++){
      printf("%c", preencher[i]);
    }
    tamanho = strlen(palavra);
    //printf("\nA palavra possui %i letras\n", tamanho);

    for (int i=0; i<tamanho; i++);{
      preencher[i] = '-' ;
    }
    //printf(preencher)
    //tirando o numero de espacos restantes
    chute = ' ';
    posi = find (palavra==chute);
    preencher[posi] = chute;

    while (1){
      printf("\n");
      
      printf ("\n");
      chute = input ('digite a letra que voce quer chutar: ', '%s');
      posi = find (palavra==chute);
      if (length(posi)==0){
        Ntenta--;
        printf("\n");
        printf("essa letra nao esta na palavra");
        printf("Seu numero de tentaivas restantes eh: %d", Ntenta);
      }
      else{
        preencher[posi] = chute;
      }
      //checando se acabou
      if (certo == tamanho){
        printf("\nPARABENS, VOCE VENCEU!!!");
        printf("\nA palavra era \"");
        for (int i = 0; i < (tamanho); i++){
          printf("%c", preencher[i]);
        }
      printf("\"");
      break;
      }
    }
  }
  continuar = input ('tecle 1 para parar ou outro para continuar: ');
  printf("\nO numero de vitorias foi: %d", vitorias);
  printf("\nO numero de derrotas foi: %d", derrotas);
  */
}

//----------------

void pc_pessoa(){

}

//----------------

void AdicionarPalavras(){
}
