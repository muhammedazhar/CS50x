#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int calls = 4;
    calls = calls + 1;
    calls = calls - 2;
    calls = calls * 3;
    calls = calls / 2;

    printf("The number of calls is %i\n", calls);
}