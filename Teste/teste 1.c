#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct veiculos{
	char tipo [20];
	char placa [20];
	struct veiculos *proximoVeiculo;
};


int main(){
	setlocale(LC_ALL, "Portuguese");

	struct veiculos *cabeca = NULL;
	cabeca = (struct veiculos *)malloc(sizeof(struct veiculos));
	strcpy(cabeca->tipo, "Caminhao");
    strcpy(cabeca->placa, "PKA0205");
	cabeca->proximoVeiculo = NULL;

	printf("\nVe�culo 01\n");
	printf("Tipo de Ve�clo: %s\n", cabeca->tipo);
	printf("Placa d0 Ve�clo: %s\n\n", cabeca->placa);

	struct veiculos *atual = (struct veiculos *)malloc(sizeof(struct veiculos));
	strcpy(atual->tipo, "Carro de Apoio");
	strcpy(atual->placa, "OLB9878");

	cabeca->proximoVeiculo = atual;

	printf("\nVe�culo 02\n");
	printf("Tipo de Ve�clo: %s\n", atual->tipo);
	printf("Placa d0 Ve�clo: %s\n\n", atual->placa);

	atual = (struct veiculos *)malloc(sizeof(struct veiculos));
	strcpy(atual->tipo, "Carro de Apoio");
	strcpy(atual->placa, "OLB9878");

	cabeca->proximoVeiculo = atual;
	printf("\nVe�culo 03\n");
	printf("Tipo de Ve�clo: %s\n", atual->tipo);
	printf("Placa d0 Ve�clo: %s\n\n", atual->placa);


	free(atual);
	free(cabeca);

}
