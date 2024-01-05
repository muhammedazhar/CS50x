#include <stdio.h>

int main(void) {
    int x = 0, y = 0;
    printf("x: ");
    scanf("%i", &x);
    printf("y: ");
    scanf("%i", &y);

    printf("x + y = %i\n", x + y);
}