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

    char *token, string[200], *virg, *ponto, *traco, aux[15], stringaux[200], aux2[15]; //Token irá separar as palavras pelo espaço.
    int j=0, pos, i, auxtraco;

    strcpy(string, "\0");
    token = strtok(text, " ");
   
    while(token) {
        strcpy(stringaux, string);

        strcat(string, token);
        if(strlen(string)!=80) //Para não considerar o espaço no final da linha na hora de inserir a palavra no texto formatado.
            strcat(string, " ");

        virg = strchr(token, ','); //Ponteiro para a vírgula em uma palavra.
        ponto = strchr(token, '.'); //Ponteiro para o ponto em uma palavra.
        traco = strchr(token, '-');

        if(strlen(string)<=80) {
            strcat(textformat[j], token); //Adiciona uma palavra a matriz do texto formatado.
            if(strlen(textformat[j])!=80)
                strcat(textformat[j], " "); 
        }
        else{
            if(traco && strlen(string)>80) {

                pos = traco - token;

                strncpy(aux, token, pos);
                printf("%s\n", aux);

                auxtraco = strlen(aux);

                if(strlen(stringaux)>=80) {
                    strcat(stringaux, aux);

                    j++;

                    strcpy(string, "\0");
                    strcat(string, aux);
                    strcat(string, "-");

                    memmove(aux, token+pos+1, strlen(token)-auxtraco+1);

                    strcat(string, aux);
                    strcat(string, " ");

                    strcat(textformat[j], string);

                    strcpy(aux, "\0");
                    strcpy(stringaux, "\0");
                }
                else{
                    strcat(stringaux, aux);

                    strcat(textformat[j], aux);
                    strcat(textformat[j], "-");

                    strcat(stringaux, "-");

                    j++;

                    memmove(aux2, token+pos+1, strlen(token)-auxtraco+1);

                    strcat(textformat[j], aux2);
                    strcat(textformat[j], " ");

                    strcpy(string, "\0");

                    strcat(string, aux2);
                    strcat(string, " ");

                    strcpy(aux, "\0");
                    strcpy(stringaux, "\0");
                    strcpy(aux2, "\0");
                
                }
            
            }
            else if(virg && strlen(string)<=82) {
                pos = virg - token; //Posição da vírgula na palavra.
                token[pos] = " ";
                strcat(textformat[j], token); //Faz com que a linha receba a palavra sem a vírgula.
                j++;
                strcpy(string, "\0");
                strcpy(string, ",");
                strcat(string, " ");
                strcpy(textformat[j], ",");
                strcat(textformat[j], " ");
                
            }
            else if(ponto && strlen(string)<=82) {
                pos = ponto - token; //Posição do ponto na palavra.
                token[pos] = " ";
                strcat(textformat[j], token); //Faz com que a linha receba a palavra sem o ponto.
                j++;
                strcpy(string, "\0");
                strcpy(string, ".");
                strcat(string, " ");
                strcpy(textformat[j], ".");
                strcat(textformat[j], " ");
            }
            else { 
                j++;
                strcpy(string, "\0");
                strcpy(string, token);
                strcat(string, " ");
                strcpy(textformat[j], token);
                strcat(textformat[j], " ");
            }
        }

        token = strtok(NULL, " "); //Faz com que o ponteiro token continue varrendo a string.
    }
}

//Objetivo: Cumpre a função "a)" e "h)", de mostrar o texto formatado e alinhado a esquerda.
//Parâmetros: text é o texto já formatado.
void ImprimeTextFormatado(char text[400][200]) {
    int i;

    for(i=0;i<45;i++) {    
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

    while(i != 45) {
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
        printf("\n--> A palavra [%s] apareceu: [%d] vez(es) no texto.", palavra, qntrep);
    else
        printf("--> A palavra [%s] nao foi encontrada!", palavra);
}

//Objetivo: Substituir uma palavra dentro do texto formatado.
//Parâmetros: text é o texto formatado, palavra é a palavra que deve ser substituída e palavrasubs é a 
//            palavra que será trocada.
void SubstituiPalavra(char text[400][200], char palavra[], char palavrasubs[]) {
    int i=0, qnt=0, lin, j, pos, confirm=0;
    char *point, *token, subscharpre[2], subscharpos[2];
    char string[100], palavramod[30], palavramodsubis[30];

    strcpy(palavramod, "\0");
    strcpy(palavramodsubis, "\0");
    strcpy(string, "\0");

    while(i!=40) {
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
                    strcat(string, token);
                    strcat(string, " ");
                }
                token = strtok(NULL, " ");
            }
            strcpy(text[lin], string);  //Coloca novamente a linha que foi alterada na matriz.
            printf("\n--> Palavra [%s] substituida por [%s] com sucesso!\n", palavra, palavrasubs);
            break;
        }
        else
            i++; //Pula a linha do texto.
    }
    if(confirm == 0)
        printf("\n--> A palavra [%s] nao foi encontrada!", palavra);
}

//Objetivo: Cumpre a função 'd)' de substituir todas as ocorrências de uma palavra.
//Parâmetros: palavra é a palavra a ser substituída e palavrasubs é a palavra que entrará no lugar.
void SubstituiVariasPalavras(char text[400][200], char palavra[], char palavrasubs[]) {

    int i=0, qntrep=0, pos;
    char *point, string[400][200], subs[] = {".............."};

    for(i=0;i<45;i++) {
        strcpy(string[i], text[i]); //Outro texto para não interferir no original formatado.
    }

    i=0;

    while(i != 45) {
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

    for(i=0;i<qntrep;i++) { //Repete até substituir todas as ocorrências.
        SubstituiPalavra(text, palavra, palavrasubs);
    }
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

                for(i=0;i<45;i++) { //Manda para o procedimento o textusubsformat, para não afetar o texformat.
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
            case 'h':
                system("clear");

                ImprimeTextFormatado(textformat);

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
