#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Objetivo: Limpa o buffer do teclado.
void flush_in(){ 
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n'){} 
}

//Objetivo: Formatar o texto original.
//Parâmetros: text: O texto original, textformat: O texto formatado. 
void FormataTexto(char text[], char textformat[400][200]) {

    char *token = strtok(text, " "), string[200], *virg, *ponto, verif[12];
    int j=0, pos;

    while(token != NULL) {

        strcat(string, token);
        strcat(string, " ");

        strcpy(verif, token);

        virg = strchr(verif, ',');
        ponto = strchr(verif, '.');

        if(virg) {
            pos = virg - verif;
            printf("%s ---- %d ---- %s\n", verif, pos, virg);
        }
        if(ponto) {
            pos = ponto - verif;
            printf("%s ---- %d ---- %s\n", verif, pos, ponto);
        }

        if(strlen(string)<=80) {
            strcat(textformat[j], token);
            strcat(textformat[j], " ");
        }
        else{
            //printf("%d = %d\n", j, strlen(textformat[j]));
            j++;
            strcpy(string, "\0");
            strcpy(string, token);
            strcat(string, " ");
            strcpy(textformat[j], token);
            strcat(textformat[j], " ");
        }

        token = strtok(NULL, " ");
    }

}

//Objetivo: Cumpre a função "a)" e "h)", de mostrar o texto formatado e alinhado a esquerda.
void ImprimeTextFormatado(char text[400][200]) {
    int i;

    for(i=0;i<41;i++) {
        printf("%d = %s\n", i, text[i]);
    }
}

//Objetivo: Mostra uma palavra desejada pelo usuário quantas vezes a mesma apareceu e em qual(is) linha(s) e coluna(s).
void MostraPalavra(char textbase[400][200], char palavra[]) {
    int i=0, j=0;
    char string[100], *point;
 
    while(i!=40) {
        strcpy(string, textbase[i]);

        do{
            point = strstr(string, palavra);
            
            if(point){
                while(string[j] != " ") {
                    printf("%c", string[j]);
                    strcpy(string[j], 'z');
                    j++;
                }
            }
            j=0;
        }while(point);

        i++;
    }
}

//Objetivo: Mostra o menu para editar o texto.
void ExecutaMenu(char text[]) {

    char textformat[400][200], choose, palavra[30];

    do {
        printf("\n\n----------------\nEditor de Textos\n----------------\n\nOpções:\n\n");
        printf("a) Imprimir o texto formatado;\n\
b) Dado uma palavra informar quantas vezes a palavra aparece e em qual(is) linha(s) e coluna(s) ela está;\n\
c) Substituir uma palavra do texto por outra fornecida pelo usuário;\n\
d) Substituir uma palavra do texto por outra fornecida pelo usuário;\n\
e) Colocar o texto em caixa-alta, ou seja, todos seus caracteres em maiúsculo;\n\
f) Colocar o texto em caixa-baixa, ou seja, todos seus caracteres em minúsculo;\n\
g) Colocar em caixa-alta o primeiro caracter de cada início de frase;\n\
h) Alinhar o texto à esquerda;\n\
i) Alinhar o texto à direita;\n\
j) Justificar o texto;\n\
k) Centralizar o texto;\n\
l) Fechar o programa.\n-->");

        scanf("%c", &choose);

        FormataTexto(text, textformat);

        switch(choose) {
            case 'a':
                //system("clear");
                ImprimeTextFormatado(textformat);
                break;
            case 'b':
                system("clear");
                printf("Digite a palavra que deseja procurar:\n-->");
                scanf("%s", palavra);
                MostraPalavra(textformat, palavra);
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

    //printf("\n\n%s",text);

    ExecutaMenu(text);

    return 0;
}
