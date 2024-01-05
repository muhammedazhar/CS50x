#include <stdio.h>

int add(int x, int y);

int main(void) {
    int x = 0, y = 0;
    printf("x: ");
    scanf("%i", &x);
    printf("y: ");
    scanf("%i", &y);

    printf("x + y = %i\n", add(x, y));
}

int add(int a, int b) {
    return a + b;
}