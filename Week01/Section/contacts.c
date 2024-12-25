#include <cs50.h>
#include <stdio.h>

int main(void){
    string name = get_string("What is your name? ");
    int age = get_int("What is your age? ");
    string number = get_string("What is your phone number? ");

    printf("Hello, %s\n", name);
    printf("You are %i years old.\n", age);
    printf("Your phone number is %s\n", number);
}