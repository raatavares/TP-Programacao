#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
// Ricardo Almeida de Aguiar Tavares - 2021144652

#define N 3
#define T N*N
#define FichInterrupcao "jogo.bin"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct mini_tabuleiro mini_tabuleiro, *ptrMini_tabuleiro;

struct mini_tabuleiro{
    char **tab;
};

typedef struct tabuleiro tabuleiro, *ptrTabuleiro;

struct tabuleiro{
    ptrMini_tabuleiro mini_tab; //vetor de 0 a 8
};



typedef struct jogadas jogadas, *ptrJogadas;


struct jogadas{
    char nome_jogador[20];
    int posicao_i, posicao_j;
    int num_tabuleiro;
    ptrJogadas prox;
};

#endif // MAIN_H_INCLUDED
