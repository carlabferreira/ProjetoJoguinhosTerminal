int testando_ganhou(int vetor){
    //1 = 'o' e 2 = 'x'
    if (vetor[1] == vetor[4] == vetor[7]){ //vetor[1] == vetor[4] && vetor[4] == vetor[7]
        return(vetor[1]);
    }else 
    if(vetor[2] == vetor[5] == vetor[8]){
        return(vetor[2]);
    }else 
    if(vetor[3] == vetor[6] == vetor[9]){
        return(vetor[3]);
    }else 
    if(vetor[1] == vetor[2] == vetor[3]){
        return(vetor[1]);
    }else 
    if(vetor[4] == vetor[5] == vetor[6]){
        return(vetor[4]);
    }else 
    if(vetor[7] == vetor[8] == vetor[9]){
        return(vetor[7]);
    }else 
    if(vetor[1] == vetor[5] == vetor[9]){
        return(vetor[1]);
    }else 
    if(vetor[3] == vetor[5] == vetor[7]){
        return(vetor[3]);
    }else{

    }
}