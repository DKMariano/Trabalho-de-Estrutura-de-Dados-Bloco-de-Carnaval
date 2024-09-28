/*
Criando uma lista simplesmente encadeada, com entradas de dados e sem fun��o e imprimindo
Criando menu
Criando fun��o contar
Criando fun��o imprimir

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
void contadorVeiculo();
void menuPrimario();
void menuVeiculo();
void adicionarVeiculoInicio();
void imprimirVeiculo();

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls");
        menuPrimario();

        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // limpar o buffer de entrada.

        if (opcao < 0 || opcao > 5) {
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
                                    adicionarVeiculoInicio();
                                    system("pause");
                                    break;
                                case 2:
                                    printf("fun��o a implementar\n");
                                    system("pause");
                                    break;
                                case 3:
                                    printf("fun��o a implementar\n");
                                    system("pause");
                                    break;
                                case 4:
                                    printf("fun��o a implementar\n");
                                    system("pause");
                                    break;
                                case 5:
                                    printf("fun��o a implementar\n");
                                    system("pause");
                                    break;

                                case 6:
                                    imprimirVeiculo();
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
                    imprimirVeiculo();
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
    printf("4 - ??????? \n");
    printf("5 - ??????? \n");
    printf("0 - Sair\n");
}

void menuVeiculo() {
    printf("\n-----------<<< Gerenciamento de Ve�culos >>>----------- \n");
    printf("\n1 - Adicionar Ve�culos no in�cio");
    printf("\n2 - Adicionar Ve�culos no meio");
    printf("\n3 - Adicionar Ve�culos no final");
    printf("\n4 - Editar Placa de Ve�culos");
    printf("\n5 - Excluir Ve�culos");
    printf("\n6 - Exibir Ve�culos Cadastrados");
    printf("\n0 - Sair");
}

void adicionarVeiculoInicio() {
    // Criando o ve�culo 01 (in�cio da lista)
    struct veiculos *novoVeiculo = (struct veiculos *)malloc(sizeof(struct veiculos));
    printf("\nDigite o tipo de ve�culo (carro de apoio ou caminh�o): ");
    fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
    novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0'; // Removendo o caractere de nova linha
    printf("Digite a placa do ve�culo 01: ");
    fgets(novoVeiculo->placa, TAM_PLACA, stdin);
    novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0'; // Removendo o caractere de nova linha

    novoVeiculo->proximoVeiculo = NULL;

    // Criando o ve�culo 02
    struct veiculos *ponteiroVeiculo1 = (struct veiculos *)malloc(sizeof(struct veiculos));
    printf("\nDigite o tipo de ve�culo (carro de apoio ou caminh�o): ");
    fgets(ponteiroVeiculo1->tipo, TAM_TIPO, stdin);
    ponteiroVeiculo1->tipo[strcspn(ponteiroVeiculo1->tipo, "\n")] = '\0';
    printf("Digite a placa do ve�culo 02: ");
    fgets(ponteiroVeiculo1->placa, TAM_PLACA, stdin);
    ponteiroVeiculo1->placa[strcspn(ponteiroVeiculo1->placa, "\n")] = '\0';
    ponteiroVeiculo1->proximoVeiculo = NULL;

    // Passar para o pr�ximo n�
    novoVeiculo->proximoVeiculo = ponteiroVeiculo1;

    // Criando o ve�culo 03
    struct veiculos *ponteiroVeiculo2 = (struct veiculos *)malloc(sizeof(struct veiculos));
    printf("\nDigite o tipo de ve�culo (carro de apoio ou caminh�o): ");
    fgets(ponteiroVeiculo2->tipo, TAM_TIPO, stdin);
    ponteiroVeiculo2->tipo[strcspn(ponteiroVeiculo2->tipo, "\n")] = '\0';
    printf("Digite a placa do ve�culo 03: ");
    fgets(ponteiroVeiculo2->placa, TAM_PLACA, stdin);
    ponteiroVeiculo2->placa[strcspn(ponteiroVeiculo2->placa, "\n")] = '\0';

    ponteiroVeiculo2->proximoVeiculo = NULL;

    // Passar para o pr�ximo n�
    ponteiroVeiculo1->proximoVeiculo = ponteiroVeiculo2;

    // Criando o ve�culo 04
    struct veiculos *ponteiroVeiculo3 = (struct veiculos *)malloc(sizeof(struct veiculos));
    printf("\nDigite o tipo de ve�culo (carro de apoio ou caminh�o): ");
    fgets(ponteiroVeiculo3->tipo, TAM_TIPO, stdin);
    ponteiroVeiculo3->tipo[strcspn(ponteiroVeiculo3->tipo, "\n")] = '\0';
    printf("Digite a placa do ve�culo 04: ");
    fgets(ponteiroVeiculo3->placa, TAM_PLACA, stdin);
    ponteiroVeiculo3->placa[strcspn(ponteiroVeiculo3->placa, "\n")] = '\0';

    ponteiroVeiculo3->proximoVeiculo = NULL;

    // Passar para o pr�ximo n�
    ponteiroVeiculo2->proximoVeiculo = ponteiroVeiculo3;

    // Imprimindo
    printf("\nLISTA DE VE�CULOS\n");
    printf("\nVe�culo 01\n");
    printf("Tipo de Ve�culo: %s\n", novoVeiculo->tipo);
    printf("Placa do Ve�culo: %s\n\n", novoVeiculo->placa);

    printf("\nVe�culo 02\n");
    printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo1->tipo);
    printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo1->placa);

    printf("\nVe�culo 03\n");
    printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo2->tipo);
    printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo2->placa);


    printf("\nVe�culo 04\n");
    printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo3->tipo);
    printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo3->placa);

}
void imprimirVeiculo() {
    int qtdVeiculo = 0;
    if (primeiroVeiculo == NULL){
        printf("A lista de ve�culos est�  vazia! \n");
    }else{
        struct veiculos *ponteiroVeiculo = NULL;
        ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo != NULL){
            qtdVeiculo++;
            printf("\nVe�culo %d\n", qtdVeiculo);
            printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo->tipo);
            printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo->placa);
            ponteiroVeiculo= ponteiroVeiculo->proximoVeiculo;
        };
        printf("Total de ve�culos registrados = %d", qtdVeiculo);
    }
}
