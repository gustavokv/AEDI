//Alunos:
//Emerson Badocco;
//Gustavo Kermaunar;
//Gustavo Martins.
//Victor Keony;
//Vinicius Schautz;

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 50

struct CARRO {
    char placa[9];          //AAA-1234
    char modelo[TAM];       //gol, celta, palio, ...
    char fabricante[TAM];   //chevrolet, fiat, ...
    int ano_fabricacao;     //1980 à 2016
    int ano_modelo;         //1980 à 2017
    char combustivel[TAM];  //alcool, gasolina, flex, diesel
    char cor[TAM];          //branca, prata, preta
    int opcional[8];        //ver matriz opcionais
    float preco_compra;
};

struct ENDERECO {
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11];       //99.999-999
};

struct TELEFONE {
    char telefone[14];  //99 99999-9999
};

struct CLIENTE {
    char nome[TAM];
    char cpf[15];       //999.999.999-99
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
};

struct DATA {
    int dia, mes, ano;
};

struct VENDA_CARRO {
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    struct DATA data_venda;
};

//Limpar o buffer do teclado.
void flush_in(){ 
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n'){} 
}

//Gera letras aleatorias.
char GeraLetra() {
    int i;
    char letras[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    i = rand() % 26;

    return letras[i];
}

//Gera numeros aleatorios.
char GeraNumero() {
    int i;
    char numeros[] = {"123456789"};

    i = rand() % 9;

    return numeros[i];
}

//Escreve todas as informacoes de um carro.
void PrintaCarro(struct CARRO c) {
    printf("\n--------------------------\n");
    printf("Placa: %s\nModelo: %s\nFabricante: %s\nAno de Fabricacao: %d\n", c.placa, c.modelo, c.fabricante, c.ano_fabricacao);
    printf("Ano Modelo: %d\nCombustivel: %s\nCor: %s\nOpcional: %s\n", c.ano_modelo, c.combustivel, c.cor, c.opcional);
    printf("Preco de Compra: %.2f\n", c.preco_compra);
    printf("---------------------------\n\n");
}

//Escreve todas as informacoes de um cliente.
void PrintaCliente(struct CLIENTE cli) {
    int i=0;

    printf("\n------------------------------\n");
    printf("Nome: %s\nCPF: %s\nEndereco:\n--> Rua %s\n--> Numero: %d\n", cli.nome, cli.cpf, cli.endereco.rua, cli.endereco.numero);
    printf("--> Bairro: %s\n--> Cidade: %s\n--> Estado: %s\n", cli.endereco.bairro, cli.endereco.cidade, cli.endereco.estado);
    printf("--> CEP: %s\nTelefone Residencial: %s\n", cli.endereco.cep, cli.residencial.telefone);
    printf("Telefone(s) Celular(es):\n");
    while(isdigit(cli.celular[i].telefone[0]) > 0) {
        printf("--> %s\n", cli.celular[i].telefone);
        i++;
    }
    if(i == 0)
        printf("--> O cliente nao possui nenhum telefone celular!\n");

    printf("Renda Mensal: %.2f\n", cli.renda_mensal);
    printf("-------------------------------\n\n");
}

void PrintaVenda(struct VENDA_CARRO v) {
    printf("\n--------------------------\n");
    printf("Placa do carro: %s\nCPF do cliente: %s\nPreco de venda: %.2f\n", v.placa_car, v.cpf_cli, v.preco_venda);
    printf("Data da venda:\n--> Dia: %d\n--> Mes: %d\n--> Ano: %d\n", v.data_venda.dia, v.data_venda.mes, v.data_venda.ano);
    printf("-----------------------------\n\n");
}

//Gera aleatoriamente uma placa ao carro.
void GeraPlaca(struct CARRO *c) {

    memset(c->placa, 0, strlen(c->placa));
    
    for(int i=0;i<3;i++)
        c->placa[i] = GeraLetra();

    c->placa[3] = '-';

    for(int i=4;i<8;i++)
        c->placa[i] = GeraNumero();

    c->placa[8] = '\0';
}

//Gera um modelo e sua respextiva marca para o carro.
void GeraModeloMarca(struct CARRO *c) {
    int i;
    char modelos[][TAM] = {{"gol"}, {"palio"}, {"celta"}, {"hb20"}, {"onix"}, {"saveiro"}, {"corolla"}, {"s10"}, {"hillux"},
                             {"strada"}, {"compass"}, {"renegade"}, {"voyage"}, {"duster"}};
    char fabricantes[][TAM] = {{"volkswagen"}, {"fiat"}, {"chevrolet"}, {"hyundai"}, {"chevrolet"}, {"volkswagen"}, {"toyota"},
                                {"chevrolet"}, {"toyota"}, {"fiat"}, {"jeep"}, {"jeep"}, {"volkswagen"}, {"renault"}};
    float preco[][TAM] = {{60000}, {40000}, {30000}, {70000}, {74000}, {57000}, {100500}, {140000}, {189300}, {35400},
                         {178000}, {134000}, {47300}, {93400}};

    i = rand() % 14;

    strcpy(c->modelo, modelos[i]); 
    strcpy(c->fabricante, fabricantes[i]);
    c->preco_compra = *preco[i];
    //Com a mesma variavel de index consegue defifinir corretamente a marca,
    //modelo e preco de compra automaticamente por causa da sequencia. 
}

//Define o combustivel do carro.
void GeraCombustivel(struct CARRO *c) {
    char combustiveis[][TAM] = {{"alcool"}, {"gasolina"}, {"diesel"}, {"flex"}};
    int i;

    i = rand() % 4;

    strcpy(c->combustivel,combustiveis[i]);
}

//Define a cor para o carro.
void GeraCor(struct CARRO *c) {
    int i;
    char cores[][TAM] = {{"preta"}, {"prata"}, {"cinza"}, {"vermelha"}, {"azul"}, {"branca"}, {"amarela"}, {"verde"},
                        {"laranja"}, {"marrom"}};
    
    i = rand() % 10;

    strcpy(c->cor, cores[i]);
}

//Define algum opcional para o carro.
void GeraOpcional(struct CARRO *c) {
    int i;
    char opcionais[][TAM]={{"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"},
                          {"banco.couro"}, {"sensor.estacionamento"}};

    i = rand() % 8;

    strcpy(c->opcional,opcionais[i]); 
}

//Gera um novo carro para ser inserido no arquivo.
void GeraNovoCarro(struct CARRO *c) {
    srand(time(NULL));
    
    GeraPlaca(c);

    GeraModeloMarca(c);

    c->ano_fabricacao = 1980 + (rand()) % 36; //Com isso a faixa fica limitada entre 1980 e 2016.
    c->ano_modelo = c->ano_fabricacao + (rand() % 2); //Ou e o proprio ano de fabricacao ou um ano posterior.

    GeraCombustivel(c);

    GeraCor(c);

    GeraOpcional(c);
}

void ArquivoVendaParaStruct(struct VENDA_CARRO *v) {
    struct VENDA_CARRO venda;
    int i=0;

    FILE *vend = fopen("vendas.dat", "rb");
    
    while(fread(&venda, sizeof(struct VENDA_CARRO), 1, vend)){
        v[i] = venda;  
        i++;
    }

    fclose(vend);
}

//Faz a insercao do carro no arquivo.
void InsereCarroCadastro(struct CARRO c) {
    char insert;
    struct CARRO car;
    int confirm=0;

    system("cls");

    printf("-> Gerando um novo carro...\n");
    GeraNovoCarro(&c);

    FILE *carro = fopen("carros.dat", "rb");

    do{
        if(carro) {
            while(fread(&car, sizeof(struct CARRO), 1, carro)) { //Verifica caso seja repetido o novo carro gerado.
                if(strcmp(car.placa, c.placa) == 0)
                    confirm++;
                else
                    confirm = 0;
            }
        }

        GeraNovoCarro(&c);

        rewind(carro);

    } while(confirm == 1);

    fclose(carro);

    printf("-> Carro gerado!\n");

    PrintaCarro(c);

    do {
        printf("-> Deseja inseri-lo? [S/N]\n");

        //flush_in();

        scanf(" %c", &insert);
        insert = toupper(insert);

        if(insert == 'S') {
            carro = fopen("carros.dat", "ab"); //Abre o arquivo para ser registrado no final dele as informacoes.

            fwrite(&c, sizeof(struct CARRO), 1, carro); //Insere o carro no final do arquivo.
            
            fclose(carro); //Fecha o arquivo.
            
            printf("-> Carro inserido no arquivo com sucesso!\n");
        }
        else if(insert == 'N')
            printf("-> Carro nao inserido!\n");
        else
            printf("-> Escolha uma opcao valida!\n");

        system("pause");

    } while(insert != 'S' && insert != 'N');
}

//Caso a placa do carro pesquisado exista, ele sera exluido do cadastro.
void ExcluiCarroCadastro(struct CARRO c) {
    char placa[9];
    int confirmExclude=0, i=0, cont=0;
    struct VENDA_CARRO v;
    struct CARRO car[50];

    system("cls");

    printf("\n-> Digite a placa do carro que deseja excluir:\n");
    flush_in();
    gets(placa);

    FILE *carro = fopen("carros.dat", "rb");

    if(!carro) {
        printf("\n-> Nao ha nenhum carro registrado!\n");
        system("pause");
        return 0;
    }  

    FILE *venda = fopen("vendas.dat", "rb");

    if(venda) {
        while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)){
            if(strcmp(v.placa_car, placa) == 0){
                printf("\n-> O carro ja foi vendido, nao e possivel exclui-lo!\n");
                system("pause");

                return 0;
            }
        }
        fclose(venda);
    }

    //Caso o arquivo exista:
    while(fread(&c, sizeof(struct CARRO), 1, carro)){ //Le todo o conteudo do arquivo, ate achar a placa procurada.
        if(strcmp(c.placa, placa) == 0) {
            confirmExclude++;
            printf("\n-> Carro encontrado!\n-> Excluindo...\n");

            rewind(carro); //Volta o ponteiro do arquivo carros para seu inicio.

            while(fread(&c, sizeof(struct CARRO), 1, carro)){
                if(strcmp(c.placa, placa) != 0){
                    car[i] = c;
                    i++;
                }  
            }

            fclose(carro);

            remove("carros.dat");             

            carro = fopen("carros.dat", "ab");

            while(cont<i) {
                fwrite(&car[cont], sizeof(struct CARRO), 1, carro); //Passa para o arquivo principal novamente.
                cont++;
            }

            fclose(carro);
            
            printf("-> Carro de placa [%s] removido com sucesso!\n", placa);

            break;
        }
    }

    if(!confirmExclude){
        printf("\n-> Carro nao foi encontrado!\n");
        fclose(carro);
    }

    system("pause");
}

//Passa o arquivo carros para uma estrutura.
void ArquivoCarParaStruct(struct CARRO *c) {
    struct CARRO car;
    int i=0;

    FILE *carro = fopen("carros.dat", "rb");
    
    while(fread(&car, sizeof(struct CARRO), 1, carro)){
        c[i] = car;  
        i++;
    }

    fclose(carro);
}

//Inverte uma duas posicoes em um vetor de estruturas de carros.
void InverteStructCar(struct CARRO *c1, struct CARRO *c2) {
    struct CARRO aux;

    aux = *c1;  
    *c1 = *c2;
    *c2 = aux;
}

//Lista os carros disponiveis para a venda ordenados crescentemente por fabricante e modelo.
void ListaPorFabModelo(struct CARRO c) {
    struct CARRO carro[TAM];
    struct CARRO newCarro[TAM];
    int tam=0, verifFabricante, verifModelo, i=0, qntVenda=0;
    struct VENDA_CARRO v[TAM];
    
    ArquivoCarParaStruct(carro);
    
    system("cls");

    FILE *car = fopen("carros.dat", "rb");
    FILE *venda = fopen("vendas.dat", "rb");

    while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda))
        qntVenda++;

    ArquivoVendaParaStruct(v);

    if(qntVenda>0) {
        while(fread(&c, sizeof(struct CARRO), 1, car)) {
            while(i<qntVenda) {
                if(strcmp(c.placa, v[i].placa_car) != 0) {
                    newCarro[tam] = c;
                    tam++;
                }
                i++;
            }
            i=0;
        }
    }
    else {
        i=0;
        while(fread(&c, sizeof(struct CARRO), 1, car)) {
            newCarro[i] = c;
            i++;
            tam++;
        }
    }

    fclose(venda);

    fclose(car);

    if(tam==0){
        printf("-> Nao ha nenhum carro para ser listado!\n\n");
        system("pause");
        return 0;
    }

    printf("\n-> Carros disponiveis a venda ordenados por fabricante e modelo:\n");

    for (int i=0;i<tam;i++) {
        for(int j=0;j<tam;j++) {
            verifFabricante = strcmp(newCarro[i].fabricante, newCarro[j].fabricante); //strcmp para verificar alfabeticamente as strings.
            verifModelo = strcmp(newCarro[i].modelo, newCarro[j].modelo);//verifica tambem o modelo para ordenar corretamente.

            if(verifFabricante>0)
                InverteStructCar(&newCarro[i], &newCarro[j]); 
            else if(verifFabricante == 0 && verifModelo > 0) //Caso os fabricantes sejam iguais, ele seleciona pelo modelo.
                InverteStructCar(&newCarro[i], &newCarro[j]);
        }
    }
    
    for(int i=tam-1;i>=0;i--) 
        PrintaCarro(newCarro[i]); 

    system("pause");
}

//O usuario digita o(s) opcionais que deseja listar dos carros à venda e eles sao mostrados.
void ListaPorOpcional(struct CARRO c) {
    char opcional[8][TAM];
    int i, qntOp, resp, qntPrint=0, j=0, confirm=0;
    struct VENDA_CARRO v[TAM];

    system("cls");

    for(i=0;i<8;i++)
        memset(opcional[i], 0, TAM);

    i=0;

    do{
        system("cls");

        printf("\n-> Qual(is) opcional(is) deseja que seja listado?\n");
        flush_in();
        gets(opcional[i]);

        printf("\n-> Deseja adicionar mais algum opcional? [1-Sim 2-Nao]\n");
        scanf("%d", &resp);

        i++;
    }while(resp == 1);

    FILE *carro = fopen("carros.dat", "rb");
    FILE *venda = fopen("vendas.dat", "rb");

    ArquivoVendaParaStruct(v);

    if(!carro){
        printf("\n-> Arquivo nao encontrado!\n");
        system("pause");
        return 0;
    }

    system("cls");

    printf("\n-> Carros com o(s) opcional(is) pedidos:\n");

    while(fread(&c, sizeof(struct CARRO), 1, carro)) {
        qntOp = 0;
        while(qntOp<i) {
            if(strcmp(c.opcional, opcional[qntOp]) == 0){ //Compara os opcionais digitados pelo usuario com todos os carros.
                if(venda) {
                    while(v[j].placa_car[0]) {
                        if(strcmp(v[j].placa_car, c.placa) == 0){
                            confirm++;
                            break;
                        }
                        j++;
                    }
                }
                if(confirm == 0){
                    PrintaCarro(c);
                    qntPrint++;
                }
            }
            confirm=0;
            qntOp++;
            j=0;
        }
    }

    if(qntPrint==0)
        printf("\n-> Nenhum carro com esse(s) opcional(is) encontrado!\n");

    system("pause");

    fclose(carro);
}

//O usuario pede pra listar os carros à venda numa determinada faixa de ano de fabricacao.
void ListaPorFaixaAno(struct CARRO c) {
    int min, max, qntPrint=0;

    system("cls");

    printf("\n-> Qual a faixa de ano de fabricacao que deseja ver?\n-> Digite o ano minimo:\n");
    scanf("%d", &min);

    do{
        printf("\n-> Digite o ano maximo:\n");
        scanf("%d", &max);

        if(max<min) {
            printf("\n-> O ano maximo deve ser maior ou igual ao minimo!\n");
            system("pause");
            system("cls");
        }
    }while(max<min);

    FILE *carro = fopen("carros.dat", "rb");

    if(!carro){
        printf("\n-> Arquivo nao encontrado!\n");
        system("pause");
        return 0;
    }

    system("cls");

    printf("\n-> Carros na faixa de ano desejado:\n");

    while(fread(&c, sizeof(struct CARRO), 1, carro)) {
        if(c.ano_fabricacao>=min && c.ano_fabricacao<=max){ //Caso esteja no intervalo e printado.
            PrintaCarro(c);
            qntPrint++;
        }
    }

    if(qntPrint==0)
        printf("\n-> Nenhum carro nessa faixa foi encontrado!\n");

    system("pause");

    fclose(carro);
}

void MenuCarro(struct CARRO c) {
    char escolhaMenuCarro;

    do{
        system("cls");

        printf("\n----------------\n|  Menu Carro  |\n----------------\n");
        printf("\n[a] Inserir um carro no cadastro\n\
[b] Excluir um carro do cadastro\n\
[c] Listar os carros disponiveis para a venda ordenados crescentemente por fabricante e modelo\n\
[d] Listar os carros disponiveis para a venda por selecao de um ou mais opcionais\n\
[e] Listar os carros disponiveis para a venda por selecao da faixa de ano de fabricacao\n\
[f] Voltar ao menu principal\n");

        //flush_in();

        scanf(" %c", &escolhaMenuCarro);

        escolhaMenuCarro = tolower(escolhaMenuCarro);

        switch(escolhaMenuCarro) {
            case 'a':
                InsereCarroCadastro(c);
                break;
            case 'b':
                ExcluiCarroCadastro(c);
                break;
            case 'c':   
                ListaPorFabModelo(c);
                break;
            case 'd':
                ListaPorOpcional(c);
                break;
            case 'e':
                ListaPorFaixaAno(c);
                break;
            case 'f':
                printf("\n-> Voltando ao menu principal...\n");

                system("pause");
                break;
            default:
                printf("\n->Escolha uma opcao valida!\n");

                system("pause");
                break;
        }
    } while(escolhaMenuCarro != 'f');
}

void GeraNomeCliente(struct CLIENTE *cli) {
    char nomes[][TAM] = {{"Pedro"}, {"Larissa"}, {"Jose"}, {"Carlos"}, {"Roberto"}, {"Gustavo"}, {"Vinicius"}, {"Victor"}, 
                     {"Emerson"}, {"Felipe"}, {"Warley"}, {"Maria"}, {"Isabel"}, {"Ronaldo"}, {"Erica"}};
    char sobrenomes[][TAM] = {{"Kermaunar"}, {"Badocco"}, {"Keony"}, {"Schautz"}, {"Martins"}, {"Ribeiro"}, {"Henrique"},
                             {"Santos"}, {"Silva"}, {"Volobueff"}, {"Ortega"}, {"Rodrigues"}, {"Alves"}, {"Pereira"}, {"Souza"},
                             {"Oliveira"}};
    int i, j;

    i = rand() % 15;
    j = rand() % 16;

    strcpy(cli->nome, nomes[i]);
    strcat(cli->nome, " ");
    strcat(cli->nome, sobrenomes[j]);
}

//Gera os dois ultimos digitos do CPF.
void GeraCPFDigito(char *cpf) {
    int Dig1, Dig2;

    Dig1 = ((cpf[0] - '0') * 10 + (cpf[1] - '0') * 9 + (cpf[2] - '0') * 8 + (cpf[4] - '0') * 7 + (cpf[5] - '0') * 6 + (cpf[6] - '0') * 5 +(cpf[8] - '0') * 4 + (cpf[9] - '0') * 3 + (cpf[10] - '0') * 2) % 11;
    Dig1 = 11 - Dig1;

    if(Dig1>=10)
        Dig1 = 0;

    cpf[12] = Dig1 + '0';

    Dig2 = ((cpf[0] - '0') * 11 + (cpf[1] - '0') * 10 + (cpf[2] - '0') * 9 + (cpf[4] - '0') * 8 + (cpf[5] - '0') * 7 + (cpf[6] - '0') * 6 +(cpf[8] - '0') * 5 + (cpf[9] - '0') * 4 + (cpf[10] - '0') * 3 + (cpf[12] - '0') * 2) % 11;
    Dig2 = 11 - Dig2;

    if(Dig2>=10)
        Dig2 = 0;

    cpf[13] = Dig2 + '0';
}

void GeraCPFCliente(struct CLIENTE *cli) {
    char cpfmod[15];

    memset(cpfmod, 0, 15);

    for(int i=0;i<11;i++) {
        if(i==3 || i== 7)
            cpfmod[i] = '.';
        else
            cpfmod[i] = GeraNumero();
    }
    cpfmod[11] = '-';

    GeraCPFDigito(cpfmod);

    strcpy(cli->cpf, cpfmod);
}

//Adiciona pontuacao num CPF lido pelo usuario.
void AdicionaPontCPF(char *cpf) {
    char cpfMod[15];

    if(strlen(cpf) == 14)
        return 0;

    cpfMod[0] = cpf[0];
    cpfMod[1] = cpf[1];
    cpfMod[2] = cpf[2];
    cpfMod[3] = '.';
    cpfMod[4] = cpf[3];
    cpfMod[5] = cpf[4];
    cpfMod[6] = cpf[5];
    cpfMod[7] = '.';
    cpfMod[8] = cpf[6];
    cpfMod[9] = cpf[7];
    cpfMod[10] = cpf[8];
    cpfMod[11] = '-';
    cpfMod[12] = cpf[9];
    cpfMod[13] = cpf[10];
    cpfMod[14] = '\0';

    strcpy(cpf, cpfMod);
}

//Gera o endereco completo do cliente.
void GeraEnderecoCliente(struct CLIENTE *cli) {
    char ruas[][TAM] = {{"Alberto Pasqualini"}, {"Aurora"}, {"Bartolomeu Mitre"}, {"Nascimento Silva"}, {"Oscar Freire"}, 
                       {"Aurelio Lago"}, {"14-Bis"}, {"Mucuge"}, {"Adolfo Tabacow"}, {"Suinam"}, {"25 de Agosto"},
                       {"Pituba"}, {"Bento Goncalves"}, {"Conde de Bobadela"}};
    char bairros[][TAM] = {{"Leblon"}, {"Itaim Bibi"}, {"Planalto"}, {"Vila Brasilia"}, {"Boqueirao"}, {"Pinheirinho"}, {"Macedo"},
                          {"Vila Belmiro"}, {"Itanhanga"}, {"Vila Ubiratan"}, {"Petropolis"}, {"Jardim Camburi"}, 
                          {"Barro Duro"}, {"Guararapes"}};
    char cidades[][TAM] = {{"Rio de Janeiro"}, {"Sao Paulo"}, {"Gramado"}, {"Volta Redonda"}, {"Curitiba"}, 
                          {"Curitiba"}, {"Guarulhos"}, {"Santos"}, {"Campo Grande"}, {"Dourados"}, {"Porto Alegre"},
                          {"Vitoria"}, {"Maceio"}, {"Fortaleza"}};
    char estados[][3] = {{"RJ"}, {"SP"}, {"RS"}, {"RJ"}, {"PR"}, {"PR"}, {"SP"}, {"SP"}, {"MS"}, {"MS"}, {"RS"}, {"ES"}, {"AL"},
                        {"CE"}};
    char ceps[][TAM] = {{"22.431-000"}, {"01.453-040"}, {"95.670-000"}, {"27.277-230"}, {"81.670-200"}, {"81.820-170"},
                      {"07.113-020"}, {"11.010-020"}, {"13.471-410"}, {"79.800-006"}, {"09.179-340"}, {"29.010-035"},
                      {"57.010-445"}, {"60.010-010"}};
    int i;

    i = rand() % 14;

    strcpy(cli->endereco.rua, ruas[i]);
    cli->endereco.numero = 1 + (rand()) % 999; //Numero e gerado entre 1 e 1000.
    strcpy(cli->endereco.bairro, bairros[i]);
    strcpy(cli->endereco.cidade, cidades[i]);
    strcpy(cli->endereco.estado, estados[i]);
    strcpy(cli->endereco.cep, ceps[i]);
}

//Gera os dois telefones do cliente.
void GeraTelefone(struct CLIENTE *cli) {
    int qntCel, j;
    
    for(int i=0;i<9;i++) {
        if(i==4)
            cli->residencial.telefone[i] = '-';
        else    
            cli->residencial.telefone[i] = GeraNumero(); 
    }

    cli->residencial.telefone[9] = '\0';
    
    qntCel = rand() % 6; //Quantidade de numeros celulares que sera criado. 0 a 5.

    for(j=0;j<qntCel;j++) {
        for(int i=0;i<13;i++){
            if(i==2)
                cli->celular[j].telefone[i] = ' ';
            else if(i==8)
                cli->celular[j].telefone[i] = '-';
            else
                cli->celular[j].telefone[i] = GeraNumero();

            cli->celular[j].telefone[13] = '\0';
        }
    }

    if(j==6)
        return 0;

    while(j<6) {
        strncpy(cli->celular[j].telefone, "\0", 14);
        j++;
    }
}

void GeraNovoCliente(struct CLIENTE *cli) {

    srand(time(NULL));

    GeraNomeCliente(cli);

    GeraCPFCliente(cli);

    GeraEnderecoCliente(cli);

    GeraTelefone(cli);

    cli->renda_mensal =  1200 + (float)(rand())/(float)(RAND_MAX)*33800.0; //Gera um valor float de R$1200 ate R$35 mil.
}

void InsereClienteCadastro(struct CLIENTE cli) {
    char escolhaCliente;

    system("cls");

    printf("\n-> Gerando novo cliente...\n");
    GeraNovoCliente(&cli);
    printf("-> Novo cliente gerado!\n");

    PrintaCliente(cli);

    do {
        printf("-> Deseja inseri-lo? [S/N]\n");

        //flush_in();

        scanf(" %c", &escolhaCliente);
        escolhaCliente = toupper(escolhaCliente);

        if(escolhaCliente == 'S') {
            FILE *cliente = fopen("clientes.dat", "ab");

            fwrite(&cli, sizeof(struct CLIENTE), 1, cliente);

            fclose(cliente);

            printf("\n-> Cliente inserido com sucesso!\n");
        }
        else if(escolhaCliente == 'N')
            printf("\n-> Cliente nao inserido!\n");
        else
            printf("-> Escolha uma opcao valida!\n");

        system("pause");
    } while(escolhaCliente != 'S' && escolhaCliente != 'N');
}

void ExcluiClienteCadastro(struct CLIENTE cli){
    char cpf[15];
    int confirmEx=0, i=0, cont=0;
    struct VENDA_CARRO v;
    struct CLIENTE c[50];

    memset(cpf, 0, 15);

    system("cls");

    printf("\n-> Digite o CPF do cliente que deseja excluir:\n");
    flush_in();
    gets(cpf);

    AdicionaPontCPF(&cpf); 

    FILE *cliente = fopen("clientes.dat", "rb");

    if(!cliente) {
        printf("\n-> Nao ha nenhum cliente registrado!\n");
        system("pause");
        
        return 0;
    }  

    FILE *venda = fopen("vendas.dat", "rb");

    if(venda) {
        while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)) {
            if(strcmp(v.cpf_cli, cpf) == 0) {
                printf("\n-> Nao e possivel excluir o cliente pois ha pelo menos uma venda registrada para ele!\n");
                system("pause");
                fclose(venda);
                return 0;
            }
        }
    }

    fclose(venda);

    //Caso o arquivo exista:
    while(fread(&cli, sizeof(struct CLIENTE), 1, cliente)){ //Le todo o conteudo do arquivo, ate achar o cpf procurado.
        if(strcmp(cli.cpf, cpf) == 0) {
            confirmEx++;
            printf("\n-> Cliente encontrado!\n-> Excluindo...\n");

            rewind(cliente); //Volta o ponteiro do arquivo clientes para seu inicio.

            while(fread(&cli, sizeof(struct CLIENTE), 1, cliente)){
                if(strcmp(cli.cpf, cpf) != 0) {
                    c[i] = cli;
                    i++;
                }
            }

            fclose(cliente);

            remove("clientes.dat"); 

            cliente = fopen("clientes.dat", "ab");

            while(cont<i) { 
                fwrite(&c[cont], sizeof(struct CLIENTE), 1, cliente); //Passa para o arquivo principal novamente.
                cont++;
            }

            fclose(cliente);
            
            printf("-> Cliente de CPF [%s] removido com sucesso!\n", cpf);

            break;
        }
    }

    if(!confirmEx){
        printf("\n-> Cliente nao foi encontrado!\n");
        fclose(cliente);
    }

    system("pause");
}

void ArquivoClienteParaStruct(struct CLIENTE *cli) {
    struct CLIENTE c;
    int i=0;

    FILE *cliente = fopen("clientes.dat", "rb");
    
    while(fread(&c, sizeof(struct CLIENTE), 1, cliente)){
        cli[i] = c;  
        i++;
    }

    fclose(cliente);
}

void InverteStructCliente(struct CLIENTE *cli1, struct CLIENTE *cli2) {
    struct CLIENTE aux;

    aux = *cli1;  
    *cli1 = *cli2;
    *cli2 = aux;
}

void ListaCresNomeCliente(struct CLIENTE cli) {
    struct CLIENTE cliente[TAM];
    int tam=0, verifNome;
    
    ArquivoClienteParaStruct(cliente);
    
    system("cls");

    FILE *c = fopen("clientes.dat", "rb");

    while(fread(&cli, sizeof(struct CLIENTE), 1, c))
        tam++;

    fclose(c);

    if(tam==0) {
        printf("\n-> Arquivo nao encontrado!\n");
        system("pause");
        return 0;
    }

    printf("\n-> Clientes ordenados crescentemente pelo nome:\n");

    for(int i=0;i<tam;i++) {
        for(int j=0;j<tam;j++) {
            verifNome = strcmp(cliente[i].nome, cliente[j].nome); //strcmp para verificar alfabeticamente as strings.

            if(verifNome>0)
                InverteStructCliente(&cliente[i], &cliente[j]);//Caso precise inverter para seguir alfabeticamente.
        }
    }
    
    for(int i=tam-1;i>=0;i--) 
        PrintaCliente(cliente[i]); 

    system("pause");
}

void ListaPorNomeSalario(struct CLIENTE cli) {
    struct CLIENTE cliente[TAM];
    int tam=0, verifNome;
    float max, min;
    
    ArquivoClienteParaStruct(cliente);
    
    system("cls");

    FILE *c = fopen("clientes.dat", "rb");

    while(fread(&cli, sizeof(struct CLIENTE), 1, c))
        tam++;

    fclose(c);

    if(tam==0) {
        printf("\n-> Arquivo nao encontrado!\n");
        system("pause");
        return 0;
    }

    printf("\n-> Qual o valor minimo do salario que deseja ver?\n");
    scanf("%f", &min);

    do{
        system("cls");

        printf("\n-> E o salario maximo?\n");
        scanf("%f", &max);

        if(max<min){
            printf("-> O valor maximo deve ser maior que o minimo!\n");
            system("pause");
        }
    } while(max<min);

    system("cls");

    printf("\n-> Clientes ordenados crescentemente pelo nome e pela faixa salarial desejada:\n");

    for(int i=0;i<tam;i++) {
        for(int j=0;j<tam;j++) {
            verifNome = strcmp(cliente[i].nome, cliente[j].nome); //strcmp para verificar alfabeticamente as strings.

            if(verifNome>0)
                InverteStructCliente(&cliente[i], &cliente[j]);//Caso precise inverter para seguir alfabeticamente.
        }
    }

    for(int i=tam-1;i>=0;i--) {
        if(cliente[i].renda_mensal>=min && cliente[i].renda_mensal<=max) //Caso esteja dentro da faixa salarial desejada...
            PrintaCliente(cliente[i]);
    } 

    system("pause");
}

void MenuCliente(struct CLIENTE cli) {
    char escolhaMenuCliente;

    do {
        system("cls");

        printf("\n------------------\n|  Menu Cliente  |\n------------------\n");
        printf("\n[a] Inserir um cliente no cadastro\n\
[b] Excluir um cliente do cadastro\n\
[c] Listar os clientes do cadastro ordenados crescentemente pelo nome\n\
[d] Listar os clientes do cadastro ordenados crescentemente pelo nome por selecao de faixa de renda salarial mensal\n\
[e] Voltar ao menu principal\n");

        //flush_in();

        scanf(" %c", &escolhaMenuCliente);

        escolhaMenuCliente = tolower(escolhaMenuCliente);

        switch(escolhaMenuCliente) {
            case 'a':
                InsereClienteCadastro(cli);
                break;
            case 'b':
                ExcluiClienteCadastro(cli);
                break;
            case 'c':
                ListaCresNomeCliente(cli);
                break;
            case 'd':
                ListaPorNomeSalario(cli);
                break;
            case 'e':
                printf("\n-> Voltando ao menu principal...\n");

                system("pause");
                break;
            default:
                printf("\n->Escolha uma opcao valida!\n");

                system("pause");
                break;
        }
    } while(escolhaMenuCliente != 'e');
}

void InsereVenda(struct VENDA_CARRO v, struct CARRO c, struct CLIENTE cli) {
    int confirmPlaca=0, confirmCPF=0;
    char placa[9], cpf[15], escolhaVenda;
    float precoVenda;

    srand(time(NULL));

    system("cls");

    FILE *carro = fopen("carros.dat", "rb");
    FILE *cliente = fopen("clientes.dat", "rb");

    flush_in();

    printf("\n-> Qual a placa do carro que deseja inserir a venda?\n");
    gets(placa);

    while(fread(&c, sizeof(struct CARRO), 1, carro)){ //Validacao da existencia do carro.
        if(strcmp(placa, c.placa)==0) {
            confirmPlaca=1;
            precoVenda = c.preco_compra * 10 / 100 + c.preco_compra; //Isso faz com que o preco de venda de um lucro de 10%.
        }
    }

    fclose(carro);

    if(confirmPlaca == 0) {
        printf("\n-> O carro buscado nao foi encontrado!\n");
        system("pause");
        return 0;
    }

    printf("-> E o CPF do cliente que deseja vende-lo?\n");
    gets(cpf);

    AdicionaPontCPF(&cpf);

    while(fread(&cli, sizeof(struct CLIENTE), 1, cliente)){ //Validacao do CPF.
        if(strcmp(cpf, cli.cpf) == 0)
            confirmCPF=1;
    }

    fclose(cliente);

    if(confirmCPF == 0) {
        printf("\n-> O CPF buscado nao foi encontrado!\n");
        system("pause");
        return 0;
    }

    FILE *venda = fopen("vendas.dat", "a+b");

    if(venda) { //Caso o arquivo exista, procura caso o carro ja tenha sido vendido.
        while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)) {
            if(strcmp(v.placa_car, placa) == 0) {
                printf("\n-> O carro ja foi vendido!\n");
                system("pause");
                fclose(venda);
                return 0;
            }
        }
    }

    //Insere a venda na estrutura para depois inserir no arquivo.
    strcpy(v.placa_car, placa);
    strcpy(v.cpf_cli, cpf);
    v.preco_venda = precoVenda;
    v.data_venda.ano = 2010 + (rand()) % 12; //Randomiza o ano entre 2010 e 2022.
    v.data_venda.mes = 1 + (rand()) % 11;
    v.data_venda.dia = 1 + (rand()) % 29;

    system("cls");

    PrintaVenda(v);

    printf("\n-> Deseja inserir esta venda? [S/N]\n");

    scanf(" %c", &escolhaVenda);

    escolhaVenda = toupper(escolhaVenda);

    if(escolhaVenda == 'S') {
        fwrite(&v, sizeof(struct VENDA_CARRO), 1, venda);
        printf("\n-> Venda inserida com sucesso!\n");
    }
    else
        printf("-> A venda nao sera inserida!\n");

    fclose(venda);

    system("pause");
}

void ExcluiVenda(struct VENDA_CARRO v) {
    char placa[9];
    int confirmEx=0, i=0, cont=0;
    struct VENDA_CARRO vend[50];

    memset(placa, 0, 9);

    system("cls");

    printf("\n-> Digite a placa do carro que deseja excluir a venda:\n");
    flush_in();
    gets(placa);

    FILE *venda = fopen("vendas.dat", "rb");

    //Caso nao haja nenhuma venda:
    if(!venda) {
        printf("\n-> Nao ha nenhuma venda registrada!\n");
        system("pause");
        
        return 0;
    }  

    //Caso o arquivo exista:
    while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)){ //Le todo o conteudo do arquivo, ate achar a placa procurada.
        if(strcmp(v.placa_car, placa) == 0) {
            confirmEx++;
            printf("\n-> Carro encontrado!\n-> Excluindo...\n");

            rewind(venda); //Volta o ponteiro do arquivo venda para seu inicio.

            while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)){
                if(strcmp(v.placa_car, placa) != 0) {
                    vend[i] = v;
                    i++;
                }
            }

            fclose(venda);

            remove("vendas.dat"); 

            venda = fopen("vendas.dat", "ab");

            while(cont<i) { 
                fwrite(&vend[cont], sizeof(struct VENDA_CARRO), 1, venda); //Passa para o arquivo principal novamente.
                cont++;
            }

            fclose(venda);
            
            printf("-> Venda de carro com placa [%s] removida com sucesso!\n", placa);

            break;
        }
    }

    if(!confirmEx){
        printf("\n-> Venda nao foi encontrada!\n");
        fclose(venda);
    }

    system("pause");
}

void ListaVendaFabricante(struct VENDA_CARRO v) {
    char fab[15], cpfs[50][15];
    struct CARRO vendidos[50];
    struct CARRO c;
    struct CLIENTE cli;
    int tam=0, verifMod, cont=0, i, qntVend=0, j=0;

    system("cls");

    memset(fab, 0, 15);

    for(i=0;i<50;i++) {
        memset(cpfs[i], 0, 15);
        memset(vendidos[i].modelo, 0, TAM);
    }

    i=0;

    printf("\n-> Qual o fabricante que deseja listar?\n");
    flush_in();
    gets(fab);

    FILE *venda = fopen("vendas.dat", "rb");

    if(!venda) {
        printf("\n-> Nenhuma venda registrada!\n");
        system("pause");
        return 0;
    }

    while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)) //Verifica quantas estruturas ha no arquivo.
        tam++;

    rewind(venda);  

    FILE *carro = fopen("carros.dat", "rb");

    while(cont<tam) {
        fread(&v, sizeof(struct VENDA_CARRO), 1, venda);

        while(fread(&c, sizeof(struct CARRO), 1, carro)) {
            if(strcmp(v.placa_car, c.placa) == 0 && strcmp(fab, c.fabricante) == 0) { //Separa quais sao os carros vendidos.
                vendidos[i] = c;
                strcpy(cpfs[i], v.cpf_cli); //Ja aproveita e marca o CPF para printar o cliente depois.
                i++;
                qntVend++;
            }
        }

        rewind(carro);

        cont++;
    }

    fclose(carro);
    fclose(venda);

    if(qntVend==0) {
        printf("\n-> Nenhum carro encontrado com esse fabricante!\n");
        system("pause");
        return 0;
    }
    
    printf("\n-> Vendas do fabricante [%s] ordenados pelo modelo:\n", fab);

    for(i=0;i<qntVend;i++) {
        for(int j=0;j<qntVend;j++) {
            verifMod = strcmp(vendidos[i].modelo, vendidos[j].modelo); //strcmp para verificar alfabeticamente as strings.

            if(verifMod>0)
                InverteStructCar(&vendidos[i], &vendidos[j]);//Caso precise inverter para seguir alfabeticamente.
        }
    }

    FILE *cliente = fopen("clientes.dat", "rb");

    for(i=qntVend-1;i>=0;i--) {
        printf("\n---------------------\n");
        printf("Modelo: %s\nPlaca: %s\nAno de Fabricacao: %d\n", vendidos[i].modelo, vendidos[i].placa, vendidos[i].ano_fabricacao);
        while(fread(&cli, sizeof(struct CLIENTE), 1, cliente)) { //Varre o arquivo de clientes ate achar o CPF do carro vendido
            if(strcmp(cpfs[j], cli.cpf) == 0) {                  //e printar o nome do cliente.
                printf("Nome do Cliente: %s\n", cli.nome);
                break;
            }
        }
        printf("\n---------------------\n\n");

        j++;

        rewind(cliente);
    }

    fclose(cliente);

    system("pause");
}

void ListaVendaAnoFab(struct VENDA_CARRO v){
    char mod[15], cpfs[50][15];
    struct CARRO vendidos[50];
    struct CARRO c;
    struct CLIENTE cli;
    int tam=0, cont=0, i, qntVend=0, j, nomeCont=0;

    system("cls");

    memset(mod, 0, 15);

    for(i=0;i<50;i++) {
        memset(cpfs[i], 0, 15);
        memset(vendidos[i].modelo, 0, TAM);
    }

    i=0;

    printf("\n-> Qual o modelo que deseja listar?\n");
    flush_in();
    gets(mod);

    FILE *venda = fopen("vendas.dat", "rb");

    if(!venda) {
        printf("\n-> Nenhuma venda registrada!\n");
        system("pause");
        return 0;
    }

    while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)) //Verifica quantas estruturas ha no arquivo.
        tam++;

    rewind(venda);  

    FILE *carro = fopen("carros.dat", "rb");

    while(cont<tam) {
        fread(&v, sizeof(struct VENDA_CARRO), 1, venda);

        while(fread(&c, sizeof(struct CARRO), 1, carro)) {
            if(strcmp(v.placa_car, c.placa) == 0 && strcmp(mod, c.modelo) == 0) { //Separa quais sao os carros vendidos.
                vendidos[i] = c;
                strcpy(cpfs[i], v.cpf_cli); //Ja aproveita e marca o CPF para printar o cliente depois.
                i++;
                qntVend++;
            }
        }

        rewind(carro);

        cont++;
    }

    fclose(carro);
    fclose(venda);

    if(qntVend==0) {
        printf("\n-> Nenhum carro encontrado com esse modelo!\n");
        system("pause");
        return 0;
    }
    
    printf("\n-> Vendas do modelo [%s] ordenados por ano de fabricacao:\n", mod);

    for(i=0;i<qntVend;i++) {
        for(int j=0;j<qntVend;j++) {
            if(vendidos[i].ano_fabricacao < vendidos[j].ano_fabricacao){
                InverteStructCar(&vendidos[i], &vendidos[j]);//Caso precise inverter para seguir alfabeticamente.  
            } 
        }
    }

    FILE *cliente = fopen("clientes.dat", "rb");

    for(i=0;i<qntVend;i++) {
        printf("\n---------------------\n");
        printf("Ano de Fabricacao: %d\nPlaca: %s\n", vendidos[i].ano_fabricacao, vendidos[i].placa);
        while(fread(&cli, sizeof(struct CLIENTE), 1, cliente)) { //Varre o arquivo de clientes ate achar o CPF do carro vendido
            if(strcmp(cpfs[nomeCont], cli.cpf) == 0) {                  //e printar o nome do cliente.
                printf("Nome do Cliente: %s\n", cli.nome);
                break;
            }
        }
        printf("\n---------------------\n\n");

        nomeCont++;

        rewind(cliente);
    }

    fclose(cliente);

    system("pause");
}

void ListaQntCarrosVend(struct VENDA_CARRO v) {
    int qntCarros=0;
    float qntPreco=0;

    FILE *venda = fopen("vendas.dat", "rb");

    system("cls");

    if(!venda) {
        printf("\n-> Nao ha nenhuma venda registrada!\n");
        system("pause");
        return 0;
    }

    while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)) {
        qntCarros++;
        qntPreco += v.preco_venda;
    }

    fclose(venda);

    printf("\n-> Quantidade de carros vendidos: %d\n", qntCarros);
    printf("-> Valor total vendido: %.2f\n", qntPreco);

    system("pause");
}

void ListaLucroVendas(struct VENDA_CARRO v) {
    struct CARRO c;
    float lucro=0;

    system("cls");

    FILE *venda = fopen("vendas.dat", "rb");
    FILE *carro = fopen("carros.dat", "rb");

    while(fread(&v, sizeof(struct VENDA_CARRO), 1, venda)) {
        while(fread(&c, sizeof(struct CARRO), 1, carro)) {
            if(strcmp(v.placa_car, c.placa) == 0) {
                lucro += v.preco_venda - c.preco_compra;
                break;
            }
        }

        rewind(carro);
    }

    fclose(carro);
    fclose(venda);

    printf("\n-> Lucro total das vendas: %.2f\n", lucro);

    system("pause");
}
 
void MenuVenda(struct VENDA_CARRO v) {
    char escolhaMenuVenda;
    struct CARRO c;
    struct CLIENTE cli;

    do {
        system("cls");

        printf("\n------------------\n|  Menu Venda  |\n------------------\n");
        printf("\n[a] Inserir uma venda\n\
[b] Excluir uma venda\n\
[c] Listar os carros vendidos de um determinado fabricante, ordenados crescentemente pelo modelo (as seguintes\n\
informacoes devem aparecer: modelo, placa, ano fabricacao e nome cliente)\n\
[d] Listar os carros vendidos de um determinado modelo, ordenados crescentemente pelo ano de fabricacao (as\n\
seguintes informacoes devem aparecer: ano de fabricacao, placa e nome cliente)\n\
[e] Informar a quantidade de carros vendidos com o valor totalizado dos precos vendidos\n\
[f] Informar o lucro total das vendas\n\
[g] Voltar ao menu principal\n");

        scanf(" %c", &escolhaMenuVenda);

        escolhaMenuVenda = tolower(escolhaMenuVenda);

        switch(escolhaMenuVenda) {
            case 'a':
                InsereVenda(v, c, cli);
                break;
            case 'b':
                ExcluiVenda(v);
                break;
            case 'c':
                ListaVendaFabricante(v);
                break;
            case 'd':
                ListaVendaAnoFab(v);
                break;
            case 'e':
                ListaQntCarrosVend(v);
                break;
            case 'f':
                ListaLucroVendas(v);
                break;
            case 'g':
                printf("\n-> Voltando ao menu principal...\n");

                system("pause");
                break;
            default:
                printf("\n->Escolha uma opcao valida!\n");

                system("pause");
                break;
        }
    } while(escolhaMenuVenda != 'g');
}

void MenuPrincipal() {
    int escolhaMenuMain;
    struct CARRO carro;
    struct CLIENTE cliente;
    struct VENDA_CARRO venda;

    do {
        system("cls");

        printf("\n---------------------------\n|  Revenda de Automoveis  |\n---------------------------\n");
        printf("\n[1] CARRO\n[2] CLIENTE\n[3] VENDA\n[4] SAIR DO PROGRAMA\n");

        scanf("%d", &escolhaMenuMain);

        switch(escolhaMenuMain) {
            case 1:
                MenuCarro(carro);
                break;
            case 2:
                MenuCliente(cliente);
                break;
            case 3:
                MenuVenda(venda);
                break;
            case 4:
                printf("-> Programa encerrado com sucesso!\n");
                break;
            default:
                printf("-> Escolha uma opcao valida!\n");

                system("pause");
                break;
        }

    }while(escolhaMenuMain!=4);
}

int main() {
    MenuPrincipal();

    return 0;
}  
