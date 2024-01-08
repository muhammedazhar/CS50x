#include <stdio.h>

int get_int(void);

int main(void) {
    int n = 0, i, j;
    // Prompt user to enter a natural number.
    do {
        n = get_int();
    }
    while (n < 1);
    // Prints an n-by-n grid of bricks.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("# ");
        }
        printf("\n");
    }
}

int get_int(void) {
    int number;
    printf("Enter the size of matrix: ");
    scanf("%i", &number);
    return number;
}