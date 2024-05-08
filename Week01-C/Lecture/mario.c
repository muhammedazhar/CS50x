#include <cs50.h>
#include <stdio.h>

int main(void){
    int n;
    // Prompt user for height of block.
    do {
        // Get height of block.
        n = get_int("Enter block size: ");
        // If height is less than 1, print error message.
        if (n < 1){
            printf("Height must be positive! Try again.\n");
        }
    } while (n < 1);  // If height is less than 1, repeat prompt.
    printf("\nPrinting block of height %i.\n\n", n);
    // Loop to print each row of block.
    for (int i = 0; i < n; i++){
        // Loop to print each column of block.
        for (int j = 0; j < n; j++){
            printf("# ");
        }
        printf("\n");
    }
}