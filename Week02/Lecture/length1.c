#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("Number of characters: %i\n", n);
}
