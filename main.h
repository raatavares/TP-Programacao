#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#define N 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct mini_tabuleiro{
    char **tab;

} mini_tabuleiro;

struct tabuleiro{
    struct mini_tabuleiro mini_tab[N][N];

};

void mostra(struct tabuleiro tabuleiro);


#endif // MAIN_H_INCLUDED
