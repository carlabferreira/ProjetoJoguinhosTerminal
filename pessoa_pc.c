  
  
void pessoa_pc(){  
    //gerando semente para numeros aleatorios
    time_t t ;
    srand (( unsigned ) time (&t ) );

    //Declaração de variaveis
    int x, linhas = 0;
    char palavra[MAX], c;
    char * palavras;
    FILE *fptr;

    fptr = fopen("palavras.txt", "r");;

    //Abrindo o arquivo
    if (fptr == NULL){
        printf("Erro ao abrir arquivo palavras.txt\n");
        exit(1);
    }
    //descobrindo quantas palavras o aquivo tem pelas linhas
    while(fread (&c, sizeof(char), 1, fptr)) {
        if(c == '\n') {
            linhas++;
        }
    } 
    printf("\nLinhas: %i\n",linhas + 1);
    palavras = malloc (sizeof(char) * (linhas+1));

    //lendo a palvra certa no aquivo
    x = rand() % linhas;
    //printf("x = %d", x);
    fscanf ( fptr , "%s", palavras);
    //palavra[0] = palavras[x];
    printf("\n A palavra escolhida foi %s", palavra);
  

  
    /*
    while(continuar!=1){
        x = rand() % tamarquivo;
        fscanf ( fptr , " %s", palavras) ;
        palavra = palavras[x];
        printf("\n");
        for (int i = 0; i < (tamanho); i++){
        printf("%c", preencher[i]);
        }
        tamanho = strlen(palavra);
        preencher = malloc(sizeof(char) * tamanho);
        //printf("\nA palavra possui %i letras\n", tamanho);

        for (int i=0; i<tamanho; i++);{
        preencher[i] = '-' ;
        }

        //tirando o numero de espacos restantes
        letra[0] = ' ';
        for (int i = 0; i < (tamanho); i++) printf("%c", preencher[i]);
        //posi = find (palavra==letra);
        for (int i = 0; i < tamanho; i++){
            if (palavra[i] == letra[0]){
                preencher[i] = letra[0];
            }
        }
        while (1){
        //posi = find (palavra==letra);

        //checando se a letra esta na palavra
        printf("\nDigite a letra que voce quer chutar: ");
        fflush(stdin);
        scanf("%c", letra);
        for (int i = 0; i < tamanho; i++){
            if (palavra[i] == letra[0]){
            preencher[i] = letra[0];
            tentativas = tentativas +1;
            certo ++;
            }
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
    printf("\nTecle 1 para parar ou outro para continuar: ");
    printf("\nO numero de vitorias foi: %d", vitorias);
    printf("\nO numero de derrotas foi: %d", derrotas);
    fclose(fptr);*/
}