#include <cs50.h>
#include <stdio.h>

int checkSum(long card_num);

int main(void)
{
    // prompts user for card number
    long number = get_long("Number: ");

    // stores returned checksum value
    int check = checkSum(number);

    // if card is valid then prints type of card
    if (((number / 10000000000000) == 37 || (number / 10000000000000) == 34) && (check % 10 == 0))
    {
        printf("AMEX\n");
    }
    else if (((number / 100000000000000) == 51 || (number / 100000000000000) == 52 || (number / 100000000000000) == 53 ||
              (number / 100000000000000) == 54 || (number / 100000000000000) == 55) &&
             (check % 10 == 0))
    {
        printf("MASTERCARD\n");
    }
    else if (((number / 1000000000000000) == 4 || (number / 1000000000000) == 4) && (check % 10 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// checks the card number and returns checkSum
int checkSum(long card_num)
{
    int checksum, second_last_digit, last_digit, product;
    int sum_of_product = 0;
    int sum_of_leftover_digits = 0;

    while (card_num != 0)
    {
        // last and second last digit
        second_last_digit = (card_num / 10) % 10;
        last_digit = card_num % 10;

        // multiply second last digit with 2 and sum all the products
        product = 2 * second_last_digit;
        if (product >= 10)
        {
            product = (product / 10) + (product % 10);
            sum_of_product += product;
        }
        else
        {
            sum_of_product += product;
        }

        // sum of remaining digits which are multiplied by 2
        sum_of_leftover_digits += last_digit;

        card_num = card_num / 100;
    }

    // checksum
    checksum = sum_of_product + sum_of_leftover_digits;
    return checksum;
}
