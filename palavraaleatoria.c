
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE* arquivo = fopen("palavras.txt", "r");
    FILE* arquivo2 = fopen("palavras.txt", "r");
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }
    int i = 1, tamanho = 0;
    char linha[1024], linha2[1024];
    char c, letra = '\n';
    
    while(fgets(linha2, sizeof(linha2), arquivo2) != NULL) {
        tamanho++;
    }

    srand(time(NULL));
    while(i <= rand() % tamanho) {
        fgets(linha, sizeof(linha), arquivo);
        i++;
    }

    printf("%s", linha);
    fclose(arquivo);

    return 0;
}