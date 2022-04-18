#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"
void Calculo(Jobs* inicio, int control);
void somas(Jobs* inicio, int estado);
void estadoPoe(Jobs* inicio, int aux1, int maquina, int estado);
void estadoTira(Jobs* inicio, int aux1, int maquina);