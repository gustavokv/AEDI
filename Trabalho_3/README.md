## Programe um sistema para controle de um caixa eletrônico usando a linguagem C. As funcionalidades do sistema serão controladas usando o menu de opções a seguir.


MENU PRINCIPAL
1-Cliente
2-Saque
3-Relatórios
4-Finalizar

MENU CLIENTE
1-Incluir
2-Mostrar
3-Alterar
4-Excluir
5-Voltar

MENU RELATÓRIOS
1-Valores sacados
2-Valor do saldo existente
3-Quantidade de cédulas existentes
4-Voltar ao menu principal

##

O sistema deve manter no máximo 50 clientes cadastrados.

Inicialmente o cadastro de clientes está vazio e ao acionar a opção incluir do menu cliente o sistema deve gerar automaticamente um cpf válido 
e um número de conta corrente nos formatos '999.999.999-99' e '999.999-x', respectivamente, e fazer a inclusão do novo cliente no cadastro caso 
haja confirmação do usuário. Um novo cliente só pode ser incluído se não existir um cpf ou número de conta corrente já cadastrados. Utilize as 
rotinas 'void gera_cpf_valido(char cpf[])' e 'void geraContaCorrente(char c[])' para a geração automática do cpf e da conta corrente.

A opção mostrar do menu cliente deve apresentar os dados dos clientes cadastrados no sistema.

A opção alterar do menu cliente permite fazer uma alteração no cpf ou número da conta corrente. A alteração somente será permitida se não existir
nenhum saque realizado por aquele cliente. O sistema deverá preservar os formatos '999.999.999-99' (do cpf) e '999.999-x' (da conta corrente).

A opção excluir do menu cliente permite apagar um cliente do cadastro caso não há nenhum saque realizado deste cliente. O dado de consulta para a 
alteração e exclusão é o número da conta corrente (formato '999.999-x').

Para sacar dinheiro um cliente deve fornecer seu número de conta corrente (formato '999.999-x') e caso ela exista no cadastro o sistema liberará a 
menor quantidade de cédulas para o valor solicitado e imprimirá a quantidade de cada cédula liberada e o valor do saque por extenso. O caixa eletrônico 
deve estar abastecido automaticamente antes do primeiro saque e os valores máximos de cada cédula são: 100 (cédulas) de 450; 200 de 250; 400 de 50; 800 
de 20; 1.600 de 10; 3.200 de 5; 6.400 de 2 e 12.800 de 1 real.

Os relatórios serão apresentados pelo sistema através das opções do menu relatório e a seguir o formato de cada relatório.

##

----------------------------------------------------------------------------------------------------------------------------
Relatório 'Valores sacados'
----------------------------------------------------------------------------------------------------------------------------
conta-corrente1 cpf1 R$ valor1
R$ valor2
R$ valor3
R$ total_l
conta-corrente2 cpf2 R$ valor1
R$ valor2
R$ total_2
...
----------------------------------------------------------------------------------------------------------------------------
R$ valor_total_geral (valor por extenso)
----------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------
Relatório 'Valor do saldo existente '
----------------------------------------------------------------------------------------------------------------------------
R$ valor (valor por extenso)
----------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------
Relatório 'Quantidade de cédulas existentes '
----------------------------------------------------------------------------------------------------------------------------
Cedula X quantidade1 (valor por extenso)
Cedula Y quantidade2 (valor por extenso)
Cedula Z quantidade3 (valor por extenso)
...
--------------------------------------------------------------------------------------------------------------------------

##

Para a construção do sistema utilize o extrato de código do arquivo 'gerador.c' e complemente o código no que for necessário. 
Construa módulos e para o armazenamento utilize estruturas homogêneas.
