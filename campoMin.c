#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void facil (void);
void medio (void);
void dificil (void);
void personalizado (void);
void printatabuleiro(void);

int main()
{
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

    switch (opcao)
    {
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