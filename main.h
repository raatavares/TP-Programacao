#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#define N 3
#define T N*N

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct mini_tabuleiro mini_tabuleiro, *ptrMini_tabuleiro;

struct mini_tabuleiro{
    char **tab;

};

typedef struct tabuleiro tabuleiro, *ptrTabuleiro;

struct tabuleiro{
    ptrMini_tabuleiro mini_tab;
};

void mostra(ptrTabuleiro tabuleiro);


#endif // MAIN_H_INCLUDED
