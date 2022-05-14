#include <stdio.h>
#include <math.h>

int main () {

    int numfunc, i, j, matricula;
    float sal=0;

    //Leitura da quantidade de funcionarios
    printf("-------------------\n");
    printf("Folha de Pagamentos\n");
    printf("-------------------\n");
    printf("Digite o numero de funcionarios: ");
    scanf("%d", &numfunc);
    while((numfunc<1)||(numfunc>pow(10, 4))) {
        printf("Numero de funcionarios invalido!\nDigite novamente: ");
        scanf("%d", &numfunc);
    }

    //Calculo do salario com base na matricula
    for(i=1;i<=numfunc;i++) {
        //Leitura da matricula dos funcionarios
        printf("\nDigite a matricula do funcionario %d: ", i);
        scanf("%d", &matricula);
        while((matricula<1)||(matricula>30000)) {
            printf("Numero da matricula incorreto!\nDigite novamente: ");
            scanf("%d", &matricula);
        }
        
        //Verifica a soma dos divisores da matricula
        for(j=1;j<=matricula;j++) {
            if(matricula%j==0) {
                sal = sal + (matricula/j); 
            }
        }

        printf("O novo salario do funcionario %d sera: R$%.2f.\n", i, sal);

        sal = 0;
    }
    
    return 0;
}