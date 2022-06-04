// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022


#include "matdin.h"
#include "main.h"
#include "utils.h"

/*
int limpar(ptrTabuleiro tabuleiro){
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

void mostra(ptrTabuleiro tabuleiro){
    int tab, lin, col;
    for(lin=0; lin<N; lin++){
        for(tab=0; tab<N; tab++){
            for(col=0; col<N; col++){
                printf("%c ", getPos(tabuleiro->mini_tab[tab].tab, lin, col));
            }
            printf("       ");
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for(lin=0; lin<N; lin++){
        for(tab=0; tab<N; tab++){
            for(col=0; col<N; col++){
                printf("%c ", getPos(tabuleiro->mini_tab[tab].tab, lin, col));
            }
            printf("       ");
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for(lin=0; lin<N; lin++){
        for(tab=0; tab<N; tab++){
            for(col=0; col<N; col++){
                printf("%c ", getPos(tabuleiro->mini_tab[tab].tab, lin, col));
            }
            printf("       ");
        }
        printf("\n");
    }
}


//Ricardo

void limparTabuleiro(ptrTabuleiro tabuleiro){
    for(int i=0; i<T; i++){
            for(int j=0; j<N; j++){
                for(int h=0; h<N; h++){
                    setPos(tabuleiro->mini_tab[i].tab, j, h, ' ');
                }
            }
    }
}

int disponibilidadeMiniTab(ptrMini_tabuleiro mini_tabuleiro){
    for(int i=0; i<N; i++){
        for(int e=0; e<N; e++){
            if(getPos(mini_tabuleiro, i, e) == ' ')
                return 1;
        }
    }
    return 0;
}

int disponibilidadeTabInteiro(ptrTabuleiro tabuleiro){
    ptrMini_tabuleiro aux;
    for(int i=0; i<T; i++){
            if(disponibilidadeMiniTab(&tabuleiro->mini_tab[i]) == 1)
                return 1;
    }
    return 0;
}

char validarVencedorMiniTab(ptrMini_tabuleiro mini_tabuleiro){
    for(int e=0; e<N; e++){
        if(getPos(mini_tabuleiro, e, 0) == getPos(mini_tabuleiro, e, 1) == getPos(mini_tabuleiro, e, 2))
            return getPos(mini_tabuleiro, e, 0);
    }
    for(int i=0; i<N; i++){
        if(getPos(mini_tabuleiro, 0, i) == getPos(mini_tabuleiro, 1, i) == getPos(mini_tabuleiro, 2, i))
            return getPos(mini_tabuleiro, 0, i);
    }
    if(getPos(mini_tabuleiro, 0, 0) == getPos(mini_tabuleiro, 1, 1) == getPos(mini_tabuleiro, 2, 2))
            return getPos(mini_tabuleiro, 0, 0);
    if(getPos(mini_tabuleiro, 2, 0) == getPos(mini_tabuleiro, 1, 1) == getPos(mini_tabuleiro, 0, 2))
            return getPos(mini_tabuleiro, 2, 0);
    return ' ';
}

char validarVencedorTabuleiro(ptrTabuleiro tabuleiro){
    for(int e=0; e<N; e+3){
        if(validarVencedorMiniTab(&tabuleiro->mini_tab[0+e]) == validarVencedorMiniTab(&tabuleiro->mini_tab[1+e]) == validarVencedorMiniTab(&tabuleiro->mini_tab[2+e]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[0+e]);
    }
    for(int i=0; i<N; i++){
        if(validarVencedorMiniTab(&tabuleiro->mini_tab[i]) == validarVencedorMiniTab(&tabuleiro->mini_tab[i+3]) == validarVencedorMiniTab(&tabuleiro->mini_tab[i+6]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[i]);
    }
    if(validarVencedorMiniTab(&tabuleiro->mini_tab[0]) == validarVencedorMiniTab(&tabuleiro->mini_tab[4]) == validarVencedorMiniTab(&tabuleiro->mini_tab[8]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[0]);
    if(validarVencedorMiniTab(&tabuleiro->mini_tab[2]) == validarVencedorMiniTab(&tabuleiro->mini_tab[4]) == validarVencedorMiniTab(&tabuleiro->mini_tab[6]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[2]);
    return ' ';
}










int main(int argc, char** argv){
    ptrTabuleiro tabuleiro = NULL;
    tabuleiro=realloc(tabuleiro, sizeof(tabuleiro));
    if(tabuleiro==NULL){
        printf("Erro de alocacao de memoria!");
        return 0;
    }

    ptrMini_tabuleiro mini_tabuleiro = NULL;
    mini_tabuleiro=realloc(mini_tabuleiro, sizeof(mini_tabuleiro)*N*N);
    if(mini_tabuleiro==NULL){
        printf("Erro de alocacao de memoria!");
        return 0;
    }
    tabuleiro->mini_tab=mini_tabuleiro;

    for(int i=0; i<T; i++){
        tabuleiro->mini_tab[i].tab = criaMat(N, N);
    }

    mostra(tabuleiro);
    return (EXIT_SUCCESS);
}




