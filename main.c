// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022


#include "matdin.h"
#include "main.h"
#include "utils.h"
#include "ficheiros.h"

/*
int limpar(ptrTabuleiro tabuleiro){
    for(int i=0; i<N; i++){
        for(int e=0; e<N; e++){
            for(int j=0; j<N; j++){
                for(int h=0; h<N; h++){
                    if(tabuleiro.mini_tab[i][e].tab[j][h] != ' ')
                        tabuleiro.mini_tab[i][e].tab[j][h] = '_';
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


//Ricardo

void limparTabuleiro(ptrTabuleiro tabuleiro){
    for(int i=0; i<T; i++){
            for(int j=0; j<N; j++){
                for(int h=0; h<N; h++){
                    setPos(tabuleiro->mini_tab[i].tab, j, h, '_');
                }
            }
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
    ptrMini_tabuleiro aux;
    for(int i=0; i<T; i++){
            if(disponibilidadeMiniTab(&tabuleiro->mini_tab[i]) == 1)
                return 1;
    }
    return 0;
}

char validarVencedorMiniTab(ptrMini_tabuleiro mini_tabuleiro){
    for(int e=0; e<N; e++){
        if(getPos(mini_tabuleiro->tab, e, 0) == getPos(mini_tabuleiro->tab, e, 1) == getPos(mini_tabuleiro->tab, e, 2))
            return getPos(mini_tabuleiro->tab, e, 0);
    }
    for(int i=0; i<N; i++){
        if(getPos(mini_tabuleiro->tab, 0, i) == getPos(mini_tabuleiro->tab, 1, i) == getPos(mini_tabuleiro->tab, 2, i))
            return getPos(mini_tabuleiro->tab, 0, i);
    }
    if(getPos(mini_tabuleiro->tab, 0, 0) == getPos(mini_tabuleiro->tab, 1, 1) == getPos(mini_tabuleiro->tab, 2, 2))
            return getPos(mini_tabuleiro->tab, 0, 0);
    if(getPos(mini_tabuleiro->tab, 2, 0) == getPos(mini_tabuleiro->tab, 1, 1) == getPos(mini_tabuleiro->tab, 0, 2))
            return getPos(mini_tabuleiro->tab, 2, 0);
    return '_';
}

char validarVencedorTabuleiro(ptrTabuleiro tabuleiro){
    for(int e=0; e<N; e++){
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
    return '_';
}

int tabuleiro_ajogar( ptrTabuleiro tabuleiro, int posicao){
    int random;
    if(posicao == -1 || disponibilidadeMiniTab(&tabuleiro->mini_tab[posicao]) == 0){
        do{
            random = intUniformRnd(0,8);
        }while(disponibilidadeMiniTab(&tabuleiro->mini_tab[random]) == 0);
        posicao=random;
    }
    return posicao;
}








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
    if(validarVencedorTabuleiro(tabuleiro) == '_' && disponibilidadeTabInteiro(tabuleiro) == 1)
        printf("Sem vencedor\n");

    while(validarVencedorTabuleiro(tabuleiro) == '_' && disponibilidadeTabInteiro(tabuleiro) == 1){
        mostra(tabuleiro);
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
        }
        //posicao=ultima posicao jogada
        //Se for jogo a solo, gera jogada aleatoria

        do {
        printf("\n Quer continuar o Jogo? ");
        scanf(" %c", &continuar);
        }while( continuar != 'n' && continuar != 's');
        if (continuar == 'n')
            break;
    }

    //se interronpeu guarda
    //se nao
    if(validarVencedorTabuleiro(tabuleiro) == '_')
        printf("\n Empate! ");
    else if(validarVencedorTabuleiro(tabuleiro) == 'X')
        printf("\n Ganhou o Jogador %s", nome_Jogador1);
    else
        printf("\n Ganhou o Jogador %s", nome_Jogador2);


    return (EXIT_SUCCESS);
}



