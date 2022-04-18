#define _CRT_SECURE_NO_WARNINGS
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

//!função ler do ficheiro e coloca os dados numa lista ligada simples
Jobs* ler(char ficheiro[]) {
	Jobs* lista = NULL; //! Lista ligada simples vazia
	system("cls");
	int valor = 0, b = 0, c = 0, d = 1, estado = 0, tempo = 0, posicao = 1;
	char linha[100], * t;
	int operacoes;
	const char* maquinas = "(,)";
	const char* tempos = "[,]";
	//!Abre ficheiro para leitura 
	fp = fopen(ficheiro, "r");
	if (fp == NULL) {
		gotoxy(30, 12);
		textcolor(LIGHTRED);
		printf("Não foi possivel abrir o ficheiro!!!\n");//!Verificar se o ficheiro foi aberto com sucesso
		textcolor(WHITE);
		strcpy(ficheiro, "dados.txt");//!repor nome do ficheiro por defeito 
	}
	else {
		fgets(linha, 100, fp);//!Retira a primeira linha 
		fgets(linha, 100, fp);//!Retira a segunda linha 
		while ((fgets(linha, 100, fp)) != NULL) { //!Lê do ficheiro uma linha completa enquanto não encontrar o fim do ficheiro
			operacoes = 0;
			t = strtok(linha, maquinas);//!Lê a promeira ocurrencia na linha
			while (t != NULL) {
				valor = atoi(t);
				if (valor == 0) operacoes++;
				if (valor != 0) {
					lista = inserirInicio(lista, estado, d, operacoes, valor, tempo);
					b++;
				}
				t = strtok(NULL, maquinas);
			}
			operacoes = 0;
			b = c;
			fgets(linha, 100, fp);//!Lê do ficheiro uma linha completa
			t = strtok(linha, tempos);
			while (t != NULL) {
				valor = atoi(t);
				if (valor == 0) operacoes++;
				if (valor != 0) {
					tempo = valor;
					lista = repetir(lista, tempo, b);
					b++;
				}
				t = strtok(NULL, tempos);
			}
			c = b;//!atribui ao c o ultimo registo na estrutura
			d++; //!incrementa Lista
		}
		fclose(fp);
	}
	
	return lista;
}

//!Vai para o fim da lista para guardar a linha dos tempos maquinas
Jobs* repetir(Jobs* inicio, int Tempo, int Posicao)
{
	Jobs* aux = inicio;
	int a = 0, b = 0;//!Criação de variaveis e atribuição de valores
	//!Devolve numero de registos da lista
	while (aux != NULL)
	{
		aux = aux->seguinte;//!faz avançar na lista 
		a++;
	}
	free(aux);//!Apaga a lista auxiliar
	b = a - Posicao;//!Numero de registos da lista
	a = 0;//!Volta a por a 0 o contador
	Jobs* Pr = inicio;
	//!Coloca na posição da lista para alterar adicionar o registo tempo
	while (a + 1 != b)
	{
		if (Pr != NULL) Pr = Pr->seguinte;
		a++;
	}
	if (Pr != NULL) Pr->tempo = Tempo;//!Altera os dados

	return(inicio);
}
//!função escrever no ficheiro 
void escrever(Jobs* inicio, char ficheiro[])
{
	system("cls");
	Jobs* menor = inicio;
	int contador = 0, min = 1, a = 1, max = 0;
	int atual = 0, anterior = 0, oper = 0, saida = 0, tem = 0;
	if (menor != NULL) {//!Verifica se lista está vazia para não gravar ficheiro 
		
		//!Abre ficheiro para escrita  
		fp = fopen(ficheiro, "w");
		printf("							Operation\n\n");
		fprintf(fp, "										Operation\n");
		printf("Process Plan");
		fprintf(fp, "Process Plan");
		Jobs* menor = inicio;
		//!Deteta qual a operação menor e maior de um job e conta o numero de registos na lista 
		while (menor != NULL) {
			if (min > menor->operacoes) min = menor->operacoes;//!Determina o numeros de operação e a mais baixa 
		if (max < menor->operacoes) max = menor->operacoes;//!Determina o maximo operação 
			menor = menor->seguinte;
			contador++;
		}
		//!Guarda no ficheiro as operações 
		for (int i = min; i <= max; i++) {
			printf("\t\t 0%d", i);
			fprintf(fp, "\t\t\t 0%d", i);
		}
		printf("\n");
		fprintf(fp, "\n");
		free(menor);//!Limpa da memória cópia da lista não necessária 
		Jobs* aux = inicio;
		//!Guarda em ficheiro as maquinas 
		while (a <= contador) {
			aux = inicio;
			for (int i = 1; i < (contador + 1 - a); i++) {
				aux = aux->seguinte;
			}
			saida++;
			atual = aux->operacoes;
			if (a == 1) printf("Pr%d\t", aux->process);
			if (a == 1) fprintf(fp, "Pr%d\t\t\t\t", aux->process);
			if (anterior != atual) {
				oper = 0;
			}
			else {
				oper = 1;
			}
			if (oper == 0 && tem == 1) printf(")");
			if (oper == 0 && tem == 1) fprintf(fp, ")");
			if (oper == 0) {
				anterior = atual;
				printf("\t\t(%d", aux->maquina);
				fprintf(fp, "\t\t(%d", aux->maquina);
				anterior = aux->operacoes;
				tem = 0;
			}
			if (atual == anterior && oper == 1) {
				anterior = atual;
				printf(",%d", aux->maquina);
				fprintf(fp, ",%d", aux->maquina);
				anterior = aux->operacoes;
				tem = 1;
				if (a == contador) printf(")\n");
				if (a == contador) fprintf(fp, ")\n");
			}
			a++;
		}
		atual = 0;
		while (a <= contador) {
			aux = inicio;
			for (int i = 1; i < (contador + 1 - a); i++) {
				aux = aux->seguinte;
			}
			saida++;
			atual = aux->operacoes;
			if (a == 1) printf("Pr%d", aux->process);
			if (a == 1) fprintf(fp, "Pr%d\t\t\t", aux->process);
			if (anterior != atual) {
				oper = 0;
			}
			else {
				oper = 1;
			}
			if (oper == 0 && tem == 1) printf(")");
			if (oper == 0 && tem == 1) fprintf(fp, ")");
			if (oper == 0) {
				anterior = atual;
				printf("\t\t(%d", aux->maquina);
				fprintf(fp, "\t\t(%d", aux->maquina);
				anterior = aux->operacoes;
				tem = 0;
			}
			if (atual == anterior && oper == 1) {
				anterior = atual;
				printf(",%d", aux->maquina);
				fprintf(fp, ",%d", aux->maquina);
				anterior = aux->operacoes;
				tem = 1;
				if (a == contador) printf(")\n");
				if (a == contador) fprintf(fp, ")\n");
			}
			a++;
		}
		//!guarda no ficheiro os tempos 
		atual = 0;
		anterior = 0; oper = 0; saida = 0; tem = 0;
		a = 1;
		while (a <= contador) {
			aux = inicio;
			for (int i = 1; i < (contador + 1 - a); i++) {
				aux = aux->seguinte;
			}
			saida++;
			atual = aux->operacoes;
			if (a == 1) printf("\t");
			if (a == 1) fprintf(fp, "\t\t\t\t");
			if (anterior != atual) {
				oper = 0;
			}
			else {
				oper = 1;
			}
			if (oper == 0 && tem == 1) printf("]");
			if (oper == 0 && tem == 1) fprintf(fp, "]");
			if (oper == 0) {
				anterior = atual;
				printf("\t\t[%d", aux->tempo);
				fprintf(fp, "\t\t[%d", aux->tempo);
				anterior = aux->operacoes;
				tem = 0;
			}
			if (atual == anterior && oper == 1) {
				anterior = atual;
				printf(",%d", aux->tempo);
				fprintf(fp, ",%d", aux->tempo);
				anterior = aux->operacoes;
				tem = 1;
				if (a == contador) printf("]\n");
				if (a == contador) fprintf(fp, "]\n");
			}
			a++;
		}
		fclose(fp);
		textcolor(GREEN);
		printf("\n\n                      Ficheiro guardado");
		textcolor(WHITE);
		printf("\n\n                  Tecla enter para continuar");
	}
	else {
		textcolor(RED);
		printf("\n\n\n\t\t\tLista vazia, não é possivel gravar no ficheiro %s",ficheiro);
		textcolor(WHITE);
		free(menor);
	}

}
