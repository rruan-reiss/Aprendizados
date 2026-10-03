/*Desafio de Revisão: Comparador de Formas
Declare um vetor de 5 inteiros. Implemente duas funções para somar apenas os valores pares:
int somaParesIndices(int v[], int n): usando obrigatoriamente colchetes [].
int somaParesPonteiro(int *p, int n): usando obrigatoriamente ponteiro * e sem colchetes.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5

/* Prototipos */
int somaParesIndices(int v[], int n);
int somaParesPonteiro(int *p, int n);
int posicaoDoMaior(int *p, int n);
void mostraEnderecos(int *p, int n);

int main()
{
    int i;
    int vetor [MAX];
    int somaPIndice, somaPPonteiros;
    int maior;

    setlocale(LC_ALL, "portuguese");

    for (i=0; i<5; i++){

        printf("%d° numero: ", i+1);
        scanf("%d", &vetor[i]);
    }

    somaPIndice = somaParesIndices(vetor, MAX);
    somaPPonteiros = somaParesPonteiro(vetor, MAX);

    printf("\n");
    mostraEnderecos(vetor, MAX);
    maior = posicaoDoMaior(vetor, MAX);

    printf("\nSoma pares usando vetor: %d\n", somaPIndice);
    printf("Soma pares usando ponteiros: %d\n", somaPPonteiros);
    printf("\nPosição do maior: %d\n", maior);

    return 0;
}

int somaParesIndices(int v[], int n){

    int i;
    int somaI = 0;

    for(i=0; i<n; i++){

        if((v[i]%2) == 0){

            somaI += v[i];
        }
    }
    return somaI;
}

int somaParesPonteiro(int *p, int n){

    int i;
    int somaP = 0;

    for(i=0; i<n; i++){
        if((*p%2) == 0){

            somaP += *p;
        }
        p++;
    }
    return somaP;
}

int posicaoDoMaior(int *p, int n){
    int i;
    int maior=*p;
    int maiorIndice=0;

    for(i=0; i<n; i++){

        if(maior<*p){

            maior = *p;
            maiorIndice = i;
        }
        p++;
    }
    return maiorIndice;
}

void mostraEnderecos(int *p, int n){
    int i;

    for(i=0; i<n; i++){
    printf("Posição [%d] -> endereço %p valor %d\n", i, p, *p);
    p++;
    }
}


