#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

FILE* fp;//!Definição do ficheiro
//!*Definição das funções e procedimentos
Jobs* inserirInicio(Jobs* inicio, int Estado, int Processo, int Operacao, int Maquina, int Tempo);
Jobs* inserirFim(Jobs* inicio, int Estado, int Processo, int Operacao, int Maquina, int Tempo);
Jobs* repetir(Jobs* inicio, int Tempo, int Posicao);
Jobs* NovoRegistoInicio(Jobs* inicio);
Jobs* NovoRegistoFim(Jobs* inicio);
Jobs* ler(char ficheiro[]);
Jobs* inverteLista(Jobs* inicio);
Jobs* altera(Jobs* inicio);
Jobs* remover(Jobs* inicio);
Jobs* RemoveRegisto(Jobs* inicio, int registo);
Jobs* ordenaLista(Jobs* inicio);
Jobs* ordenaListaCrescente(Jobs* inicio);
int verificaOperacao(Jobs* inicio, int operacao, int maquina);
int listar(Jobs* inicio);
void escrever(Jobs* inicio, char ficheiro[]);



