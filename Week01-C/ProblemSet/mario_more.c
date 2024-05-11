#include <cs50.h>
#include <stdio.h>

#define TERMINAL_WIDTH 23

void print_rows(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int bricks;
    do
    {
        bricks = get_int("Height: ");
    } while (bricks < 1 || bricks > TERMINAL_WIDTH);
    // Print the pyramid
    for (int i = 0; i < bricks; i++)
    {
        int spaces = i;
        print_rows(spaces, bricks);
    }
}

// Print a row of bricks
void print_rows(int spaces, int bricks)
{
    // Print spaces
    for (int j = 0; j < bricks - spaces - 1; j++)
    {
        printf(" ");
    }
    // Print bricks left
    for (int k = 0; k < spaces + 1; k++)
    {
        printf("#");
    }
    // Print gap
    printf("  ");
    // Print bricks right
    for (int l = 0; l < spaces + 1; l++)
    {
        printf("#");
    }
    printf("\n");
}