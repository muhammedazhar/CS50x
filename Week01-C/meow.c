#include <stdio.h>

void meow(void); // Setting function prototype.

int main(void) {
    for(int i = 0; i < 3; i++) {
        meow();
    }

    return 0;
}

void meow(void) {
    printf("meow\n");
}