
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE* arquivo = fopen("palavras.txt", "r");
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }
    int i = 1;
    char linha[1024];
    
    srand(time(NULL));
    while(i <= rand() % 528) {
        fgets(linha, sizeof(linha), arquivo);
        i++;
    }

    printf("%s", linha);
    fclose(arquivo);

    return 0;
}