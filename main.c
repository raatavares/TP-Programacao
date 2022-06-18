// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
// Ricardo Almeida de Aguiar Tavares - 2021144652


#include "matdin.h"
#include "main.h"
#include "utils.h"
#include "ficheiros.h"
#include "funcoes.h"


int main(int argc, char** argv){
    initRandom();
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


    char Continuar_Jogo, Jogo_Solo, nome_Jogador1[20], nome_Jogador2[20], continuar;
    int posicao=-1, i, j, cont_jogadas=0;

    //verifica se ha jogos interrompidos
    if(existeFicheiro(FichInterrupcao)==1){
        do {
            printf("\n Ha um Jogo interrompido, deseja continuar o jogo interrompido? ");
            scanf(" %c", &Continuar_Jogo);
        }while( Continuar_Jogo != 'n' && Continuar_Jogo != 's');
        //if(Continuar_Jogo == 's')
            //Recupera o jogo

        //Remove o ficheiro
    }

    do {
        printf("\n Quer jogar com o computador? ");
        scanf(" %c", &Jogo_Solo);
    }while( Jogo_Solo != 'n' && Jogo_Solo != 's');

    if(Jogo_Solo == 's'){
        printf("\n Insira o nome do Jogador: ");
        scanf(" %s", nome_Jogador1);
        strcpy(nome_Jogador2, "Computador");
    }
    else{
        printf("\n Insira o nome do Jogador 1: ");
        scanf(" %s", nome_Jogador1);
        printf("\n Insira o nome do Jogador 2: ");
        scanf(" %s", nome_Jogador2);
    }

    mostra(tabuleiro);
    while(validarVencedorTabuleiro(tabuleiro) == '_' && disponibilidadeTabInteiro(tabuleiro) == 1){

        cont_jogadas++;

        posicao = tabuleiro_ajogar( tabuleiro, posicao);
        printf("\n Vai Jogar no Mini-Tabuleiro %d", posicao);

        do{
            printf("\n Onde vai Jogar(0-2)(0-2)? ");
            scanf("%d %d", &i, &j);
        }while(i<0 || i>2 || j<0 || j>2 || getPos(tabuleiro->mini_tab[posicao].tab, i, j) != '_');



        if(Jogo_Solo == 'n'){
            if( cont_jogadas%2 != 0)
                setPos(tabuleiro->mini_tab[posicao].tab, i, j, 'X');
            else
                setPos(tabuleiro->mini_tab[posicao].tab, i, j, 'O');
            //posicao=ultima posicao jogada
            posicao=i*3+j;
        }

        //Se for jogo a solo, gera jogada aleatoria
        if(Jogo_Solo != 'n'){
            setPos(tabuleiro->mini_tab[posicao].tab, i, j, 'X');
            //posicao=ultima posicao jogada
            posicao=i*3+j;
            posicao = tabuleiro_ajogar( tabuleiro, posicao);

            do{
                j = intUniformRnd(0,2);
                i = intUniformRnd(0,2);
            }while(getPos(tabuleiro->mini_tab[posicao].tab, i, j) != '_');
            setPos(tabuleiro->mini_tab[posicao].tab, i, j, 'O');
            //posicao=ultima posicao jogada
            posicao=i*3+j;
            posicao = tabuleiro_ajogar( tabuleiro, posicao);
        }

        mostra(tabuleiro);

        do {
        printf("\n Quer continuar o Jogo? ");
        scanf(" %c", &continuar);
        }while( continuar != 'n' && continuar != 's');
        if (continuar == 'n')
            break;
    }

    char nome_ficheiro[20];
    if(continuar == 'n'){
        printf("\n Introduza o nome do ficheiro! ");
        scanf(" %s", nome_ficheiro);
        //guarda jogadas no ficheiro
    }else{
        if(validarVencedorTabuleiro(tabuleiro) == '_')
            printf("\n Empate! ");
        else if(validarVencedorTabuleiro(tabuleiro) == 'X')
            printf("\n Ganhou o Jogador %s", nome_Jogador1);
        else
            printf("\n Ganhou o Jogador %s", nome_Jogador2);
    }


    return (EXIT_SUCCESS);
}



