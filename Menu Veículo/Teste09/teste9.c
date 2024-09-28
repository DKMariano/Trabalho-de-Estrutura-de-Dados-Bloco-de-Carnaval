/*
Fun��o Inserir no in�cio, inserior no final e inserir no meio validadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_PLACA 50  // Tamanho m�ximo da placa
#define TAM_TIPO 50   // Tamanho m�ximo do tipo de ve�culo

// Estrutura para armazenar os ve�culos
struct veiculos{
    char tipo[TAM_TIPO];
    char placa[TAM_PLACA];
    struct veiculos *proximoVeiculo;
};

struct veiculos *primeiroVeiculo = NULL;
void verificarListaVazia();
void menuPrimario();
void menuVeiculo();
void excluirVeiculo();
void editarVeiculos();
void adicionarVeiculoInicio();
void adicionarVeiculoMeio();
void adicionarVeiculoFim();
int contadorVeiculos();
void imprimirVeiculo(struct veiculos *primeiroVeiculo);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls");
        menuPrimario();

        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // limpar o buffer de entrada.

        if (opcao < 0 || opcao > 3) {
            printf("\nA op��o digitada � inv�lida!");
            printf("\nTente novamente.");
            system("pause");
        } else {
            system("cls");
            switch (opcao) {
                case 1: {
                    int opcaoVeiculo;
                    do {
                        system("cls");
                        menuVeiculo();
                        printf("\nDigite a op��o desejada: ");
                        scanf("%d", &opcaoVeiculo);
                        while (getchar() != '\n');  // limpar o buffer de entrada.

                        if (opcaoVeiculo < 0 || opcaoVeiculo > 6) {
                            printf("\nA op��o digitada � inv�lida!");
                            printf("\nTente novamente.");
                            system("pause");
                        } else {
                            system("cls");
                            switch (opcaoVeiculo) {
                                case 1:
                                	printf("\n-----------<<< Adicionar Ve�culo no In�cio >>>----------- \n");
                                    adicionarVeiculoInicio();
                                    system("pause");
                                    break;
                                case 2:
                                    printf("\n-----------<<< Adicionar Ve�culo no Meio >>>----------- \n");
                                    adicionarVeiculoMeio();
                                    system("pause");
                                    break;
                                case 3:
                                	printf("\n-----------<<< Adicionar Ve�culo no Final >>>----------- \n");
                                    adicionarVeiculoFim();
                                    system("pause");
                                    break;
                                case 4:
                                    printf("\n-----------<<< Editar Informa��es do Ve�culo >>>----------- \n");
                                    editarVeiculos();
                                    system("pause");
                                    break;
                                case 5:
                                     printf("\n-----------<<< Excluir Ve�culo >>>----------- \n");
                                    excluirVeiculo();
                                    system("pause");
                                    break;

                                case 6:
                                	printf("\n-----------<<< Lista de Ve�culos >>>----------- \n");
                                    imprimirVeiculo(primeiroVeiculo);
                                    system("pause");
                                    break;
                            }
                        }
                    } while (opcaoVeiculo != 0);
                    break;
                }
                case 2:
                    printf("fun��o a implementar\n");
                    system("pause");
                    break;
                case 3:
                    imprimirVeiculo(primeiroVeiculo);
                    system("pause");
                    break;

            }
        }
    } while (opcao != 0);

    return 0;
}

void menuPrimario() {
    printf("\n************************************************************************\n");
    printf("\n************************* BLOCO DO EU SOZINHO **************************\n");
    printf("\n************************************************************************\n");
    printf("\n1 - Ve�culos \n");
    printf("2 - Pessoas \n");
    printf("3 - Imprimir \n");
    printf("0 - Sair\n");
}

void menuVeiculo() {
	printf("\n-----------<<< Gerenciamento de Ve�culos >>>----------- \n");
    printf("\n1 - Adicionar ve�culos no in�cio");
    printf("\n2 - Adicionar ve�culos no meio");
    printf("\n3 - Adicionar ve�culos no final");
    printf("\n4 - Editar informa��es de um ve�culo");
    printf("\n5 - Excluir ve�culos");
    printf("\n6 - Exibir ve�culos cadastrados");
    printf("\n0 - Sair");
}

void adicionarVeiculoInicio() {
    // ponteiro para armazenar as novas ionforma��pes do ve�culo

    struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
    printf("\nDigite o tipo de ve�culo (carro de apoio ou caminh�o): ");
    fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
    novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
    printf("Digite a placa do ve�culo: ");
    fgets(novoVeiculo->placa, TAM_PLACA, stdin);
    novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

    novoVeiculo->proximoVeiculo = primeiroVeiculo;
    primeiroVeiculo = novoVeiculo;
    printf(" \nO ve�culo foi inserido com sucesso. \n");
}

void imprimirVeiculo(struct veiculos *primeiroVeiculo) {

    int qtdVeiculo = 0;
    if (primeiroVeiculo == NULL){
        printf("A lista de ve�culos est�  vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    }else{
        struct veiculos *ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo != NULL){
            qtdVeiculo++;
            printf("\nVe�culo %d \n", qtdVeiculo);
            printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo->tipo);
            printf("Placa do Ve�culo: %s\n", ponteiroVeiculo->placa);
            ponteiroVeiculo= ponteiroVeiculo->proximoVeiculo;
        };
		printf("\nTotal de ve�culos registrados: %d\n\n", contadorVeiculos());
    }
}

void adicionarVeiculoFim(){

    if (primeiroVeiculo == NULL){
        printf("A lista de ve�culos est�  vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    }else{
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        printf("\nDigite o tipo de ve�culo (carro de apoio ou caminh�o): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do ve�culo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        struct veiculos *ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo->proximoVeiculo != NULL){
            ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
        };
        ponteiroVeiculo->proximoVeiculo = novoVeiculo;
        novoVeiculo->proximoVeiculo = NULL;

		printf("\nO ve�culo foi inserido com sucesso. \n");
    }
}
void adicionarVeiculoMeio(){
    if (primeiroVeiculo == NULL || primeiroVeiculo->proximoVeiculo == NULL ){
        printf("� necess�rio ter, pelo menos, dois ve�culos para inserir um ve�culo no meio! \n");
    } else {
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        printf("Digite o tipo de ve�culo (carro de apoio ou caminh�o): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do ve�culo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        printf("\nVoc� j� cadastrou os seguintes ve�culos:");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posi��o que voc� deseja inserir o ve�culo: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo < 2 || posicaoVeiculo > totalVeiculos) {
            printf("N�o � poss�vel inserir o ve�culo nessa posi��o.\n");
        } else {
            int qtdVeiculo = 1;
            struct veiculos *ponteiroVeiculo = primeiroVeiculo;

            while(qtdVeiculo!= totalVeiculos -1 && ponteiroVeiculo->proximoVeiculo !=NULL) {
                ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }

            struct veiculos *temporario = ponteiroVeiculo->proximoVeiculo;
            ponteiroVeiculo->proximoVeiculo = novoVeiculo;
            novoVeiculo->proximoVeiculo = temporario;
            printf("O ve�culo foi inserido com sucesso.\n");
        }
    }
}

int contadorVeiculos(){
    int qtdVeiculo = 0;
    if (primeiroVeiculo == NULL){
        return qtdVeiculo;
    }else{
        struct veiculos *ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo != NULL){
            qtdVeiculo++;
            ponteiroVeiculo= ponteiroVeiculo->proximoVeiculo;
        };
    return qtdVeiculo;
    }
}

void editarVeiculos(){
    if (primeiroVeiculo == NULL || primeiroVeiculo->proximoVeiculo == NULL ){
        printf("A lista est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    } else {
        printf("\nVoc� j� cadastrou os seguintes ve�culos: ");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posi��o do ve�culo que voc� deseja editar: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

         if (posicaoVeiculo <0 || posicaoVeiculo > totalVeiculos) {
            printf("Posi��o inv�lida! Por favor, insira uma posi��o v�lida.\n\n");
        } else {
            int qtdVeiculo = 1;
            struct veiculos *ponteiroVeiculo = primeiroVeiculo;

            while(qtdVeiculo!= totalVeiculos -1 && ponteiroVeiculo->proximoVeiculo !=NULL) {
                ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }
            printf("Digite o tipo de ve�culo (carro de apoio ou caminh�o): ");
            fgets(ponteiroVeiculo->tipo, TAM_TIPO, stdin);
            ponteiroVeiculo->tipo[strcspn(ponteiroVeiculo->tipo, "\n")] = '\0';
            printf("Digite a placa do ve�culo: ");
            fgets(ponteiroVeiculo->placa, TAM_TIPO, stdin);
            ponteiroVeiculo->placa[strcspn(ponteiroVeiculo->placa, "\n")] = '\0';

            printf("O ve�culo foi editado com sucesso.\n");
        }
    }
}
void excluirVeiculo(){

    if (primeiroVeiculo == NULL || primeiroVeiculo->proximoVeiculo == NULL ){
        printf("A lista est� vazia! \n");
        printf("Por favor, insira um ve�culo. \n");
    } else {
        printf("\nVoc� j� cadastrou os seguintes ve�culos: ");

        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;

        printf("\nDigite a posi��o do ve�culo que voc� deseja excluir: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo <1 || posicaoVeiculo > totalVeiculos) {
            printf("Posi��o inv�lida! Por favor, insira uma posi��o v�lida.\n\n");
        }

        struct veiculos *atualVeiculo = primeiroVeiculo;
        struct veiculos *anteriorVeiculo = NULL;

        if (posicaoVeiculo==1) {
            primeiroVeiculo = atualVeiculo->proximoVeiculo;
            free(atualVeiculo);
            printf("\nVe�culo da posi��o %d foi exclu�do com sucesso.\n", posicaoVeiculo);
        } else {
            int contador = 0;
            for (contador = 1; contador < posicaoVeiculo; contador++) {
                anteriorVeiculo = atualVeiculo;
                atualVeiculo= atualVeiculo->proximoVeiculo;
        }
        anteriorVeiculo->proximoVeiculo = atualVeiculo->proximoVeiculo;

        free(atualVeiculo);

        printf("\nVe�culo da posi��o %d foi exclu�do com sucesso.\n", posicaoVeiculo);

        }
    }
}
