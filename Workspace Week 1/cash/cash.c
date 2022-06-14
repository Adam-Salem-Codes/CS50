#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents -= pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int amount; // Declares integer amount
    do
    {
        amount = get_int("Cents: ");// Prompts user to input amount of money owed...
    }
    while (amount <= 0); // Ask them while this condition is true. If it's false than don't ask.

    return amount; // returns the amount.
}

int calculate_quarters(int cents)
{
    int amount_of_quarters = 0;
    while (cents >= 25)
    {
        amount_of_quarters++;
        cents -= 25;
    }

    return amount_of_quarters; // returns the amount of quarters needed.
}

int calculate_dimes(int cents)
{
    int amount_of_dimes = 0;
    while (cents >= 10)
    {
        amount_of_dimes++;
        cents -= 10;
    }

    return amount_of_dimes; //returns the amount of dimes needed
}

int calculate_nickels(int cents)
{
    int amount_of_nickels = 0;
    while (cents >= 5)
    {
        amount_of_nickels++;
        cents -= 5;
    }

    return amount_of_nickels; //returns the amount of nickels needed
}

int calculate_pennies(int cents)
{
    int amount_of_pennies = 0;
    while (cents >= 1)
    {
        amount_of_pennies++;
        cents -= 1;
    }

    return amount_of_pennies; //returns the amount of pennies needed
}
