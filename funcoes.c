#define _CRT_SECURE_NO_WARNINGS
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "estrutura.h"
#include "calculos.h"
//!Inserir novo registo no inicio da lista com dados 
Jobs* inserirInicio(Jobs* inicio, int Estado, int Processo, int Operacao, int Maquina, int Tempo)
{
	Jobs* novo = (Jobs*)malloc(sizeof(Jobs));
	if (novo != NULL)
	{
		novo->estado = Estado;
		novo->process = Processo;
		novo->operacoes = Operacao;
		novo->maquina = Maquina;
		novo->tempo = Tempo;
		novo->seguinte = inicio;
		return(novo);
	}
	else return(inicio);
}

//!Inserir um registo no fim da lista ou no inicio se estiver vazia 
Jobs* inserirFim(Jobs* inicio, int Estado, int Processo, int Operacao, int Maquina, int Tempo)
{
	Jobs* aux = inicio, * novo = (Jobs*)malloc(sizeof(Jobs));
	if (novo != NULL)
	{
		if (aux == NULL) return(inserirInicio(aux, Estado, Processo, Operacao, Maquina, Tempo));
		else {
			while (aux->seguinte != NULL)
				aux = aux->seguinte;
			novo->estado = Estado;
			novo->process = Processo;
			novo->operacoes = Operacao;
			novo->maquina = Maquina;
			novo->tempo = Tempo;
			novo->seguinte = NULL;
			aux->seguinte = novo;
			return(inicio);
		}
	}
	else return(inicio);
}
//!Novo registo no fim, sendo a lista vazia grava no inicio 
Jobs* NovoRegistoFim(Jobs* inicio) {
	Jobs* lista = inicio;
	int estado = 0, processo = 1, operacao = 0, maquina = 0, tempo = 0, resultado = 1;
	printf("\nProcesso -> 1 ");//!Neste momento do trabalho é relacionado só com um job
	textcolor(RED);
	printf("Neste momento do trabalho é relacionado só com um processo\n");
	textcolor(WHITE);
	while (resultado == 1) {
		printf("\nOperação ->");
		scanf("%d", &operacao);
		printf("\nMaquina ->");
		scanf("%d", &maquina);
		printf("\nMáquina (%d) Tempo ->", maquina);
		scanf("%d", &tempo);
		resultado = verificaOperacao(lista, operacao, maquina);
		if (resultado == 1) {
			textcolor(BLUE);
			printf("\nMáquina (%d) existente para esta operação-> %d Escolha outra máquina", maquina, operacao);
			textcolor(WHITE);
		}
		else
		{
			break;
		}
	}
	printf("Deseja gravar os dados na lista ? (S) ENTER não grava ");
	while (getchar() != '\n') {}
	if (toupper(getchar()) == 'S') {
		if (lista != NULL) {
			lista = inserirFim(lista, estado, processo, operacao, maquina, tempo);
		}
		else {
			lista = inserirInicio(lista, estado, processo, operacao, maquina, tempo);
		}
		textcolor(GREEN);
		printf("\n                 Os dados foram gravados na lista");
		textcolor(WHITE);
		getchar();
		getchar();
	}
	else {
		textcolor(RED);
		printf("                Os dados não foram gravados na lista");
		textcolor(WHITE);
		getchar();
	}
	fflush(stdin);
	return lista;
}
//!Inserir dados para guardar no inicio 
Jobs* NovoRegistoInicio(Jobs* inicio)
{
	Jobs* lista = inicio;
	int estado = 0, processo = 1, operacao = 0, maquina = 0, tempo = 0, resultado = 1;
	printf("\nProcesso -> 1 ");//!Neste momento do trabalho é relacionado só com um job
	textcolor(RED);
	printf("Neste momento do trabalho é relacionado só com um processo\n");
	textcolor(WHITE);
	while (resultado == 1) {
		printf("\nOperação ->");
		scanf("%d", &operacao);
		printf("\nMaquina ->");
		scanf("%d", &maquina);
		printf("\nMáquina (%d) Tempo ->", maquina);
		scanf("%d", &tempo);
		resultado = verificaOperacao(lista, operacao, maquina);//!Verifica se na operação já existe a maquina 
		if (resultado == 1) {
			textcolor(BLUE);
			printf("\nMáquina (%d) existente para esta operação-> %d Escolha outra máquina", maquina, operacao);
			textcolor(WHITE);
		}
		else
		{
			break;
		}
	}
	printf("Deseja gravar os dados na lista ? (S) ENTER não grava ");
	while (getchar() != '\n') {}
	if (toupper(getchar()) == 'S') {
		//!Insere na lista os dados 
		inicio = inserirInicio(lista, estado, processo, operacao, maquina, tempo);
		textcolor(GREEN);
		printf("\n                 Os dados foram gravados na lista");
		textcolor(WHITE);
		getchar();
		getchar();
	}
	else {
		textcolor(RED);
		printf("                Os dados não foram gravados na lista");
		textcolor(WHITE);
		getchar();
	}


	return inicio;
}
//!Altera os valores de um registo menos os dados que sao controlados pelo programa 
//!Como seguinte, estado e processo, este ultimo está restringido a um job  
Jobs* altera(Jobs* inicio)
{
	int opcao = 0, NumRegistos = 0, registo = 0, operacao, maquina, tempo, resultado = 1;
	Jobs* aux = inicio;

	if (aux == NULL) {
		system("cls");
		textcolor(RED);
		printf("\n                                          Lista vazia");
		textcolor(WHITE);
		printf("\n                                     Tecla ENTER continua");
		getchar();
		getchar();
		return NULL;
	}
	else {

		system("cls");
		NumRegistos = listar(inicio);
		printf("\n\nOnde quer alterar, escolha -> 1 ate %d ", NumRegistos);
		scanf("%d", &opcao);
		aux = inicio;
		if (opcao > 0 && opcao <= NumRegistos) {
			for (int i = 1; i < opcao; i++) {
				aux = aux->seguinte;
			}
			textcolor(GREEN);
			printf("\nRegisto->%d Operação->%d Máquina->%d,Tempo->%d\n", opcao, aux->operacoes, aux->maquina, aux->tempo);
			textcolor(WHITE);
			printf("Operação->");
			scanf("%d", &operacao);
			printf("Maquina->");
			scanf("%d", &maquina);
			while (resultado == 1) {
				resultado = verificaOperacao(aux, operacao, maquina);//!Verifica se na operação já existe a maquina 
				if (resultado == 1) {
					textcolor(BLUE);
					printf("\nMáquina (%d) existente para operação-> %d Escolha outra máquina\n", maquina, operacao);
					textcolor(WHITE);
					printf("Operação->");
					scanf("%d", &operacao);
					printf("Maquina->");
					scanf("%d", &maquina);
				}
			}
			printf("Tempo->");
			scanf("%d", &tempo);

			printf("Deseja gravar os dados ? (S) ENTER não grava ");
			while (getchar() != '\n') {}
			if (toupper(getchar()) == 'S') {
				//!Insere na lista os dados 
				aux->operacoes = operacao;
				aux->maquina = maquina;
				aux->tempo = tempo;
				textcolor(GREEN);
				printf("\n                 Os dados foram gravados na lista");
				textcolor(WHITE);
				getchar();
			}
			else {
				textcolor(RED);
				printf("                Os dados não foram gravados na lista");
				textcolor(WHITE);
			}
			getchar();
		}
		else {
			printf("Registo inválido");
			getchar();
			getchar();
		}
		return inicio;
	}
	return inicio;
}
//!Remove um registo da lista 
Jobs* remover(Jobs* inicio) {
	int numero = 0, operacao = 0, maquina = 0, opcao = 0, registo = 0, estado = 0, contador = 1;
	system("cls");
	if (inicio != NULL) {
		numero = listar(inicio);
		getchar();//!Lista na consola e retorna quantos registos tem a lista 
		printf("\n\n\nDeseja remover um registo, ou uma máquina referente a uma operação ?  (1) Registo (2) Máquina->");
		scanf("%d", &opcao);
		if ((opcao < 1) || (opcao > 2)) {
			textcolor(RED);
			printf("\nOpeçao %d inválida", opcao); getchar(); getchar();
			textcolor(WHITE);
			return inicio;
		}
		if (opcao == 1) {
			registo = opcao;
			printf("\nQual o registo a remover %d até %d ? ", registo, numero);
			scanf("%d", &registo);
			textcolor(RED);
			if ((registo < 1) || (registo > numero))	printf("\n\n              Registo %d inválido !!", registo); getchar();
			textcolor(WHITE);
			RemoveRegisto(inicio, registo);
			textcolor(GREEN);
			if ((registo > 0) && (registo <= numero))	printf("\n\n              Remoção efetuada do registo %d !!", registo); getchar();
			textcolor(WHITE);
		}
		if (opcao == 2) {
			printf("\nQual a Operação ? ");
			scanf("%d", &operacao);
			printf("\nQual maquina ? ");
			scanf("%d", &maquina);
			Jobs* aux = inicio;
			while (aux != NULL) {
				//!verifica se encontra
				if ((aux->operacoes == operacao) && (aux->maquina == maquina)) {
					printf("contador %d", contador);
					RemoveRegisto(inicio, contador);
					textcolor(GREEN);
					printf("\n\n              Remoção efetuada na operação %d maquina %d !!", operacao, maquina); getchar(); getchar();
					textcolor(WHITE);
					free(aux);
					return inicio;
				}
				aux = aux->seguinte;
				contador++;
			}
			textcolor(RED);
			printf("\n\n             Operação %d e Maquina %d não encontrada !!", operacao, maquina); getchar(); getchar();
			textcolor(WHITE);
			free(aux);
			return inicio;

		}
	}
	else
	{
		textcolor(RED);
		printf("\n\n           Lista vazia !!  carregue uma lista ou pode criar uma"); getchar(); getchar();
		textcolor(WHITE);

	}
	return(inicio);
}
Jobs* RemoveRegisto(Jobs* inicio, int registo)
{
	Jobs* aux, * antes;
	int contador = 1;
	if (inicio == NULL)
	{
		return 0;  //! Lista vazia !!!
	}
	else
	{   //! Caso a lista nao esteja vazia
		aux = inicio;
		antes = inicio;
		while (aux != NULL)
		{


			if (contador == registo)

			{
				if (aux == inicio) //! Remove primeiro registo da lista 
				{
					antes = aux->seguinte;
					free(aux);

					inicio = antes;
					return antes; //! removeu !!
				}
				else  //! Remover meio da lista
				{
					antes->seguinte = aux->seguinte;  //! Refaz o encadeamento
					free(aux);                //! Liberta a memoria de aux
					return antes;
				}
			}
			else  //! continua procurando no prox. nodo
			{
				antes = aux;
				aux = aux->seguinte;
				contador++;
			}
		}
		return inicio;
	}
}
//! Função de listagem
int listar(Jobs* inicio)
{
	int a = 0;
	Jobs* aux = inicio;
	printf("         Listagem geral da lista\n\n");
	while (aux != NULL)
	{
		a++;
		if (aux->estado == 1) {
			textcolor(GREEN);
			printf("Job %d operacao -> %d  Maquina ->(%d) Tempo ->[%d]  Registo %d \n", aux->process, aux->operacoes, aux->maquina, aux->tempo, a);
			textcolor(WHITE);
		}
		if (aux->estado == 2) {
			textcolor(BLUE);
			printf("Job %d operacao -> %d  Maquina ->(%d) Tempo ->[%d]  Registo %d \n", aux->process, aux->operacoes, aux->maquina, aux->tempo, a);
			textcolor(WHITE);
		}
		if (aux->estado == 0) {
			textcolor(WHITE);
			printf("Job %d operacao -> %d  Maquina ->(%d) Tempo ->[%d]  Registo %d \n", aux->process, aux->operacoes, aux->maquina, aux->tempo, a);

		}


		aux = aux->seguinte;
	}
	return a;
}
//!ordena lista decrescente
Jobs* ordenaLista(Jobs* inicio) {
	Jobs* i, * j, * aux;
	aux = (Jobs*)malloc(sizeof(Jobs));
	i = inicio;
	while (i != NULL) {
		j = i->seguinte;
		while (j != NULL) {
			if (i->operacoes < j->operacoes) {
				*aux = *i; //! copia valor de i em aux.
				*i = *j; //! copia valor de j em i.
				i->seguinte = aux->seguinte; //! altera ponterio do próximo de i para que continue a ser o mesmo que era antes da copia
				aux->seguinte = j->seguinte; //! copia o valor do ponteiro do proximo j
				*j = *aux; //! copia valor de aux em j.
				j->seguinte = aux->seguinte; //! altera ponteiro do próximo de i para que ele continue a ser o mesmo que era antes da copia
			}
			j = j->seguinte;
		}
		i = i->seguinte;
	}
	free(aux);
	return inicio;
}

//!Verifica se a máquina ja existe para a mesma operação
int verificaOperacao(Jobs* inicio, int operacao, int maquina) {
	int resultado = 0;
	while (inicio != NULL)
	{
		if (inicio != NULL) {
			if ((inicio->operacoes == operacao) && (inicio->maquina == maquina)) {
				resultado = 1;
				break;
			}
		}
		inicio = inicio->seguinte;
	}
	return resultado;
}


//!ordena lista crescente
Jobs* ordenaListaCrescente(Jobs* inicio)
{
	Jobs* i, * j, * aux;
	aux = (Jobs*)malloc(sizeof(Jobs));
	i = inicio;
	while (i != NULL) {
		j = i->seguinte;
		while (j != NULL) {
			if (i->operacoes > j->operacoes) {
				*aux = *i; //! copia valor de i em aux.
				*i = *j; //! copia valor de j em i.
				i->seguinte = aux->seguinte; //! altera ponterio do próximo de i para que continue a ser o mesmo que era antes da copia
				aux->seguinte = j->seguinte; //! copia o valor do ponteiro do proximo j
				*j = *aux; //! copia valor de aux em j.
				j->seguinte = aux->seguinte; //! altera ponteiro do próximo de i para que ele continue a ser o mesmo que era antes da copia
			}
			j = j->seguinte;
		}
		i = i->seguinte;
	}
	free(aux);
	return inicio;
}
