#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Hello, World\n");
    }
    else
    {
        printf("Hello, %s", argv[1]);
        for (int i = 2; i < argc; i++)
        {
            printf(" %s", argv[i]);
        }
        printf("\n");
    }
}
