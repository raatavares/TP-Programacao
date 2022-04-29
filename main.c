// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022


#include "matdin.h"
#include "main.h"
#include "utils.h"

/*
int limpar(struct tabuleiro tabuleiro){
    for(int i=0; i<N; i++){
        for(int e=0; e<N; e++){
            for(int j=0; j<N; j++){
                for(int h=0; h<N; h++){
                    if(tabuleiro.mini_tab[i][e].tab[j][h] != ' ')
                        tabuleiro.mini_tab[i][e].tab[j][h] = ' ';
                }
            }
        }
    }
}
*/

void mostra(struct tabuleiro tabuleiro){
    for(int i=0; i<N; i++){
        for(int e=0; e<N; e++){
            mostraMat(tabuleiro.mini_tab[i][e].tab,N ,N);
            printf("    ");
        }
        printf("\n");
    }
}

int main(int argc, char** argv){
    struct tabuleiro tabuleiro;

    for(int i=0; i<N; i++){
        for(int e=0; e<N; e++){
            tabuleiro.mini_tab[i][e].tab = criaMat(N, N);
        }
    }

    mostra(tabuleiro);
    return (EXIT_SUCCESS);
}
