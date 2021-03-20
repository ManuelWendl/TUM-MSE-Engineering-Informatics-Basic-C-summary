#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Enums

enum symb{
    NONE,
    CROSS,
    CIRCLE,
    INGAME,
    TIED
};

// Structures

struct Board{
    char field[3][3];
};

struct Game{
    struct Board board;
    unsigned int count;
};

// Functions

void display_game(struct Game g){
    printf("Move Number %d \n-------------------- \n",g.count);
    for(int i=0;i<3;i++){
        for(int ii=0;ii<3;ii++){
            printf("|");
            switch (g.board.field[i][ii]){
                case CROSS:
                    printf("X");
                    break;
                case CIRCLE:
                    printf("O");
                    break;
                case NONE:
                    printf(" ");
                    break;
            }
        }
        printf("|");
        printf("\n");
        printf("-------");
        printf("\n");
    }
    printf("---------------------");
    printf("\n");
}

struct Board initialize_board(){
    struct Board *board = calloc(sizeof(*board),1);
    for(int i=0;i<3;i++) {
        for (int ii = 0; ii < 3; ii++) {
            board->field[i][ii] = NONE;
        }
    }
    return *board;
}

struct Game initialize_game(){
    struct Game *game = calloc(sizeof(*game),1);
    game->board = initialize_board();
    game->count = 0;
    return *game;
}

void move(struct Game *g){
    printf("It's your turn");

    int input1;
    do {
        printf("Please enter line number (between 1,3): ");
        fflush(stdin);
        scanf("%1d", &input1);
    }while(input1 < 1 || input1 > 3);
    int input2;
    do {
        printf("Please enter column number (between 1,3): ");
        fflush(stdin);
        scanf("%1d", &input2);
    }while(input2 < 1 || input2 > 3);
    if(g->board.field[input1-1][input2-1]!= NONE){
        printf("\n Field already occupied. Please enter other field. \n");
        move(g);
    }else{
        g->board.field[input1-1][input2-1] = CIRCLE;
        g->count++;
    }
}

int board_full(struct Game g){
    int boolean = 1;
    for(int i = 0;i<3;i++){
        for (int ii = 0; ii < 3; ++ii) {
            if(g.board.field[i][ii] == NONE)
            {
                boolean = 0;
            }
        }
    }
    return boolean;
}

enum symb checkwinner(struct Game g) {
    for (int i = 0; i < 3; i++) {
        if (g.board.field[i][0] == g.board.field[i][1] && g.board.field[i][0] == g.board.field[i][2]) {
            if (g.board.field[i][0] != NONE)
                return g.board.field[i][0];
        } else if (g.board.field[0][i] == g.board.field[1][i] && g.board.field[0][i] == g.board.field[2][i]) {
            if (g.board.field[0][i] != NONE)
                return g.board.field[0][i];
        }
    }
    if (g.board.field[0][0] == g.board.field[1][1] && g.board.field[0][0] == g.board.field[2][2]) {
        if (g.board.field[0][0] != NONE)
            return g.board.field[0][0];
    } else if (g.board.field[0][2] == g.board.field[1][1] && g.board.field[0][2] == g.board.field[2][0]) {
        if (g.board.field[0][2] != NONE)
            return g.board.field[0][2];
    }
    if (board_full(g) == 1 || g.count == 9) {
        return TIED;
    } else {
        return INGAME;
    }
}


// AI PROGRAMM ==========================

double minimax(struct Game *g,int isMaximising,double depth){
    enum symb winner = checkwinner(*g);
    if(winner == CROSS){
        double score = 10-depth;
        return score;
    }else if(winner == CIRCLE){
        double score = -10+depth;
        return score;
    }else if(winner == TIED){
        double score = 0.0;
        return score;
    }

    if(isMaximising) {
        double best = -999999999999999;
        for(int i=0;i<3;i++) {
            for (int ii = 0; ii < 3; ++ii) {
                if (g->board.field[i][ii] == NONE) {
                    g->board.field[i][ii] = CROSS;
                    double score = minimax(g, 0, depth + 1);
                    g->board.field[i][ii] = NONE;
                    if (score > best)
                        best = score;
                }
            }
        }
        return best;
    }else{
        double best = 999999999999999;
        for(int i=0;i<3;i++){
            for (int ii=0;ii<3;++ii) {
                if(g->board.field[i][ii] == NONE){
                    g->board.field[i][ii] = CIRCLE;
                    double score = minimax(g,1,depth+1);
                    g->board.field[i][ii] = NONE;
                    if(score < best)
                        best = score;
                }
            }
        }
        return best;
    }
}

void ai_move(struct Game *g){
    double best = -10000;
    int bestmove[2] = {0,0};
    for(int i=0;i<3;i++){
        for(int ii=0;ii<3;ii++){
            if(g->board.field[i][ii] == NONE){
                g->board.field[i][ii] = CROSS;
                double score = minimax(g,0,0);
                printf("Scores:%f move to:%d%d  ",score,i,ii);
                if(score>best) {
                    best = score;
                    bestmove[0] = i;
                    bestmove[1] = ii;
                }
                g->board.field[i][ii] = NONE; //Undo TestMove
            }
        }
    }
    printf("\nbestscore: %f move to: %d%d",best,bestmove[0],bestmove[1]);
    g->board.field[bestmove[0]][bestmove[1]]= CROSS;
    g->count ++;
}

enum symb ai_winner(){
    int input5;
    do {
        printf("Type 1 for human begin or 2 for computer begin.\n");
        fflush(stdin);
        scanf("%1d", &input5);
    }while(input5 <1||input5>2);

    struct Game g = initialize_game();
    enum symb winner;
    if(input5==1) {
        display_game(g);
        for(int i = 1;i<=9;i++) {
            move(&g);
            display_game(g);
            winner = checkwinner(g);
            if(winner != INGAME){
                return winner;
            }
            ai_move(&g);
            display_game(g);
            winner = checkwinner(g);
            if(winner != INGAME){
                return winner;
            }
        }
        return winner;
    }else{
        display_game(g);
        for(int i = 1;i<=9;i++) {
            ai_move(&g);
            display_game(g);
            winner = checkwinner(g);
            if(winner != INGAME) {
                return winner;
            }
            move(&g);
            display_game(g);
            winner = checkwinner(g);
            if(winner != INGAME) {
                return winner;
            }
        }
        return winner;
    }
}

// Main ==============================

int main() {
    enum symb winner;

    winner = ai_winner();

    switch (winner) {
        case CROSS:
            printf("The Winner of This Game is: X");
            break;
        case CIRCLE:
            printf("The Winner of This Game is: o");
            break;
        case TIED:
            printf("Tied Game.");
            break;
        default: break;
    }
    printf("\n==========================================\nEnter 1 if you want to play again.");
    int input3;
    fflush(stdin);
    scanf("%1d", &input3);
    if(input3==1){
        main();
    }
}