#include <stdio.h>

int main(void) {
    int x = 0, y = 0;

    printf("What is 'x'? ");
    scanf("%d", &x);
    printf("What is 'y'? ");
    scanf("%d", &y);

    if(x > y) {
        printf("The 'x' (%d) is greater than 'y' (%d).\n", x, y);
    }
    else if(x < y) {
        printf("The 'x' (%d) is less than 'y' (%d).\n", x, y);
    }
    else {
        printf("Both are equal.\n");
    }
}