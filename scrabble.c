/*Objetivos:
Criar o jogo scrabble (sem necessidade de verificar se a palavra existe)

Em compute_score() , seu programa deve calcular, usando o array POINTS , e retornar a pontuação para o argumento string.
Os caracteres que não são letras devem receber zero pontos, e as letras maiúsculas e minúsculas devem receber os mesmos
valores de pontos.


*/
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(string word)
{
    int score = 0;
    //Compute and return score for string
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //para transformar o indice numero de ascii para alfabetico (a ser 0, b ser 1 e etc) p aplicar a formula
        if (isupper(word[i]))//se maiusuclo
        {
            word[i] = word[i] - 65; //65 = 'A' //cada letra tera sua posição mudada para o correspondente no alfaveto (A = 0 ...)
        }
        else if (islower(word[i]))//se minusculo
        {
            word[i] = word[i] - 97; //97 = 'a'
        }
        score += POINTS[(int) word[i]];
    }

    return (score);
}
