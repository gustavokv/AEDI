#include <stdio.h>
#include <stdlib.h>

int main () {
    int pes1, pes2, pes3, a1, a2, a3;

    //Entradas
    printf("-> Digite a quantidade de pessoas no andar 1:\n");
    scanf("%d", &pes1);
    while(pes1<0||pes1>1000) {
        printf("\n-> Numero de pessoas deve estar entre 0 e 1000!\nDigite novamente:\n");
        scanf("%d", &pes1);
    }
    
    printf("\n-> Digite a quantidade de pessoas no andar 2:\n");
    scanf("%d", &pes2);
    while(pes2<0||pes2>1000) {
        printf("\n-> Numero de pessoas deve estar entre 0 e 1000!\nDigite novamente:\n");
        scanf("%d", &pes2);
    }
   
    printf("\n-> Digite a quantidade de pessoas no andar 3:\n");
    scanf("%d", &pes3);
    while(pes3<0||pes3>1000) {
        printf("\n-> Numero de pessoas deve estar entre 0 e 1000!\nDigite novamente:\n");
        scanf("%d", &pes3);
    }

    //Calcula o tempo das pessoas de cada andar ira levar para ir ao outro
    a1 = pes2 * 2 + pes3 * 4;
    a2 = pes1 * 2 + pes3 * 2;
    a3 = pes1 * 4 + pes2 * 2;

    
    //Calcula qual andar as pessoas levam menos tempo para ir
    if(a1==0&&a2==0&&a3==0) {
        printf("\n-> Nenhuma maquina necessaria!");
    }
    else {
        if(a1==a2&&a2==a3) {
            printf("\nTempo: %d\n", a2);
            printf("Maquina localizada no(s) andar(es): 1 ou 2 ou 3");
        }
        else if(a1<=a2&&a1<=a3) {
            printf("\nTempo: %d\n", a1);
            if(a1==a2) {
                printf("\nMaquina localizada no(s) andar(es): 1 ou 2");
            }
            else if(a1==a3) {
                printf("\nMaquina localizada no(s) andar(es): 1 ou 3");
            }
            else {
                printf("\nMaquina localizada no(s) andar(es): 1");
            }
        }
        else if(a2<=a1&&a2<=a3) {
            printf("\nTempo: %d\n", a2);
            if(a2==a3) {
                printf("\nMaquina localizada no(s) andar(es): 2 ou 3");
            }
            else {
                printf("\nMaquina localizada no(s) andar(es): 2");
            }
        }
        else if(a3<=a1&&a3<=a2) {
            printf("\nTempo: %d\n", a3);
            printf("\nMaquina localizada no(s) andar(es): 3");
        }
    }

    return 0;
}