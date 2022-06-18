// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
// Ricardo Almeida de Aguiar Tavares - 2021144652


#include "ficheiros.h"

int existeFicheiro(char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "rb")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}




ptrJogadas Le_jogadas_texto(ptrJogadas jogadas){
    FILE *file;
    ptrJogadas aux = NULL;
    aux = malloc(sizeof (jogadas));
    if (aux == NULL) {
        printf("\nErro ao alocar memoria!");
        return jogadas;
    }
    file=fopen("jogadas.txt", "rt");
    if(file==NULL){
        printf("\nNao foi possivel abrir ficheiro\n");
        return jogadas;
    }
     while(fscanf(file, "%s %d %d %d", aux->nome_jogador, &aux->posicao_i, &aux->posicao_j, &aux->num_tabuleiro)>1){
        aux->prox = NULL;
        jogadas = insereJogadas(jogadas, aux);

        aux = malloc(sizeof (jogadas));
        if (aux == NULL) {
            printf("\nErro ao alocar memoria!");
            return jogadas;
        }
     }
    fclose(file);
    return jogadas;
}

ptrJogadas Le_jogadas(ptrJogadas jogadas){
    FILE *file;
    ptrJogadas aux = NULL;
    aux = malloc(sizeof (jogadas));
    if (aux == NULL) {
        printf("\nErro ao alocar memoria!");
        return jogadas;
    }
    file=fopen("jogadas.txt", "rb");
    if(file==NULL){
        printf("\nNao foi possivel abrir ficheiro\n");
        return jogadas;
    }
     while(fread(&aux, sizeof (jogadas), 1, file)>=1){
        aux->prox = NULL;
        jogadas = insereJogadas(jogadas, aux);

        aux = malloc(sizeof (jogadas));
        if (aux == NULL) {
            printf("\nErro ao alocar memoria!");
            return jogadas;
        }
     }
    fclose(file);
    return jogadas;
}

void Escreve_jogadas_texto(ptrJogadas jogadas, char *nome_ficheiro){
    FILE *file;
    ptrJogadas percorre = jogadas;
    file=fopen(nome_ficheiro, "wt");
    if(file==NULL){
        printf("\nNao foi possivel abrir ficheiro\n");
        return ;
    }
    while(percorre != NULL){
        fprintf(file, "O jogador %s fez a jogada na posicao (%d,%d) do tabuleiro %d \n", percorre->nome_jogador, percorre->posicao_i, percorre->posicao_j, percorre->num_tabuleiro);
        percorre = percorre->prox;
    }

    fclose(file);
    return ;
}

void Escreve_jogadas_bin(ptrJogadas jogadas, char *nome_ficheiro){
    FILE *file;
    ptrJogadas percorre = jogadas;
    file=fopen(nome_ficheiro, "wb");
    if(file==NULL){
        printf("\nNao foi possivel abrir ficheiro\n");
        return ;
    }
    while(percorre != NULL){
        fwrite(&percorre, sizeof (jogadas), 1, file);
        percorre = percorre->prox;
    }

    fclose(file);
    return ;
}
