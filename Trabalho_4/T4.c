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

//Objetivo: Formatar o texto original.
//Parâmetros: text: O texto original, textformat: O texto formatado. 
void FormataTexto(char text[], char textformat[400][200]) {

    char *token = strtok(text, " "), string[200], *virg, *ponto, *abreparent, *fechaparent;
    int j=0, i;

    strcpy(string, "\0");
   
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
                strcat(string, " ");
                strncat(textformat[j], token+1, strlen(token)-1);
                strcat(textformat[j], " ");
            }
            else if(fechaparent && strlen(string)==81) {
                strncat(textformat[j], token, strlen(token)-1);
                strcat(textformat[j], " ");
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
        printf("%d %s\n", strlen(text[i]), text[i]);
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
        printf("\n--> A palavra [%s] apareceu: [%d] vez(es) no texto.\n", palavra, qntrep);
    else
        printf("\n--> A palavra [%s] nao foi encontrada!\n", palavra);
}

//Objetivo: Substituir uma palavra dentro do texto formatado.
//Parâmetros: text é o texto formatado, palavra é a palavra que deve ser substituída e palavrasubs é a 
//            palavra que será trocada.
void SubstituiPalavra(char text[400][200], char palavra[], char palavrasubs[]) {
    int i=0, qnt=0, lin, j, pos, confirm=0, qntlin=0;
    char *point, *token, subscharpre[2], subscharpos[2];
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
                subscharpre[0] = text[i][pos-1];                       //da palavra

                palavramod[0] = subscharpre[0];
                strcpy(palavramodsubis, subscharpre);

                strcat(palavramod, palavra);
                strcat(palavramodsubis, palavrasubs);
            }
            else {
                strcpy(palavramod, palavra);
                strcpy(palavramodsubis, palavrasubs);
            }
            if(!isalpha(text[i][pos+strlen(palavra)]) && !isblank(text[i][pos+strlen(palavra)])) { //Caso haja algum caracter
                subscharpos[0] = text[i][pos+strlen(palavra)];                                     //depois.
   
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

            printf("\n--> Palavra [%s] substituida por [%s] com sucesso!\n", palavra, palavrasubs);
            strcpy(text[lin], string);  //Coloca novamente a linha que foi alterada na matriz.

            break;
        }
        else
            i++; //Pula a linha do texto.
    }
    if(confirm == 0)
        printf("\n--> A palavra [%s] nao foi encontrada!\n", palavra);
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

    if(qntrep==0)
        printf("\n--> A palavra [%s] nao foi encontrada no texto!\n", palavra);
    else {
        for(i=0;i<qntrep;i++) { //Repete até substituir todas as ocorrências.
            SubstituiPalavra(text, palavra, palavrasubs);
        }
    }
}

//Objetivo: Cumprir a função 'e)' de formatar o texto inteiro em caixa alta.
//Parâmetros: text é o texto a ser formatado.
void TudoCaixaAlta(char text[400][200]) {
    int i=0, j, qnt=0;
    char string[200];

    strcpy(string, "\0");

    while(text[i][0]) {
        qnt++;
        i++;
    }

    for(i=0;i<qnt;i++) {
        strcpy(string, text[i]);
        
        for (j=0;string[j]!='\0';j++) {
            if(string[j] >= 'a' && string[j] <= 'z') { //Encontra na tabela ASCII a letra correspondente em caixa alta.
                string[j] = string[j]-32;
            }
        }

        strcpy(text[i], string);
    }

    printf("\n--> Texto inteiro transformado em caixa alta com sucesso!\n");
}

//Objetivo: Cumprir a função 'f)' de formatar o texto inteiro em caixa baixa.
//Parâmetros: text é o texto a ser formatado.
void TudoCaixaBaixa(char text[400][200]) {
    int i=0, j, qnt=0;
    char string[200];

    strcpy(string, "\0");

    while(text[i][0]) {
        qnt++;
        i++;
    }

    for(i=0;i<qnt;i++) {
        strcpy(string, text[i]);

        for(j=0;string[j]!='\0';j++) {
            if(string[j] >= 'A' && string[j] <= 'Z') { //Encontra na tabela ASCII a letra correspondente em caixa baixa.
                string[j] = string[j]+32;
            }
        }
        strcpy(text[i], string);

        strcpy(string, "\0");
    }

    printf("\n--> Texto inteiro transformado em caixa baixa com sucesso!\n");
}   

//Objetivo: Cumpre a função 'g)' de tranformar a primeira letra de cada frase para caixa alta.
//Parâmetros: text é o texto a ser formatado.
void PrimeiraLetraMaiuscula(char text[400][200]) {
    int i=0, qnt=0;
    char string[200];

    while(text[i][0]) {
        qnt++;
        i++;
    }

    for(i=0;i<qnt;i++) {
        strcpy(string, text[i]);
        
        if(string[0] >= 'a' && string[0] <= 'z')  //Encontra na tabela ASCII a letra correspondente em caixa alta.
            string[0] = string[0]-32;

        strcpy(text[i], string);
    }

    printf("\n--> Todas as primeiras letras transformadas para caixa alta com sucesso!\n");
}

//Objetivo: Mostra o menu para editar o texto.
//Parâmetros: text é o texto sem estar formatado.
void ExecutaMenu(char text[]) {

    char textformat[400][200], textnovoformat[400][200], textsubsformat[400][200];
    char palavra[30], palavrasubs[30], subspalavra[30], arraytextsubs[3200];
    char choose;
    int i;

    FormataTexto(text, textformat);

    do {
        printf("\n----------------\nEditor de Textos\n----------------\n\nOpções:\n\n");
        printf("a) Imprimir o texto formatado;\n\
b) Dado uma palavra informar quantas vezes a palavra aparece e em qual(is) linha(s) e coluna(s) ela está;\n\
c) Substituir uma palavra do texto por outra fornecida pelo usuário;\n\
d) Substituir uma palavra do texto por outra fornecida pelo usuário. Todas as ocorrências da palavra devem ser substituídas; \n\
e) Colocar o texto em caixa-alta, ou seja, todos seus caracteres em maiúsculo;\n\
f) Colocar o texto em caixa-baixa, ou seja, todos seus caracteres em minúsculo;\n\
g) Colocar em caixa-alta o primeiro caracter de cada início de frase;\n\
h) Alinhar o texto à esquerda;\n\
i) Alinhar o texto à direita;\n\
j) Justificar o texto;\n\
k) Centralizar o texto;\n\
l) Fechar o programa.\n-->");

        scanf("%c", &choose);

        switch(choose) {
            case 'a':
                system("clear");

                ImprimeTextFormatado(textformat);

                break;
            case 'b':
                system("clear");

                printf("Digite a palavra que deseja procurar:\n-->");
                scanf("%s", palavra);

                MostraPalavra(textformat, palavra);

                break;
            case 'c':
                system("clear");

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
                
                strcpy(arraytextsubs, "\0"); //Reseta o array para não estar sujo quando executar novamente.

                for(i=0;i<45;i++) {
                    strcpy(textformat[i], textnovoformat[i]); //Passando o texto alterado para o original.
                }

                LimpaMatriz(textnovoformat); //Reseta também a matriz.

                break;
            case 'd':
                system("clear");

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
                
                strcpy(arraytextsubs, "\0"); //Reseta o array para não estar sujo quando executar novamente.

                for(i=0;i<45;i++) {
                    strcpy(textformat[i], textnovoformat[i]); //Passando o texto alterado para o original.
                }

                LimpaMatriz(textnovoformat); //Reseta também a matriz.

                break;
            case 'e':
                system("clear");

                TudoCaixaAlta(textformat);

                break;
            case 'f':
                system("clear");

                TudoCaixaBaixa(textformat);

                break;
            case 'g':
                system("clear");

                PrimeiraLetraMaiuscula(textformat);

                break;
            case 'h':
                system("clear");

                ImprimeTextFormatado(textformat);

                break;
            case 'j':
                system("clear");

                
                break;
            case 'l':
                printf("\n[Programa encerrado!]\n");
                break;
            default:
                printf("\n[Escolha uma opcao valida!]\n");
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
 comercializa��o deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
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
