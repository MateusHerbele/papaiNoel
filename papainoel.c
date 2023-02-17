#include <stdio.h>
#include <stdlib.h>

int somaPeso(int* vp, int n){
    int soma = 0;
    for(int i = 0; i < (n *2); i + 2){
        soma += vp[i];
    }
    return soma;
}

int somaValor(int* vp, int n){
    int soma = 0;
    for(int i = 1; i < (n *2); i + 2){
        soma += vp[i];
    }
    return soma;
}

void vetorAval(int* vp, int n, int i, int p_max, int* vetorPsb){        
    if(somaPeso(vp, n) <= p_max){
        vetorPsb[i] = somaValor(vp, n);
    }

    // int maior = soma[i];
    // int indice = i;
    // for(int j = i+1; j <= i; j++){
    //     if(maior < soma[j]){
    //         maior = soma[j];
    //         indice = j;
    //     }        
    // }
    // return indice;
}

void printVetor(int vetor[], int* vp, int n, int p_max){
    int* vetorTemp = malloc((n*2) * sizeof(int));//melhorar isso aqui pra tod achamada pra n precisar alocar dnv
    for(int i, j = 0; i < n; i + 2){
        if(vetor[i] == 1){
            vetorTemp[j] = vp[i];
            vetorTemp[j+1] = vp[i+1];
            printf("%2d%2d", vp[i], vp[i+1]);
            printf("\n");
            j++;
        }
        vetorAval(vetorTemp, j);
        j = 0;
    }
}

void addPesoValor(int* vp, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o peso do presente %d: ", i+1);
        scanf("%d", &vp[i]);
        printf("Digite o valor sentimental do presente %d: ", i+1);
        scanf("%d", &vp[i+1]);
    }
    
}

void conjuntosPsv(int* vetor, int* vp, int i, int n, int p_max){
    if(i == n){
        printVetor(vetor, vp, n, p_max);
        return;
    }
    vetor[i] = 0;
    conjuntosPsv(vetor,vp, i+1, n, p_max);
    vetor[i] = 1;
    conjuntosPsv(vetor, vp, i+1, n, p_max);

}

int main(){
    int n, p_max;
    int *vp;
    int *vetorBinario;
    
    vp = malloc(2 * n * sizeof(int));    
    vetorBinario = malloc(n * sizeof(int));

    printf("Digite o peso máximo que é aguentado: ");
    scanf("%d", &p_max);
    printf("Digite o número de presentes existentes: ");
    scanf("%d", &n);


    addPesoValor(vp, n);

    conjuntosPsv(vetorBinario, vp, 0, n, p_max);


    return 0;
}