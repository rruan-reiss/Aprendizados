#include <stdio.h>
#include <string.h>

#define MAXVOOS 2
#define MAX_NOME 20

/*Estrutura*/
typedef struct{
    int numVoo;
    char origem[20];
    char destino[20];
    int vagas;
} Voo;

/*Protótipos*/
Voo cadastrarVoo(int ordem);
/*void mostrarVoo(Voo v[], int ordem);*/
void porNum(Voo v[]);
void porOrigem(Voo v[]);
void porDestino(Voo v[]);
void efetuarReserva(Voo v[]);

int main(){
    int i;
    int menu;
    int consulta;
    Voo voo[MAXVOOS];

    printf("|Cadastro de Voos|\n");
    for(i=0; i<MAXVOOS; i++){
        voo[i] = cadastrarVoo(i+1);
    }

    do{
        printf("|MENU|\n\n");
        printf("1.CONSULTAR\n2.EFETUAR RESERVA\n0.SAIR\n");
        scanf("%d", &menu);

        switch (menu){

            case 1:
                printf("1.Por numero de voo\n2.Por Origem\n3.Por destino\n");
                scanf("%d", &consulta);
                if(consulta == 1){
                    porNum(voo);
                }else if(consulta == 2){
                    porOrigem(voo);
                }else if(consulta == 3){
                    porDestino(voo);
                }
                break;
            case 2:
                efetuarReserva(voo);
                break;
            case 0:
                printf("ENCERRADO\n");
                break;
            default:
                printf("\nOpcao Invalida\n");
                break;
        }
    }while(menu != 0);

    return 0;
}

Voo cadastrarVoo(int ordem){
    Voo v;

    printf("Voo n%d\n", ordem);
    printf("Numero do voo: ");
    scanf("%d", &v.numVoo);
    getchar(); /*Limpar o '\n'*/
    printf("Origem: ");
    fgets(v.origem, MAX_NOME, stdin);
    v.origem[strcspn(v.origem, "\n")] = '\0'; /*usado para substituir a quebra de linha por caracter nulo*/
    printf("Destino: ");
    fgets(v.destino, MAX_NOME, stdin);
    v.destino[strcspn(v.destino, "\n")] = '\0';
    printf("Quantidade de lugares disponiveis: ");
    scanf("%d", &v.vagas);

    return v;
}

void porNum(Voo v[]){
    int i;
    printf("|CONSULTA POR NUMERO|\n\n");
    for(i=0; i<MAXVOOS; i++){
        printf("O voo de numero [%d] tem %d locais disponiveis\n", v[i].numVoo, v[i].vagas);
    }
}

void porOrigem(Voo v[]){
    int i;
    printf("|CONSULTA POR ORIGEM|\n\n");
    for(i=0; i<MAXVOOS; i++){
            printf("O voo com origem [%s] tem %d locais disponiveis\n", v[i].origem, v[i].vagas);
    }
}

void porDestino(Voo v[]){
    int i;
    printf("|CONSULTA POR DESTINO|\n\n");
    for(i=0; i<MAXVOOS; i++){
           printf("O voo com destino para [%s] tem %d locais disponiveis\n", v[i].destino, v[i].vagas);
    }
}

void efetuarReserva(Voo v[]){
    int num;
    int i;
    int test=0;
    Voo vooSelec;

    printf("|EFETUAR RESERVA|\n");
    printf("\nDigite o numero do voo: ");
    scanf("%d", &num);

    for(i=0; i<MAXVOOS; i++){
        if(v[i].numVoo==num){
            vooSelec=v[i];
            test=1;
            if(vooSelec.vagas>0){
                printf("Reserva confirmada!\n");
                vooSelec.vagas--;
                v[i].vagas=vooSelec.vagas;
            }else if (vooSelec.vagas==0){
                printf("Este voo ja esta com lotacao maxima.\n");
            }

        }else if(test==0){
            printf("Voo inexistente.\n");

        }
    }
}
