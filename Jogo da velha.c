#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void emptyBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
}

void showBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c ",board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---|---|---\n");
    }
}

int checkWinning(){
    for(int i= 0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }

    for(int i=0;i<3;i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

int draw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void play(int player){
    int row,col;
    char mark = (player == 1) ? 'X' : 'O';

    while(1){
        printf("\n\tJogador %d, digite a linha(1-3) e a coluna(1-3)\n",player);
        if(scanf("%d %d",&row,&col) != 2){
            printf("\nPosicao invalida, digite novamente");

            while(getchar() != '\n');
            continue;
        }
        row--;col--;

        if(row < 0 || row >= 3 || col < 0 || col >= 3){
            printf("\nPosicao invalida, digite os numeros entre 1 e 3");
            continue;
        }
        if(board[row][col] != ' '){
            printf("\nPosicao ja escolhida, digite outra posicao");
            continue;
        }
        board[row][col] = mark;
        break;
    }
}


int main(){
    int player,winner;
    char keep;

    do{
    player = 1;
    winner = 0;

    printf("\t---------JOGO DA VELHA---------\n\n");
    emptyBoard();
    while(!winner && !draw()){
        showBoard();
        play(player);
        winner =checkWinning();
        if(!winner)
            player = (player % 2) + 1;
    }

    showBoard();
    if(winner)
        printf("\nParabens o jogardor %d ganhou", player);
    else
        printf("\nihh deu velha");

    printf("\nQuer jogar novamente digite 'y' se quiser parar digite 'n'\n");
    while(getchar() != '\n')
    scanf("%c",&keep);

    }while(keep == 'y');

    return 0;
}
