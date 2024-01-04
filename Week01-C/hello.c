#include <stdio.h>
#define MAX_NAME_LENGTH 50 // Defining array length

int main() {
    char answer[MAX_NAME_LENGTH];
    printf("What's your first name? ");
    scanf("%49s", answer); // Added '%49s' to limit the input to 49 characters to avoid buffer overflow.
    printf("Hello, %s!\n", answer);

    return 0;
}