//Alunos:
//Gustavo Kermaunar Volobueff;
//Victor Keony;
//Vinícius Schautz;
//Emmerson Badocco;
//Gustavo Martins.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Objetivo: Limpa o buffer do teclado.
void flush_in(){ 
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n'){} 
}

//Objetivo: Reseta uma matriz.
void LimpaMatriz(char matriz[400][200]) {
    int i;

    for(i=0;i<400;i++) {
        strcpy(matriz[i], "\0");
    }
}

//Objetivo: Tranforma uma matriz em um vetor, para fazer a formatação novamente corretamente.
//Parâmetros: matriz é a matriz e array, o vetor.
void MatrizParaVetor(char matriz[400][200], char array[3200]) {
    int i;

    for(i=0;i<400;i++) {
        strcat(array, matriz[i]);
        strcat(array, " ");
    }
}

void MatrizParaVetorSEspaco(char matriz[400][200], char array[3200]) {
    int i;

    for(i=0;i<400;i++) {
        strcat(array, matriz[i]);
    }
}
//Objetivo: Formatar o texto original.
//Parâmetros: text: O texto original, textformat: O texto formatado. 
void FormataTexto(char text[], char textformat[400][200]) {

    char *token = strtok(text, " "), string[200], *virg, *ponto, *abreparent, *fechaparent;
    int j=0, i;

    strcpy(string, "\0");

    for(i=0;i<80;i++) {
        memmove(textformat[i], "\0", strlen(textformat[i]));
    }
   
    while(token) {
        strcat(string, token);
        strcat(string, " ");

        virg = strchr(token, ','); //Ponteiro para a vírgula em uma palavra.
        ponto = strchr(token, '.'); //Ponteiro para o ponto em uma palavra.
        abreparent = strchr(token, '(');
        fechaparent = strchr(token, ')');

        if(strlen(string)<=80) {
            strcat(textformat[j], token); //Adiciona uma palavra a matriz do texto formatado.
            strcat(textformat[j], " "); 
        }
        else{
            if(virg && strlen(string)==81) { //Somente a vírgula deve pular de linha.
                strncat(textformat[j], token, strlen(token)-1); //Faz com que a linha receba a palavra sem a vírgula.
                j++;
                strcpy(string, "\0");
                strcat(string, ",");
                strcat(string, " ");
                strcat(textformat[j], ",");
                strcat(textformat[j], " ");
                
            }
            else if(ponto && strlen(string)==82) {//Somente o ponto deve pular de linha.
                strncat(textformat[j], token, strlen(token)-1); //Faz com que a linha receba a palavra sem o ponto.
                j++;
                strcpy(string, "\0");
                strcat(string, ".");
                strcat(string, " ");
                strcat(textformat[j], ".");
                strcat(textformat[j], " ");
            }
            else if(abreparent && strlen(textformat[j])<80) {
                strcat(textformat[j], "(");
                j++;
                strcpy(string, "\0");
                strncat(string, token+1, strlen(token)-1);
                strncat(textformat[j], token+1, strlen(token)-1);
                strcat(textformat[j], " ");
            }
            else if(fechaparent && strlen(string)==81) {
                strncat(textformat[j], token, strlen(token)-1);
                j++;
                strcpy(string, "\0");
                strcat(string, ")");
                strcat(string, " ");
                strcat(textformat[j], ")");
                strcat(textformat[j], " ");
            }
            else { 
                j++;
                strcpy(string, "\0");
                strcat(string, token);
                strcat(string, " ");
                strcat(textformat[j], token);
                strcat(textformat[j], " ");
            }
        }

        token = strtok(NULL, " "); //Faz com que o ponteiro token continue varrendo a string.
    }
}

//Objetivo: Cumpre a função "a)" e "h)", de mostrar o texto formatado e alinhado a esquerda.
//Parâmetros: text é o texto já formatado.
void ImprimeTextFormatado(char text[400][200]) {
    int i=0, qnt=0;

    while(text[i][0]!=NULL) {
        qnt++;
        i++;
    } 

    for(i=0;i<qnt;i++) {    
        printf("%s\n", text[i]);
    }

}

//Objetivo: Função "b)" de mostrar uma palavra desejada pelo usuário quantas vezes a mesma apareceu e em 
//          qual(is) linha(s) e coluna(s).
//Parâmetros: textbase é o texto formatado; palavra é a palavra que deseja ser procurada.
void MostraPalavra(char textbase[400][200], char palavra[]) {
    int i=0, pos, qntrep=0;
    char string[200][400], *point, subs[] = {".................."};

    for(i=0;i<45;i++) {
        strcpy(string[i], textbase[i]); //Outro texto para não interferir no original formatado.
    }

    i=0;

    while(i != 80) {
        point = strstr(string[i], palavra); //Ponteiro que aponta para a primeira ocorrência da palavra.

        if(point) {
            pos = point - string[i]; //Posição da palavra.
            memmove(string[i]+pos, subs, strlen(palavra)); //Muda a substring que é igual a palavra desejada.
            qntrep++;
            printf("\n--> Linha: %d Coluna: %d;", i, pos);
        }
        else {
            i++;
        }
    }

    for(i=0;i<40;i++) {
        strcpy(string[i], "\0");
    }

    if(qntrep>0) 
        printf("\n--> A palavra [%s] apareceu: [%d] vez(es) no texto.\n\n", palavra, qntrep);
    else
        printf("\n--> A palavra [%s] nao foi encontrada!\n\n", palavra);

    system("pause");
}

//Objetivo: Substituir uma palavra dentro do texto formatado.
//Parâmetros: text é o texto formatado, palavra é a palavra que deve ser substituída e palavrasubs é a 
//            palavra que será trocada.
void SubstituiPalavra(char text[400][200], char palavra[], char palavrasubs[]) {
    int i=0, qnt=0, lin, j, pos, confirm=0, qntlin=0;
    char *point, *token, subscharpre[3], subscharpos[3];
    char string[200], palavramod[30], palavramodsubis[30], stringaux[40];

    strcpy(palavramod, "\0");
    strcpy(palavramodsubis, "\0");
    strcpy(string, "\0");
    strcpy(stringaux, "\0");

    while(text[i][0]) {
        qntlin++;
        i++;
    }

    i=0;

    while(i!=qntlin) {
        point = strstr(text[i], palavra); //Aponta para a palavra que deve ser trocada.

        if(point) {
            lin = i;

            pos = point - text[i];

            if(!isalpha(text[i][pos-1]) && !isblank(text[i][pos-1])) { //Caso haja algum caracter especial uma letra antes
                subscharpre[0] = text[i][pos-1];                      //da palavra
                strncpy(palavramod, subscharpre, 1);
                palavramod[1] = '\0';
                
                strcpy(palavramodsubis, subscharpre);
                palavramodsubis[1] = '\0';

                strcat(palavramod, palavra);
                strcat(palavramodsubis, palavrasubs);
            }
            else {
                strcpy(palavramod, palavra);
                strcpy(palavramodsubis, palavrasubs);
            }
            if(!isalpha(text[i][pos+strlen(palavra)]) && !isblank(text[i][pos+strlen(palavra)])) { //Caso haja algum caracter
                subscharpos[0] = text[i][pos+strlen(palavra)];                                    //depois.
                
                strcat(palavramod, subscharpos);
                strcat(palavramodsubis, subscharpos);
            }
            
            token = strtok(text[i], " "); //Ponteiro para as palavras da linha onde está a palavra.

            while(token) {
                if(strcmp(token, palavramod) == 0) {
                    strcat(string, palavramodsubis); //Caso encontre a palavra desejada, será substituída pela digitada.
                    strcat(string, " ");
                    confirm++;
                }
                else{
                    if(lin+1==qntlin) {//Caso deseje mudar alguma palavra que está junto ao link, para não bugar.
                        strncat(string, text[i], pos);
                        strncat(stringaux, text[i]+pos+strlen(palavra), strlen(text[i])-pos);
                        strcat(string, palavrasubs);
                        strcat(string, stringaux);

                        confirm++;
                    }
                    else {
                        strcat(string, token);
                        strcat(string, " ");
                    }
                }

                token = strtok(NULL, " ");
            }

            printf("\n--> Palavra [%s] substituida por [%s] com sucesso!\n\n", palavra, palavrasubs);
            strcpy(text[lin], string);  //Coloca novamente a linha que foi alterada na matriz.

            break;
        }
        else
            i++; //Pula a linha do texto.
    }
    if(confirm == 0)
        printf("\n--> A palavra [%s] nao foi encontrada!\n\n", palavra);
}

//Objetivo: Cumpre a função 'd)' de substituir todas as ocorrências de uma palavra.
//Parâmetros: palavra é a palavra a ser substituída e palavrasubs é a palavra que entrará no lugar.
void SubstituiVariasPalavras(char text[400][200], char palavra[], char palavrasubs[]) {

    int i=0, qntrep=0, pos;
    char *point, string[400][200], subs[] = {".............."};

    strcpy(string, "\0");

    for(i=0;i<80;i++) {
        strcpy(string[i], text[i]); //Outro texto para não interferir no original formatado.
    }

    i=0;

    while(i != 80) {
        point = strstr(string[i], palavra); //Ponteiro que aponta para a primeira ocorrência da palavra.

        if(point) {
            pos = point - string[i]; //Posição da palavra.
            memmove(string[i]+pos, subs, strlen(palavra)); //Muda a substring que é igual a palavra desejada para verificar
            qntrep++;                                      //a próxima vez que ela aparece.
        }
        else {
            i++;
        }
    }

    if(qntrep==0){
        printf("\n--> A palavra [%s] nao foi encontrada no texto!\n\n", palavra);
    }
    else {
        for(i=0;i<qntrep;i++) { //Repete até substituir todas as ocorrências.
            SubstituiPalavra(text, palavra, palavrasubs);
        }
    }

}

//Objetivo: Cumprir a função 'e)' de formatar o texto inteiro em caixa alta.
//Parâmetros: text é o texto a ser formatado.
void TudoCaixaAlta(char textbase[400][200], char text[400][200]) {
    int i=0, j, qnt=0;
    char string[200];

    strcpy(string, "\0");

    while(textbase[i][0]) {
        qnt++;
        i++;
    }

    for(i=0;i<qnt;i++) {
        strcpy(string, textbase[i]);
        
        for (j=0;string[j]!='\0';j++) {
            if(string[j] >= 'a' && string[j] <= 'z') { //Encontra na tabela ASCII a letra correspondente em caixa alta.
                string[j] = string[j]-32;
            }
        }

        strcpy(text[i], string);
    }
}

//Objetivo: Cumprir a função 'f)' de formatar o texto inteiro em caixa baixa.
//Parâmetros: text é o texto a ser formatado.
void TudoCaixaBaixa(char textbase[400][200], char text[400][200]) {
    int i=0, j, qnt=0;
    char string[200];

    strcpy(string, "\0");

    while(textbase[i][0]) {
        qnt++;
        i++;
    }

    for(i=0;i<qnt;i++) {
        strcpy(string, textbase[i]);

        for(j=0;string[j]!='\0';j++) {
            if(string[j] >= 'A' && string[j] <= 'Z') { //Encontra na tabela ASCII a letra correspondente em caixa baixa.
                string[j] = string[j]+32;
            }
        }
        strcpy(text[i], string);

        strcpy(string, "\0");
    }
}   

//Objetivo: Cumpre a função 'g)' de tranformar a primeira letra de cada frase para caixa alta.
//Parâmetros: text é o texto a ser formatado.
void PrimeiraLetraMaiuscula(char text[400][200]) {
    int i=0, qnt=0, pos, confirm=0;
    char string[200], *token, caixa;
    char textsubs[400][200];

    while(text[i][0]) {
        qnt++;
        i++;
    }

    for(i=0;i<qnt;i++) {
        strcpy(textsubs[i], "\0");
    }

    for(i=0;i<qnt;i++) {
        strcpy(textsubs[i], text[i]);
    }

    for(i=0;i<qnt;i++) {
        token = strtok(textsubs[i], " ");
        
        if(confirm==0){
            confirm++;

            pos = token - textsubs[i];
            caixa = textsubs[i][pos];
            text[i][pos] = toupper(caixa);
        }
        while(token) {
            if(strstr(token, ".")) {
                token = strtok(NULL, " ");
                if(token==NULL) {
                    break;
                }
                else{
                    pos = token - textsubs[i];

                    caixa = textsubs[i][pos];

                    text[i][pos] = toupper(caixa);
                }
            }
            else {
                token = strtok(NULL, " ");
            }
        }
    }

    printf("\n--> Todas as primeiras letras transformadas para caixa alta com sucesso!\n\n");

    system("pause");
}

//Objetivo: Cumpre a função 'i)' de alinhar o texto a direita.
//Parâmetros: texto é o texto a ser alinhado.
void AlinhaDireita(char textbase[400][200], char texto[400][200]) {
    char text[400][200], stringespa[81];
    int i=0, qnt=0, qntespa, j=0;

    while(textbase[i][0]) {
        qnt++;
        i++;
    }
    
    strcpy(stringespa, "\0");

    for(i=0;i<qnt;i++) {

        qntespa = 80 - strlen(textbase[i]);

        while(j<qntespa) {
            strcat(stringespa, " ");
            j++;
        }

        sprintf(text[i], "%s%s", stringespa, textbase[i]);

        memmove(stringespa, "\0", 81);

        j=0;

        strcpy(texto[i], text[i]);
    }
}

//Objetivo: Cumprir a função 'j)' de justificar o texto.
//Parâmetros: texto é o texto a ser justiticado.
void JustificaTexto(char textbase[400][200], char texto[400][200]) {
    int i=0, qnt=0, pos;
    char *token, string[100], stringbase[400][200], stringjustif[400][200], textbase2[400][200];

    strcpy(string, "\0");

    while(textbase[i][0]) {
        qnt++;
        i++;
    }

    for(i=0;i<qnt;i++) {
        strcpy(stringbase[i], "\0");
        strcpy(stringjustif[i], "\0");
        strcpy(textbase2[i], "\0");
    }

    for(i=0;i<qnt;i++) {
        strcpy(stringbase[i], textbase[i]);
        strcpy(textbase2[i], textbase[i]);
    }
   
    for(i=0;i<qnt;i++){
        token = strtok(textbase2[i], " "); 

        while(token){
            pos = token - textbase2[i];

            if(strlen(stringbase[i])==80) {
                strcpy(stringjustif[i], stringbase[i]);
                break;
            }

            strncat(stringjustif[i], stringbase[i]+pos, strlen(token));
            strcat(stringjustif[i], " ");

            memmove(string, stringbase[i]+pos+strlen(token)+1, strlen(stringbase[i]));
        
            strcat(stringjustif[i], " ");
            
            if(strlen(stringjustif[i])+strlen(string) == 80) {
                token = strtok(NULL, " ");

                if(token) {
                    while(token) {
                        strcat(stringjustif[i], token);
                        if(strlen(stringjustif[i])==80)
                            break;
                        else
                            strcat(stringjustif[i], " ");

                        token = strtok(NULL, " ");
                    }
                }
            }

            token = strtok(NULL, " ");
        }
        strcpy(texto[i], stringjustif[i]);

        strcpy(string, "\0");
    }
}   

//Objetivo: Cumprir a função 'k)' de centralizar o texto.
//Parâmetros: texto é o texto para ser centralizado.
void CentralizaTexto(char textbase[400][200], char texto[400][200]) {
    int i=0, qntesquer=0, qntdiret=0, qnt=0, qntotal, j=0;
    char espaesqu[40], espadire[40], text[400][200];

    while(textbase[i][0]) {
        qnt++;
        i++;
    }

    strcpy(espaesqu, "\0");
    strcpy(espadire, "\0");

    for(i=0;i<qnt;i++) {
        qntotal = 80 - strlen(textbase[i]);

        if(qntotal % 2 == 0) {
            qntesquer = qntotal / 2;
            qntdiret = qntotal / 2;
        }
        else {
            qntotal--;

            qntesquer = qntotal / 2 + 1;
            qntdiret = qntotal / 2;
        }

        while(j<qntesquer) {
            strcat(espaesqu, " ");
            j++;
        }
        j=0;
        while(j<qntdiret) {
            strcat(espadire, " ");
            j++;
        }
        j=0;

        sprintf(text[i], "%s%s%s", espaesqu, textbase[i], espadire);

        strcpy(texto[i], text[i]);

        strcpy(espaesqu, "\0");
        strcpy(espadire, "\0");
    }
}

//Objetivo: Mostra o menu para editar o texto.
//Parâmetros: text é o texto sem estar formatado.
void ExecutaMenu(char text[]) {

    char textformat[400][200], textnovoformat[400][200], textsubsformat[400][200], textbase[400][200];
    char palavra[30], palavrasubs[30], subspalavra[30], arraytextsubs[3200];
    char choose;
    int i, alinhadodireita=0, centralizado=0, justificado=0, alinhadoesquerda=0;

    FormataTexto(text, textformat);
    
    for(i=0;i<80;i++) {
        strcpy(textbase[i], textformat[i]);
    }

    do {
        system("cls");

        printf("\n----------------\nEditor de Textos\n----------------\n\nOpcoes:\n\n");
        printf("a) Imprimir o texto formatado;\n\
b) Dado uma palavra informar quantas vezes a palavra aparece e em qual(is) linha(s) e coluna(s) ela esta;\n\
c) Substituir uma palavra do texto por outra fornecida pelo usuario;\n\
d) Substituir uma palavra do texto por outra fornecida pelo usuario. Todas as ocorrencias da palavra devem ser substituidas; \n\
e) Colocar o texto em caixa-alta, ou seja, todos seus caracteres em maiusculo;\n\
f) Colocar o texto em caixa-baixa, ou seja, todos seus caracteres em minusculo;\n\
g) Colocar em caixa-alta o primeiro caracter de cada inicio de frase;\n\
h) Alinhar o texto a esquerda;\n\
i) Alinhar o texto a direita;\n\
j) Justificar o texto;\n\
k) Centralizar o texto;\n\
l) Fechar o programa.\n-->");

        scanf("%c", &choose);

        switch(choose) {
            case 'a':
                system("cls");

                ImprimeTextFormatado(textformat);

                system("pause");

                break;
            case 'b':
                system("cls");

                printf("Digite a palavra que deseja procurar:\n-->");
                scanf("%s", palavra);

                MostraPalavra(textformat, palavra);

                break;
            case 'c':
                system("cls");

                printf("Digite a palavra que deseja substituir no texto:\n-->");
                scanf("%s", palavrasubs);

                printf("Digite a palavra que deseja inserir no lugar:\n-->");
                scanf("%s", subspalavra);

                for(i=0;i<45;i++) { //Manda para o procedimento o textusubsformat, para não afetar o texformat.
                    strcpy(textsubsformat[i], textformat[i]);
                }       

                SubstituiPalavra(textsubsformat, palavrasubs, subspalavra);

                MatrizParaVetor(textsubsformat, arraytextsubs); 
                FormataTexto(arraytextsubs, textnovoformat);


                for(i=0;i<80;i++) {
                    strcpy(textformat[i], textnovoformat[i]); //Passando o texto alterado para o original.
                    strcpy(textbase[i], textnovoformat[i]);
                }

                if(centralizado==1)
                    CentralizaTexto(textbase, textformat);
                if(alinhadodireita==1)
                    AlinhaDireita(textbase, textformat);
                if(justificado==1)
                    JustificaTexto(textbase, textformat);

                LimpaMatriz(textnovoformat);
                memmove(arraytextsubs, "\0", strlen(arraytextsubs));

                system("pause");

                break;
            case 'd':
                system("cls");

                printf("Digite a palavra que deseja substituir no texto:\n-->");
                scanf("%s", palavrasubs);

                printf("Digite a palavra que deseja inserir no lugar:\n-->");
                scanf("%s", subspalavra);

                for(i=0;i<80;i++) { //Manda para o procedimento o textusubsformat, para não afetar o texformat.
                    strcpy(textsubsformat[i], textformat[i]);
                }      

                SubstituiVariasPalavras(textsubsformat, palavrasubs, subspalavra);

                MatrizParaVetor(textsubsformat, arraytextsubs); 

                FormataTexto(arraytextsubs, textnovoformat);

                for(i=0;i<80;i++) {
                    strcpy(textformat[i], textnovoformat[i]); //Passando o texto alterado para o original.
                    strcpy(textbase[i], textnovoformat[i]);
                }

                if(centralizado==1)
                    CentralizaTexto(textbase, textformat);
                if(alinhadodireita==1)
                    AlinhaDireita(textbase, textformat);
                if(justificado==1)
                    JustificaTexto(textbase, textformat);

                memmove(arraytextsubs, "\0", strlen(arraytextsubs));
                LimpaMatriz(textnovoformat);

                system("pause");

                break;
            case 'e':
                system("cls");

                TudoCaixaAlta(textbase, textformat);

                printf("\n--> Texto inteiro transformado em caixa alta com sucesso!\n");

                system("pause");

                break;
            case 'f':
                system("cls");

                TudoCaixaBaixa(textbase, textformat);

                printf("\n--> Texto inteiro transformado em caixa baixa com sucesso!\n");

                system("pause");

                break;
            case 'g':
                system("cls");

                PrimeiraLetraMaiuscula(textformat);

                break;
            case 'h':
                system("cls");

                for(i=0;i<80;i++) {
                    strcpy(textnovoformat[i], textformat[i]);
                }

                MatrizParaVetorSEspaco(textnovoformat, arraytextsubs);
                
                FormataTexto(arraytextsubs, textnovoformat);

                for(i=0;i<80;i++) {
                    strcpy(textformat[i], textnovoformat[i]);
                }

                alinhadodireita=0;
                centralizado=0;
                justificado=0;
                alinhadoesquerda=1;

                memmove(arraytextsubs, "\0", strlen(arraytextsubs));
                LimpaMatriz(textnovoformat);

                printf("\n--> Texto alinhado a esquerda com sucesso!\n\n");

                system("pause");
                break; 
            case 'i':
                system("cls");

                AlinhaDireita(textbase, textformat);

                //printf("%s\n%s\n", textformat[0], textformat[1]);

                alinhadodireita=1;
                centralizado=0;
                justificado=0;

                printf("\n--> Texto alinhado a direita com sucesso!\n\n");

                system("pause");

                break;
            case 'j':
                system("cls");

                alinhadodireita=0;
                centralizado=0;
                justificado=1;
                
                JustificaTexto(textbase, textformat);

                printf("\n--> Texto justificado com sucesso!\n\n");

                system("pause");

                break;
            case 'k':
                system("cls");

                alinhadodireita=0;
                centralizado=1;
                justificado=0;

                CentralizaTexto(textbase, textformat);

                printf("\n--> Texto centralizado com sucesso!\n\n");

                system("pause");

                break;
            case 'l':
                printf("\n[Programa encerrado!]\n");

                system("pause");

                break;
            default:
                printf("\n[Escolha uma opcao valida!]\n");

                system("pause");

                break;
        }

        flush_in();
    }while(choose != 'l');          
}

int main()
{
    char text[]="William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates,\
 e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por \
 fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor \
 de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado \
 regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E \
 um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu \
 pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da \
 Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, \
 frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do \
 Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade \
 Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e \
 Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de \
 software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem \
 trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando \
 com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes \
 de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, \
 a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto \
 estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros \
 computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na \
 comercializacao deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
 focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao \
 longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era \
 considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por \
 concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider \
 no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, \
 porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, \
 a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia \
 desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou \
 o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. \
 Fonte: https://pt.wikipedia.org/wiki/Bill_Gates";

    //printf("\n\n%s", text);

    ExecutaMenu(text);

    return 0;
}
