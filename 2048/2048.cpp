/*
Jogo 2048
Início em 20/08/2021

*/
// string a;
// int *a = new int[30];
// delete a;
// cin >> a;
// cout << nome;

/*USADO PARA ALEATORIO:
    
    srand(time(NULL));
    while(i <= rand() % tamanho) {
        fgets(linha, sizeof(linha), arquivo);
        i++;

*/

#include <iostream>
#include <time.h> 
#include <conio.h>

using namespace std;

//declarando funções usadas:
int joga(int tamanho, int **tabuleiro);
int a(int tamanho, int **tabuleiro);
int w(int tamanho, int **tabuleiro);
int s(int tamanho, int **tabuleiro);
int d(int tamanho, int **tabuleiro);
int preencheInicial(int tamanho, int **tabuleiro);
int preencheNovo(int tamanho, int **tabuleiro);
int contaVazios(int tamanho, int **tabuleiro);


int main(){
    string nome;
    int tamanho;
    srand (time(NULL));

    cout << "______________________________\n";
    cout << "|                            |\n";
    cout << "|          Dois Mil          |\n";
    cout << "|             e              |\n";
    cout << "|      Quarenta e Oito       |\n";
    cout << "|                            |\n";
    cout << "|____________________________|\n";
    cout << "             by Crala And Victro";
    
    cout << "Digite seu nome: ";
    cin >> nome;
    cout << "Puta nome merda né? Mas vamos lá\n";
    cout << "Escolha um tamanho de tabuleiro (Entre 4 e 8): ";
    cin >> tamanho;
    while(tamanho < 4 || tamanho > 8){
        cout << "Escolhe direito né animal: \n";
        cout << "Escolha um tamanho de tabuleiro (Entre 4 e 8): ";
        cin >> tamanho;
    }
    
    //ALOCA A MATRIZ 
    int **tabuleiro = new int*[tamanho];
    for(int i = 0; i < tamanho; i++){
        tabuleiro[i] = new int[tamanho];
    }

    for(int i=0; i < tamanho; i++){
        for(int j=0; j < tamanho; j++){
            tabuleiro[i][j] = 0;
        }
    }

    preencheInicial(tamanho, tabuleiro);
    joga(tamanho, tabuleiro);

    for(int i = 0; i < tamanho; i ++){
        delete[] tabuleiro[i];
    }
    delete[] tabuleiro;
    return 0;
}

int joga(int tamanho, int **tabuleiro){
    char direcao =  'a';
    int jogando = 1;
    while(jogando){
        cout << "Digite uma direção (w, a, s, d):";
        cin >> direcao;

        switch (direcao){
            case 'w': 
                w(tamanho, tabuleiro); //cima - linha -1
                preencheNovo(tamanho, tabuleiro);
                break;
            case 'a': 
                a(tamanho, tabuleiro); //direita - coluna +1
                preencheNovo(tamanho, tabuleiro);
                break;
            case 's': 
                s(tamanho, tabuleiro); //baixo - linha +1
                preencheNovo(tamanho, tabuleiro);
                break;
            case 'd': 
                d(tamanho, tabuleiro); //esquerda - coluna -1
                preencheNovo(tamanho, tabuleiro);
                break;
            default:  
                cout << "digite uma direção válida";
                return 0;
        }

        
    }
       
}

int w(int tamanho, int **tabuleiro){
    for(int i=tamanho-1; i >= 0; i--){
        for(int j=tamanho-1; j >= 0; j--){
            if tabuleiro[i][j] == tabuleiro[i-1][j]{
                tabuleiro[i][j] = tabuleiro[i][j] * 2;
                tabuleiro[i-1][j] = 0;
            }
        }
    }
}

int a(int tamanho, int **tabuleiro){
    
}

int s(int tamanho, int **tabuleiro){
    
}

int d(int tamanho, int **tabuleiro){
    
}

int preencheInicial(int tamanho, int **tabuleiro){
    int i, j;
    int novo = rand() % contaVazios(tamanho, tabuleiro) + 1;
    int pos = 0;
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            if(tabuleiro[i][j] == 0){
                pos++;
            }
            if(pos == novo){
                break;
            }
        }
        if(pos == novo){
            break;
        }
    } 
    tabuleiro[i][j] = 2;
}

int preencheNovo(int tamanho, int **tabuleiro){
    int i, j;
    int novo = rand() % contaVazios(tamanho, tabuleiro) + 1;
    int pos = 0;
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            if(tabuleiro[i][j] == 0){
                pos++;
            }
            if(pos == novo){
                break;
            }
        }
        if(pos == novo){
            break;
        }
    } 
    
    int numero = rand() % 10 + 1;
    if(numero < 8){
        tabuleiro[i][j] = 2;
    }
    else{
        tabuleiro[i][j] = 4;
    }
    
}

int contaVazios(int tamanho, int **tabuleiro){
    int vazios = 0;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(tabuleiro[i][j] == 0){
                vazios++;
            }
        }
    } 
    return vazios;
}

int imprime(int tamanho, int **tabuleiro){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            cout << tamanho[i][j];
        }
    } 
}