#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

void efetuarDeposito(char numero[10],char agencia[6],float valor);
void efetuarSaque(char numero[10],char agencia[6],float valor );
void efetuarTransf(char numero[10],char agencia[6],char numeroDestino[10],char agenciaDestino[6],float valor);
Conta *conta;

int main(){

    conta=(Conta*)malloc(10*sizeof(Conta));
    int i,aux;
    i=0;
    char numero[10];
    char agencia[6];
    char cpf[12];
    float saldos;


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
        system("cls");

        bool loop=true;
        int opc;
        float valor;
        char numeroDestino[10];
        char agenciaDestino[6];
        while(loop){

            system("cls");
            printf("--------------BEM VINDO------------------\n");
            printf("\n\nO que você deseja fazer?\n\n");
			printf("1 - Efetuar Deposito\n");
			printf("2 - Efetuar Saque\n");
			printf("3 - Efetuar Transferencia\n");
			printf("4 - Consultar o Ativo Bancario\n");
			printf("5 - Exibir Realtorio de Contas\n");
			printf("6 - Finalizar Programa\n");
			printf("Digite o número da opção que deseja:\n");

            scanf("%d",&opc);
            fflush(stdin);


			switch(opc){

				case 1:
                    printf("\n\n---------DEPOSITO-----------\n\n");
				    printf("\nDigite o numero da conta na qual deseja fazer o deposito\n");
                    gets(numero);
                    fflush(stdin);

                    printf("\nDigite a agencia da conta na qual deseja fazer o deposito\n");
                    gets(agencia);
                    fflush(stdin);

                    printf("\nDigite o valor que quer depositar\n");
                    scanf("%f",&valor);
                    fflush(stdin);
				    efetuarDeposito(numero,agencia,valor);
				break;

				case 2:

				    printf("\n\n---------SAQUE-----------\n\n");
				    printf("\nDigite o numero da conta na qual deseja fazer o saque\n");
                    gets(numero);
                    fflush(stdin);

                    printf("\nDigite a agencia da conta na qual deseja fazer o saque\n");
                    gets(agencia);
                    fflush(stdin);

                    printf("\nDigite o valor que quer sacar\n");
                    scanf("%f",&valor);
                    fflush(stdin);
				    efetuarSaque(numero,agencia,valor);
				break;

				case 3:
				    printf("\n\n---------TRANSFERENCIA-----------\n\n");
				    printf("\nDigite o numero da conta de origem\n");
                    gets(numero);
                    fflush(stdin);

                    printf("\nDigite a agencia da conta de origem\n");
                    gets(agencia);
                    fflush(stdin);

                    printf("\nDigite o valor que quer transferir\n");
                    scanf("%f",&valor);
                    fflush(stdin);

				    printf("\nDigite o numero da conta de destino\n");
                    gets(numeroDestino);
                    fflush(stdin);

                    printf("\nDigite a agencia da conta de destino\n");
                    gets(agenciaDestino);
                    fflush(stdin);
				    efetuarTransf(numero,agencia,numeroDestino,agenciaDestino,valor);
				break;

				case 4:consulAtBanc();
				break;

				case 5:exibirRelConta();
                break;
				case 6:free(conta);
                       loop=false;


			}

        }


    }

void efetuarDeposito(char numero[10],char agencia[6],float valor){

    int i;
    bool loop=true;



    while(loop){

        if(valor<0){

            printf("\nValor de depósito inválido. Deve ser positivo.\n");
            printf("\nDigite um novo valor.\n");
            scanf("%f",&valor);
            fflush(stdin);

        }else{

            int veriNumCon=1;
            for(i=0;i<10;i++){

                if((strcmp(conta[i].numero,numero)==0)&&(strcmp(conta[i].agencia,agencia)==0)){

                    conta[i].saldo+=valor;
                    printf("\nDeposito efetuado com sucesso\n");
                    getchar();
                    veriNumCon=1;
                    break;

                }else{

                    veriNumCon=0;

                }

            }
            if(veriNumCon==0){
                printf("Conta não encontrada");
                getchar();
            }
            loop=false;

        }

    }
}

void efetuarSaque(char numero[10],char agencia[6],float valor ){

    int i;
    bool loop=true;



    while(loop){

        if(valor<0){

            printf("\nValor de saque inválido.Deve ser positivo.\n");
            printf("\nDigite um novo valor.\n");
            scanf("%f",&valor);
            fflush(stdin);

        }else{

            int veriNumCon=1;
            for(i=0;i<10;i++){

                if((strcmp(conta[i].numero,numero)==0)&&(strcmp(conta[i].agencia,agencia)==0)){

                    if(conta[i].saldo<valor){
                       printf("\nSaldo insuficiente para saque\n");
                       getchar();
                       veriNumCon=1;
                       break;
                    }else{
                        conta[i].saldo-=valor;
                        printf("\nSaque efetuado com sucesso\n");
                        getchar();
                        veriNumCon=1;
                        break;
                    }
                }else{

                    veriNumCon=0;

                }

            }
            if(veriNumCon==0){

                printf("Conta não encontrada");
                getchar();

            }
            loop=false;

        }

    }


}
void efetuarTransf(char numero[10],char agencia[6],char numeroDestino[10],char agenciaDestino[6],float valor){

    int i;
    int j;
    bool loop=true;



    while(loop){

        if(valor<0){

            printf("\nValor de tranferencia inválido.Deve ser positivo.\n");
            printf("\nDigite um novo valor.\n");
            scanf("%f",&valor);
            fflush(stdin);

        }else{

            int veriNumCon=1;
            for(i=0;i<10;i++){

                if((strcmp(conta[i].numero,numero)==0)&&(strcmp(conta[i].agencia,agencia)==0)){

                    if(conta[i].saldo<valor){
                       printf("\nSaldo insuficiente para transferencia\n");
                       getchar();
                       veriNumCon=1;
                       break;
                    }else{


                         int veriNumConDes;
                         for(j=0;j<10;j++){

                                if((strcmp(conta[j].numero,numeroDestino)==0)&&(strcmp(conta[j].agencia,agenciaDestino)==0)){
                                    conta[j].saldo+=valor;
                                    conta[i].saldo-=valor;
                                    printf("\nTransferencia efetuada com sucesso\n");
                                    getchar();
                                    veriNumConDes=1;
                                    break;
                                }else{
                                    veriNumConDes=0;

                                }

                         }

                         if(veriNumConDes==0){

                            printf("Conta de destino não encontrada");
                            getchar();
                         }

                         loop=false;
                         break;
                    }
                }else{

                    veriNumCon=0;

                }

            }
            if(veriNumCon==0){

                printf("Conta de origem não encontrada");
                getchar();

            }
            loop=false;


        }

    }
}

void consulAtBanc(){

     int i;
     float valorTotal;

     for(i=0;i<10;i++){

       valorTotal+=conta[i].saldo;


     }

     printf("O valor do ativo bancario é %.2f",valorTotal);
     getchar();

}

void exibirRelConta(){

    int i;
    for(i=0;i<10;i++){

        printf("\n\n------------CONTA %d-------------\n\n",i+1);
        printf("Numero: %s\n",conta[i].numero);
        printf("Agencia: %s\n",conta[i].agencia);
        printf("Saldo: %.2f\n",conta[i].saldo);
        printf("CPF: %s\n",conta[i].cliente.cpf);
        printf("Nome: %s\n",conta[i].cliente.nome);
        printf("Data de nascimento: %s\n",conta[i].cliente.dataNasc);

     }

     getchar();
}

