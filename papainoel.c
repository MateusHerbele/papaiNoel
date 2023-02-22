#include <stdio.h>
#include <stdlib.h>

// Estrutura do presente
struct presente{
        int peso;
        int valor;
        int indice; // precisa disso para a impressão final ser a pedida no trabalaho
        };

// função que soma o peso dos presentes
int somaPeso(struct presente* presentes, int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        soma += presentes[i].peso;
    }
    return soma;
}
// função que soma o valor sentimental dos presentes
int somaValor(struct presente* presentes, int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        soma += presentes[i].valor;
    }
    return soma;
}
// função que faz a análise dos elementos do vetor binário gerado na função conjuntosPsv e transforma nos valores dos presentes
// em seguida já faz a soma do peso e do valor sentimental dos presentes e compara com o peso máximo que o papai noel aguenta
// assim se consegue o maior vallor sentimental dos presentes que o papai noel consegue levar
void printVetor(int vetor[], struct presente* presentes, int n, int p_max, int* i_max, int* maior, struct presente* vetorFinal, struct presente* vetorTemp) {
    int j = 0;
    for(int i = 0; i < n; i++){
        if(vetor[i] == 1){
            vetorTemp[j].peso = presentes[i].peso;
            vetorTemp[j].valor = presentes[i].valor;
            vetorTemp[j].indice = presentes[i].indice;
            j++; // j é o tamanho do vetorTemp
        }
    }
            if(somaPeso(vetorTemp, j) <= p_max){
            if(somaValor(vetorTemp, j) > *maior){
                *maior = somaValor(vetorTemp, j);
                *i_max = j; // i_max é o tamanho do vetorFinal
                for(int k = 0; k < j; k++){
                    vetorFinal[k].peso = vetorTemp[k].peso;
                    vetorFinal[k].valor = vetorTemp[k].valor;
                    vetorFinal[k].indice = vetorTemp[k].indice;
                }
            }
        }
}
//função que gera os conjuntos possíveis de presentes que o papai noel pode levar através do backtracking do conjuntos binários possíveis
void conjuntosPsv(int* vetor, struct presente* presentes, int i, int n, int p_max, int* i_max, int* maior, struct presente* vetosPsb, struct presente* vetorTemp){
    if(i == n){
        printVetor(vetor, presentes, n, p_max, i_max, maior, vetosPsb, vetorTemp);
        return;
    }
    vetor[i] = 0;
    conjuntosPsv(vetor,presentes, i+1, n, p_max, i_max, maior, vetosPsb, vetorTemp);
    vetor[i] = 1;
    conjuntosPsv(vetor, presentes, i+1, n, p_max, i_max, maior, vetosPsb, vetorTemp);

}
// função que adiciona o peso e o valor sentimental dos presentes
void addPesoValor(struct presente* presentes, int n){
    for(int i = 0; i < n; i++){
       // printf("Digite o valor sentimental do presente %d: ", i+1);
        scanf("%d", &presentes[i].valor);
        //printf("Digite o peso do presente %d: ", i+1);
        scanf("%d", &presentes[i].peso);
        presentes[i].indice = i+1;// indices dos presentes
    }
}
// função que imprime o maior conjunto de presentes que o papai noel consegue levar
// tudo fica armazenado no endereço que o vetorFinal aponta
void maiorConjunto(struct presente* vetorFinal, int n){
    int total = 0;
    //printf("O maior conjunto de presentes que pode ser levado é: \n");
    printf("presente: ");
    for(int i = 0; i < n; i++){
        printf(" %d ", vetorFinal[i].indice);
        //printf("valor:%d ", vetorFinal[i].valor);
        //printf("peso: %d \n", vetorFinal[i].peso);
        total = total + vetorFinal[i].valor;
    }
    printf("\nO valor total dos valores sentimentais dos presentes é: %d \n", total);
}

int main(){
    //declaração de variáveis
    int n, p_max; // p_max -> peso máximo
    int* i_max; // tamanho do vetorFinal
    int max = 0;
    i_max = &max;
    int maior = 0;
    int *p_maior;
    p_maior = &maior;

    //printf("Digite o número de presentes existentes: ");
    scanf("%d", &n);
    //printf("Digite o peso máximo que é aguentado: ");
    scanf("%d", &p_max);
   
   // alocação dinâmica de memória
    struct presente* p_presentes;
        p_presentes = malloc(n * sizeof(struct presente));  
        if(p_presentes == NULL){
            printf("Memória insuficiente");
            exit(1);
        }
    int *vetorBinario;
    ;   vetorBinario = malloc(n * sizeof(int));
        if(vetorBinario == NULL){
            printf("Memória insuficiente");
            exit(1);
        }
    struct presente* p_vetorFinal;
        p_vetorFinal = malloc(n * sizeof(struct presente));
        if(p_vetorFinal == NULL){
            printf("Memória insuficiente");
            exit(1);
        }
    struct presente* p_vetorTemp;
        p_vetorTemp = malloc(n * sizeof(struct presente));
        if(p_vetorTemp == NULL){
            printf("Memória insuficiente");
            exit(1);
        }

    addPesoValor(p_presentes, n);

    conjuntosPsv(vetorBinario, p_presentes, 0, n, p_max, i_max, p_maior, p_vetorFinal, p_vetorTemp);
    maiorConjunto(p_vetorFinal, *i_max);

    //liberação da memória
    free(p_presentes);
    free(vetorBinario);
    free(p_vetorFinal);
    free(p_vetorTemp);


    return 0;
}