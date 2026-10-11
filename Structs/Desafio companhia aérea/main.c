#include <stdio.h>
#include <string.h>

#define MAXVOOS 2
#define MAX_NOME 20

/*Estrutura*/
typedef struct{
    int numVoo;
    char origem[20];
    char destino[20];
} Voo;

/*Protótipos*/
Voo cadastrarVoo(int ordem);

int main(){
    int i;
    Voo voo[MAXVOOS];

    printf("|Cadastro de Voos|\n");
    for(i=0; i<MAXVOOS; i++){
        voo[i] = cadastrarVoo(i+1);
    }

    return 0;
}

Voo cadastrarVoo(int ordem){
    Voo v;

    printf("Voo n%d\n", ordem);
    printf("Numero do voo: ");
    scanf("%d", &v.numVoo);
    getchar();
    printf("Origem: ");
    fgets(v.origem, MAX_NOME, stdin);
    v.origem[strcspn(v.origem, "\n")] = '\0'; /*usado para substituir a quebra de linha por caracter nulo*/
    printf("Destino: ");
    fgets(v.destino, MAX_NOME, stdin);
    v.destino[strcspn(v.destino, "\n")] = '\0';

    return v;
}