#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MIN_CARD_LENGTH 13
#define MAX_CARD_LENGTH 16
#define AMEX_CARD_LENGTH 15

// Function prototypes
string removeNonNumeric(string str);
string getCardType(string card_number);
bool luhnAlgorithm(string card_number);

int main(void)
{
    string card_number;
    card_number = get_string("Number: ");
    // Remove non-numeric characters from the card number
    card_number = removeNonNumeric(card_number);
    // Check if the card number is valid according to Luhn's algorithm
    if (luhnAlgorithm(card_number))
    {
        // Determine and print the card type
        string card_type = getCardType(card_number);
        printf("%s", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Function to remove non-numeric characters from a string
string removeNonNumeric(string str)
{
    size_t j = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Add null terminator to the end of the string
    return str;
}

// Function to determine the card type
string getCardType(string card_number)
{
    int length = strlen(card_number);
    // Check for a VISA card
    if (card_number[0] == '4' && (length == MIN_CARD_LENGTH || length == MAX_CARD_LENGTH))
    {
        return "VISA\n";
    }
    // Check for a MasterCard
    else if (length == MAX_CARD_LENGTH && card_number[0] == '5' && card_number[1] >= '1' && card_number[1] <= '5')
    {
        return "MASTERCARD\n";
    }
    // Check for AMEX card
    else if (length == AMEX_CARD_LENGTH && card_number[0] == '3' && (card_number[1] == '4' || card_number[1] == '7'))
    {
        return "AMEX\n";
    }
    // Otherwise, the card is invalid
    else
    {
        return "INVALID\n";
    }
}

// Function to implement Luhn's algorithm
bool luhnAlgorithm(string card_number)
{
    int length = strlen(card_number);
    int sum = 0;
    // Iterate over the digits in reverse order
    for (int i = length - 1; i >= 0; i--)
    {
        int digit = card_number[i] - '0';
        // Double every second digit
        if ((length - i) % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        // Add the digit to the sum
        sum += digit;
    }
    // Check if the sum is divisible by 10
    return sum % 10 == 0;
}