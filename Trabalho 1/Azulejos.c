#include <stdio.h>

int main() {
    int nazulejos=1, a=1, b=1, i=1, j=1, quantazu=0, multia=0, multib=0, aux;

    while((nazulejos!=0)&&(a!=0)&&(b!=0)) {
        //Entrada da quantidade total de azulejos
        printf("Digite o numero de azulejos:\n");
        scanf("%d", &nazulejos);
        while(((nazulejos<3)||(nazulejos>10000))&&(nazulejos!=0)) {
            printf("Numero de azulejos invalido! Deve estar entre 3 e 10000.\nDigite novamente:\n");
            scanf("%d", &nazulejos);
        }
        
        //Entrada do primeiro inteiro(a)
        printf("Digite o primeiro inteiro:\n");
        scanf("%d", &a);
        while(((a<2)||(a>nazulejos))&&(nazulejos!=0)) {
            printf("O primeiro inteiro esta incorreto! Deve ser maior ou igual 2.\nDigite novamente:\n");
            scanf("%d", &a);
        }

        //Entrada do segundo inteiro(b)
        printf("Digite o segundo inteiro:\n");
        scanf("%d", &b);
        while((b>nazulejos)&&(nazulejos!=0)) {
            printf("O segundo inteiro esta incorreto! Deve ser menor que a quantidade de azulejos.\nDigite novamente:\n");
            scanf("%d", &b);
        }

        //Caso todos as entradas sejam 0 o programa se encerra
        if((nazulejos==0)&&(a==0)&&(b==0)) {
            printf("Programa encerrado!");
            return 0;
        }

        //Troca de valores, para aceitar qualquer ordem quando inserido os inteiros
        if(b<a) {
            aux = a;
            a = b;
            b = aux;
        }

        //Calculo da quantidade de azulejos pelos multiplos de A
        for(i=1;a*i<=nazulejos;i++) {
            multia = a * i;
            quantazu += 1;
            //Verifica se algum valor de B e igual a A, caso seja, sera ignorado
            while(b*j<=nazulejos) {
                multib = b * j;
                if(multia==multib) {
                    quantazu -= 1;
                }
                j++;
            }
            j = 1;
        }

        //Calculo da quantidade de azulejos pelos multiplos de B
        for(i=1;b*i<=nazulejos;i++) {
            multib = b * i;
            quantazu += 1;
        }

        printf("A quantidade de azulejos pintados sera de: %d.\n\n", quantazu);

        quantazu = 0;
    }


    return 0;
}