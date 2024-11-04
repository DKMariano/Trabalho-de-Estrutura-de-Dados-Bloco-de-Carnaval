#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>


#define TAM_PLACA 50
#define TAM_TIPO 50
#define TAM_NOME 50
#define TAM_CPF 30


struct veiculos{
    char tipo[TAM_TIPO];
    char placa[TAM_PLACA];
    struct veiculos *proximoVeiculo;
    struct Pessoa *listaPessoa;
};

typedef struct Pessoa {
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    struct Pessoa *proximaPessoa;
} pessoa;

struct veiculos *primeiroVeiculo = NULL;

//FUN��ES MENU
void menuPrincipal();
void menuVeiculo();
void opcoesMenuVeiculo(int*opcaoVeiculo);
void menuPessoa();
void opcoesMenuPessoa(int *opcaoPessoa);

//FUN��ES ADD VE�CULOS
void adicionarVeiculoInicio();
void adicionarVeiculoMeio();
void adicionarVeiculoFim();

//FUN��ES VE�CULOS
void buscarVeiculo();
void editarVeiculos();
void excluirVeiculo();

//FUN��ES ADD PESSOAS
void adicionarPessoaInicio();
void adicionarPessoaMeio();
void adicionarPessoaFim();

//FUN��ES PESSOAS
void buscarPessoa();
void editarPessoa();
void excluirPessoa();
void trocarPessoa();


//OUTRAS FUN��ES
int contadorVeiculos();
int gerarTXT();
void imprimirLista();
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
            printf("\nA opcao digitada � invalida!");
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
                    imprimirLista(primeiroVeiculo);
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
    printf("\n7 - Exibir pessoas cadastradas");
    printf("\n8 - Mudar pessoa do ve�culo");
    printf("\n0 - Sair");
}

void opcoesMenuVeiculo(int *opcaoVeiculo){
    system("cls");
    menuVeiculo();

    printf("\nDigite a opcao desejada: ");
    scanf("%d", opcaoVeiculo);
    while (getchar() != '\n');

    if (*opcaoVeiculo < 0 || *opcaoVeiculo > 7) {
        printf("\nA opcao digitada � invalida!");
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
                printf("\n------------------------<<< Editar Informac�es do Veiculo Cadastrado >>>---------------------- \n");
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
                imprimirLista(primeiroVeiculo);
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
    while (getchar() != '\n');

    if (opcaoPessoa<0 || *opcaoPessoa > 8) {
        printf("\n Opcao invalida!");
        printf("\nTente novamente.");
        system("pause");
    }else{
        system("cls");
        switch (*opcaoPessoa) {
            case 1:
                printf("\n------------------------<<< Adicionar Pessoa no Inicio da Lista >>>---------------------- \n");
                adicionarPessoaInicio();
                system("pause");
                break;
            case 2:
                printf("\n------------------------<<< Adicionar Pessoa no Meio da Lista >>>---------------------- \n");
                adicionarPessoaMeio();
                system("pause");
                break;
            case 3:
                printf("\n------------------------<<< Adicionar Pessoa no Final da Lista >>>---------------------- \n");
                adicionarPessoaFim();
                system("pause");
                break;
            case 4:
                printf("\n------------------------<<< Buscar Pessoa Cadastrada >>>---------------------- \n");
                buscarPessoa();
                system("pause");
                break;
            case 5:
                printf("\n------------------------<<< Editar Informac�es da Pessoa Cadastrada >>>---------------------- \n");
                editarPessoa();
                system("pause");
                break;
            case 6:
                printf("\n------------------------<<< Excluir Pessoa Cadastrada >>>---------------------- \n");
                excluirPessoa();
                system("pause");
                break;
            case 7:
                printf("\n------------------------<<< Lista de Pessoas Cadastradas  >>>---------------------- \n");
                imprimirLista(primeiroVeiculo);
                system("pause");
                break;

            case 8:
                printf("\n------------------------<<< Mudar pessoa do ve�culo >>>---------------------- \n");
                trocarPessoa();
                system("pause");
                break;
           }

        }
}

void adicionarVeiculoInicio() {
    struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
    novoVeiculo->listaPessoa= NULL;

    printf("\nDigite o tipo de ve�culo (carro de apoio ou caminhao): ");
    fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
    novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
    printf("Digite a placa do ve�culo: ");
    fgets(novoVeiculo->placa, TAM_PLACA, stdin);
    novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

    novoVeiculo->proximoVeiculo = primeiroVeiculo;
    primeiroVeiculo = novoVeiculo;
    printf(" \nO veiculo foi inserido com sucesso. \n");
}

void adicionarVeiculoMeio(){
    if (primeiroVeiculo == NULL || primeiroVeiculo->proximoVeiculo == NULL ){
        printf("� necessario ter, pelo menos, dois ve�culos para inserir um veiculo no meio! \n");
    } else {
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));

        novoVeiculo->listaPessoa= NULL;

        printf("Digite o tipo de veiculo (carro de apoio ou caminhao): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do veiculo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        printf("\nVoce ja cadastrou os seguintes veiculos:\n");
        imprimirLista(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite o n�mero do ve�culo que voc� deseja inserir o ve�culo: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');

        if (posicaoVeiculo < 2 || posicaoVeiculo > totalVeiculos) {
            printf("N�o � possivel inserir o veiculo nessa posicao.\n");
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
            printf("O veiculo foi inserido com sucesso.\n\n");
        }
    }
}

void adicionarVeiculoFim(){
    if (primeiroVeiculo == NULL){
        printf("A lista de ve�culos est�  vazia! \nPor favor, insira um veiculo. \n");
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
        printf("A lista de veiculos est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
        return;
    }

    char placa_buscada[TAM_PLACA];
    printf("\nDigite a placa do veiculo que voc� deseja localizar: ");
    fgets(placa_buscada, TAM_PLACA, stdin);
    placa_buscada[strcspn(placa_buscada, "\n")] = '\0';


    letraMinuscula(placa_buscada);

    struct veiculos *atualVeiculo = primeiroVeiculo;
    int qtdVeiculo = 1;
    char placa_atual[TAM_PLACA];


    while (atualVeiculo != NULL) {
        strcpy(placa_atual, atualVeiculo->placa);
        letraMinuscula(placa_atual);


        if (strcmp(placa_atual, placa_buscada) == 0) {
            printf("O veiculo foi localizado: \n");
            printf("\nVeiculo %d \n", qtdVeiculo);
            printf("Tipo de Veiculo: %s\n", atualVeiculo->tipo);
            printf("Placa do Veiculo: %s\n", atualVeiculo->placa);
        }

        atualVeiculo = atualVeiculo->proximoVeiculo;
        qtdVeiculo++;
    }


    printf("O veiculo n�o existe! \n");
}

void editarVeiculos(){
    if (primeiroVeiculo == NULL){
        printf("A lista est� vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    } else {
        printf("\nVoc� ja cadastrou os seguintes veiculos: \n");
        imprimirLista(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posicao do veiculo que voc� deseja editar: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

         if (posicaoVeiculo <=0 || posicaoVeiculo > totalVeiculos) {
            printf("Posicao invalida! Por favor, insira uma posi��o valida.\n\n");
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
        printf("A lista est� vazia! \n");
        printf("Por favor, insira um veiculo. \n");
        return;
    } else {
        printf("\nVoc� ja cadastrou os seguintes veiculos: \n");

        imprimirLista(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;

        printf("\nDigite a posicao do veiculo que voce deseja excluir: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo <1 || posicaoVeiculo > totalVeiculos) {
            printf("Posi��o invalida! Por favor, insira uma posi��o valida.\n\n");
            return;
        }

        struct veiculos *atualVeiculo = primeiroVeiculo;
        struct veiculos *anteriorVeiculo = NULL;

        if (posicaoVeiculo==1) {
            primeiroVeiculo = atualVeiculo->proximoVeiculo;
            free(atualVeiculo);
            printf("\nVeiculo da posi��o %d foi excluido com sucesso.\n", posicaoVeiculo);
        } else {
            int contador = 0;
            for (contador = 1; contador < posicaoVeiculo; contador++) {
                anteriorVeiculo = atualVeiculo;
                atualVeiculo= atualVeiculo->proximoVeiculo;
        }
        anteriorVeiculo->proximoVeiculo = atualVeiculo->proximoVeiculo;

        free(atualVeiculo);

        printf("\nVeiculo da posi��o %d foi excluido com sucesso.\n", posicaoVeiculo);

        }
    }
}

void imprimirLista() {
    int qtdVeiculo = 0;

    if (primeiroVeiculo == NULL) {
        printf("A lista de ve�culos est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    } else {
        struct veiculos *atualVeiculo = primeiroVeiculo;

        while (atualVeiculo != NULL) {
            qtdVeiculo++;
            printf("\nVE�CULO #%d \n", qtdVeiculo);
            printf("Tipo de Ve�culo: %s\n", atualVeiculo->tipo);
            printf("Placa do Ve�culo: %s\n", atualVeiculo->placa);

            printf("Pessoas no ve�culo: ");
            if (atualVeiculo->listaPessoa == NULL) {
                printf("N�o h� pessoas associadas a esse ve�culo.");
                printf("\n------------\n");
            } else {
                pessoa *ponteiroPessoaTemp = atualVeiculo->listaPessoa;
                while (ponteiroPessoaTemp != NULL) {
                    printf("\n\t- %s, CPF n. %s.", ponteiroPessoaTemp->nome, ponteiroPessoaTemp->cpf);
                    ponteiroPessoaTemp = ponteiroPessoaTemp->proximaPessoa;
                }
                printf("\n------------\n");
            }

            atualVeiculo = atualVeiculo->proximoVeiculo;  // Avan�ando para o pr�ximo ve�culo na lista
        }

        printf("\nTotal de ve�culos registrados: %d\n\n", contadorVeiculos());  // Corre��o: chamar contadorVeiculos para exibir total correto
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

void adicionarPessoaInicio() {
    if (primeiroVeiculo == NULL){
        printf("A lista de ve�culos est�  vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    } else {
        pessoa *novaPessoa = malloc(sizeof(pessoa));
        novaPessoa->proximaPessoa = NULL;

        printf("\nDigite o nome da pessoa: ");
        fgets(novaPessoa->nome, TAM_NOME, stdin);
        novaPessoa->nome[strcspn(novaPessoa->nome, "\n")] = '\0';

        printf("Digite o CPF da pessoa (apenas n�meros): ");
        fgets(novaPessoa->cpf, sizeof(novaPessoa->cpf), stdin);
        novaPessoa->cpf[strcspn(novaPessoa->cpf, "\n")] = '\0';

        printf("\nVoc� j� cadastrou os seguintes ve�culos:\n");
        imprimirLista(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite o n�mero do ve�culo onde deseja inserir %s: ", novaPessoa->nome);
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');

        if (posicaoVeiculo < 1 || posicaoVeiculo > totalVeiculos) {
            printf("N�mero do ve�culo inv�lido.\n");
            return;
        }

        int qtdVeiculo = 1;
        struct veiculos *atualVeiculo = primeiroVeiculo;
        while (qtdVeiculo != posicaoVeiculo) {
            atualVeiculo = atualVeiculo->proximoVeiculo;
            qtdVeiculo++;
        }

        if (atualVeiculo->listaPessoa == NULL) {
            atualVeiculo->listaPessoa = novaPessoa;
            printf("\n%s foi inserido(a) no ve�culo %d. \n\n", novaPessoa->nome, posicaoVeiculo);
        } else {
            pessoa *ponteiroPessoaTemp = atualVeiculo->listaPessoa;
            atualVeiculo->listaPessoa = novaPessoa;
            novaPessoa->proximaPessoa = ponteiroPessoaTemp;
            printf("\n%s foi inserido(a) no ve�culo %d. \n\n", novaPessoa->nome, posicaoVeiculo);
        }
    }
}

void adicionarPessoaMeio() {
    if (primeiroVeiculo == NULL) {
        printf("A lista de ve�culos est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    } else {
        if (primeiroVeiculo->listaPessoa == NULL || primeiroVeiculo->listaPessoa->proximaPessoa == NULL) {
            printf("� necessario ter, pelo menos, duas pessoas para inserir outra pessoa no meio! \n");
        } else {
            pessoa *novaPessoa = malloc(sizeof(pessoa));
            novaPessoa->proximaPessoa = NULL;

            printf("\nDigite o nome da pessoa: ");
            fgets(novaPessoa->nome, TAM_NOME, stdin);
            novaPessoa->nome[strcspn(novaPessoa->nome, "\n")] = '\0';

            printf("Digite o CPF da pessoa (apenas n�meros): ");
            fgets(novaPessoa->cpf, sizeof(novaPessoa->cpf), stdin);
            novaPessoa->cpf[strcspn(novaPessoa->cpf, "\n")] = '\0';

            printf("\nVoc� j� cadastrou os seguintes ve�culos:\n");
            imprimirLista(primeiroVeiculo);

            int totalVeiculos = contadorVeiculos();
            int posicaoVeiculo = 0;
            printf("\nDigite o n�mero do ve�culo onde deseja inserir %s: ", novaPessoa->nome);
            scanf("%d", &posicaoVeiculo);
            while (getchar() != '\n');

            if (posicaoVeiculo < 1 || posicaoVeiculo > totalVeiculos) {
                printf("N�mero do ve�culo inv�lido.\n");
                return;
            }

            int qtdVeiculo = 1;
            struct veiculos *atualVeiculo = primeiroVeiculo;
            while (qtdVeiculo != posicaoVeiculo) {
                atualVeiculo = atualVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }

            char pessoa_buscada[TAM_NOME];
            printf("\nVoc� deseja inserir %s antes de qual pessoa? ", novaPessoa->nome);
            fgets(pessoa_buscada, sizeof(pessoa_buscada), stdin);
            pessoa_buscada[strcspn(pessoa_buscada, "\n")] = '\0';

            letraMinuscula(pessoa_buscada);

            pessoa *atualPessoa = atualVeiculo->listaPessoa;
            pessoa *anteriorPessoa = NULL;

            if (strcmp(pessoa_buscada, atualVeiculo->listaPessoa->nome) == 0) {
                printf("Erro: N�o � permitido inserir uma pessoa no in�cio da lista!\n");
                return;
            }

            pessoa *ultimaPessoa = atualVeiculo->listaPessoa;
            while (ultimaPessoa->proximaPessoa != NULL) {
                ultimaPessoa = ultimaPessoa->proximaPessoa;
            }

            if (strcmp(pessoa_buscada, ultimaPessoa->nome) == 0) {
                printf("Erro: N�o � permitido inserir uma pessoa no final da lista!\n");
                return;
            }

            while (atualPessoa != NULL) {
                char nomeAtual[TAM_NOME];
                strcpy(nomeAtual, atualPessoa->nome);
                letraMinuscula(nomeAtual);

                if (strcmp(nomeAtual, pessoa_buscada) == 0) {
                    if (anteriorPessoa == NULL) {
                        novaPessoa->proximaPessoa = atualVeiculo->listaPessoa;
                        atualVeiculo->listaPessoa = novaPessoa;
                    } else {
                        anteriorPessoa->proximaPessoa = novaPessoa;
                        novaPessoa->proximaPessoa = atualPessoa;
                    }
                    printf("\n%s foi inserido(a) no ve�culo %d.\n\n", novaPessoa->nome,  posicaoVeiculo);
                    return;
                }
                anteriorPessoa = atualPessoa;
                atualPessoa = atualPessoa->proximaPessoa;
            }

            printf("%s n�o encontrada na lista do ve�culo %d.\n", pessoa_buscada, posicaoVeiculo);
        }
    }
}

void adicionarPessoaFim() {
    if (primeiroVeiculo == NULL) {
        printf("A lista de ve�culos est�  vazia! \nPor favor, insira um veiculo. \n");
    } else {
        if (primeiroVeiculo->listaPessoa == NULL){
            printf("� necessario ter, pelo menos, uma pessoa para inserir uma pessoa no final! \n");
        } else {
            pessoa *novaPessoa = malloc(sizeof(pessoa));
            novaPessoa->proximaPessoa = NULL;

            printf("\nDigite o nome da pessoa: ");
            fgets(novaPessoa->nome, TAM_NOME, stdin);
            novaPessoa->nome[strcspn(novaPessoa->nome, "\n")] = '\0';

            printf("Digite o CPF da pessoa (apenas n�meros): ");
            fgets(novaPessoa->cpf, sizeof(novaPessoa->cpf), stdin);
            novaPessoa->cpf[strcspn(novaPessoa->cpf, "\n")] = '\0';

            printf("\nVoc� j� cadastrou os seguintes ve�culos:\n");
            imprimirLista(primeiroVeiculo);

            int totalVeiculos = contadorVeiculos();
            int posicaoVeiculo = 0;
            printf("\nDigite o n�mero do ve�culo onde deseja inserir %s: ", novaPessoa->nome);
            scanf("%d", &posicaoVeiculo);
            while (getchar() != '\n');

            if (posicaoVeiculo < 1 || posicaoVeiculo > totalVeiculos) {
                printf("N�mero do ve�culo inv�lido.\n");
            }

            int qtdVeiculo = 1;
            struct veiculos *atualVeiculo = primeiroVeiculo;
            while (qtdVeiculo != posicaoVeiculo) {
                atualVeiculo = atualVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }

            if (atualVeiculo->listaPessoa == NULL) {
                atualVeiculo->listaPessoa = novaPessoa;
                printf("\n%s adicionado com sucesso!\n", novaPessoa->nome);
            } else {
                pessoa *tempPessoa = atualVeiculo->listaPessoa;

                while (tempPessoa->proximaPessoa != NULL) {
                    tempPessoa = tempPessoa->proximaPessoa;
                }
                tempPessoa->proximaPessoa = novaPessoa;
                printf("\n%s adicionado com sucesso!\n", novaPessoa->nome);
            }
        }
    }
}

void buscarPessoa() {
    if (primeiroVeiculo == NULL) {
        printf("A lista de ve�culos est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    } else {
        if (primeiroVeiculo->listaPessoa == NULL) {
            printf("� necess�rio ter, pelo menos, uma pessoa para realizar a busca! \n");
        } else {
            int tipo_busca;
            printf("\nTipos de busca");
            printf("\n1 - Buscar pelo nome");
            printf("\n2 - Buscar pelo CPF");
            printf("\nDigite a opcao desejada: ");
            scanf("%d", &tipo_busca);
            while (getchar() != '\n'); // Limpar buffer

            // Valida��o da op��o de busca
            if (tipo_busca < 1 || tipo_busca > 2) {
                printf("\nA op��o digitada � inv�lida!");
                printf("\nTente novamente.\n");
            } else {
                char pessoa_buscada[TAM_NOME]; // Buffer para nome ou CPF

                // Buscar pelo nome
                if (tipo_busca == 1) {
                    printf("\nDigite o nome da pessoa que voc� deseja localizar: ");
                    fgets(pessoa_buscada, sizeof(pessoa_buscada), stdin);
                    pessoa_buscada[strcspn(pessoa_buscada, "\n")] = '\0'; // Remove newline
                    letraMinuscula(pessoa_buscada); // Fun��o para transformar em min�sculas
                }
                // Buscar pelo CPF
                else {
                    printf("\nDigite o CPF da pessoa que voc� deseja localizar: ");
                    fgets(pessoa_buscada, sizeof(pessoa_buscada), stdin);
                    pessoa_buscada[strcspn(pessoa_buscada, "\n")] = '\0'; // Remove newline
                }

                // In�cio da busca nos ve�culos e pessoas
                int qtdVeiculo = 1;
                struct veiculos *atualVeiculo = primeiroVeiculo;
                int pessoaEncontrada = 0; // Flag para indicar se a pessoa foi encontrada

                while (atualVeiculo != NULL) {
                    pessoa *atualPessoa = atualVeiculo->listaPessoa;

                    while (atualPessoa != NULL) {
                        char nomeAtual[TAM_NOME];

                        if (tipo_busca == 1) {
                            // Comparar nomes em min�sculas
                            strcpy(nomeAtual, atualPessoa->nome);
                            letraMinuscula(nomeAtual);
                            if (strcmp(nomeAtual, pessoa_buscada) == 0) {
                                pessoaEncontrada = 1;
                                printf("\n%s est� localizado no seguinte ve�culo:\n", atualPessoa->nome);
                                printf("\nVE�CULO #%d \n", qtdVeiculo);
                                printf("Tipo de Ve�culo: %s\n", atualVeiculo->tipo);
                                printf("Placa do Ve�culo: %s\n", atualVeiculo->placa);
                            }
                        } else {
                            // Comparar CPFs
                            if (strcmp(atualPessoa->cpf, pessoa_buscada) == 0) {
                                pessoaEncontrada = 1;
                                printf("\nPessoa com CPF de n�mero %s est� localizada no seguinte ve�culo:", atualPessoa->cpf);
                                printf("\nVE�CULO #%d \n", qtdVeiculo);
                                printf("Tipo de Ve�culo: %s\n", atualVeiculo->tipo);
                                printf("Placa do Ve�culo: %s\n", atualVeiculo->placa);
                            }
                        }
                        atualPessoa = atualPessoa->proximaPessoa;
                    }

                    atualVeiculo = atualVeiculo->proximoVeiculo;
                    qtdVeiculo++;
                }
v
                if (!pessoaEncontrada) {
                    if (tipo_busca == 1) {
                        printf("\nPessoa de nome %s n�o est� em nenhum ve�culo.\n", pessoa_buscada);
                    } else {
                        printf("\nPessoa de CPF n. %s n�o est� em nenhum ve�culo.\n", pessoa_buscada);
                    }
                }
            }
        }
    }
}

void editarPessoa(){
    if (primeiroVeiculo == NULL) {
        printf("A lista de ve�culos est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    } else {
        if (primeiroVeiculo->listaPessoa == NULL) {
            printf("� necess�rio ter, pelo menos, uma pessoa para realizar a busca! \n");
        } else {
            printf("\nVoc� j� cadastrou os seguintes ve�culos:\n");
            imprimirLista(primeiroVeiculo);

            int totalVeiculos = contadorVeiculos();
            int posicaoVeiculo = 0;
            printf("\nDigite o n�mero do ve�culo onde deseja alterar os dados de uma pessoa: ");
            scanf("%d", &posicaoVeiculo);
            while (getchar() != '\n'); // Limpa o buffer

            if (posicaoVeiculo < 1 || posicaoVeiculo > totalVeiculos) {
                printf("N�mero do ve�culo inv�lido.\n");
                return;
            }

            int qtdVeiculo = 1;
            struct veiculos *atualVeiculo = primeiroVeiculo;
            while (qtdVeiculo != posicaoVeiculo) {
                atualVeiculo = atualVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }

            struct Pessoa *atualPessoa = atualVeiculo->listaPessoa;

            char pessoa_buscada[TAM_NOME];
            printf("\nVoc� deseja alterar os dados de qual pessoa? ");
            fgets(pessoa_buscada, sizeof(pessoa_buscada), stdin);
            pessoa_buscada[strcspn(pessoa_buscada, "\n")] = '\0';

            letraMinuscula(pessoa_buscada);

            while (atualPessoa != NULL) {
                char nomeAtual[TAM_NOME];
                strcpy(nomeAtual, atualPessoa->nome);
                letraMinuscula(nomeAtual);

                if (strcmp(nomeAtual, pessoa_buscada) == 0) {
                    printf("\nDigite o novo nome da pessoa: ");
                    fgets(atualPessoa->nome, TAM_NOME, stdin);
                    atualPessoa->nome[strcspn(atualPessoa->nome, "\n")] = '\0';

                    printf("Digite o CPF da pessoa (apenas n�meros): ");
                    fgets(atualPessoa->cpf, sizeof(atualPessoa->cpf), stdin);
                    atualPessoa->cpf[strcspn(atualPessoa->cpf, "\n")] = '\0';

                    printf("\nOs dados de %s foram alterados com sucesso.\n\n", atualPessoa->nome);
                    return;
                }

                atualPessoa = atualPessoa->proximaPessoa;
            }

            printf("%s n�o foi encontrada.\n", pessoa_buscada);
        }
    }
}

void excluirPessoa(){
    if (primeiroVeiculo == NULL) {
        printf("A lista de ve�culos est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    } else {
        if (primeiroVeiculo->listaPessoa == NULL) {
            printf("� necess�rio ter, pelo menos, uma pessoa para realizar a busca! \n");
        } else {
            printf("\nVoc� j� cadastrou os seguintes ve�culos:\n");
            imprimirLista(primeiroVeiculo);

            int totalVeiculos = contadorVeiculos();
            int posicaoVeiculo = 0;
            printf("\nDigite o n�mero do ve�culo onde est� localizada a pessoa que voc� deseja excluir: ");
            scanf("%d", &posicaoVeiculo);
            while (getchar() != '\n'); // Limpa o buffer do teclado

            if (posicaoVeiculo < 1 || posicaoVeiculo > totalVeiculos) {
                printf("N�mero do ve�culo inv�lido.\n");
                return;
            }

            int qtdVeiculo = 1;
            struct veiculos *atualVeiculo = primeiroVeiculo;
            while (qtdVeiculo != posicaoVeiculo) {
                atualVeiculo = atualVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }

            struct Pessoa *atualPessoa = atualVeiculo->listaPessoa;
            struct Pessoa *anteriorPessoa = NULL;

            char pessoa_buscada[TAM_NOME];
            printf("\nDigite o nome da pessoa que voc� deseja excluir: ");
            fgets(pessoa_buscada, sizeof(pessoa_buscada), stdin);
            pessoa_buscada[strcspn(pessoa_buscada, "\n")] = '\0';

            letraMinuscula(pessoa_buscada);

            while (atualPessoa != NULL) {
                char nomeAtual[TAM_NOME];
                strcpy(nomeAtual, atualPessoa->nome);
                letraMinuscula(nomeAtual);

                if (strcmp(nomeAtual, pessoa_buscada) == 0) {
                    if (anteriorPessoa == NULL) {
                        atualVeiculo->listaPessoa = atualPessoa->proximaPessoa;
                    } else {
                        anteriorPessoa->proximaPessoa = atualPessoa->proximaPessoa;
                    }

                    free(atualPessoa);

                    printf("\nA pessoa '%s' foi exclu�da com sucesso.\n", pessoa_buscada);
                    return;
                }

                anteriorPessoa = atualPessoa;
                atualPessoa = atualPessoa->proximaPessoa;
            }

            printf("Pessoa '%s' n�o foi encontrada.\n", pessoa_buscada);
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
                    ponteiroPessoaTemp = ponteiroPessoaTemp->proximaPessoa;
                }

                //hora de escolher a pessoa que vai ser trocada de ve�culo
                char pessoaBuscada[TAM_NOME];
                printf("\nDigite o nome da pessoa que voce quer retirar: ");
                fgets(pessoaBuscada, TAM_NOME, stdin);

                pessoa *ponteiroTempAntecessor = atualVeiculoTemp->listaPessoa;
                pessoa *ponteiroTempSucessor = ponteiroTempAntecessor->proximaPessoa;
                pessoa *ponteiroSalvarPessoa = NULL;
                //buscando a pessoa
                if (strcmp(ponteiroTempAntecessor->nome, pessoaBuscada)==0) {
                    ponteiroSalvarPessoa= ponteiroTempAntecessor;
                    atualVeiculoTemp->listaPessoa=ponteiroTempSucessor;
                    ponteiroSalvarPessoa->proximaPessoa=NULL;

                    qtdVeiculo = 1;
                    printf("\nDigite a placa do veiculo onde a pessoa vai ficar: ");
                    fgets(placa_buscada, TAM_PLACA, stdin);
                    placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
                    //procurando o ve�culo
                    atualVeiculoTemp = primeiroVeiculo;
                    while(strcmp(atualVeiculoTemp->placa, placa_buscada) != 0 && atualVeiculoTemp->proximoVeiculo !=NULL) {
                        atualVeiculoTemp = atualVeiculoTemp->proximoVeiculo;
                        qtdVeiculo++;
                    }
                    if(strcmp(atualVeiculoTemp->placa, placa_buscada) == 0) {
                        if(atualVeiculoTemp->listaPessoa == NULL) {
                            atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                            ponteiroSalvarPessoa->proximaPessoa = NULL;
                        }else {
                            ponteiroSalvarPessoa->proximaPessoa = atualVeiculoTemp->listaPessoa;
                            atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                        }
                    }else {
                        printf("\nO veiculo nao existe!");
                    }
                }else if(strcmp(ponteiroTempSucessor->nome,pessoaBuscada)==0) {
                    while (strcmp(ponteiroTempSucessor->nome,pessoaBuscada)!=0 && ponteiroTempSucessor->proximaPessoa!= NULL) {
                        ponteiroTempAntecessor = ponteiroTempSucessor;
                        ponteiroTempSucessor = ponteiroTempSucessor->proximaPessoa;
                    }

                    ponteiroTempAntecessor->proximaPessoa = ponteiroTempSucessor->proximaPessoa;
                    ponteiroTempSucessor->proximaPessoa = NULL;
                    ponteiroSalvarPessoa = ponteiroTempSucessor;
                    //o n� foi salvo e a lista foi reconfigurada

                qtdVeiculo = 1;
                printf("\nDigite a placa do veiculo onde a pessoa vai ficar: ");
                fgets(placa_buscada, TAM_PLACA, stdin);
                placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
                //procurando o ve�culo
                atualVeiculoTemp = primeiroVeiculo;
                while(strcmp(atualVeiculoTemp->placa, placa_buscada) != 0 && atualVeiculoTemp->proximoVeiculo !=NULL) {
                    atualVeiculoTemp = atualVeiculoTemp->proximoVeiculo;
                    qtdVeiculo++;
                }
                if(strcmp(atualVeiculoTemp->placa, placa_buscada) == 0) {
                    if(atualVeiculoTemp->listaPessoa == NULL) {
                        atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                        ponteiroSalvarPessoa->proximaPessoa = NULL;
                    }else {
                        ponteiroSalvarPessoa->proximaPessoa = atualVeiculoTemp->listaPessoa;
                        atualVeiculoTemp->listaPessoa = ponteiroSalvarPessoa;
                    }
                }else {
                    printf("\nO veiculo nao existe!");
                }
            }else {
                    printf("\n A pessoa n�o existe");
                }
            }
        }else{
            printf("O veiculo n�o existe! \n");
        }
    }
}

void letraMinuscula(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


