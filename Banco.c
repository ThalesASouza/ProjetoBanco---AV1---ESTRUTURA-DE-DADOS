#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ValidaCPF.c"


typedef struct Cliente{

    char nome[20];
    char cpf[12];
    char dataNasc[10];


}Cliente;


typedef struct Conta{

    char numero[10];
    char agencia[6];
    float saldo;
    Cliente cliente;

}Conta;


int main(){


    Conta *conta;
    conta=(Conta*)malloc(10*sizeof(Conta));

    int i,aux;
    i=0;
    char numero[10];
    char agencia[6];
    float saldos;
    char cpf[12];

    printf("--------------BEM VINDO------------------\n");
    printf("\n\nFORNEÇA OS DADOS DE 10 CONTAS\n\n");

    while(i<10){

        int valSaldo;
        int valCPF;


        if(i==0){
            printf("\nDigite o numero da conta %d \n",i+1);
            gets(numero);
            fflush(stdin);
            printf("\nDigite a agencia da conta %d \n",i+1);
            gets(agencia);
            fflush(stdin);
        }

        if(i>0){
            int veriNumCon=1;

            do{

                printf("\nDigite o numero da conta %d \n",i+1);
                gets(numero);
                fflush(stdin);

                printf("\nDigite a agencia da conta %d \n",i+1);
                gets(agencia);
                fflush(stdin);

                for(aux=0;aux<i;aux++){

                    if((strcmp(conta[aux].numero,numero)==0)&&(strcmp(conta[aux].agencia,agencia)==0)){

                        printf("Numero e agencia já cadastrados no sistema\n");
                        veriNumCon=0;
                        break;

                    }else{

                        veriNumCon=1;

                    }

                }

            }while(veriNumCon==0);

        }

        //RECEBENDO E VALIDANDO O SALDO
        do{

            printf("\nDigite o saldo da conta %d\n",i+1);
            scanf("%f",&saldos);
            fflush(stdin);

            if(saldos<0){

                printf("\nSaldo da conta não pode ser negativo, digite novamente\n");
                valSaldo=0;

            }else{

                valSaldo=1;

            }

        }while(valSaldo!=1);

        //RECEBENDO E VALIDANDO O CPF
        do{

            printf("\nDigite o CPF do cliente da conta %d\n",i+1);
            fgets(cpf,12,stdin);
            fflush(stdin);
            valCPF=validaCPF(cpf);

            if(valCPF==0){

                printf("\nCPF INVALIDO, DIGITE NOVAMENTE\n");

            }else{

                printf("\nCPF VALIDADO\n");

            }

        }while(valCPF!=1);


        printf("\nDigite o nome o cliente da conta %d\n",i+1);
        fgets(conta[i].cliente.nome,19,stdin);

        printf("\nDigite a data de nascimento do cliente da conta %d - formato(dd/mm/aaaa)\n",i+1);
        gets(conta[i].cliente.dataNasc);


        strcpy(conta[i].numero,numero);
        strcpy(conta[i].agencia,agencia);
        conta[i].saldo=saldos;
        strcpy(conta[i].cliente.cpf,cpf);

        i++;
        }


    }

