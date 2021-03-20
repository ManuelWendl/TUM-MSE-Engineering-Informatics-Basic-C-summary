#include <stdio.h>
#include <stdlib.h>

// Enums

enum symb{
    NONE,
    CROSS,
    CIRCLE
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

void move(struct Game *g,enum symb *current){
    switch(*current) {
        case CROSS:
            printf("It's the turn of player: X \n");
            break;
        case CIRCLE:
            printf("It's the turn of player: o \n");
            break;
        default:
            break;
    }

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
        move(g,current);
    }else{
        g->board.field[input1-1][input2-1] = *current;
        g->count++;
        if(*current == CROSS)
            *current = CIRCLE;
        else
            *current = CROSS;
    }
}

enum symb checkwinner(struct Game g){
    for(int i = 0;i<3;i++){
        if(g.board.field[i][0] == g.board.field[i][1] && g.board.field[i][0] == g.board.field[i][2]){
            return g.board.field[i][0];
        }else if(g.board.field[0][i] == g.board.field[1][i] && g.board.field[0][i] == g.board.field[2][i]){
            return g.board.field[0][i];
        }
    }
    if(g.board.field[0][0] == g.board.field[1][1] && g.board.field[0][0] == g.board.field[2][2]) {
        return g.board.field[0][0];
    }else if(g.board.field[0][2] == g.board.field[1][1] && g.board.field[0][2] == g.board.field[2][0]) {
        return g.board.field[0][2];
    }else {
        return NONE;
    }
}

enum symb human_winner(){
    struct Game g = initialize_game();
    enum symb currentsymb = CROSS;
    enum symb winner;
    do {
        display_game(g);
        move(&g, &currentsymb);
        winner = checkwinner(g);
    }while(winner == NONE && g.count<9);
    display_game(g);
    return winner;
}


// Main ==============================

int main() {

    enum symb winner;

    winner = human_winner();

    switch (winner) {
        case CROSS:
            printf("The Winner of This Game is: X");
            break;
        case CIRCLE:
            printf("The Winner of This Game is: o");
            break;
        default:
            printf("Tied Game.");
            break;
    }
    printf("\n==========================================\nEnter 1 if you want to play agian.");
    int input3;
    fflush(stdin);
    scanf("%1d", &input3);
    if(input3==1){
        main();
    }
}