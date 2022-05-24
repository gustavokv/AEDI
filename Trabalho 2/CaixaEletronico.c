#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* 
Implementações feitas:

 * Contador de cedulas
 * Menus
 * Revarga de Cedulas (com checagem para 0 e numeros negativos) (limite de cedulas)
 * Total sacado e saldo existente
 * Checagem de saque (se o saldo < saque avisar o usuario)
 * Contagem de cedulas
 * Caso for impossivel dar o valor com as notas atuais, exibe mensagem de erro e não é descontado do saldo nem entregue nota alguma
 * Identificadores de SAIDA e ERRO

TODO:

 * Validador de CPF
 * Escrever numeros por extenso
 * Checar se é possivel dar o valor (com as notas disponiveis)

*/


int main(){
    char me1[15], me2[15], me3[15], cente[15], deze[15], une[10]; //Numeros por extenso
    int m1, m2, m3, cent, dez, un;

    int escolha, escolhaGerente, escolhaCedulas, qntCedulas; //escolhas

    int saque, saque_holder;

    long long int cpf;
    int c1, d1, u1, c2, d2, u2, c3, d3, u3, dig_1, dig_2, soma_mod, v_dig1, v_dig2, v_cpf;

    int totalSacado = 0; //o valor é acumulativo

    //contador de cedulas
    int cedulas450, cedulas250, cedulas50, cedulas20, cedulas10, cedulas5, cedulas2, cedulas1;
    cedulas450 = 100;
    cedulas250 = 200;
    cedulas50 = 400;
    cedulas20 = 800; 
    cedulas10 = 1600;
    cedulas5 = 3200;
    cedulas2 = 6400;
    cedulas1 = 12800;

    //o valor máximo de cédulas que pode existir de cada tipo.
    int limite450, limite250, limite50, limite20, limite10, limite5, limite2, limite1;
    limite450 = 100;
    limite250 = 200;
    limite50 = 400;
    limite20 = 800; 
    limite10 = 1600;
    limite5 = 3200;
    limite2 = 6400;
    limite1 = 12800;

    int saque450, saque250, saque50, saque20, saque10, saque5, saque2, saque1;

    int saldo = cedulas450 * 450 + cedulas250 * 250 + cedulas50 * 50 + cedulas20 * 20 + cedulas10 * 10 + cedulas5 * 5 + cedulas2 * 2 + cedulas1;

    do {
        printf("----------Menu----------\n1.Saque\n2.Gerente\n3.Finalizar\n -> Escolha sua opcao: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1: // saque
                printf(" -> Informe o valor a ser sacado: ");
                scanf("%d", &saque);

                //TODO: validador de cpf
                do{
                    printf("Digite seu CPF (Cadastro de Pessoas Fisicas): ");
                    scanf("%lld", &cpf);
                    //DECOMPOSICAO DO NUMERO
                    c1 = (cpf/10000000000) % 10;
                    d1 = (cpf/1000000000) % 10;
                    u1 = (cpf/100000000) % 10;
                    c2 = (cpf/10000000) % 10;
                    d2 = (cpf/1000000) % 10;
                    u2 = (cpf/100000) % 10;
                    c3 = (cpf/10000) % 10;
                    d3 = (cpf/1000) % 10;
                    u3 = (cpf/100) % 10;
                    dig_1 = (cpf/10) % 10;
                    dig_2 = cpf % 10;

                    //1. DIGITO
                    soma_mod = c1*10 + d1*9 + u1*8 + c2*7 + d2*6 + u2*5 + c3*4 + d3*3 + u3*2;

                    v_dig1 = 11 - (soma_mod % 11);
                    if(v_dig1>=10)
                        v_dig1 = 0;

                    //2. DIGITO
                    soma_mod = c1*11 + d1*10 + u1*9 + c2*8 + d2*7 + u2*6 + c3*5 + d3*4 + u3*3 + v_dig1*2;

                    v_dig2 = 11 - (soma_mod % 11);
                    if(v_dig2>=10)
                        v_dig2 = 0;

                    //VALIDACAO
                    if((v_dig1!=dig_1)||(v_dig2!=dig_2)){
                        v_cpf = 1;
                        printf("\nCPF invalido!\n\n");
                    }
                    else {
                        v_cpf = 0;
                        printf("\nCPF valido!\n");
                        //continue
                    }
                } while ((v_cpf == 1));
                
                if(saque > saldo) {  //impossivel sacar mais dinheiro do que a maquina tem
                    printf("[ERRO!] A maquina nao possui saldo suficiente!\n");
                    break;
                }
                saque_holder = saque;
                saque450 = 0;
                saque250 = 0;
                saque50 = 0;
                saque20 = 0; 
                saque10 = 0;
                saque5 = 0;
                saque2 = 0;
                saque1 = 0;



                while (saque_holder > 0) { // saque_holder != 0 testar dps
                    if (saque_holder - 450 >= 0 && cedulas450 > 0) {
                        saque_holder -= 450;
                        saque450++;
                    }
                    else if (saque_holder - 250 >= 0 && cedulas250 > 0) {
                        saque_holder -= 250;
                        saque250++;
                    }
                    else if (saque_holder - 50 >= 0 && cedulas50 > 0) {
                        saque_holder -= 50;
                        saque50++;
                    }
                    else if (saque_holder - 20 >= 0 && cedulas20 > 0) {
                        saque_holder -= 20;
                        saque20++;
                    }
                    else if (saque_holder - 10 >= 0 && cedulas10 > 0) {
                        saque_holder -= 10;
                        saque10++;
                    }
                    else if (saque_holder - 5 >= 0 && cedulas5 > 0) {
                        saque_holder -= 5;
                        saque5++;
                    }
                    else if (saque_holder - 2 >= 0 && cedulas2 > 0) {
                        saque_holder -= 2;
                        saque2++;
                    }
                    else if (saque_holder - 1 >= 0 && cedulas1 > 0) {
                        saque_holder -= 1;
                        saque1++;
                    }
                    else { //talvez esse caso nunca ocorra, mas é bom se precaver
                        printf("[ERRO!] Impossivel dar o valor com as notas atuais!\n");
                        saque450 = 0;
                        saque250 = 0;
                        saque50 = 0;
                        saque20 = 0; 
                        saque10 = 0;    //zerar o saque, já que nenhuma nota será dada.
                        saque5 = 0;
                        saque2 = 0;
                        saque1 = 0;
                        break;
                    }
                }

                cedulas450 -= saque450;
                cedulas250 -= saque250;
                cedulas50  -= saque50;
                cedulas20  -= saque20; 
                cedulas10  -= saque10;
                cedulas5   -= saque5;
                cedulas2   -= saque2;
                cedulas1   -= saque1;

                if (saque_holder > 0) { //foi possivel retirar o dinheiro
                    //converter pra texto

                    //Para a casa m1
                    if(m1==1&&(m2>0||m3>0)) {
                        strcpy(me1, "Cento e");
                    }
                    else if(m1==1) {
                        strcpy(me1, "Cem mil");
                    }

                    //Para a casa m2
                    if(m2==1&&m3==0) {
                        strcpy(me2, "dez mil");
                    }
                    else if (m2==1&&m3==1) {
                        strcpy(me2, "onze mil");
                    }
                    else if (m2==1&&m3==2) {
                        strcpy(me2, "doze mil");
                    }
                    else if (m2==1&&m3==3) {
                        strcpy(me2, "treze mil");
                    }
                    else if (m2==1&&m3==4) {
                        strcpy(me2, "quatorze mil");
                    }
                    else if (m2==1&&m3==5) {
                        strcpy(me2, "quinze mil");
                    }
                    else if (m2==1&&m3==6) {
                        strcpy(me2, "dezesseis mil");
                    }
                    else if (m2==1&&m3==7) {
                        strcpy(me2, "dezessete mil");
                    }
                    else if (m2==1&&m3==8) {
                        strcpy(me2, "dezoito mil");
                    }
                    else if (m2==1&&m3==9) {
                        strcpy(me2, "dezenove mil");
                    }
                    else if(m3==1) { //Para a casa m3
                        strcpy(me3, "mil");
                    }
                    else if(m3==2) {
                        strcpy(me3, "dois");
                    }
                    else if(m3==3) {
                        strcpy(me3, "tres");
                    }
                    else if(m3==4) {
                        strcpy(me3, "quatro");
                    }
                    else if(m3==5) {
                        strcpy(me3, "cinco");
                    }
                    else if(m3==6) {
                        strcpy(me3, "seis");
                    }
                    else if(m3==7) {
                        strcpy(me3, "sete");
                    }
                    else if(m3==8) {
                        strcpy(me3, "oito");
                    }
                    else if(m3==9) {
                        strcpy(me3, "nove");
                    }
                    else if(m2==2) {
                        strcpy(me2, "vinte");
                    }
                    else if(m2==3) {
                        strcpy(me2, "trinta");
                    }
                    else if(m2==4) {
                        strcpy(me2, "quarenta");
                    }
                    else if(m2==5) {
                        strcpy(me2, "cinquenta");
                    }
                    else if(m2==6) {
                        strcpy(me2, "sessenta");
                    }
                    else if(m2==7) {
                        strcpy(me2, "setenta");
                    }
                    else if(m2==8) {
                        strcpy(me2, "oitenta");
                    }
                    else if(m2==9) {
                        strcpy(me2, "noventa");
                    }
                    
                    


                    printf("[SAIDA] Saque %d:\n%d notas de 450\n%d notas de 250\n%d notas de 50\n%d notas de 20\n%d notas de 10\n%d notas de 5\n%d notas de 2\n%d notas de 1", saque450, saque250, saque50, saque20, saque10, saque5, saque2, saque1);
                    saldo -= saque; //o saldo PRECISA ser calculado aqui
                }
            break;
            case 2: // menu gerente
                do {
                    printf("----------Menu gerente:----------\n(1) Valor total sacado\n(2) Valor do saldo existente\n(3) Quantidade de cedulas existentes\n(4) Abastecer o caixa eletronico\n(5) Voltar ao menu principal\n -> Sua escolha: ");
                    scanf("%d", &escolhaGerente);
                    switch(escolhaGerente){
                        case 1: //valor total sacado
                            printf("[SAIDA] O valor total sacado nesse caixa eletronico foi de %d reais\n", totalSacado);
                        break;
                        case 2: //Valor do saldo existente
                            //não se calcula o saldo aqui, já que o saldo só atualizaria quando se escolhesse essa opção
                            printf("[SAIDA] Saldo existente: %d\n", saldo);
                        break;
                        case 3: //quantidade de cedulas existentes
                            printf("[SAIDA] Quantidade de cedulas:\nCedulas de 450: %d\nCedulas de 250: %d\nCedulas de 50: %d\nCedulas de 20: %d\nCedulas de 10: %d\nCedulas de 5: %d\nCedulas de 2: %d\nCedulas de 1: %d\n", cedulas450, cedulas250, cedulas50, cedulas20, cedulas10, cedulas5, cedulas2, cedulas1);
                        break;
                        case 4: //Abastecer caixa eletronico
                            do {
                                printf("----------Menu abastecer o caixa eletronico:----------\n(450) Cedulas de 450\n(250) Cedulas de 250\n(50) Cedulas de 50\n(20) Cedulas de 20\n(10) Cedulas de 10\n(5) Cedulas de 5\n(2) Cedulas de 2\n(1) Cedulas de 1\n(0) Voltar para o menu gerente\n -> Sua escolha:");
                                scanf("%d", &escolhaCedulas);
                                switch(escolhaCedulas){
                                    case 450:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite450 < qntCedulas + cedulas450) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite450, cedulas450);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas450 += qntCedulas;
                                    break;
                                    case 250:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite250 < qntCedulas + cedulas250) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite250, cedulas250);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas250 += qntCedulas;
                                    break;
                                    case 50:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite50 < qntCedulas + cedulas50) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite50, cedulas50);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas50 += qntCedulas;
                                    break;
                                    case 20:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite20 < qntCedulas + cedulas20) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite20, cedulas20);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas20 += qntCedulas;
                                    break;
                                    case 10:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite10 < qntCedulas + cedulas10) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite10, cedulas10);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas10 += qntCedulas;
                                    break;
                                    case 5:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite5 < qntCedulas + cedulas5) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite5, cedulas5);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas5 += qntCedulas;
                                    break;
                                    case 2:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite2 < qntCedulas + cedulas2) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite2, cedulas2);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas2 += qntCedulas;
                                    break;
                                    case 1:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite1 < qntCedulas + cedulas1) {
                                            printf("[ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite1, cedulas1);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("[ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas1 += qntCedulas;
                                    break;
                                    case 0:
                                        printf("Retornando ao menu gerente.\n");
                                    break;
                                    default:
                                        printf("[ERRO!] Escolha uma opcao valida!\n");
                                }
                                saldo = cedulas450 * 450 + cedulas250 * 250 + cedulas50 * 50 + cedulas20 * 20 + cedulas10 * 10 + cedulas5 * 5 + cedulas2 * 2 + cedulas1;
                                //atualizar o saldo depois do abastecimento
                            } while (escolhaCedulas != 0);
                        break;
                        case 5: //sair
                            printf("Voltando ao menu principal.\n");
                        break;
                        default:
                            printf("[ERRO!] Escolha uma opcao valida!\n");
                    }
                } while (escolhaGerente != 5);


            break;
            case 3:
                printf("Finalizado\n");
            break;
            default:
                printf("[ERRO!] Escolha um valor valido!\n");
        }
    } while (escolha != 3);
}