// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
// Ricardo Almeida de Aguiar Tavares - 2021144652

#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int existeFicheiro(char *fname);

ptrJogadas Le_jogadas(ptrJogadas jogadas);

ptrJogadas Le_jogadas_texto(ptrJogadas jogadas);

void Escreve_jogadas_texto(ptrJogadas jogadas, char *nome_ficheiro);

void Escreve_jogadas_bin(ptrJogadas jogadas, char *nome_ficheiro);
