#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ASCII_OFFSET 65 // this is not even used. 
#define SIZE 19 // this is the size of the board. 
#define MAX_INPUT_SIZE 10 //this includes a space (for the place command) and a null byter. 
char array[SIZE][SIZE];

// int setup(){ //initialization of array "empty board". 
//     for(int y = 0; y < SIZE; y++){
//         for(int x = 0; x < SIZE; x++){
//             array[y][x] = '.';
//         }
//     }
// }



int print_out(){
    for(int y = SIZE - 1; y >= 0; y--){ // SIZE - 1 is because we don't want the index we want actual number of row. 
        printf("\n%d ",y + 1); // this is for the side panel of numbers. and the newline for each row of array. 
        for(int x = 0; x < SIZE; x++){
            printf("%c ", array[y][x]);
        }
    }
    printf("\n  ");
    for(int z = 0; z < SIZE; z++){ // this is for the bottom panel of letters. 
        printf("%c ",ASCII_OFFSET + z);
    }
    printf("\n");
    return 0;
}

// int place(){

// }

int term(){ // 
    exit(1);
}

int input_parser(char input[MAX_INPUT_SIZE],char* parsed_input[2]){ //parses input, return 1 if success 0 otherwise.
    if(fgets(input, MAX_INPUT_SIZE, stdin) == NULL){ //checks that input was given at all. 
        printf("invalid input\n");
        return 0;
    }
    int word_counter = 1;
    for(int i = 0; i < MAX_INPUT_SIZE; i++){ // this checks the amount of words in input. 
        if(input[i] == ' '){
            printf("goodness");
            word_counter++;
        }
    }
    parsed_input[0] = strtok(input, " "); //first word in input.
    printf("%s",parsed_input[0]);

    if(word_counter == 2 && strcmp(parsed_input[0],"place") == 0){
        printf("yes\n");
        parsed_input[1]  = strtok(NULL, " ");
        return 1;
    }
    else if(strcmp(parsed_input[0],"place\n") == 0){
        printf("invalid input");
        return 0;
    }
    return 1;
}

int place(char* coordinates){ //check for arguments for this function. (coordinates required i believe)
    return 0;
}


int main(){
    char* parsed_input[2];
    char input[MAX_INPUT_SIZE];
    //fgets(input, MAX_INPUT_SIZE, stdin);
    input_parser(input,parsed_input); 
    // printf("%s\n",parsed_input[1]);

    place()

    //testing. 
    // if(strcmp(parsed_input[0],"place") == 0){
    //     printf("scooby\n");
    // }
    // if(strcmp(parsed_input[1],"A1\n") == 0){ //you need to have the newline in there otherwise this won't work. 
    //     printf("hazzah\n");
    // }
    // if(strcmp(parsed_input[0],"who\n") == 0){
    //     printf("who\n");
    // }


    // printf("%s\n",parsed_input[0]);
    // printf("%s",parsed_input + 6);

    // printf("hello: %s\n", *hello);
    // printf("good: %s\n", *good);

    //strtok();
    // int x = scanf("%s%c", hello, &good);
    // int x = scanf("%[^\n]c%[^\n]c",hello, &good);
    // printf("%d\n",x);
    // printf("hello: %d\n",good);
}