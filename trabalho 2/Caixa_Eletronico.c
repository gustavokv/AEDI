#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int escolha, escolhaGerente, escolhaCedulas, qntCedulas; //escolhas
    
    //saque
    int saque, saque_holder;
    char cpf[14];
    int c1, d1, u1, c2, d2, u2, c3, d3, u3, dig_1, dig_2, soma_mod, v_dig1, v_dig2, v_cpf;
    int escolhaSaque;
    
    //numero extenso
    char e1, e2, e3, e4, e5, e6;
    char valExtenso[80];

    //para ajudar no printf (cedula/cedulas) e (real/reais)
    char flexaoCedula[8];
    char flexaoReal[7];

    //total sacado
    int totalSacado = 0; //o valor é acumulativo

    //contador de cedulas
    int cedulas450, cedulas250, cedulas50, cedulas20, cedulas10, cedulas5, cedulas2, cedulas1;
    cedulas450 = 100;
    cedulas250 = 200;
    cedulas50 = 0;
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

    //o saldo maximo é 188600
    int saldo = cedulas450 * 450 + cedulas250 * 250 + cedulas50 * 50 + cedulas20 * 20 + cedulas10 * 10 + cedulas5 * 5 + cedulas2 * 2 + cedulas1;
   
    int totalCedulas = cedulas450 + cedulas250 + cedulas50 + cedulas20 + cedulas10 + cedulas5 + cedulas2 + cedulas1;
    int checadorCedulas, localizador;

    do {
        system("cls");
        printf("-------<[ Menu ]>-------\n(1) Saque\n(2) Gerente\n(3) Finalizar\n\n -> Escolha sua opcao: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1: // saque
                do {
                    escolhaSaque = 0;
                    system("cls");
                    printf("----------Saque----------\n");
                    printf(" -> Informe seu CPF: ");
                    scanf("%s", &cpf);
                    //Validador de cpf
                    v_cpf = 0; //variavel de loop, a unica forma de sair é pelo break

                    //resetar os digitos a cada repetição
                    c1 = 0;
                    d1 = 0;
                    u1 = 0;
                    c2 = 0;
                    d2 = 0;
                    u2 = 0;
                    c3 = 0;
                    d3 = 0;
                    u3 = 0;
                    dig_1 = 0;
                    dig_2 = 0;

                    //ele só checa se o cpf for XXXXXXXXXXX ou XXX.XXX.XXX-XX
                    if (strlen(cpf) == 14) { //ponto e traço (XXX.XXX.XXX-XX)
                        c1 = cpf[0] - '0';
                        d1 = cpf[1] - '0';
                        u1 = cpf[2] - '0';
                        c2 = cpf[4] - '0';
                        d2 = cpf[5] - '0'; //converter char para int 
                        u2 = cpf[6] - '0';
                        c3 = cpf[8] - '0';
                        d3 = cpf[9] - '0';
                        u3 = cpf[10] - '0';
                        dig_1 = cpf[12] - '0';
                        dig_2 = cpf[13] - '0';
                    }
                    else if (strlen(cpf) == 11) { //sem ponto e traço (XXXXXXXXXXX)
                        c1 = cpf[0] - '0';
                        d1 = cpf[1] - '0';
                        u1 = cpf[2] - '0';
                        c2 = cpf[3] - '0';
                        d2 = cpf[4] - '0';
                        u2 = cpf[5] - '0';
                        c3 = cpf[6] - '0';
                        d3 = cpf[7] - '0';
                        u3 = cpf[8] - '0';
                        dig_1 = cpf[9] - '0';
                        dig_2 = cpf[10] - '0';
                    }

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
                    if((v_dig1==dig_1 && v_dig2 == dig_2) &&
                        !(c1 == d1 && 
                        d1 == u1 && 
                        u1 == c2 && 
                        c2 == d2 &&
                        d2 == u2 &&  // testar se todos os números são iguais (00000000000, 11111111111)
                        u2 == c3 &&  // o metodo funciona com traço e ponto também, visto que são usados os DIGITOS
                        c3 == d3 && 
                        d3 == u3 &&
                        u3 == dig_1 &&
                        dig_1 == dig_2))
                        break; //cpf é válido
                    
                    system("cls");
                    printf("\n [ERRO!] O CPF %s nao e valido!\n\n", cpf);
                    printf(" 1. Tentar novamente\n");
                    printf(" 2. Voltar ao menu\n\n");
                    do { //se não for válido, executa essa linha
                        printf(" -> Sua escolha: ");
                        scanf("%d", &escolhaSaque);
                        if(escolhaSaque == 1)
                            break;
                        else if (escolhaSaque == 2)
                            break;
                        printf("Escolha uma opcao valida!\n\n"); //um else aqui não é necessário já que a linha só é executada se não der break (não for nenhum dos 2 casos acima)
                    } while (escolhaSaque != 1 && escolhaSaque != 2);

                    if (escolhaSaque == 2) break; 
                } while (v_cpf == 0);

                if (escolhaSaque == 2) break; //errou o cpf e decidiu voltar

                do {
                    system("cls");
                    printf("----------Saque----------\n");
                    printf(" -> CPF: %d%d%d.%d%d%d.%d%d%d-%d%d\n", c1, d1, u1, c2, d2, u2, c3, d3, u3, dig_1, dig_2);
                    printf(" -> Informe o valor a ser sacado: ");
                    scanf("%d", &saque);

                    if(saque > 0 && saque <= saldo) // é possivel executar
                        break;
                    system("cls");
                    printf("\n");
                    if(saque > saldo)  //impossivel sacar mais dinheiro do que a maquina tem
                        printf("[ERRO!] A maquina nao possui saldo suficiente!\n");
                    if (saque <= 0)
                        printf("[ERRO!] Impossivel sacar valores neutros ou negativos\n");
                    
                    printf(" 1. Tentar novamente\n");
                    printf(" 2. Voltar ao menu\n\n");
                    do { //perguntar se deseja tentar novamente ou desistir
                        printf(" -> Sua escolha: ");
                        scanf("%d", &escolhaSaque);
                        if(escolhaSaque == 1)
                            break;
                        else if (escolhaSaque == 2)
                            break;
                        printf("Escolha uma opcao valida!\n\n");
                    } while (escolhaSaque != 1 && escolhaSaque != 2);

                    if (escolhaSaque == 2) break;
        
                } while (saque <= 0 || saque > saldo);

                if (escolhaSaque == 2) break; //errou e decidiu voltar

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
                    if (saque_holder - 450 >= 0 && cedulas450 - 1 - saque450 >= 0) {
                        saque_holder -= 450;
                        saque450++;
                    }
                    else if (saque_holder - 250 >= 0 && cedulas250 - 1 - saque250 >= 0) {
                        saque_holder -= 250;
                        saque250++;
                    }
                    else if (saque_holder - 50 >= 0 && cedulas50 - 1 - saque50 >= 0) {
                        saque_holder -= 50;
                        saque50++;
                    }
                    else if (saque_holder - 20 >= 0 && cedulas20 - 1 - saque20 >= 0) {
                        saque_holder -= 20;
                        saque20++;
                    }
                    else if (saque_holder - 10 >= 0 && cedulas10 - 1 - saque10 >= 0) {
                        saque_holder -= 10;
                        saque10++;
                    }
                    else if (saque_holder - 5 >= 0 && cedulas5 - 1 - saque5 >= 0) {
                        saque_holder -= 5;
                        saque5++;
                    }
                    else if (saque_holder - 2 >= 0 && cedulas2 - 1 - saque2 >= 0) {
                        saque_holder -= 2;
                        saque2++;
                    }
                    else if (saque_holder - 1 >= 0 && cedulas1 - 1 - saque1 >= 0) {
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
                if (saque_holder == 0 ) { //foi possivel retirar o dinheiro
                    //converter pra texto
                    strcpy(valExtenso, ""); //resetar o valor extenso
                    e6 = saque % 10;
                    e5 = (saque % 100) / 10;
                    e4 = (saque % 1000) / 100;
                    e3 = (saque % 10000) / 1000;
                    e2 = (saque % 100000) / 10000;
                    e1 = (saque % 1000000) / 100000;
                    if (e1 == 1 && e2 != 0 && e3 != 0) //primeiro dígito [0] 0 0 0 0 0 só pode ser 0 ou 1
                        strcat(valExtenso, "cento e ");
                    else if (e1 == 1 && e2 == 0 && e3 == 0) 
                        strcat(valExtenso, "cem ");

                    if(e2 != 0) { //segundo dígito 0 [0] 0 0 0 0
                        if(e2 == 1 && e3 == 0) //onze, doze, etc
                            strcat(valExtenso, "dez ");
                        else if(e2 == 1 && e3 == 1) 
                            strcat(valExtenso, "onze ");
                        else if(e2 == 1 && e3 == 2) 
                            strcat(valExtenso, "doze ");
                        else if(e2 == 1 && e3 == 3) 
                            strcat(valExtenso, "treze "); 
                        else if(e2 == 1 && e3 == 4) 
                            strcat(valExtenso, "quatorze "); 
                        else if(e2 == 1 && e3 == 5) 
                            strcat(valExtenso, "quinze "); 
                        else if(e2 == 1 && e3 == 6) 
                            strcat(valExtenso, "dezesseis "); 
                        else if(e2 == 1 && e3 == 7) 
                            strcat(valExtenso, "dezessete "); 
                        else if(e2 == 1 && e3 == 8) 
                            strcat(valExtenso, "dezoito "); 
                        else if(e2 == 1 && e3 == 9) 
                            strcat(valExtenso, "dezenove "); 
                        else if (e2 == 2)
                            strcat(valExtenso, "vinte ");
                        else if (e2 == 3)
                            strcat(valExtenso, "trinta ");
                        else if (e2 == 4)
                            strcat(valExtenso, "quarenta ");
                        else if (e2 == 5)
                            strcat(valExtenso, "cinquenta ");
                        else if (e2 == 6)
                            strcat(valExtenso, "sessenta ");
                        else if (e2 == 7)
                            strcat(valExtenso, "setenta ");
                        else if (e2 == 8)
                            strcat(valExtenso, "oitenta ");
                        else if (e2 == 9)
                            strcat(valExtenso, "noventa ");            
                    }
                    if(e3 != 0 && e2 != 1) {
                        if(e2 != 0 || e1 != 0)
                            strcat(valExtenso, "e ");

                        if(e3 == 1 && (e2 != 0 || e1 != 0)) 
                            strcat(valExtenso, "um ");
                        else if(e3 == 2) 
                            strcat(valExtenso, "dois ");
                        else if(e3 == 3) 
                            strcat(valExtenso, "tres "); 
                        else if(e3 == 4) 
                            strcat(valExtenso, "quatro "); 
                        else if(e3 == 5) 
                            strcat(valExtenso, "cinco "); 
                        else if(e3 == 6) 
                            strcat(valExtenso, "seis "); 
                        else if(e3 == 7) 
                            strcat(valExtenso, "sete "); 
                        else if(e3 == 8) 
                            strcat(valExtenso, "oito "); 
                        else if(e3 == 9) 
                            strcat(valExtenso, "nove ");
                    }
                    // "Não se emprega a conjunção entre os milhares e as centenas, salvo quando o número terminar numa centena com dois zeros"
                    // Exemplo: 1800 = mil e oitocentos
                    if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0)))
                        strcat(valExtenso, "mil e ");
                    else if(e1 != 0 || e2 != 0 || e3 != 0)
                        strcat(valExtenso, "mil ");
                    
                    //acabou a casa dos milhares, agora da pra repetir o codigo e mudar as variaveis
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(valExtenso, "cem ");
                        else if(e4 == 1)
                            strcat(valExtenso, "cento ");
                        else if(e4 == 2)
                            strcat(valExtenso, "duzentos ");  
                        else if(e4 == 3)
                            strcat(valExtenso, "trezentos ");  
                        else if(e4 == 4)
                            strcat(valExtenso, "quatrocentos ");  
                        else if(e4 == 5)
                            strcat(valExtenso, "quinhentos ");  
                        else if(e4 == 6)
                            strcat(valExtenso, "seiscentos ");  
                        else if(e4 == 7)
                            strcat(valExtenso, "setecentos ");
                        else if(e4 == 8)
                            strcat(valExtenso, "oitocentos ");
                        else if(e4 == 9)
                            strcat(valExtenso, "novecentos ");       
                    }

                    if(e5 != 0) { //quinto dígito 0 0 0 0 [0] 0
                        if (e4 != 0)
                           strcat(valExtenso, "e ");

                        if(e5 == 1 && e6 == 0) //onze, doze, etc
                            strcat(valExtenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(valExtenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(valExtenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(valExtenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(valExtenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(valExtenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(valExtenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(valExtenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(valExtenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(valExtenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(valExtenso, "vinte ");
                        else if (e5 == 3)
                            strcat(valExtenso, "trinta ");
                        else if (e5 == 4)
                            strcat(valExtenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(valExtenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(valExtenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(valExtenso, "setenta ");
                        else if (e5 == 8)
                            strcat(valExtenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(valExtenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(valExtenso, "e ");

                        if(e6 == 1) 
                            strcat(valExtenso, "um ");
                        else if(e6 == 2) 
                            strcat(valExtenso, "dois ");
                        else if(e6 == 3) 
                            strcat(valExtenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(valExtenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(valExtenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(valExtenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(valExtenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(valExtenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(valExtenso, "nove ");  
                    }

                    strcpy(flexaoReal, "real");
                    if(saque > 1) //plural e singular
                        strcpy(flexaoReal, "reais");
                    //se for 1 real vai printar 1 real ao invés de 1 reais. gramática é importante
                    printf("Saque realizado! A quantia de %s(%d) %s foi retirada!\n\n", valExtenso, saque, flexaoReal);
                    printf("A retirada do dinheiro sera distribuida em:\n");
                    if (saque450 == 1) printf("%d cedula de 450 reais\n", saque450);
                    else if (saque450 > 1) printf("%d cedulas de 450 reais\n", saque450);

                    if (saque250 == 1) printf("%d cedula de 250 reais\n", saque250);
                    else if (saque250 > 1) printf("%d cedulas de 250 reais\n", saque250);

                    if (saque50 == 1) printf("%d cedula de 50 reais\n", saque50);
                    else if (saque50 > 1) printf("%d cedulas de 50 reais\n", saque50);

                    if (saque20 == 1) printf("%d cedula de 20 reais\n", saque20);
                    else if (saque20 > 1) printf("%d cedulas de 20 reais\n", saque20);

                    if (saque10 == 1) printf("%d cedula de 10 reais\n", saque10);
                    else if (saque10 > 1) printf("%d cedulas de 10 reais\n", saque10);

                    if (saque5 == 1) printf("%d cedula de 5 reais\n", saque5);
                    else if (saque5 > 1) printf("%d cedulas de 5 reais\n", saque5);

                    if (saque2 == 1) printf("%d cedula de 2 reais\n", saque2);
                    else if (saque2 > 1) printf("%d cedulas de 2 reais\n", saque2);

                    if (saque1 == 1) printf("%d cedula de 1 real\n", saque1);
                    else if (saque1 > 1) printf("%d cedulas de 1 real\n", saque1);

                    printf("\n");
                    totalCedulas = cedulas450 + cedulas250 + cedulas50 + cedulas20 + cedulas10 + cedulas5 + cedulas2 + cedulas1;
                    saldo -= saque; //o saldo PRECISA ser calculado aqui
                    totalSacado += saque;
                }
            break;
            case 2: // menu gerente
                do {
                    system("cls");
                    printf("--------<[ Menu gerente ]>--------\n(1) Valor total sacado\n(2) Valor do saldo existente\n(3) Quantidade de cedulas existentes\n(4) Abastecer o caixa eletronico\n(5) Voltar ao menu principal\n\n -> Sua escolha: ");
                    scanf("%d", &escolhaGerente);
                    switch(escolhaGerente){
                        case 1: //valor total sacado
                            system("cls");
                            printf("\n -> Sua escolha:\n (1). Valor total sacado\n\n");
                            strcpy(valExtenso, ""); //resetar o valor extenso
                            if(totalSacado == 0)
                                strcpy(valExtenso, "zero ");
                            else {
                                e6 = totalSacado % 10;
                                e5 = (totalSacado % 100) / 10;
                                e4 = (totalSacado % 1000) / 100;
                                e3 = (totalSacado % 10000) / 1000;
                                e2 = (totalSacado % 100000) / 10000;
                                e1 = (totalSacado % 1000000) / 100000;
                                // o valor sacado mostrará numeros por extenso de 0 até 999.999
                                if(e1 != 0) {  //primeiro dígito [0] 0 0 0 0 0
                                    if (e1 == 1 && e2 == 0 && e3 == 0) 
                                        strcat(valExtenso, "cem ");
                                    else if (e1 == 1)
                                        strcat(valExtenso, "cento ");
                                    else if (e1 == 2)
                                        strcat(valExtenso, "duzentos ");
                                    else if (e1 == 3)
                                        strcat(valExtenso, "trezentos ");
                                    else if (e1 == 4)
                                        strcat(valExtenso, "quatrocentos ");
                                    else if (e1 == 5)
                                        strcat(valExtenso, "quinhentos ");
                                    else if (e1 == 6)
                                        strcat(valExtenso, "seiscentos ");
                                    else if (e1 == 7)
                                        strcat(valExtenso, "setecentos ");
                                    else if (e1 == 8)
                                        strcat(valExtenso, "oitocentos ");
                                    else if (e1 == 9)
                                        strcat(valExtenso, "novecentos ");
                                }


                                if(e2 != 0) { //segundo dígito 0 [0] 0 0 0 0
                                    if(e1 != 0)
                                        strcat(valExtenso, "e ");
                                    if(e2 == 1 && e3 == 0) //onze, doze, etc
                                        strcat(valExtenso, "dez ");
                                    else if(e2 == 1 && e3 == 1) 
                                        strcat(valExtenso, "onze ");
                                    else if(e2 == 1 && e3 == 2) 
                                        strcat(valExtenso, "doze ");
                                    else if(e2 == 1 && e3 == 3) 
                                        strcat(valExtenso, "treze "); 
                                    else if(e2 == 1 && e3 == 4) 
                                        strcat(valExtenso, "quatorze "); 
                                    else if(e2 == 1 && e3 == 5) 
                                        strcat(valExtenso, "quinze "); 
                                    else if(e2 == 1 && e3 == 6) 
                                        strcat(valExtenso, "dezesseis "); 
                                    else if(e2 == 1 && e3 == 7) 
                                        strcat(valExtenso, "dezessete "); 
                                    else if(e2 == 1 && e3 == 8) 
                                        strcat(valExtenso, "dezoito "); 
                                    else if(e2 == 1 && e3 == 9) 
                                        strcat(valExtenso, "dezenove "); 
                                    else if (e2 == 2)
                                        strcat(valExtenso, "vinte ");
                                    else if (e2 == 3)
                                        strcat(valExtenso, "trinta ");
                                    else if (e2 == 4)
                                        strcat(valExtenso, "quarenta ");
                                    else if (e2 == 5)
                                        strcat(valExtenso, "cinquenta ");
                                    else if (e2 == 6)
                                        strcat(valExtenso, "sessenta ");
                                    else if (e2 == 7)
                                        strcat(valExtenso, "setenta ");
                                    else if (e2 == 8)
                                        strcat(valExtenso, "oitenta ");
                                    else if (e2 == 9)
                                        strcat(valExtenso, "noventa ");            
                                }
                                if(e3 != 0 && e2 != 1) {
                                    if(e2 != 0 || e1 != 0)
                                        strcat(valExtenso, "e ");

                                    if(e3 == 1 && (e2 != 0 || e1 != 0)) 
                                        strcat(valExtenso, "um ");
                                    else if(e3 == 2) 
                                        strcat(valExtenso, "dois ");
                                    else if(e3 == 3) 
                                        strcat(valExtenso, "tres "); 
                                    else if(e3 == 4) 
                                        strcat(valExtenso, "quatro "); 
                                    else if(e3 == 5) 
                                        strcat(valExtenso, "cinco "); 
                                    else if(e3 == 6) 
                                        strcat(valExtenso, "seis "); 
                                    else if(e3 == 7) 
                                        strcat(valExtenso, "sete "); 
                                    else if(e3 == 8) 
                                        strcat(valExtenso, "oito "); 
                                    else if(e3 == 9) 
                                        strcat(valExtenso, "nove ");
                                }
                                // "Não se emprega a conjunção entre os milhares e as centenas, salvo quando o número terminar numa centena com dois zeros"
                                // Exemplo: 1800 = mil e oitocentos
                                if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0)))
                                    strcat(valExtenso, "mil e ");
                                else if(e1 != 0 || e2 != 0 || e3 != 0)
                                    strcat(valExtenso, "mil ");
                                
                                //acabou a casa dos milhares, agora da pra repetir o codigo e mudar as variaveis
                                if (e4 != 0){
                                    if(e4 == 1 && e5 == 0 && e6 == 0)
                                        strcat(valExtenso, "cem ");
                                    else if(e4 == 1)
                                        strcat(valExtenso, "cento ");
                                    else if(e4 == 2)
                                        strcat(valExtenso, "duzentos ");  
                                    else if(e4 == 3)
                                        strcat(valExtenso, "trezentos ");  
                                    else if(e4 == 4)
                                        strcat(valExtenso, "quatrocentos ");  
                                    else if(e4 == 5)
                                        strcat(valExtenso, "quinhentos ");  
                                    else if(e4 == 6)
                                        strcat(valExtenso, "seiscentos ");  
                                    else if(e4 == 7)
                                        strcat(valExtenso, "setecentos ");
                                    else if(e4 == 8)
                                        strcat(valExtenso, "oitocentos ");
                                    else if(e4 == 9)
                                        strcat(valExtenso, "novecentos ");       
                                }

                                if(e5 != 0) { //quinto dígito 0 0 0 0 [0] 0
                                    if (e4 != 0)
                                    strcat(valExtenso, "e ");

                                    if(e5 == 1 && e6 == 0) //onze, doze, etc
                                        strcat(valExtenso, "dez ");
                                    else if(e5 == 1 && e6 == 1) 
                                        strcat(valExtenso, "onze ");
                                    else if(e5 == 1 && e6 == 2) 
                                        strcat(valExtenso, "doze ");
                                    else if(e5 == 1 && e6 == 3) 
                                        strcat(valExtenso, "treze "); 
                                    else if(e5 == 1 && e6 == 4) 
                                        strcat(valExtenso, "quatorze "); 
                                    else if(e5 == 1 && e6 == 5) 
                                        strcat(valExtenso, "quinze "); 
                                    else if(e5 == 1 && e6 == 6) 
                                        strcat(valExtenso, "dezesseis "); 
                                    else if(e5 == 1 && e6 == 7) 
                                        strcat(valExtenso, "dezessete" ); 
                                    else if(e5 == 1 && e6 == 8) 
                                        strcat(valExtenso, "dezoito "); 
                                    else if(e5 == 1 && e6 == 9) 
                                        strcat(valExtenso, "dezenove "); 
                                    else if (e5 == 2)
                                        strcat(valExtenso, "vinte ");
                                    else if (e5 == 3)
                                        strcat(valExtenso, "trinta ");
                                    else if (e5 == 4)
                                        strcat(valExtenso, "quarenta ");
                                    else if (e5 == 5)
                                        strcat(valExtenso, "cinquenta ");
                                    else if (e5 == 6)
                                        strcat(valExtenso, "sessenta ");
                                    else if (e5 == 7)
                                        strcat(valExtenso, "setenta ");
                                    else if (e5 == 8)
                                        strcat(valExtenso, "oitenta ");
                                    else if (e5 == 9)
                                        strcat(valExtenso, "noventa ");             
                                }
                                if(e6 != 0 && e5 != 1) {
                                    if(e5 != 0 || e4 != 0)
                                        strcat(valExtenso, "e ");

                                    if(e6 == 1) 
                                        strcat(valExtenso, "um ");
                                    else if(e6 == 2) 
                                        strcat(valExtenso, "dois ");
                                    else if(e6 == 3) 
                                        strcat(valExtenso, "tres "); 
                                    else if(e6 == 4) 
                                        strcat(valExtenso, "quatro "); 
                                    else if(e6 == 5) 
                                        strcat(valExtenso, "cinco "); 
                                    else if(e6 == 6) 
                                        strcat(valExtenso, "seis "); 
                                    else if(e6 == 7) 
                                        strcat(valExtenso, "sete "); 
                                    else if(e6 == 8) 
                                        strcat(valExtenso, "oito "); 
                                    else if(e6 == 9) 
                                        strcat(valExtenso, "nove ");  
                                }
                            }
                            strcpy(flexaoReal, "real");
                            if(totalSacado > 1) //plural e singular
                                strcpy(flexaoReal, "reais");
                                printf(" -> O valor total sacado nesse caixa eletronico foi de %s(%d) %s\n\n", valExtenso, totalSacado, flexaoReal);
                        break;



                        case 2: //Valor do saldo existente
                            //não se calcula o saldo aqui, já que o saldo só atualizaria quando se escolhesse essa opção
                            system("cls");
                            printf("\n -> Sua escolha:\n (2). Saldo existente\n\n");
                            strcpy(valExtenso, ""); //resetar o valor extenso
                            if(saldo == 0)
                                strcpy(valExtenso, "zero ");
                            else {
                                e6 = saldo % 10;
                                e5 = (saldo % 100) / 10;
                                e4 = (saldo % 1000) / 100;
                                e3 = (saldo % 10000) / 1000;
                                e2 = (saldo % 100000) / 10000;
                                e1 = (saldo % 1000000) / 100000;
                                if (e1 == 1 && e2 != 0 && e3 != 0) //primeiro dígito [0] 0 0 0 0 0 só pode ser 0 ou 1
                                    strcat(valExtenso, "cento e ");
                                else if (e1 == 1 && e2 == 0 && e3 == 0) 
                                    strcat(valExtenso, "cem ");

                                if(e2 != 0) { //segundo dígito 0 [0] 0 0 0 0
                                    if(e2 == 1 && e3 == 0) //onze, doze, etc
                                        strcat(valExtenso, "dez ");
                                    else if(e2 == 1 && e3 == 1) 
                                        strcat(valExtenso, "onze ");
                                    else if(e2 == 1 && e3 == 2) 
                                        strcat(valExtenso, "doze ");
                                    else if(e2 == 1 && e3 == 3) 
                                        strcat(valExtenso, "treze "); 
                                    else if(e2 == 1 && e3 == 4) 
                                        strcat(valExtenso, "quatorze "); 
                                    else if(e2 == 1 && e3 == 5) 
                                        strcat(valExtenso, "quinze "); 
                                    else if(e2 == 1 && e3 == 6) 
                                        strcat(valExtenso, "dezesseis "); 
                                    else if(e2 == 1 && e3 == 7) 
                                        strcat(valExtenso, "dezessete "); 
                                    else if(e2 == 1 && e3 == 8) 
                                        strcat(valExtenso, "dezoito "); 
                                    else if(e2 == 1 && e3 == 9) 
                                        strcat(valExtenso, "dezenove "); 
                                    else if (e2 == 2)
                                        strcat(valExtenso, "vinte ");
                                    else if (e2 == 3)
                                        strcat(valExtenso, "trinta ");
                                    else if (e2 == 4)
                                        strcat(valExtenso, "quarenta ");
                                    else if (e2 == 5)
                                        strcat(valExtenso, "cinquenta ");
                                    else if (e2 == 6)
                                        strcat(valExtenso, "sessenta ");
                                    else if (e2 == 7)
                                        strcat(valExtenso, "setenta ");
                                    else if (e2 == 8)
                                        strcat(valExtenso, "oitenta ");
                                    else if (e2 == 9)
                                        strcat(valExtenso, "noventa ");            
                                }
                                if(e3 != 0 && e2 != 1) {
                                    if(e2 != 0 || e1 != 0)
                                        strcat(valExtenso, "e ");

                                    if(e3 == 1 && (e2 != 0 || e1 != 0)) 
                                        strcat(valExtenso, "um ");
                                    else if(e3 == 2) 
                                        strcat(valExtenso, "dois ");
                                    else if(e3 == 3) 
                                        strcat(valExtenso, "tres "); 
                                    else if(e3 == 4) 
                                        strcat(valExtenso, "quatro "); 
                                    else if(e3 == 5) 
                                        strcat(valExtenso, "cinco "); 
                                    else if(e3 == 6) 
                                        strcat(valExtenso, "seis "); 
                                    else if(e3 == 7) 
                                        strcat(valExtenso, "sete "); 
                                    else if(e3 == 8) 
                                        strcat(valExtenso, "oito "); 
                                    else if(e3 == 9) 
                                        strcat(valExtenso, "nove ");
                                }
                                // "Não se emprega a conjunção entre os milhares e as centenas, salvo quando o número terminar numa centena com dois zeros"
                                // Exemplo: 1800 = mil e oitocentos
                                if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0)))
                                    strcat(valExtenso, "mil e ");
                                else if(e1 != 0 || e2 != 0 || e3 != 0)
                                    strcat(valExtenso, "mil ");
                                
                                //acabou a casa dos milhares, agora da pra repetir o codigo e mudar as variaveis
                                if (e4 != 0){
                                    if(e4 == 1 && e5 == 0 && e6 == 0)
                                        strcat(valExtenso, "cem ");
                                    else if(e4 == 1)
                                        strcat(valExtenso, "cento ");
                                    else if(e4 == 2)
                                        strcat(valExtenso, "duzentos ");  
                                    else if(e4 == 3)
                                        strcat(valExtenso, "trezentos ");  
                                    else if(e4 == 4)
                                        strcat(valExtenso, "quatrocentos ");  
                                    else if(e4 == 5)
                                        strcat(valExtenso, "quinhentos ");  
                                    else if(e4 == 6)
                                        strcat(valExtenso, "seiscentos ");  
                                    else if(e4 == 7)
                                        strcat(valExtenso, "setecentos ");
                                    else if(e4 == 8)
                                        strcat(valExtenso, "oitocentos ");
                                    else if(e4 == 9)
                                        strcat(valExtenso, "novecentos ");       
                                }

                                if(e5 != 0) { //quinto dígito 0 0 0 0 [0] 0
                                    if (e4 != 0)
                                    strcat(valExtenso, "e ");

                                    if(e5 == 1 && e6 == 0) //onze, doze, etc
                                        strcat(valExtenso, "dez ");
                                    else if(e5 == 1 && e6 == 1) 
                                        strcat(valExtenso, "onze ");
                                    else if(e5 == 1 && e6 == 2) 
                                        strcat(valExtenso, "doze ");
                                    else if(e5 == 1 && e6 == 3) 
                                        strcat(valExtenso, "treze "); 
                                    else if(e5 == 1 && e6 == 4) 
                                        strcat(valExtenso, "quatorze "); 
                                    else if(e5 == 1 && e6 == 5) 
                                        strcat(valExtenso, "quinze "); 
                                    else if(e5 == 1 && e6 == 6) 
                                        strcat(valExtenso, "dezesseis "); 
                                    else if(e5 == 1 && e6 == 7) 
                                        strcat(valExtenso, "dezessete "); 
                                    else if(e5 == 1 && e6 == 8) 
                                        strcat(valExtenso, "dezoito "); 
                                    else if(e5 == 1 && e6 == 9) 
                                        strcat(valExtenso, "dezenove "); 
                                    else if (e5 == 2)
                                        strcat(valExtenso, "vinte ");
                                    else if (e5 == 3)
                                        strcat(valExtenso, "trinta ");
                                    else if (e5 == 4)
                                        strcat(valExtenso, "quarenta ");
                                    else if (e5 == 5)
                                        strcat(valExtenso, "cinquenta ");
                                    else if (e5 == 6)
                                        strcat(valExtenso, "sessenta ");
                                    else if (e5 == 7)
                                        strcat(valExtenso, "setenta ");
                                    else if (e5 == 8)
                                        strcat(valExtenso, "oitenta ");
                                    else if (e5 == 9)
                                        strcat(valExtenso, "noventa ");             
                                }
                                if(e6 != 0 && e5 != 1) {
                                    if(e5 != 0 || e4 != 0)
                                        strcat(valExtenso, "e ");

                                    if(e6 == 1) 
                                        strcat(valExtenso, "um ");
                                    else if(e6 == 2) 
                                        strcat(valExtenso, "dois ");
                                    else if(e6 == 3) 
                                        strcat(valExtenso, "tres "); 
                                    else if(e6 == 4) 
                                        strcat(valExtenso, "quatro "); 
                                    else if(e6 == 5) 
                                        strcat(valExtenso, "cinco "); 
                                    else if(e6 == 6) 
                                        strcat(valExtenso, "seis "); 
                                    else if(e6 == 7) 
                                        strcat(valExtenso, "sete "); 
                                    else if(e6 == 8) 
                                        strcat(valExtenso, "oito "); 
                                    else if(e6 == 9) 
                                        strcat(valExtenso, "nove ");  
                                }
                            }
                            strcpy(flexaoReal, "reais");
                            if(saldo == 1) strcpy(flexaoReal, "real") ;
                            printf(" -> Saldo existente: %s(%d) %s\n\n", valExtenso, saldo, flexaoReal);
                        break;


         
                        case 3: //quantidade de cedulas existentes
                            system("cls");
                            printf("\n -> Sua escolha:\n (3). Quantidade de cedulas existentes\n\n");
                            for (int i = 0; i <= 8; i++){ //evitar escrever a mesma linha de código 9 vezes (mesmo sem usar função)
                                if (i == 0) {
                                    checadorCedulas = cedulas450;
                                    localizador = 450;
                                }
                                else if (i == 1) { 
                                    checadorCedulas = cedulas250;
                                    localizador = 250;
                                }
                                else if (i == 2) { 
                                    checadorCedulas = cedulas50;
                                    localizador = 50;
                                }
                                else if (i == 3) { 
                                    checadorCedulas = cedulas20;
                                    localizador = 20;
                                }
                                else if (i == 4) { 
                                    checadorCedulas = cedulas10;
                                    localizador = 10;
                                }
                                else if (i == 5) { 
                                    checadorCedulas = cedulas5;
                                    localizador = 5;
                                }
                                else if (i == 6) { 
                                    checadorCedulas = cedulas2;
                                    localizador = 2;
                                }
                                else if (i == 7) { 
                                    checadorCedulas = cedulas1;
                                    localizador = 1;
                                }
                                else if (i == 8)
                                    checadorCedulas = totalCedulas;
                                    

                                strcpy(valExtenso, "");
                                if(checadorCedulas == 0) // o codigo não está comentado pra não repetir os mesmos comentários
                                    strcpy(valExtenso, "zero ");
                                else {
                                    e6 = checadorCedulas % 10;
                                    e5 = (checadorCedulas % 100) / 10;
                                    e4 = (checadorCedulas % 1000) / 100;
                                    e3 = (checadorCedulas % 10000) / 1000;
                                    e2 = (checadorCedulas % 100000) / 10000;
                                    
                                    // a única diferença é que não há o e1, já que o valor máximo é 22500
                                    if(e2 != 0) {
                                        if(e2 == 1 && e3 == 0)
                                            strcat(valExtenso, "dez ");
                                        else if(e2 == 1 && e3 == 1) 
                                            strcat(valExtenso, "onze ");
                                        else if(e2 == 1 && e3 == 2) 
                                            strcat(valExtenso, "doze ");
                                        else if(e2 == 1 && e3 == 3) 
                                            strcat(valExtenso, "treze "); 
                                        else if(e2 == 1 && e3 == 4) 
                                            strcat(valExtenso, "quatorze "); 
                                        else if(e2 == 1 && e3 == 5) 
                                            strcat(valExtenso, "quinze "); 
                                        else if(e2 == 1 && e3 == 6) 
                                            strcat(valExtenso, "dezesseis "); 
                                        else if(e2 == 1 && e3 == 7) 
                                            strcat(valExtenso, "dezessete "); 
                                        else if(e2 == 1 && e3 == 8) 
                                            strcat(valExtenso, "dezoito "); 
                                        else if(e2 == 1 && e3 == 9) 
                                            strcat(valExtenso, "dezenove "); 
                                        else if (e2 == 2)
                                            strcat(valExtenso, "vinte ");
                                        else if (e2 == 3)
                                            strcat(valExtenso, "trinta ");
                                        else if (e2 == 4)
                                            strcat(valExtenso, "quarenta ");
                                        else if (e2 == 5)
                                            strcat(valExtenso, "cinquenta ");
                                        else if (e2 == 6)
                                            strcat(valExtenso, "sessenta ");
                                        else if (e2 == 7)
                                            strcat(valExtenso, "setenta ");
                                        else if (e2 == 8)
                                            strcat(valExtenso, "oitenta ");
                                        else if (e2 == 9)
                                            strcat(valExtenso, "noventa ");            
                                    }
                                    if(e3 != 0 && e2 != 1) {
                                        if(e2 != 0)
                                            strcat(valExtenso, "e ");

                                        if(e3 == 1 && e2 != 0)
                                            strcat(valExtenso, "uma ");
                                        else if(e3 == 2) 
                                            strcat(valExtenso, "duas ");
                                        else if(e3 == 3) 
                                            strcat(valExtenso, "tres "); 
                                        else if(e3 == 4) 
                                            strcat(valExtenso, "quatro "); 
                                        else if(e3 == 5) 
                                            strcat(valExtenso, "cinco "); 
                                        else if(e3 == 6) 
                                            strcat(valExtenso, "seis "); 
                                        else if(e3 == 7) 
                                            strcat(valExtenso, "sete "); 
                                        else if(e3 == 8) 
                                            strcat(valExtenso, "oito "); 
                                        else if(e3 == 9) 
                                            strcat(valExtenso, "nove ");
                                    }

                                    if((e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0)))
                                        strcat(valExtenso, "mil e ");
                                    else if(e2 != 0 || e3 != 0)
                                        strcat(valExtenso, "mil ");
                                    
                                    if (e4 != 0){
                                        if(e4 == 1 && e5 == 0 && e6 == 0)
                                            strcat(valExtenso, "cem ");
                                        else if(e4 == 1)
                                            strcat(valExtenso, "cento ");
                                        else if(e4 == 2)
                                            strcat(valExtenso, "duzentas ");  
                                        else if(e4 == 3)
                                            strcat(valExtenso, "trezentas ");  
                                        else if(e4 == 4)
                                            strcat(valExtenso, "quatrocentas ");  
                                        else if(e4 == 5)
                                            strcat(valExtenso, "quinhentas ");  
                                        else if(e4 == 6)
                                            strcat(valExtenso, "seiscentas ");  
                                        else if(e4 == 7)
                                            strcat(valExtenso, "setecentas ");
                                        else if(e4 == 8)
                                            strcat(valExtenso, "oitocentas ");
                                        else if(e4 == 9)
                                            strcat(valExtenso, "novecentas ");       
                                    }

                                    if(e5 != 0) {
                                        if (e4 != 0)
                                        strcat(valExtenso, "e ");

                                        if(e5 == 1 && e6 == 0)
                                            strcat(valExtenso, "dez ");
                                        else if(e5 == 1 && e6 == 1) 
                                            strcat(valExtenso, "onze ");
                                        else if(e5 == 1 && e6 == 2) 
                                            strcat(valExtenso, "doze ");
                                        else if(e5 == 1 && e6 == 3) 
                                            strcat(valExtenso, "treze "); 
                                        else if(e5 == 1 && e6 == 4) 
                                            strcat(valExtenso, "quatorze "); 
                                        else if(e5 == 1 && e6 == 5) 
                                            strcat(valExtenso, "quinze "); 
                                        else if(e5 == 1 && e6 == 6) 
                                            strcat(valExtenso, "dezesseis "); 
                                        else if(e5 == 1 && e6 == 7) 
                                            strcat(valExtenso, "dezessete "); 
                                        else if(e5 == 1 && e6 == 8) 
                                            strcat(valExtenso, "dezoito "); 
                                        else if(e5 == 1 && e6 == 9) 
                                            strcat(valExtenso, "dezenove "); 
                                        else if (e5 == 2)
                                            strcat(valExtenso, "vinte ");
                                        else if (e5 == 3)
                                            strcat(valExtenso, "trinta ");
                                        else if (e5 == 4)
                                            strcat(valExtenso, "quarenta ");
                                        else if (e5 == 5)
                                            strcat(valExtenso, "cinquenta ");
                                        else if (e5 == 6)
                                            strcat(valExtenso, "sessenta ");
                                        else if (e5 == 7)
                                            strcat(valExtenso, "setenta ");
                                        else if (e5 == 8)
                                            strcat(valExtenso, "oitenta ");
                                        else if (e5 == 9)
                                            strcat(valExtenso, "noventa ");             
                                    }
                                    if(e6 != 0 && e5 != 1) {
                                        if(e5 != 0 || e4 != 0)
                                            strcat(valExtenso, "e ");

                                        if(e6 == 1) 
                                            strcat(valExtenso, "uma ");
                                        else if(e6 == 2) 
                                            strcat(valExtenso, "duas ");
                                        else if(e6 == 3) 
                                            strcat(valExtenso, "tres "); 
                                        else if(e6 == 4) 
                                            strcat(valExtenso, "quatro "); 
                                        else if(e6 == 5) 
                                            strcat(valExtenso, "cinco "); 
                                        else if(e6 == 6) 
                                            strcat(valExtenso, "seis "); 
                                        else if(e6 == 7) 
                                            strcat(valExtenso, "sete "); 
                                        else if(e6 == 8) 
                                            strcat(valExtenso, "oito "); 
                                        else if(e6 == 9) 
                                            strcat(valExtenso, "nove ");  
                                    }
                                }
                                strcpy(flexaoReal, "real");
                                strcpy(flexaoCedula, "cedula");
                                if(localizador != 1) strcpy(flexaoReal, "reais");
                                if (checadorCedulas != 1) strcpy(flexaoCedula, "cedulas");

                                if(i <= 7)
                                    printf("%d: a maquina possui %s(%d) %s de %d %s\n", localizador, valExtenso, checadorCedulas, flexaoCedula, localizador, flexaoReal);
    
                                else 
                                    printf("\nQuantidade total de %s na maquina: %s(%d)\n\n", flexaoCedula, valExtenso, checadorCedulas);
                            
                            }
                        break;



                        case 4: //Abastecer caixa eletronico
                            do {
                                system("cls");
                                printf("-------<[ Menu abastecer o caixa eletronico ]>-------\n(450) Cedulas de 450\n(250) Cedulas de 250\n(50) Cedulas de 50\n(20) Cedulas de 20\n(10) Cedulas de 10\n(5) Cedulas de 5\n(2) Cedulas de 2\n(1) Cedulas de 1\n(0) Voltar para o menu gerente\n\n -> Sua escolha: ");
                                scanf("%d", &escolhaCedulas);
                                switch(escolhaCedulas){
                                    case 450:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite450 < qntCedulas + cedulas450) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 450 reais!\n", qntCedulas, limite450);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas450 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n-> Reabastecido %d %s de R$450!\n", qntCedulas, flexaoCedula);
                                    break;

                                    case 250:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite250 < qntCedulas + cedulas250) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 250 reais!\n", qntCedulas, limite250);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas250 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n-> Reabastecido %d %s de 250\n", qntCedulas, flexaoCedula);
                                    break;

                                    case 50:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite50 < qntCedulas + cedulas50) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 50 reais!\n", qntCedulas, limite50);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas50 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n-> Reabastecido %d %s R$50!\n", qntCedulas, flexaoCedula);
                                    break;

                                    case 20:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite20 < qntCedulas + cedulas20) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 20 reais!\n", qntCedulas, limite20);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas20 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n-> Reabastecido %d %s R$20!\n", qntCedulas, flexaoCedula);
                                    break;

                                    case 10:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite10 < qntCedulas + cedulas10) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 10 reais!\n", qntCedulas, limite10);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas10 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n-> Reabastecido %d %s R$10!\n", qntCedulas, flexaoCedula);
                                    break;

                                    case 5:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite5 < qntCedulas + cedulas5) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 5 reais!\n", qntCedulas, limite5);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas5 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n->Reabastecido %d %s de R$5!\n", qntCedulas, flexaoCedula);
                                    break;

                                    case 2:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite2 < qntCedulas + cedulas2) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 2 reais!\n", qntCedulas, limite2);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas2 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n-> Reabastecido %d %s de R$2!\n", qntCedulas, flexaoCedula);
                                    break;

                                    case 1:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite1 < qntCedulas + cedulas1) {
                                            printf(" [ERRO!] A quantidade (%d) ultrapassa o limite de %d cedulas de 1 real!\n", qntCedulas, limite1);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf(" [ERRO!] Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas1 += qntCedulas;
                                        strcpy(flexaoCedula,  "cedula");
                                        if (qntCedulas > 1) strcpy(flexaoCedula, "cedulas");
                                        printf("\n-> Reabastecido %d %s de R$1!\n", qntCedulas, flexaoCedula);
                                    break;
                                    case 0:
                                        printf("Retornando ao menu gerente...\n\n");
                                    break;
                                    default:
                                        printf(" [ERRO!] Escolha uma opcao valida!\n");
                                }
                                //atualizar valores depois do abastecimento
                                totalCedulas = cedulas450 + cedulas250 + cedulas50 + cedulas20 + cedulas10 + cedulas5 + cedulas2 + cedulas1;
                                saldo = cedulas450 * 450 + cedulas250 * 250 + cedulas50 * 50 + cedulas20 * 20 + cedulas10 * 10 + cedulas5 * 5 + cedulas2 * 2 + cedulas1;
                                if(escolhaCedulas != 0)
                                    system("pause");
                            } while (escolhaCedulas != 0);
                        break;


                        
                        case 5: //sair
                            printf("Voltando ao menu principal...\n\n");
                        break;
                        default:
                            printf(" [ERRO!] Escolha uma opcao valida!\n\n");
                    }
                    if(escolhaGerente != 5)
                        system("pause");
                } while (escolhaGerente != 5);


            break;
            case 3:
                printf("Finalizado...\n\n");
            break;
            default:
                printf(" [ERRO!] Escolha um valor valido!\n");
        }
        system("pause");
    } while (escolha != 3);
}