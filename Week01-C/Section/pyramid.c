#include <cs50.h>
#include <stdio.h>

void print_rows(int length);

int main(void){
    int height = get_int("Height: ");
    printf("\n");
    for(int i = 0; i < height; i++){
        print_rows(i + 1);
    }
}

void print_rows(int length){
    for(int i = 0; i < length; i++){
        printf("# ");
    }
    printf("\n");
}