#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//!Criação da estrutura da lista ligada
typedef struct obj
{
	int estado;
	int process;
	int operacoes;
	int maquina;
	int tempo;
	struct obj* seguinte;
}Jobs;
