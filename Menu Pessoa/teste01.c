
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>


#define TAM_PLACA 50  // Tamanho máximo da placa
#define TAM_TIPO 50   // Tamanho máximo do tipo de veículo
#define TAM_NOME 50   // Tamanho máximo do nome da pessoa

// Estrutura para armazenar os veículos
struct veiculos{
    char tipo[TAM_TIPO];
    char placa[TAM_PLACA];
    struct veiculos *proximoVeiculo;
    struct Pessoa *listaPessoa;
};

struct Pessoa {
    char nome[TAM_NOME];
    int cpf;
    struct Pessoa *proximo;
};

typedef struct Pessoa pessoa;

struct veiculos *primeiroVeiculo = NULL;

//FUNÇÕES MENU
void menuPrincipal();
void menuVeiculo();
void opcoesMenuVeiculo(int*opcaoVeiculo);
void menuPessoa();
void opcoesMenuPessoa(int *opcaoPessoa);
//FUNÇÕES ADD VEÍCULOS
void adicionarVeiculoInicio();
void adicionarVeiculoMeio();
void adicionarVeiculoFim();

//FUNÇÕES VEÍCULOS
void buscarVeiculo();
int contadorVeiculos();
void editarVeiculos();
void excluirVeiculo();
void imprimirVeiculo();

//FUNÇÕES ADD PESSOAS
void adicionarPessoaInicio();
void adicionarPessoaFim();
void trocarPessoa();


//OUTRAS FUNÇÕES
void letraMinuscula(char *str);


int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls");
        menuPrincipal();

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // limpar o buffer de entrada.

        if (opcao < 0 || opcao > 3) {
            printf("\nA opcao digitada é invalida!");
            printf("\nTente novamente.");
            system("pause");
        } else {
            system("cls");
            switch (opcao) {
                case 1: {
                    int opcaoVeiculo;
                    do {
                        opcoesMenuVeiculo(&opcaoVeiculo);
                    } while (opcaoVeiculo != 0);
                    break;
                }
                case 2:{
                    int opcaoPessoa;
                    do {
                        opcoesMenuPessoa(&opcaoPessoa);
                    }while (opcaoPessoa != 0);
                    break;
                }
                case 3:
                    imprimirVeiculo(primeiroVeiculo);
                    system("pause");
                    break;
            }
        }
    } while (opcao != 0);

    return 0;
}

void menuPrincipal() {
    printf("\n************************************************************************\n");
    printf("\n************************* BLOCO DO EU SOZINHO **************************\n");
    printf("\n************************************************************************\n");
    printf("\n1 - Veiculos \n");
    printf("2 - Pessoas \n");
    printf("3 - Imprimir \n");
    printf("0 - Sair\n");
}

void menuVeiculo() {
	printf("\n-----------<<< Gerenciamento de Veiculos >>>----------- \n");
    printf("\n1 - Adicionar veiculo no inicio da lista");
    printf("\n2 - Adicionar veiculo no meio da lista");
    printf("\n3 - Adicionar veiculo no final da lista");
    printf("\n4 - Buscar de veiculo cadastrados");
    printf("\n5 - Editar informacoes de um veiculo");
    printf("\n6 - Excluir veiculo cadastrados");
    printf("\n7 - Exibir veiculos cadastrados");
    printf("\n0 - Sair");
}

void menuPessoa() {
    printf("\n-----------<<< Gerenciamento de Pessoas>>>----------- \n");
    printf("\n1 - Adicionar pessoa no inicio da lista");
    printf("\n2 - Adicionar pessoa no meio  da lista");
    printf("\n3 - Adicionar pessoa no final  da lista");
    printf("\n4 - Buscar pessoa cadastrada");
    printf("\n5 - Editar informacoes de uma pessoa");
    printf("\n6 - Excluir pessoa cadastrada");
    printf("\n7 - Exibir pessoa cadastrada");
    printf("\n8 - Mudar pessoa do veículo");
    printf("\n0 - Sair");
}

void opcoesMenuVeiculo(int *opcaoVeiculo){
    system("cls");
    menuVeiculo();

    printf("\nDigite a opcao desejada: ");
    scanf("%d", opcaoVeiculo);
    while (getchar() != '\n');  // limpar o buffer de entrada.

    if (*opcaoVeiculo < 0 || *opcaoVeiculo > 7) {
        printf("\nA opcao digitada é invalida!");
        printf("\nTente novamente.");
        system("pause");
    } else {
        system("cls");
        switch (*opcaoVeiculo) {
            case 1:
                printf("\n------------------------<<< Adicionar Veiculo no Inicio da Lista >>>---------------------- \n");
                adicionarVeiculoInicio();
                system("pause");
                break;
            case 2:
                printf("\n------------------------<<< Adicionar Veiculo no Meio da Lista >>>---------------------- \n");
                adicionarVeiculoMeio();
                system("pause");
                break;
            case 3:
                printf("\n------------------------<<< Adicionar Veiculo no Final da Lista >>>---------------------- \n");
                adicionarVeiculoFim();
                system("pause");
                break;
            case 4:
                printf("\n------------------------<<< Buscar Veiculo Cadastrado >>>---------------------- \n");
                buscarVeiculo();
                system("pause");
                break;
            case 5:
                printf("\n------------------------<<< Editar Informacões do Veiculo Cadastrado >>>---------------------- \n");
                editarVeiculos();
                system("pause");
                break;
            case 6:
                printf("\n------------------------<<< Excluir Veiculo Cadastrado >>>---------------------- \n");
                excluirVeiculo();
                system("pause");
                break;
            case 7:
                printf("\n------------------------<<< Lista de Veiculos Cadastrados >>>---------------------- \n");
                imprimirVeiculo(primeiroVeiculo);
                system("pause");
                break;
            }
        }
}

void opcoesMenuPessoa(int *opcaoPessoa) {
    system("cls");
    menuPessoa();

    printf("\nDigite a opcao desejada: ");
    scanf("%d", opcaoPessoa);
    while (getchar() != '\n');  // limpeza de buffer

    if (opcaoPessoa<0 || *opcaoPessoa > 8) {
        printf("\n Opcao invalida!");
        printf("\nTente novamente.");
        system("pause");
    }else{
        system("cls");
        switch (*opcaoPessoa) {
            case 1:
                printf("\n------------------------<<< Adicionar Pessoa no Inicio da Lista >>>---------------------- \n");

                system("pause");
                break;
            case 2:
                printf("\n------------------------<<< Adicionar Pessoa no Meio da Lista >>>---------------------- \n");

                system("pause");
                break;
            case 3:
                printf("\n------------------------<<< Adicionar Pessoa no Final da Lista >>>---------------------- \n");
                adicionarPessoaFim();
                system("pause");
                break;
            case 4:
                printf("\n------------------------<<< Buscar Pessoa Cadastrada >>>---------------------- \n");

                system("pause");
                break;
            case 5:
                printf("\n------------------------<<< Editar Informacões da Pessoa Cadastrada >>>---------------------- \n");

                system("pause");
                break;
            case 6:
                printf("\n------------------------<<< Excluir Pessoa Cadastrada >>>---------------------- \n");

                system("pause");
                break;
            case 7:
                printf("\n------------------------<<< Lista de Pessoas Cadastradas  >>>---------------------- \n");
                imprimirVeiculo(primeiroVeiculo);
                system("pause");
                break;

            case 8:
                printf("\n------------------------<<< Mudar pessoa do veículo >>>---------------------- \n");
                trocarPessoa();
                system("pause");
                break;
           }

        }
}

void adicionarVeiculoInicio() {
    // ponteiro para armazenar as novas informações do veículo
    struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
    //pessoa *primeiraPessoa = NULL;
    novoVeiculo->listaPessoa= NULL;

    printf("\nDigite o tipo de veiculo (carro de apoio ou caminhao): ");
    fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
    novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
    printf("Digite a placa do veiculo: ");
    fgets(novoVeiculo->placa, TAM_PLACA, stdin);
    novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

    novoVeiculo->proximoVeiculo = primeiroVeiculo;
    primeiroVeiculo = novoVeiculo;
    printf(" \nO veiculo foi inserido com sucesso. \n");
}

void adicionarVeiculoMeio(){
    if (primeiroVeiculo == NULL || primeiroVeiculo->proximoVeiculo == NULL ){
        printf("É necessario ter, pelo menos, dois veículos para inserir um veiculo no meio! \n");
    } else {
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        //pessoa *primeiraPessoa = NULL;
        novoVeiculo->listaPessoa= NULL;

        printf("Digite o tipo de veiculo (carro de apoio ou caminhao): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do veiculo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        printf("\nVoce ja cadastrou os seguintes veiculos:");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posicao que voce deseja inserir o veiculo: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo < 2 || posicaoVeiculo > totalVeiculos) {
            printf("Nao e possivel inserir o veiculo nessa posicao.\n");
        } else {
            int qtdVeiculo = 1;
            struct veiculos *atualVeiculo = primeiroVeiculo;

            while(qtdVeiculo != posicaoVeiculo - 1 && atualVeiculo->proximoVeiculo != NULL) {
                atualVeiculo = atualVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }

            struct veiculos *temporario = atualVeiculo->proximoVeiculo;
            atualVeiculo->proximoVeiculo = novoVeiculo;
            novoVeiculo->proximoVeiculo = temporario;
            printf("O veiculo foi inserido com sucesso.\n");
        }
    }
}

void adicionarVeiculoFim(){
    if (primeiroVeiculo == NULL){
        printf("A lista de veículos está  vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    }else{
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        //pessoa *primeiraPessoa = NULL;
        novoVeiculo->listaPessoa= NULL;
        printf("\nDigite o tipo de veiculo (carro de apoio ou caminhao): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do veiculo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        novoVeiculo->proximoVeiculo = NULL;

        struct veiculos *atualVeiculo = primeiroVeiculo;
        while(atualVeiculo->proximoVeiculo != NULL){
            atualVeiculo = atualVeiculo->proximoVeiculo;
        };
        atualVeiculo->proximoVeiculo = novoVeiculo;

		printf("\nO veeculo foi inserido com sucesso. \n");
    }
}

void buscarVeiculo() {
    if (primeiroVeiculo == NULL) {
        printf("A lista de veiculos está vazia! \n");
        printf("Por favor, insira um veículo. \n");
        return;
    }

    char placa_buscada[TAM_PLACA];
    printf("\nDigite a placa do veiculo que você deseja localizar: ");
    fgets(placa_buscada, TAM_PLACA, stdin);
    placa_buscada[strcspn(placa_buscada, "\n")] = '\0';

    // Converter a placa buscada para minúsculas
    letraMinuscula(placa_buscada);

    struct veiculos *atualVeiculo = primeiroVeiculo;
    int qtdVeiculo = 1;
    char placa_atual[TAM_PLACA];

    // Percorrer toda a lista para encontrar o veículo
    while (atualVeiculo != NULL) {
        // Copiar a placa atual para uma variável temporária e convertê-la para minúsculas
        strcpy(placa_atual, atualVeiculo->placa);
        letraMinuscula(placa_atual);

        // Comparar as placas em minúsculas
        if (strcmp(placa_atual, placa_buscada) == 0) {
            printf("O veiculo foi localizado: \n");
            printf("\nVeiculo %d \n", qtdVeiculo);
            printf("Tipo de Veiculo: %s\n", atualVeiculo->tipo);
            printf("Placa do Veiculo: %s\n", atualVeiculo->placa);
            return;
        }

        atualVeiculo = atualVeiculo->proximoVeiculo;
        qtdVeiculo++;
    }

    // Se o loop terminar sem encontrar a placa, informar que o veículo não existe
    printf("O veiculo não existe! \n");
}


void editarVeiculos(){
    if (primeiroVeiculo == NULL){
        printf("A lista está vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    } else {
        printf("\nVocê ja cadastrou os seguintes veiculos: ");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posicao do veiculo que você deseja editar: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

         if (posicaoVeiculo <=0 || posicaoVeiculo > totalVeiculos) {
            printf("Posicao invalida! Por favor, insira uma posição valida.\n\n");
        } else {
            int qtdVeiculo = 1;
            struct veiculos *atualVeiculo = primeiroVeiculo;

            while(qtdVeiculo!= posicaoVeiculo && atualVeiculo->proximoVeiculo !=NULL) {
                atualVeiculo = atualVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }
            printf("Digite o tipo de veiculo (carro de apoio ou caminhao): ");
            fgets(atualVeiculo->tipo, TAM_TIPO, stdin);
            atualVeiculo->tipo[strcspn(atualVeiculo->tipo, "\n")] = '\0';
            printf("Digite a placa do veiculo: ");
            fgets(atualVeiculo->placa, TAM_TIPO, stdin);
            atualVeiculo->placa[strcspn(atualVeiculo->placa, "\n")] = '\0';

            printf("O veiculo foi editado com sucesso.\n");
        }
    }
}

void excluirVeiculo(){

    if (primeiroVeiculo == NULL){
        printf("A lista está vazia! \n");
        printf("Por favor, insira um veiculo. \n");
        return;
    } else {
        printf("\nVocê ja cadastrou os seguintes veiculos: ");

        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;

        printf("\nDigite a posicao do veiculo que voce deseja excluir: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo <1 || posicaoVeiculo > totalVeiculos) {
            printf("Posição invalida! Por favor, insira uma posição valida.\n\n");
            return;
        }

        struct veiculos *atualVeiculo = primeiroVeiculo;
        struct veiculos *anteriorVeiculo = NULL;

        if (posicaoVeiculo==1) {
            primeiroVeiculo = atualVeiculo->proximoVeiculo;
            free(atualVeiculo);
            printf("\nVeiculo da posição %d foi excluido com sucesso.\n", posicaoVeiculo);
        } else {
            int contador = 0;
            for (contador = 1; contador < posicaoVeiculo; contador++) {
                anteriorVeiculo = atualVeiculo;
                atualVeiculo= atualVeiculo->proximoVeiculo;
        }
        anteriorVeiculo->proximoVeiculo = atualVeiculo->proximoVeiculo;

        free(atualVeiculo);

        printf("\nVeiculo da posição %d foi excluido com sucesso.\n", posicaoVeiculo);

        }
    }
}

void imprimirVeiculo() {

    int qtdVeiculo = 0;
    if (primeiroVeiculo == NULL){
        printf("A lista de veiculos esta  vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    }else{
        struct veiculos *atualVeiculo = primeiroVeiculo;
        while(atualVeiculo != NULL){

            qtdVeiculo++;
            printf("\nVeiculo %d \n", qtdVeiculo);
            printf("Tipo de Veiculo: %s\n", atualVeiculo->tipo);
            printf("Placa do Veiculo: %s\n", atualVeiculo->placa);
            printf("Pessoas no veículo:\n");
            if(atualVeiculo->listaPessoa == NULL) {
                printf("Não há pessoas associadas a esse veículo.\n");
            }else {
                pessoa *ponteiroPessoaTemp = atualVeiculo->listaPessoa;
                while (ponteiroPessoaTemp!= NULL) {
                    printf("Nome: %s\n",ponteiroPessoaTemp->nome);
                    printf("CPF: %d\n\n",ponteiroPessoaTemp->cpf);
                    ponteiroPessoaTemp = ponteiroPessoaTemp->proximo;
                }
            }
            atualVeiculo= atualVeiculo->proximoVeiculo;
            //ponteiroPessoaTemp = atualVeiculo->listaPessoa;
        }
        printf("\nTotal de veiculos registrados: %d\n\n", contadorVeiculos());
    }
}

int contadorVeiculos(){
    int cont = 0;
    struct veiculos *atualVeiculo = primeiroVeiculo;
    while(atualVeiculo != NULL){
        cont++;
        atualVeiculo= atualVeiculo->proximoVeiculo;
    }
    return cont;
}

void adicionarPessoaInicio(){
}

void adicionarPessoaFim() {
    if (primeiroVeiculo == NULL){
        printf("A lista de veiculos esta  vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    }else {
        char placa_buscada[TAM_PLACA];
        printf("\nDigite a placa do veiculo onde voce deseja adicionar: ");
        fgets(placa_buscada, TAM_PLACA, stdin);
        placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
        struct veiculos *atualVeiculo = primeiroVeiculo;
        while(strcmp(atualVeiculo->placa, placa_buscada) != 0 && atualVeiculo->proximoVeiculo !=NULL) {
            atualVeiculo = atualVeiculo->proximoVeiculo;
        }
        if(strcmp(atualVeiculo->placa, placa_buscada) == 0) {
            pessoa *novaPessoa = malloc(sizeof(pessoa));
            novaPessoa->proximo = NULL;
            printf("\nDigite o nome da pessoa: ");
            fgets(novaPessoa->nome, TAM_NOME, stdin);
            printf("\nDigite o CPF da pessoa: ");
            scanf("%d", &novaPessoa->cpf);

            if (atualVeiculo->listaPessoa == NULL){
                atualVeiculo->listaPessoa = novaPessoa;
                printf("\n %s adicionado com sucesso!",novaPessoa->nome);
            }else {
                pessoa *tempPessoa = atualVeiculo->listaPessoa;
                while (tempPessoa->proximo!= NULL){
                    tempPessoa = tempPessoa->proximo;
                }
                tempPessoa->proximo = novaPessoa;
                printf("\n %s adicionado com sucesso!",novaPessoa->nome);
            }
        }else{
            printf("O veiculo não existe! \n");
        }
    }
}

void trocarPessoa() {
    if (primeiroVeiculo == NULL){
        printf("A lista de veiculos esta  vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    }else {
        int qtdVeiculo = 1;
        char placa_buscada[TAM_PLACA];

        printf("\nDigite a placa do veiculo onde a pessoa esta: ");
        fgets(placa_buscada, TAM_PLACA, stdin);
        placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
        struct veiculos *atualVeiculoTemp = primeiroVeiculo;

        while(strcmp(atualVeiculoTemp->placa, placa_buscada) != 0 && atualVeiculoTemp->proximoVeiculo !=NULL) {
            atualVeiculoTemp = atualVeiculoTemp->proximoVeiculo;
            qtdVeiculo++;
        }

        if(strcmp(atualVeiculoTemp->placa, placa_buscada) == 0){
            printf("O veiculo foi localizado: \n");
            printf("\nVeiculo %d \n", qtdVeiculo);
            printf("Tipo de Veiculo: %s\n", atualVeiculoTemp->tipo);
            printf("Placa do Veiculo: %s\n", atualVeiculoTemp->placa);

            //Encontramos o veiculo!

            if(atualVeiculoTemp->listaPessoa == NULL) {
                printf("Sem pessoas\n");
            }else {
                //mostrando as pessoas na tela
                pessoa *ponteiroPessoaTemp = atualVeiculoTemp->listaPessoa;
                while (ponteiroPessoaTemp!= NULL) {
                    printf("Nome: %s\n",ponteiroPessoaTemp->nome);
                    printf("CPF: %d\n\n",ponteiroPessoaTemp->cpf);
                    ponteiroPessoaTemp = ponteiroPessoaTemp->proximo;
                }

                //hora de escolher a pessoa que vai ser trocada de veículo
                char pessoaBuscada[TAM_NOME];
                printf("\nDigite o nome da pessoa que voce quer retirar: ");
                fgets(pessoaBuscada, TAM_NOME, stdin);

                pessoa *ponteiroTempAntecessor = atualVeiculoTemp->listaPessoa;
                pessoa *ponteiroTempSucessor = ponteiroTempAntecessor->proximo;
                pessoa *ponteiroSalvarPessoa = NULL;
                //buscando a pessoa
                if (strcmp(ponteiroTempAntecessor->nome, pessoaBuscada)==0) {
                    ponteiroSalvarPessoa= ponteiroTempAntecessor;
                    atualVeiculoTemp->listaPessoa=ponteiroTempSucessor;
                    ponteiroSalvarPessoa->proximo=NULL;

                    qtdVeiculo = 1;
                    printf("\nDigite a placa do veiculo onde a pessoa vai ficar: ");
                    fgets(placa_buscada, TAM_PLACA, stdin);
                    placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
                    //procurando o veículo
                    atualVeiculoTemp = primeiroVeiculo;
                    while(strcmp(atualVeiculoTemp->placa, placa_buscada) != 0 && atualVeiculoTemp->proximoVeiculo !=NULL) {
                        atualVeiculoTemp = atualVeiculoTemp->proximoVeiculo;
                        qtdVeiculo++;
                    }
                    if(strcmp(atualVeiculoTemp->placa, placa_buscada) == 0) {
                        if(atualVeiculoTemp->listaPessoa == NULL) {
                            atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                            ponteiroSalvarPessoa->proximo = NULL;
                        }else {
                            ponteiroSalvarPessoa->proximo = atualVeiculoTemp->listaPessoa;
                            atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                        }
                    }else {
                        printf("\nO veiculo nao existe!");
                    }
                }else if(strcmp(ponteiroTempSucessor->nome,pessoaBuscada)==0) {
                    while (strcmp(ponteiroTempSucessor->nome,pessoaBuscada)!=0 && ponteiroTempSucessor->proximo!= NULL) {
                        ponteiroTempAntecessor = ponteiroTempSucessor;
                        ponteiroTempSucessor = ponteiroTempSucessor->proximo;
                    }

                    ponteiroTempAntecessor->proximo = ponteiroTempSucessor->proximo;
                    ponteiroTempSucessor->proximo = NULL;
                    ponteiroSalvarPessoa = ponteiroTempSucessor;
                    //o nó foi salvo e a lista foi reconfigurada

                qtdVeiculo = 1;
                printf("\nDigite a placa do veiculo onde a pessoa vai ficar: ");
                fgets(placa_buscada, TAM_PLACA, stdin);
                placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
                //procurando o veículo
                atualVeiculoTemp = primeiroVeiculo;
                while(strcmp(atualVeiculoTemp->placa, placa_buscada) != 0 && atualVeiculoTemp->proximoVeiculo !=NULL) {
                    atualVeiculoTemp = atualVeiculoTemp->proximoVeiculo;
                    qtdVeiculo++;
                }
                if(strcmp(atualVeiculoTemp->placa, placa_buscada) == 0) {
                    if(atualVeiculoTemp->listaPessoa == NULL) {
                        atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                        ponteiroSalvarPessoa->proximo = NULL;
                    }else {
                        ponteiroSalvarPessoa->proximo = atualVeiculoTemp->listaPessoa;
                        atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                    }
                }else {
                    printf("\nO veiculo nao existe!");
                }
            }else {
                    printf("\n A pessoa não existe");
                }
            }
        }else{
            printf("O veiculo não existe! \n");
        }
    }
}

void letraMinuscula(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]); // Removido o (unsigned char)
    }
}

