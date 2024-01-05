#include <stdio.h>

void meow(int n); // Setting function prototype.

int main(void) {
    int m = 0;
    printf("How many meows you want? ");
    scanf("%d", &m);
    meow(m);
}

void meow(int n) {
    for(int i = 0; i < n; i++) {
        printf("meow\n");
    }
}