/*
Criando uma lista simplesmente encadeada, com entradas de dados e sem fun��o e imprimindo
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_PLACA 50  // Tamanho m�ximo da placa
#define TAM_TIPO 50   // Tamanho m�ximo do tipo de ve�culo

struct veiculos{
	char tipo[TAM_TIPO];
	char placa[TAM_PLACA];
	struct veiculos *proximoVeiculo;
};

int main(){
	setlocale(LC_ALL, "Portuguese");

	// Criando o ve�culo 01 (in�cio da lista)
	struct veiculos *inicio = (struct veiculos *)malloc(sizeof(struct veiculos)); // Alocando mem�ria para o primeiro ve�culo
	printf("\nDigite o tipo de ve�culo (carro de apoio ou caminh�o): ");
	fgets(inicio->tipo, TAM_TIPO, stdin);
	inicio->tipo[strcspn(inicio->tipo, "\n")] = '\0'; // Removendo o caractere de nova linha
	printf("Digite a placa do ve�culo 01: ");
	fgets(inicio->placa, TAM_PLACA, stdin);
	inicio->placa[strcspn(inicio->placa, "\n")] = '\0'; // Removendo o caractere de nova linha

	inicio->proximoVeiculo = NULL;

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
	inicio->proximoVeiculo = ponteiroVeiculo1;

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
	printf("Tipo de Ve�culo: %s\n", inicio->tipo);
	printf("Placa do Ve�culo: %s\n\n", inicio->placa);

    printf("\nVe�culo 02\n");
	printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo1->tipo);
	printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo1->placa);

    printf("\nVe�culo 03\n");
	printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo2->tipo);
	printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo2->placa);

	printf("\nVe�culo 04\n");
	printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo3->tipo);
	printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo3->placa);



	// Liberando mem�ria
	free(ponteiroVeiculo3);  // Liberando mem�ria do ve�culo 04
	free(ponteiroVeiculo2);  // Liberando mem�ria do ve�culo 03
	free(ponteiroVeiculo1);  // Liberando mem�ria do ve�culo 02
	free(inicio);  // Liberando mem�ria do ve�culo 01

	return 0;
}
