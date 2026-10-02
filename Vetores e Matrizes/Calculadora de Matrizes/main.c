#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main()

{
    int L = 1, C = 1;

    int i, j, escolha, repetir;
    setlocale(LC_ALL, "Portuguese");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);


    do{
    printf("|CALCULADORA DE MATRIZ|\n\n");
    printf("[1] |    SOMA DE DUAS MATRIZES   |\n\n[2] | DETERMINANTE USANDO SARRUS |\n\n");
    scanf("%d", &escolha);

    if(escolha == 1){
       /* Programa que lê duas matrizes inteiras (tamanho 3 x 4) e obtenha uma terceira matriz resultante da soma das duas primeiras. */


    printf("\n|SOMA DE DUAS MATRIZES|\n\n");

    printf("Quantas LINHAS:\n");
    scanf("%d", &L);

    printf("Quantas COLUNAS:\n");
    scanf("%d", &C);

    int matriz1[L][C], matriz2[L][C], matrizR[L][C];

    // Matriz 1 
    printf("1° MATRIZ\n\n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){

        printf("Digite o numero da coordenada Linha[%d] Coluna[%d]: \n", i+1, j+1);
        scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\nEssa é sua matriz 1: \n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
        printf("|%3d|", matriz1[i][j]);
        }
        printf("\n");
    }

    /* Matriz 2 */
    printf("\n\n2° MATRIZ\n\n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){

        printf("Digite o numero da coordenada Linha[%d] Coluna[%d]: \n", i+1, j+1);
        scanf("%d", &matriz2[i][j]);
        }
    }
    printf("\nEssa é sua matriz 2: \n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
        printf("|%3d|", matriz2[i][j]);
        }
        printf("\n");
    }

    printf("\n----------------------------------------\n");

    /* Matriz Resultante*/

    printf("\nSoma das Matriz: \n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
        matrizR [i][j] = matriz1[i][j] + matriz2 [i][j];
        printf("|%3d|", matrizR[i][j]);

        }
        printf("\n");
    }

/* Determinante usando Sarrus*/

    }else if(escolha == 2){


    int m[3][3];
    int i, j, determinante;


/* Formula de Sarrus | det(A) = a11 · a22 · a33 + a12 · a23 · a31 + a13 · a21 · a32 – (a13 · a22 · a31 + a11 · a21 · a32 + a12 · a21 · a33) */

    printf("\n|Determinate de Matriz 3x3 usando regra de Sarrus|\n\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
        printf("Digite o numero da coordenada Linha[%d] Coluna[%d]: \n", i+1, j+1);
        scanf("%d", &m[i][j]);
        }
    }
    printf("\nEssa é sua matriz: \n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
        printf("|%3d|", m[i][j]);
        }
        printf("\n");
    }

    determinante = ((m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[0][2] * m[1][0] * m[2][1])) - ((m[0][2] * m[1][1] * m[2][0] + m[0][0] * m[1][2] * m[2][1] + m[0][1] * m[1][0] * m[2][2]));
    printf("\n\nAplicado a regra de sarrus conseguimos descobrir que sua determinante é: [%d]\n\n", determinante);

    }else{
            printf("\n Opção inválida!\n");
    }

    printf("\nDeseja voltar ao menu?\n");
    printf("[1] Sim\n[0] Sair\n");
    printf("Escolha: ");
    scanf("%d", &repetir);

    printf("\n----------------------------------------\n\n");

    } while (repetir == 1);

    return 0;
}
