#include <stdio.h>

int main(void) {
    printf("What is 'x'? ");
    printf("What is 'y'? ");
    int x = scanf("%d", x);
    int y = scanf("%d", y);

    if(x > y) {
        printf("'x' is greater than 'y'.");
    }
}