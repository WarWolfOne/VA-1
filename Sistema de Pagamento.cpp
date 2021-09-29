/*
Matheus do Nascimento Saito - 2020262
Guilherme Gomes de Almeida - 2020890
Marcos Vinicius Fernandes Alves - 2021030
Pedro Wilson Rodrigues de Lima - 2020267
Marco Antônio Martins - 1910497
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct node Node;

struct node {
	float valorConta;
	int dia, mes, ano;
	char idCliente[30];
	char status[8];
	
	Node *next;
};

void addInicio(Node **list, float valorConta, int dia, int mes, int ano) {
	Node *novo = (Node *) malloc(sizeof(Node));
	
	if(novo) {
		novo->valorConta = valorConta;
		novo->dia = dia;
		novo->mes = mes;
		novo->ano = ano;
		novo->next = *list;
		*list = novo;
	} else
		printf("Erro na alocação!\n");
}

void addFim(Node **list, float valorConta, int dia, int mes, int ano) {
	Node *aux, *novo = (Node *) malloc(sizeof(Node));
	
	if(novo) {
		novo->valorConta = valorConta;
		novo->dia = dia;
		novo->mes = mes;
		novo->ano = ano;
		novo->next = NULL;
		
		if(*list == NULL)
			*list = novo;
		else {
			aux = *list;
			while(aux->next)
				aux = aux->next;
			aux->next = novo;
		}
	} else
		printf("Erro na alocação!\n");
}

/*void addMeio(Node **list, float valorConta, float ant, int dia, int mes, int ano) {
	Node *aux, *novo = (Node *) malloc(sizeof(Node));
	if (novo) {
		novo->valorConta = valorConta;
		novo->dia = dia;
		novo->mes = mes;
		novo->ano = ano;
		
		if(*list == NULL) {
			novo->next = NULL;
			*list = novo;			
		} else { 
			aux = *list;
			while(aux->valorConta !=ant && aux->next)
				aux = aux->next;
			novo->next = aux->next;
			aux->next = novo;
			
		}
	} else
		printf("Erro na alocação!\n");
	
}*/

void impressao (Node *node) {
	printf("\n\Lista: \n\n\n ");
	while(node) {
		printf("%2.f \n", node->valorConta);
		printf("%d/n", node->dia);
		printf("%d/", node->mes);
		printf("%d", node->ano);
		node = node->next;
	}
	printf("\n\n");
}
int main() {
	
	int select, dia, mes, ano;
	float valorConta, valorPago, ant;
	Node *list = NULL;
	
	do{
		printf("\n0 - Sair \n1 - Add no Inicio \n2 - Add no Fim \n3 - Add no Meio \n4 - Imprimir \n");
		scanf("%d", &select);
		
		switch(select){
			case 1:
				printf("Digite o valor da conta: ");
				scanf("%f", &valorConta);
				printf("Data de vencimento:");
				scanf("%d", &dia);
				scanf("%d", &mes);
				scanf("%d", &ano);
				addInicio(&list, valorConta, dia, mes, ano);
				break;
			case 2:
				printf("Digite o valor da conta ");
				scanf("%f", &valorConta);
				printf("Data de vencimento:");
				scanf("%d/", &dia);
				scanf("%d", &mes);
				scanf("%d", &ano);
				addFim(&list, valorConta, dia, mes, ano);
				break;
			case 3:
			/*	printf("Digite o valor da conta e o valor da referencia anterior: ");
				scanf("%f %f", &valorConta, &ant);
				printf("Data de vencimento:");
				scanf("%d/", &dia);
				scanf("%d", &mes);
				scanf("%d", &ano);
				addMeio(list, valorConta, dia, mes, ano);
				break; */
			case 4:
				impressao(list);
				break;
			default:
				if(select != 0)
					printf("Opção invalida!");
		}
	} while (select != 0);
}
