#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "utils.h"
#include "funcoes.h"
#include "estrutura.h"
#include "calculos.h"
void main() {
	setlocale(LC_ALL, "portuguese");
	setlocale(LC_NUMERIC, "us");
	textcolor(WHITE);
	//!Defenir variaveis 
	int opcao = 0, inicio = 0, valor = 0, opcao_1 = 0, info = 0;
	char ficheiro[50] = "dados.txt", opcao_2 = 0;
	char ficheiroGrava[50] = "saida.txt";
	Jobs* lista = NULL;
	while (opcao != 8) {
	
		//!Menu e submenu
		system("cls");
		printf("-----------Listas ligadas simples-----------\n\n");
		printf("Menu:\n");
		printf("1 - leitura de ficheiro de texto com representação de um job \n");
		printf("2 - Gravação de ficheiro de texto com representação de um job \n");
		printf("3 - Inserção e alteração de uma operação-> "); textcolor(YELLOW); printf("(SubMenu)\n"); textcolor(WHITE);
		printf("4 - Calculo do tempo minimo e listagem\n");
		printf("5 - Calculo do tempo Maximo e listagem\n");
		printf("6 - Calculo do médias de tempo e listagem\n");
		printf("7 - Listagem da lista\n");
		printf("8 - sair\n");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1://!leitura de ficheiro de texto com representação de um job
			system("cls");
			while (getchar() != '\n') {}
			if (lista != NULL) {
				textcolor(RED);
				printf("Deseja continuar ?, já existe dados na lista \nSe continuar vai perder todos os dados existentes \n");
				textcolor(MAGENTA);
				printf("Não (N) outra opção continua ->");
				textcolor(WHITE);
				while (toupper(getchar()) == 'N')
				{
					opcao = 0;
					break;
				}
			}
			if (opcao != 0) {
				//!if (lista != NULL) free(lista);
				printf("Nome do ficheiro:");
				textcolor(YELLOW);
				printf(": %s\n", ficheiro);
				textcolor(WHITE);
				printf("Deseja abrir outro ficheiro ? tecla (S) \n");
				while (toupper(getchar()) == 'S')
				{
					printf("Introduza o nome do ficheiro: ");
					scanf("%s", &ficheiro);
				}
				lista = ler(ficheiro);
				textcolor(GREEN);
				if (lista != NULL) printf("               Ficheiro lido com sucesso");//!Verifica se lista não está vazia
				textcolor(WHITE);
				printf("\n\n               Tecla enter para continua");
			}
			break;
		case 2://!Gravação de ficheiro de texto com representação de um job
			system("cls");

			//!printf("Nome do ficheiro a gravar: %s \n", ficheiroGrava);
			printf("Nome do ficheiro:");
			textcolor(YELLOW);
			printf(": %s\n", ficheiroGrava);
			textcolor(WHITE);

			printf("Se o nome for igual a um existente será apagado \n");
			printf("Deseja gravar outro ficheiro ? tecla (S) \n");
			getchar();
			while (toupper(getchar()) == 'S')
			{
				printf("Introduza o nome do ficheiro: ");
				scanf("%s", &ficheiroGrava);
			}
			escrever(lista, ficheiroGrava);/*Escreve num ficheiro o job guardado na memória*/

			break;
		case 3://!Inserção de uma nova operação
			system("cls");
			while (opcao == 3) {
				system("cls");
				textcolor(YELLOW);
				printf("   Submenu:\n\n");
				textcolor(WHITE);
				printf("1-Inserir operação no inicio\n2-Inserir operação no fim\n3-Remover operação numa das posições\n4-Alterar um registo\n5-Voltar ao menu\n");
				scanf("%d", &opcao_1);
				if (opcao_1 != 0) {
					if (opcao_1 == 1) {//!operação no inico
						lista = NovoRegistoInicio(lista);
						ordenaLista(lista);
					}
					if (opcao_1 == 2) {//!operação no fim
						lista = NovoRegistoFim(lista);
						ordenaLista(lista);
					}
					if (opcao_1 == 3) {//!operação numa posição
						lista = remover(lista);
						ordenaLista(lista);
					}
					if (opcao_1 == 4) {//!operação numa posição
						lista = altera(lista);
					}
					if (opcao_1 == 5) {//!Voltar ao menu
						opcao = 0;
					}
				}
				else {
					opcao_1 = 0;//!Volta a por a 0 opcao_1
					fflush(stdin);
				}
				//!opcao = 3;
			}
			break;

		case 4://!Calculo e listagem dos tempos minimos
			system("cls");
			info = 1;//!informa os valores minimos
			Calculo(lista, info);

			break;
		case 5://!Calculo e listagem dos tempos maximos
			system("cls");
			info = 2;//!!informa os valores máximos
			Calculo(lista, info);

			break;
		case 6://!Calculo e listagem da médias de tempo
			system("cls");
			info = 3;//!informa as médias maximas e minimas
			Calculo(lista, info);
			break;
		case 7://!Calculo e listagem da médias de tempo
			system("cls");
			if (lista != NULL) {
				ordenaLista(lista);
				listar(lista);
				getchar();
			}
			else {
				textcolor(RED);
				printf("\n                lista vazia\n\n"); getchar();
				textcolor(WHITE);
			}
			break;
			case 8:
			//!sai do programa
			if (lista != NULL) free(lista);
			system("cls");
			break;
		default:
			opcao = 0;
			break;
		}
		getchar();
	}
}

