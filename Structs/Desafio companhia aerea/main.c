#include <stdio.h>
#include <string.h>

#define MAXVOOS 2
#define MAX_NOME 25

/*Estrutura*/
typedef struct{
    int numVoo;
    char origem[MAX_NOME];
    char destino[MAX_NOME];
    int vagas;
} Voo;

/*Protótipos*/
Voo cadastrarVoo(int ordem);
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
                getchar();
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
    int num;
    int busca=0;
    printf("|CONSULTA POR NUMERO|\n\n");
    printf("Digite o numero do voo: ");
    scanf("%d", &num);
    for(i=0; i<MAXVOOS; i++){
        if(v[i].numVoo==num){
        busca=1;
        printf("\nVoo de numero [%d]\n", v[i].numVoo);
        printf("Com origem de [%s] para [%s]\n", v[i].origem, v[i].destino);
        printf("Acentos disponiveis: %d.\n", v[i].vagas);
        break;
        }
    }
    if (busca != 1){
        printf("Numero de voo invalido.\n");
    }
}

void porOrigem(Voo v[]){
    int i;
    char origem[MAX_NOME];
    int busca=0;
    printf("|CONSULTA POR ORIGEM|\n\n");
    printf("Digite a origem do voo: ");
    fgets(origem, MAX_NOME, stdin);
    origem[strcspn(origem, "\n")] = '\0'; /*retirar '\n'*/
    
    for(i=0; i<MAXVOOS; i++){
        if(strcmp(origem, v[i].origem)==0){
        busca=1;
        printf("\nVoo de numero [%d]\n", v[i].numVoo);
        printf("Com origem de [%s] para [%s]\n", v[i].origem, v[i].destino);
        printf("Acentos disponiveis: %d.\n", v[i].vagas);
        }
    }
    if (busca != 1){
        printf("A origem do voo é invalida.\n");
    }
}

void porDestino(Voo v[]){
    int i;
    char destino[MAX_NOME];
    int busca=0;
    printf("|CONSULTA POR DESTINO|\n\n");
    printf("Digite a destino do voo: ");
    fgets(destino, MAX_NOME, stdin);
    destino[strcspn(destino, "\n")] = '\0'; /*retirar '\n'*/
    
    for(i=0; i<MAXVOOS; i++){
        if(strcmp(destino, v[i].destino)==0){
        busca=1;
        printf("\nVoo de numero [%d]\n", v[i].numVoo);
        printf("Com origem de [%s] para [%s]\n", v[i].origem, v[i].destino);
        printf("Acentos disponiveis: %d.\n", v[i].vagas);
        }
    }
    if (busca != 1){
        printf("A destino do voo é invalida.\n");
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
            test=1;
            if(v[i].vagas>0){
                printf("Reserva confirmada!\n");
                v[i].vagas--;
            }else{
                printf("Este voo ja esta com lotacao maxima.\n");
            }
            break; /* interromper o laço apos encontrar*/    
        }
    }if(test!=1){
        printf("Voo inexistente.\n");
    }
}