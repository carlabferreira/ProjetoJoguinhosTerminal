  
  
void pessoa_pc(){  
    FILE* fptr = fopen("palavras2.txt", "r");
    FILE* fp = fopen("palavras2.txt", "r");
    if(fptr == NULL) {
        fprintf(stderr, "Erro ao abrir o palavras2.txt.");
    }
    int i = 1, linhas = 0, certo = 0, tamanho, tentativas = 10;
    char linha[50], linha2[50];
    char c, letra[1], chutadas[50],  *preencher;

    while(fgets(linha2, sizeof(linha2), fp) != NULL) {
        linhas++;
    }

    srand(time(NULL));
    while(i <= rand() % linhas) {
        fgets(linha, sizeof(linha), fptr);
        i++;
    }
    
    printf("%s", linha);

    //------------------------------------------
    
    tamanho = strlen(linha);
    tamanho --;
    printf("\n tamanho: %d", tamanho);

    for (i= 0; i < (tamanho); i++) linha[i] = tolower(linha[i]);

    preencher = malloc(sizeof(char) * tamanho);

    
    for (i = 0; i < (tamanho); i++) preencher[i] = '-';
    //for (i = 0; i < (tamanho); i++) printf("%c", preencher[i]);
    
    while (tentativas > 0 && certo != tamanho){
        //system("cls");
        printf("\n");
        for (i = 0; i < (tamanho); i++) printf("%c", preencher[i]);
        
        printf("\nDigite a letra que voce quer chutar: ");
        fflush(stdin);
        scanf("%c", letra);
        letra[0] = tolower(letra[0]);
        chutadas[] = letra[0];
        for (int i = 0; i < tamanho; i++){
            if (linha[i] == letra[0])
            {
                preencher[i] = letra[0];
                tentativas = tentativas +1;
                certo ++;
            }
        }
        printf("%d %d", certo, tamanho);
        if (certo == tamanho){
            printf("\nPARABENS, VOCE VENCEU!!!");
            printf("\nA palavra era \"");
            printf("%s\"", linha);
            break;
        }
        tentativas = tentativas - 1;
        printf("\nrestam %d tentativas", tentativas);
    }
     free(preencher);
    /*
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
    printf("\nO numero de derrotas foi: %d", derrotas);*/
    fclose(fptr);
    fclose(fp);
}