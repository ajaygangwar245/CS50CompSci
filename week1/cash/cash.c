#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompts user for change
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // print number of coins to give
    int quarters, dimes, nickels, pennies, coins;

    // number of quarters
    quarters = cents / 25;
    cents = cents % 25;

    // number of dimes
    dimes = cents / 10;
    cents = cents % 10;

    // number of nickels
    nickels = cents / 5;
    cents = cents % 5;

    // number of pennies
    pennies = cents / 1;
    cents = cents % 1;

    coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}
