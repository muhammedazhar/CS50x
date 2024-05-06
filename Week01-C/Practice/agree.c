#include <stdio.h>

int main(void) {
    char c;
    printf("Do you agree? ");
    scanf(" %c", &c);
    if(c == 'y' || c == 'Y') {
        printf("User agreed!\n");
    }
    else if(c == 'n' || c == 'N') {
        printf("User NOT agreed!\n");
    }
    else {
        printf("Please enter only 'y' or 'Y' for yes, 'n' or 'N' for no.\n");
    }
}