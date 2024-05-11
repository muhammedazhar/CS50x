#include <cs50.h>
#include <stdio.h>

void print_rows(int bricks);

int main(void){
    // Prompt the user for the pyramid's height
    int height;
    do {
        height = get_int("Height: ");
    } while (height < 1);
    for(int i = 0; i < height; i++){
        print_rows(i + 1);
    }
}

void print_rows(int bricks){
    for(int i = 0; i < bricks; i++){
        printf("#");
    }
    printf("\n");
}