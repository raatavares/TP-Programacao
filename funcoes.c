// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
// Ricardo Almeida de Aguiar Tavares - 2021144652

#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

//Mostra o Tabuleiro
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
        for(tab=3; tab<N*2; tab++){
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
        for(tab=6; tab<N*3; tab++){
            for(col=0; col<N; col++){
                printf("%c ", getPos(tabuleiro->mini_tab[tab].tab, lin, col));
            }
            printf("       ");
        }
        printf("\n");
    }
}

int disponibilidadeMiniTab(ptrMini_tabuleiro mini_tabuleiro){
    for(int i=0; i<N; i++){
        for(int e=0; e<N; e++){
            if(getPos(mini_tabuleiro->tab, i, e) == '_')
                return 1;
        }
    }
    return 0;
}

int disponibilidadeTabInteiro(ptrTabuleiro tabuleiro){
    for(int i=0; i<T; i++){
            if(disponibilidadeMiniTab(&tabuleiro->mini_tab[i]) == 1)
                return 1;
    }
    return 0;
}

char validarVencedorMiniTab(ptrMini_tabuleiro mini_tabuleiro){
    //LINHA
    for(int e=0; e<N; e++){
        if(getPos(mini_tabuleiro->tab, e, 0) == getPos(mini_tabuleiro->tab, e, 1) && getPos(mini_tabuleiro->tab, e, 1) == getPos(mini_tabuleiro->tab, e, 2))
            return getPos(mini_tabuleiro->tab, e, 0);
    }
    //COLUNA
    for(int i=0; i<N; i++){
        if(getPos(mini_tabuleiro->tab, 0, i) == getPos(mini_tabuleiro->tab, 1, i) && getPos(mini_tabuleiro->tab, 1, i) == getPos(mini_tabuleiro->tab, 2, i))
            return getPos(mini_tabuleiro->tab, 0, i);
    }
    //DIAGONAIS
    if(getPos(mini_tabuleiro->tab, 0, 0) == getPos(mini_tabuleiro->tab, 1, 1) && getPos(mini_tabuleiro->tab, 1, 1) == getPos(mini_tabuleiro->tab, 2, 2))
            return getPos(mini_tabuleiro->tab, 0, 0);
    if(getPos(mini_tabuleiro->tab, 2, 0) == getPos(mini_tabuleiro->tab, 1, 1) && getPos(mini_tabuleiro->tab, 1, 1) == getPos(mini_tabuleiro->tab, 0, 2))
            return getPos(mini_tabuleiro->tab, 2, 0);
    return '_';
}

char validarVencedorTabuleiro(ptrTabuleiro tabuleiro){
    //LINHA
    for(int e=0; e<N; e++){
        if(validarVencedorMiniTab(&tabuleiro->mini_tab[0+e]) == validarVencedorMiniTab(&tabuleiro->mini_tab[1+e]) && validarVencedorMiniTab(&tabuleiro->mini_tab[1+e]) == validarVencedorMiniTab(&tabuleiro->mini_tab[2+e]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[0+e]);
    }
    //COLUNA
    for(int i=0; i<N; i++){
        if(validarVencedorMiniTab(&tabuleiro->mini_tab[i]) == validarVencedorMiniTab(&tabuleiro->mini_tab[i+3]) && validarVencedorMiniTab(&tabuleiro->mini_tab[i+3]) == validarVencedorMiniTab(&tabuleiro->mini_tab[i+6]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[i]);
    }
    //DIAGONAIS
    if(validarVencedorMiniTab(&tabuleiro->mini_tab[0]) == validarVencedorMiniTab(&tabuleiro->mini_tab[4]) && validarVencedorMiniTab(&tabuleiro->mini_tab[4]) == validarVencedorMiniTab(&tabuleiro->mini_tab[8]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[0]);
    if(validarVencedorMiniTab(&tabuleiro->mini_tab[2]) == validarVencedorMiniTab(&tabuleiro->mini_tab[4]) && validarVencedorMiniTab(&tabuleiro->mini_tab[4]) == validarVencedorMiniTab(&tabuleiro->mini_tab[6]))
            return validarVencedorMiniTab(&tabuleiro->mini_tab[2]);
    return '_';
}

//valida se o tabuleiro a jogar � valido, se nao for gera uma um aleatorio
int tabuleiro_ajogar( ptrTabuleiro tabuleiro, int posicao){
    int random;
    if(posicao != -1 && disponibilidadeMiniTab(&tabuleiro->mini_tab[posicao]) != 0 && validarVencedorMiniTab(&tabuleiro->mini_tab[posicao]) == '_')
        return posicao;
    do{
        random = intUniformRnd(0,8);
    }while(disponibilidadeMiniTab(&tabuleiro->mini_tab[random]) == 0);
    return random;
}

// Insere uma jogada na lista ligada das jogadas

ptrJogadas insereJogadas(ptrJogadas jogadas,ptrJogadas aux){
    ptrJogadas novo = malloc(sizeof (jogadas)), percorre;
    if (novo == NULL) {
        printf("\nErro ao alocar memoria!");
        return jogadas;
    }
    novo->num_tabuleiro=aux->num_tabuleiro;
    novo->posicao_i=aux->posicao_i;
    novo->posicao_j=aux->posicao_j;
    strcpy(novo->nome_jogador,aux->nome_jogador);
    novo->prox=NULL;
    if(jogadas == NULL){
        jogadas = novo;
    }else{
        percorre=jogadas;
        while(percorre->prox != NULL){
            percorre=percorre->prox;
        }
        percorre->prox = novo;
    }
    return jogadas;
}

//Percorre a lista ligada das jogadas e mostra
void mostra_jogadas(ptrJogadas jogadas){
    ptrJogadas percorre;
    percorre = jogadas;
    while(percorre != NULL){
        printf(" \n %s %d %d %d", percorre->nome_jogador, percorre->posicao_i, percorre->posicao_j, percorre->num_tabuleiro);
        percorre = percorre->prox;
    }
}
