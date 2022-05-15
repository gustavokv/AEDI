## Trabalhos-AEDI

Códigos referentes ao Trabalho 1 de Algoritmo e Estrutura de Dados.

## Elevador Espacial

A China está construindo um elevador espacial, que permitirá o lançamento de sondas e satélites a um
custo muito mais baixo, viabilizando não só projetos de pesquisa científica como o turismo espacial.
No entanto, os chineses são muito supersticiosos, e por isso têm um cuidado muito especial com a
numeração dos andares do elevador: eles não usam nenhum número que contenha o dígito “4” ou a
sequência de dígitos “13”. Assim, eles não usam o andar 4, nem o andar 13, nem o andar 134, nem o andar
113, mas usam o andar 103. Assim, os primeiros andares são numerados 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 15,
16,... . .
Como o elevador espacial tem muitos andares, e eles precisam numerar todos os andares do elevador, os
chineses pediram que você escrevesse um programa que, dado o andar, indica o número que deve ser
atribuído a ele.

## Entrada
Cada caso de teste consiste de uma única linha, contendo um inteiro N (1 ≤ N ≤ 106) que indica o andar
cujo número deve ser determinado.

## Saída
Para cada caso de teste, imprima uma linha contendo um único número inteiro indicando o número
atribuído ao N-ésimo andar.

##

## Folha de Pagamentos

Este governo, como todos os anos, está muito preocupado com a folha de pagamentos. Neste ano, porém, a
maneira que os pagamentos serão efetuados será trocada. Ao invés de pagar os funcionários como de
costume, a formula utilizada para calcular os salários será mais simples: A soma dos divisores do número
de matrícula do funcionário.
Para evitar fraudes, ajude o governo a fazer este cálculo!

## Entrada
A entrada começa com uma linha com um número 1 <= N <= 104 que é o número de funcionários. Cada
uma das N linhas seguintes representa um funcionário através de seu numero de matrícula
1 <= M <= 3 x 104.

## Saída
A saída consiste de N linhas, cada uma contendo o salário do funcionário na ordem que foram incluídos na
entrada.

##

## Azulejos

Rafael resolveu trocar os azulejos de sua sala de estar, e para isto fez as medições e comprou N azulejos
brancos na loja.
O fato de todos os azulejos serem brancos deixou Rafael um pouco preocupado com o design de sua sala
de estar, e então decidiu pintar alguns deles para dar um “ar mais moderno” à sua casa.
Posicionou todos os N azulejos em uma linha reta, e enumerou todos eles de 1 até N, da esquerda para a
direita.
Para escolher quais azulejos pintar, pensou na seguinte lógica: Escolheu dois inteiros A e B, e disse que iria
pintar todos os azulejos cuja enumeração fosse múltipla de A e/ou B.
Ajude Rafael a descobrir quantos azulejos serão pintados no total.

## Entrada
Haverá diversos casos de teste. Cada caso de teste contém três inteiros, N, A e B
(3 ≤ N ≤ 10000, 2 ≤ A, B ≤ N).
O último caso de teste é indicado quando N = A = B = 0, o qual não deverá ser processado.

## Saída
Para cada caso de teste, imprima uma linha contendo um inteiro, mostrando quantos azulejos serão
pintados no final do processo.

##

## Máquina de Café

O novo prédio da Sociedade Brasileira de Computação (SBC) possui 3 andares. Em determinadas épocas
do ano, os funcionários da SBC bebem muito café. Por conta disso, a presidência da SBC decidiu
presentear os funcionários com uma nova máquina de expresso. Esta máquina deve ser instalada em um
dos 3 andares, mas a instalação deve ser feita de forma que as pessoas não percam muito tempo subindo e
descendo escadas.
Cada funcionário da SBC bebe 1 café expresso por dia. Ele precisa ir do andar onde trabalha até o andar
onde está a máquina e voltar para seu posto de trabalho. Todo funcionário leva 1 minuto para subir ou
descer um andar. Como a SBC se importa muito com a eficiência, ela quer posicionar a máquina de forma
a minimizar o tempo total gasto subindo e descendo escadas.
Sua tarefa é ajudar a diretoria a posicionar a máquina de forma a minimizar o tempo total gasto pelos
funcionários subindo e descendo escadas.

## Entrada
A entrada consiste em 3 números, A1 , A2 , A3 (≤ 0 Ai ≤ 1000), onde Ai representa o número de pessoas
que trabalham no i-ésimo andar.

## Saída
Seu programa deve imprimir na primeira linha, o número total de minutos a serem gastos com o melhor
posicionamento possível da máquina, e na segunda linha, o(s) andar(es) de melhor posicionamento para a
máquina.
