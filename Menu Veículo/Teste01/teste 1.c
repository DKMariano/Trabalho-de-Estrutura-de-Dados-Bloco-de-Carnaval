/*
Criando uma lista simplesmente encadeada sem fun��o e imprimindo
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_PLACA 10  // Tamanho m�ximo da placa
#define TAM_TIPO 20   // Tamanho m�ximo do tipo de ve�culo

struct veiculos{
	char tipo[TAM_TIPO];     // Utilizando a constante TAM_TIPO
	char placa[TAM_PLACA];   // Utilizando a constante TAM_PLACA
	struct veiculos *proximoVeiculo;
};

int main(){
	setlocale(LC_ALL, "Portuguese");

	// Criando o ve�culo 01 (in�cio da lista)
	struct veiculos *inicio = NULL;
	inicio = (struct veiculos *)malloc(sizeof(struct veiculos));
	strcpy(inicio->tipo, "Caminhao");
    strcpy(inicio->placa, "PKA0205");
	inicio->proximoVeiculo = NULL;

	printf("\nVe�culo 01\n");
	printf("Tipo de Ve�culo: %s\n", inicio->tipo);
	printf("Placa do Ve�culo: %s\n\n", inicio->placa);

	// Criando o ve�culo 02
	struct veiculos *ponteiroVeiculo1 = (struct veiculos *)malloc(sizeof(struct veiculos));
	strcpy(ponteiroVeiculo1->tipo, "Carro de Apoio");
	strcpy(ponteiroVeiculo1->placa, "OLB9878");
	ponteiroVeiculo1->proximoVeiculo = NULL;

	inicio->proximoVeiculo = ponteiroVeiculo1;

	printf("\nVe�culo 02\n");
	printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo1->tipo);
	printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo1->placa);

	// Criando o ve�culo 03
	struct veiculos *ponteiroVeiculo2 = (struct veiculos *)malloc(sizeof(struct veiculos));
	strcpy(ponteiroVeiculo2->tipo, "Carro de Apoio");
	strcpy(ponteiroVeiculo2->placa, "DEF1234");
	ponteiroVeiculo2->proximoVeiculo = NULL;

	ponteiroVeiculo1->proximoVeiculo = ponteiroVeiculo2;

	printf("\nVe�culo 03\n");
	printf("Tipo de Ve�culo: %s\n", ponteiroVeiculo2->tipo);
	printf("Placa do Ve�culo: %s\n\n", ponteiroVeiculo2->placa);

	// Criando o ve�culo 04
	struct veiculos *ponteiroVeiculo3 = (struct veiculos *)malloc(sizeof(struct veiculos));
	strcpy(ponteiroVeiculo3->tipo, "Carro de Apoio");
	strcpy(ponteiroVeiculo3->placa, "ELF5678");
	ponteiroVeiculo3->proximoVeiculo = NULL;

	ponteiroVeiculo2->proximoVeiculo = ponteiroVeiculo3;

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

