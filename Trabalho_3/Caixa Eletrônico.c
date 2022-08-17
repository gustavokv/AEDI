#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
//parametros: nenhum
//retorno:a letra do alfabeto
char geraAlfabeto() {
    int i;
    char letras[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    i=rand()%26;
    return(letras[i]-32);
}

//objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
//parametros: nenhum
//retorno:o numero
char geraNumero() {
    int i;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};


    i=rand()%9;
    return(numeros[i]);
}

//objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
//parametros: c onde armazera a conta gerada
//retorno:nenhum
void geraContaCorrente(char c[]) {
   c[0] = geraNumero();
   c[1] = geraNumero();
   c[2] = geraNumero();
   c[3] = '.';
   c[4] = geraNumero();
   c[5] = geraNumero();
   c[6] = geraNumero();
   c[7] = '-';
   c[8] = geraAlfabeto();
   c[9] = '\0';
}

//objetivo:verifica se um cpf no formato 999.999.999-99 e valido
//parametros: cpf a ser verificado
//retorno: 1 se cpf e valido ou 0 se cpf nao e valido
/*int verifica_cpf_valido(char cpf[]) {
   int valido=1;

   //implemente aqui

   return(valido);
}
*/

//objetivo:insere pontuacoes '.' e '- ' em um cpf
//parametros: cpf_origem o cpf recebido no format 99999999999
//            cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[]) {

   cpf_destino[0] = cpf_origem[0];
   cpf_destino[1] = cpf_origem[1];
   cpf_destino[2] = cpf_origem[2];
   cpf_destino[3] = '.';
   cpf_destino[4] = cpf_origem[3];
   cpf_destino[5] = cpf_origem[4];
   cpf_destino[6] = cpf_origem[5];
   cpf_destino[7] = '.';
   cpf_destino[8] = cpf_origem[6];
   cpf_destino[9] = cpf_origem[7];
   cpf_destino[10] = cpf_origem[8];
   cpf_destino[11] = '-';
   cpf_destino[12] = cpf_origem[9];
   cpf_destino[13] = cpf_origem[10];
}

//objetivo:calcula o primeiro digito verificador de um cpf no formato 999999999
//parametros: cpf o cpf sem os digitos verificadores
//retorno: o calculo do primeiro digito verificador
int obtem_primeiro_digito_verificador(char cpf[]) {
   int digito, soma, cpfmod[9], i;

   printf("\n");
   for(i=0;i<9;i++) {
      cpfmod[i] = cpf[i] - '0';
   }
   
   soma = (cpfmod[0] * 10 + cpfmod[1] * 9 + cpfmod[2] * 8 + cpfmod[3] * 7 + cpfmod[4] * 6 + cpfmod[5] * 5 + cpfmod[6] * 4 + cpfmod[7] * 3 + cpfmod[8] * 2) % 11;
   soma = 11 - soma;

   if(soma>=10) 
      digito = 0;
   else
      digito = soma;

   return(digito);
}

//objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
//parametros: cpf sem os digitos verificadores
//retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[]) {
   int digito, cpfmod[11], i, soma;

   for(i=0;i<10;i++) {
      cpfmod[i] = cpf[i] - '0';
   }

   soma = (cpfmod[0] * 11 + cpfmod[1] * 10 + cpfmod[2] * 9 + cpfmod[3] * 8 + cpfmod[4] * 7 + cpfmod[5] * 6 + cpfmod[6] * 5 + cpfmod[7] * 4 + cpfmod[8] * 3 + cpfmod[9] * 2) % 11;
   soma = 11 - soma;

   if(soma >= 10) 
      digito = 0;
   else
      digito = soma;

   return(digito);
}


//objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
//parametros: cpf onde sera armazenado o cpf valido
//retorno: nenhum
void gera_cpf_valido(char cpf[]) {
   cpf[0] = geraNumero();
   cpf[1] = geraNumero();
   cpf[2] = geraNumero();
   cpf[3] = geraNumero();
   cpf[4] = geraNumero();
   cpf[5] = geraNumero();
   cpf[6] = geraNumero();
   cpf[7] = geraNumero();
   cpf[8] = geraNumero();
   cpf[9] = '\0';
}

//Objetivo: Mostra as informacoes dos clientes
void mostraCliente(char cpf[50][14], char conta[50][9], int qntcliente) {
   int i=0, j;

   system("clear");

   while(qntcliente>i) {
      printf("\n------------\nCliente %d:\n------------\nConta: ", i + 1);
       for(j=0;j<9;j++) {
         printf("%c", conta[i][j]);
      }
      printf("\nCPF: ");
      for(j=0;j<14;j++) {
         printf("%c", cpf[i][j]);
      }
      printf("\n");
      printf("Quantidade de saques: \nValor total: \n");

      i++;
   }
}

int main () {
   int opmenu, opmenucliente, opmenurelat, resp=0, qntrep, contuser=0; //Menu
   int i, j; //Contadores

   char syspause[2];//Variaveis diversas

   char accouser[50][9], account[9]; //Contas
   int addconfirm=0, respadd;

   char cpfnopont[11], cpf[14], cpfuser[50][14], char1digit, char2digit; //CPF
   int firstdigit, secdigit;

   //Inicia a matriz de todas as contas dos usuarios.
   for(i=0;i<50;i++) {
      for(j=0;j<9;j++) {
         accouser[i][j] = '\0';
      }
   }

   do{
      system("clear");

      printf("MENU PRINCIPAL\n1-Cliente\n2-Saque\n3-Relatorios\n4-Finalizar\n-->");
      scanf("%d", &opmenu);

      switch (opmenu) {

         case 1:
            do {
               system("clear");

               printf("MENU CLIENTE\n1-Incluir\n2-Mostrar\n3-Alterar\n4-Excluir\n5-Voltar\n-->");
               scanf("%d", &opmenucliente);
               
               switch (opmenucliente) {
                  case 1:
                     if(contuser < 50) { //So funciona se tiver menos de 50 clientes cadastrados

                        //Gera uma conta nova.
                        do {
                           geraContaCorrente(account);
                           
                           qntrep = 0;

                           //Verificacao, caso a conta ja seja existente.
                           for(i=0;i<50;i++) {
                              for(j=0;j<9;j++) {
                                 if(account[j] == accouser[i][j]) {
                                    qntrep++;
                                 }
                              }

                              if(qntrep == 9) {
                                 break;
                              }

                              qntrep = 0;
                           }

                           resp = 1;
                           
                        } while(resp == 0);

                        //Cria um CPF para a nova conta.
                        gera_cpf_valido(cpfnopont);

                        firstdigit = obtem_primeiro_digito_verificador(cpfnopont);//Primeiro digito do CPF
                        cpfnopont[9] = firstdigit + '0';

                        secdigit = obtem_segundo_digito_verificador(cpfnopont);//Segundo digito do CPF
                        cpfnopont[10] = secdigit + '0';

                        insere_pontuacao_cpf(cpfnopont, cpf);

                        do{
                           system("clear");

                           printf("Deseja incluir a conta ");
                           for(i=0;i<9;i++) {
                              printf("%c", account[i]);
                           }
                           printf(" de CPF ");
                           for(i=0;i<14;i++) {
                              printf("%c", cpf[i]);
                           }
                           printf("?\n[1]-Sim\n[2]-Nao\n-->");
                           
                           scanf("%d", &respadd);
                        
                           if(respadd == 1) {
                              //Adiciona a nova conta na matriz de contas.
                              for(i=0;i<9;i++) {
                                 accouser[contuser][i] = account[i];
                              }
                              
                              //Adiciona o novo CPF na matriz de CPF.
                              for(i=0;i<14;i++) {
                                 cpfuser[contuser][i] = cpf[i];
                              }

                              printf("--> Conta adicionada com sucesso!\n\n");

                              contuser++; //Quantidades de usuarios cadastrados.
                              addconfirm = 1;

                              printf("Digite uma tecla para sair.");
                              scanf("%s", syspause);
                           }
                           else if(respadd == 2) {
                              printf("--> Conta nao adicionada!\n\n");
                              addconfirm = 1;

                              printf("Digite uma tecla para sair.");
                              scanf("%s", syspause);
                           }
                           else {
                              printf("\nEscolha uma opcao valida!\n");

                              printf("Digite uma tecla para sair.");
                              scanf("%s", syspause);
                           }
                        } while(addconfirm != 1);

                        addconfirm = 0;                       
                     }
                     else {
                        printf("Quantidade de clientes maximo atingido!");
                     }
                     break;
                  
                  case 2:
                     if(contuser!=0) {
                        mostraCliente(cpfuser, accouser, contuser);
                        printf("\n");

                        printf("Digite uma tecla para sair.");
                        scanf("%s", syspause);
                     }
                     else {
                        system("clear");
                        printf("Nao ha usuarios cadastrados!\n");

                        printf("Digite uma tecla para sair.");
                        scanf("%s", syspause);
                     }
                     break;

                  case 5:
                     break;
                  
                  default:
                     printf("Escolha uma opcao valida!\n");

                     printf("Digite uma tecla para sair.");
                     scanf("%s", syspause);
                     break;
               }
            } while(opmenucliente != 5);

            break;

         case 2:

            break;
         case 3:
            system("clear");

            printf("MENU RELATORIOS\n1-Valores sacados\n2-Valor do saldo existente\n3-Quantidade de cedulas existentes\n4-Voltar ao menu principal\n");
            scanf("%d", &opmenurelat);
            break;
         case 4:
            break;
         default:
            printf("Escolha uma opcao valida!\n");

            printf("Digite uma tecla para sair.");
            scanf("%s", syspause);
      }
   } while(opmenu != 4);
}