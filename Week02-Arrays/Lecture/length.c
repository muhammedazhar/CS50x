#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    int length = strlen(name);
    printf("Your name has %i characters.\n", length);
}