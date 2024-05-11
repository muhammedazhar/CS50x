#include <cs50.h>
#include <stdio.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    // Calculate how many quarters cashier should give customer
    int quarters = calculate_quarters(cents);
    // Subtract the value of those quarters from cents
    cents = cents - (quarters * QUARTER);
    // Calculate how many dimes cashier should give customer
    int dimes = calculate_dimes(cents);
    // Subtract the value of those dimes from cents
    cents = cents - (dimes * DIME);
    // Calculate how many nickels cashier should give customer
    int nickels = calculate_nickels(cents);
    // Subtract the value of those nickels from cents
    cents = cents - (nickels * NICKEL);
    // Calculate how many pennies cashier should give customer
    int pennies = calculate_pennies(cents);
    // Subtract the value of those pennies from cents
    cents = cents - (pennies * PENNY);
    // Print the total number of coins cashier should give customer
    printf("%i\n", quarters + dimes + nickels + pennies);
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarters = 0;
    while (cents >= QUARTER)
    {
        quarters++;
        cents = cents - QUARTER;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give customer
    int dimes = 0;
    while (cents >= DIME)
    {
        dimes++;
        cents = cents - DIME;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculate how many nickels you should give customer
    int nickels = 0;
    while (cents >= NICKEL)
    {
        nickels++;
        cents = cents - NICKEL;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculate how many pennies you should give customer
    int pennies = 0;
    while (cents >= PENNY)
    {
        pennies++;
        cents = cents - PENNY;
    }
    return pennies;
}