#include <cs50.h>
#include <stdio.h>

void print_rows(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int bricks;
    do
    {
        bricks = get_int("Height: ");
    } while (bricks < 1);
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
    // Print bricks
    for (int k = 0; k < spaces + 1; k++)
    {
        printf("#");
    }
    printf("\n");
}