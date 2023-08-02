// name: Daniel Borg
// unikey: dbor3200
// SID: 510426383
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII_VALUE_A 65 //value of 'A' in ascii
#define SIZE 19 // this is the size of the board. (there are 19 blocks per row and coloumn)
#define BLOCK_AMOUNT SIZE*SIZE //the amount of individual squares there are on the board. 
#define MAX_INPUT_SIZE 20
#define TRUE 1
#define FALSE 0
char array[SIZE][SIZE];
char history_array[BLOCK_AMOUNT * 2][3];


// enum use this enum to denote black and white players. 
//black goes first.



enum colour{
    BLACK,
    WHITE
};

struct player{
    enum colour shade;
    char symbol;
    char letter;
};

//setup functions.
int board_setup(){ //initialization of array "empty board".
    for(int y = 0; y < SIZE; y++){
        for(int x = 0; x < SIZE; x++){
            array[y][x] = '.';
        }
    }
    return 0;
}

struct player player_setup(enum colour shade, char symbol, char letter){ /*sets up a player. returns the set up player.
    letter is simply a single character denoting the first letter of the colour.*/
    struct player one;
    one.shade = shade;
    one.symbol = symbol;
    one.letter = letter;
    return one;
}
//winner functions.
/*checks the board for any potential winners, simply calls all the other winning check functions.
returns 0 if there is no winner and 1 if there is a winner. */
int s_check(int y, int x, char symbol){ //return true if the symbol is the same as the one found at the coordinates provided otherwise false. 
    if(array[y][x] == symbol){
        return TRUE;
    }
    return FALSE;
}


// //winning check functions. //all functions in this block return 0 if there is no win and 1 if there is a win.
int horizontal(struct player * current_player){ //checks board for whether player has won the game by placing pieces horizontally.
    for(int x = 0; x < SIZE - 5; x++){
        for(int y = 0; y < SIZE; y++){
            if(s_check(y,x,current_player->symbol) && s_check(y,x + 1 ,current_player->symbol) && s_check(y,x + 2,current_player->symbol) && s_check(y,x + 3,current_player->symbol) && s_check(y,x + 4,current_player->symbol)){
                return TRUE;
            }
        }
    }
    return FALSE;
}

// int little_check(struct player * current_player){
//     printf("input: %c\n",array[0][0]);
//     printf("input: %c\n",array[0][1]);
//     printf("input: %c\n",array[0][2]);
//     printf("input: %c\n",array[0][3]);
//     printf("input: %c\n",array[0][4]);
//     printf("hello: %d\n",s_check(0,0,current_player->symbol) && s_check(0,0 + 1 ,current_player->symbol) && s_check(0,0 + 2,current_player->symbol) && s_check(0,0 + 3,current_player->symbol) && s_check(0,0 + 4,current_player->symbol));
// }


int vertical(struct player * current_player){ //same as horizontal function except vertical. 
    for(int y = 0; y < SIZE - 5; y++){
        for(int x = 0; x < SIZE; x++){
            if(s_check(y,x,current_player->symbol) && s_check(y + 1,x,current_player->symbol) && s_check(y + 2,x,current_player->symbol) && s_check(y + 3,x,current_player->symbol) && s_check(y + 4,x,current_player->symbol)){
                return TRUE;
            }
        }
    }    
    return FALSE;
}

int diagonal(struct player * current_player){
    for(int y = 0; y < SIZE - 4; y++){ //from bottom right to high left?
        for(int x = 0; x < SIZE - 4; x++){
            if(s_check(y,x,current_player->symbol) && s_check(y + 1,x + 1,current_player->symbol) && s_check(y + 2,x + 2,current_player->symbol) && s_check(y + 3,x + 3,current_player->symbol) && s_check(y + 4,x + 4,current_player->symbol)){
                // printf("aloha");
                return TRUE;
            }
        }
    }    
    for(int y = 4; y < SIZE; y++){ //from bottom left to high right? 
        for(int x = 0; x < SIZE - 4; x++){
            //you could put a check here to make sure everything is valid. 
            if(s_check(y,x,current_player->symbol) && s_check(y - 1,x + 1,current_player->symbol) && s_check(y - 2,x + 2,current_player->symbol) && s_check(y - 3,x + 3,current_player->symbol) && s_check(y - 4,x + 4,current_player->symbol)){
                // printf("goodmorning");
                return TRUE;
            }
        }
    }   
    return FALSE;
}

int victor_check(struct player * current_player){ //checks the board for any potential winners, simply calls all the other winning check functions.
    if(vertical(current_player) + horizontal(current_player) + diagonal(current_player) > 0){
        //essentially if anyone one of the functions return true the whole function returns true.
        if(current_player->shade == BLACK){
            printf("Black wins!\n");
        }else{
            printf("White wins!\n");
        }
        return TRUE;
    } 
    return FALSE;
}

int draw_check(){
    for(int y = SIZE - 1; y >= 0; y--){
        for(int x = 0; x < SIZE; x++){
            if(array[y][x] == '.'){
                return FALSE;
            }
        }
    }
    return TRUE; //this means there is a draw (all spaces are occupied).
}



//functions to help test.
// int print_out(){
//     for(int y = SIZE - 1; y >= 0; y--){ // SIZE - 1 is because we don't want the index we want actual number of row. 
//         printf("\n%d ",y + 1); // this is for the side panel of numbers. and the newline for each row of array. 
//         for(int x = 0; x < SIZE; x++){
//             printf("%c ", array[y][x]);
//         }
//     }
//     printf("\n  ");
//     for(int z = 0; z < SIZE; z++){ // this is for the bottom panel of letters. 
//         printf("%c ",ASCII_VALUE_A + z);
//     }
//     printf("\n");
//     return 0;
// }

//command functions. 
char who(struct player *player_variable){ //
    return player_variable->letter;
}

int term(){ // 
    exit(1);
}



int history_setup(){
    for(int i = 0; i < BLOCK_AMOUNT * 2; i++){
        history_array[i][0] = '.';
        history_array[i][1] = '.';
        history_array[i][2] = '.';
    }
    return 0;
}

int history_print(){
    int t = 0;
    for(int i = 0; i < BLOCK_AMOUNT * 2; i++){
        if(history_array[i][0] == '.'){
            break;
        }
        t = 1;
        if(history_array[i][2] == '.'){
            printf("%c%c",history_array[i][0],history_array[i][1]);
        }else{
            printf("%c%c%c",history_array[i][0],history_array[i][1],history_array[i][2]);
        }
    }
    if(t){
        printf("\n");
    }
    return 0;
}

int history_add(char * a, char * one){
    int i = 0;
    for(; i < BLOCK_AMOUNT * 2; i++){
        if(history_array[i][0] == '.'){
            history_array[i][0] = *a;
            int numeric = atoi(one);
            if(numeric > 9){
                history_array[i][1] = one[0];
                history_array[i][2] = one[1];
                break;
            }
            history_array[i][1] = *one;
            break;
        }
    }
    return 0;
}

int view_print(int x_coordinate,int y_coordinate){
    for(int k = 3; k >= -3; k--){
        for(int i = -3; i <= 3; i++){
            if(x_coordinate + i >= SIZE || x_coordinate + i < 0 || y_coordinate + k >= SIZE || y_coordinate + k < 0){
                printf("x");
            }else{
                printf("%c",array[y_coordinate + k][x_coordinate + i]);
            }
        }
    }
    printf("\n");

    return 0;
}

int view(int mist_centre[2],int * initial){
    if(*initial){
        printf("J10,.................................................\n");
        return 0;
    }
    int mist_value_temp = mist_centre[0] + 1;
    int x = mist_value_temp;
    int y = mist_centre[1];
    int x_coordinate = 1 + ((5 * ((x) * (x))) + (3 * (x)) + 4) % 19;
    int y_coordinate = 1 + ((4 * ((y)*(y))) + (2 * (y)) -4) % 19;
    char letter_map[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'};
    char letter = '0';
    for(int index = 0; index <= SIZE; index++){
        if(x_coordinate == index){
            letter = letter_map[index-1];
            break;
        }
    }

    printf("%c%d,",letter,y_coordinate);
    view_print(x_coordinate -1, y_coordinate-1);
    *initial = FALSE;
    return 0;

}

int place(char* coordinates, struct player *current_player,int mist_centre[2]){ //check for arguments for this function. (coordinates required i believe)
    char letter_map[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'};
    int column = 0;
    char history_letter;

    if(coordinates[0] == 10 || coordinates[0] == 0){ //kind of tested.
        printf("Invalid!\n");
        return 0;
    }
    for(int i = 0; i <= SIZE; i++){
        if(i == SIZE){ //tested
            printf("Invalid coordinate\n");
            return 0;
        }
        if(coordinates[0] == letter_map[i]){
            history_letter = letter_map[i]; //getting the letter so it can be added to the history array.
            column = i;
            mist_centre[0] = column;
            break;
        }
    }
    
    if(coordinates[1] == '0'){ //this is to deal with inputs like A02 etc.
        printf("Invalid coordinate\n"); //tested.
        return 0;
    }
    if(coordinates[1] < 49 || coordinates[1] > 57){ //tested.
        printf("Invalid coordinate\n");
        return 0;
    }
    if((coordinates[2] < 48 || coordinates[2] > 57) && coordinates[2] != 10 /* && coordinates[3] != 10 */){ //tested.
        printf("Invalid coordinate\n");
        return 0;
    }

    int row = atoi(&coordinates[1]) - 1;

    if(column >= SIZE || row >= SIZE || column < 0 || row < 0){ //coloumn must be within limits of map. //tested.
        printf("Invalid coordinate\n");
        return 0;
    }
    if(array[row][column] != '.'){ //tested.
        printf("Occupied coordinate\n");
        return 0;
    }
    array[row][column] = current_player->symbol;

    history_add(&history_letter,&coordinates[1]);
    mist_centre[1] = row + 1;
    return 1;
} //YOU MUST ACCOUNT FOR THE CASE THAT A SYMBOL IS PLACED ON TOP OF ANOTHER SYMBOL.

void resign(struct player * current_player){
    if(current_player->shade == BLACK){
        printf("White wins!\n");

    }else{
        printf("Black wins!\n"); //tested.
    }
}

//====================================================================================================
void larger_than_life(char input[MAX_INPUT_SIZE],int * boolean, int * other_word_counter){
    while(fgets(input, MAX_INPUT_SIZE, stdin) != NULL){
        for(int i = 0; i < MAX_INPUT_SIZE; i++){
            if(input[i] == ' '){
                *other_word_counter += 1;
            }

        }
        if(input[strlen(input) - 1] == '\n'){
            if(*boolean == TRUE && *other_word_counter == 1){
                printf("Invalid coordinate\n");
                return;
                }
            else{
                printf("Invalid!\n");
                return;
            }
        }

    }
}

    // if(*boolean == TRUE && *other_word_counter == 1){
    //     printf("ola\n");
    //     printf("Invalid coordinate\n");
    //     return;
    //     }
    // else{
    //     printf("hooha\n");
    //     printf("Invalid!\n");
    //     getchar();
    //     return;
//====================================================================================================

int input_parser(char input[MAX_INPUT_SIZE],char* parsed_input[2]){ //parses input, return 1 if success 0 otherwise.
    fflush(stdin);
    if(fgets(input, MAX_INPUT_SIZE, stdin) == NULL){ //checks that input was given at all. 
        term();
    }
//====================================================================================
    int boolean = FALSE;
    if(input[0] == 'p' &&
        input[1] == 'l' &&
        input[2] == 'a' &&
        input[3] == 'c' &&
        input[4] == 'e' &&
        input[5] == ' '){
            boolean = TRUE;
        }
    int other_word_counter = 0;
    for(int i = 0; i < MAX_INPUT_SIZE; i++){
        if(input[i] == ' '){
            other_word_counter++;
        }
    }

    for(int i = 0; input[i] > 33 || input[i] != 10; i++){
        if(i == MAX_INPUT_SIZE - 2){
            larger_than_life(input,&boolean,&other_word_counter);
            return 0;
        }
    }

//=======================================================================================

    if(input[0] == ' '){ //this has been tested.
        printf("Invalid!\n");
        return 0;
    }

    int word_counter = 1;
    for(int i = 0; input[i] != 0; i++){ // this checks the amount of words in input. 
        if(input[i] == ' '){
            word_counter++;
        }
    }

    parsed_input[0] = strtok(input, " "); //first word in input.

    if(word_counter == 2 && strcmp(parsed_input[0],"place") == 0){ /*must check special case for 'place' function
    whereby a second argument (the coordinates are required).*/
        parsed_input[1]  = strtok(NULL, " ");

        return 1;
    }
    
    if(word_counter > 1){ //tested.
        printf("Invalid!\n");
        return 0;    
    }
    return 1;
}
struct player * change_current_player(struct player * current_player, struct player * black, struct player * white){//changing player after every turn. 
    if(current_player->shade == WHITE){ 
        current_player = black;
    }else if(current_player->shade == BLACK){
        current_player = white;
    }
    return current_player;
}

int main(){
    // array[10][10] = 'x'; //only for testing
    struct player black = player_setup(BLACK, '#', 'B');
    struct player white = player_setup(WHITE, 'o', 'W'); 
    char* parsed_input[2];
    char input[MAX_INPUT_SIZE];
    int mist_centre[2] = {0,10};
    int initial = TRUE;
    board_setup();
    history_setup();
    struct player *current_player = &black; /* initially
    set to white but will immediatley turn to black at first turn as per the notification instruction.*/
    int turn_finished = FALSE;
    int draw = FALSE;
    while(victor_check(current_player) == FALSE){
        if(draw_check() == TRUE){
            draw = TRUE;
            break;
        }
        if(turn_finished == TRUE){
            current_player = change_current_player(current_player, &black, &white);
            turn_finished = FALSE;
        }
        if(input_parser(input,parsed_input) == 0){
            continue;
        }

        if(strcmp(parsed_input[0],"place") == 0){ //performing command based on instruction. 
            if(place(parsed_input[1], current_player,mist_centre) == 0){
                continue;
            }
            // print_out(); //for testing only.
            turn_finished = TRUE;
            initial = FALSE;
        }
        else if(strcmp(parsed_input[0],"resign\n") == 0){
            resign(current_player);
            break;
        }   
        else if(strcmp(parsed_input[0],"who\n") == 0){
            printf("%c\n",who(current_player));
        }  
        else if(strcmp(parsed_input[0],"term\n") == 0){
            // printf("aloha\n");
            term();
        }   
        else if(strcmp(parsed_input[0],"history\n") == 0){
            history_print();
        }  
        else if(strcmp(parsed_input[0],"view\n") == 0){
            view(mist_centre, &initial);
        }  
        // else if(!strcmp(parsed_input[0],"place") /*|| strcmp(parsed_input[0],"place\n") == 0 */){
        //     printf("Invalid!\n");
        //     printf("here?\n");
        // } 
        else{ //this is tested.
            printf("Invalid!\n");
            continue;
        }
    }
    if(draw == FALSE){
        history_print();
        printf("Thank you for playing!\n");
        term();
    }
    else{
        printf("Wow, a tie!\n");
        history_print();
        printf("Thank you for playing!\n");
        term();
    }
}
//===================================================================================================