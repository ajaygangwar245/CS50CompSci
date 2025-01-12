#include <cs50.h>
#include <stdio.h>

float addition(float x, float y);
float subtraction(float x, float y);
float multiplication(float x, float y);
float division(float x, float y);

int main(void)
{
    char ch;
    float answer;
    do
    {
        float num1 = get_float("Enter the 1st number: ");
        float num2 = get_float("Enter the 2nd number: ");
        char choice = get_char("Choose operation you want to perform -\n (a)ADD (b)SUBTRACT (C)MULTIPLY (d)DIVIDE : ");

        switch(choice)
        {
            case 'a':
                answer = addition(num1, num2);
                printf("Addition : %f + %f = %.2f\n", num1, num2, answer);
                break;
            case 'b':
                answer = subtraction(num1, num2);
                printf("Subtraction : %f + %f = %.2f\n", num1, num2, answer);
                break;
            case 'c':
                answer = multiplication(num1, num2);
                printf("Multiplication : %f + %f = %.2f\n", num1, num2, answer);
                break;
            case 'd':
                answer = division(num1, num2);
                printf("Division : %f + %f = %.2f\n", num1, num2, answer);
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
        ch = get_char("Do you want to continue? (Y/N): ");
    }
    while(ch == 'Y' || ch == 'y');
}

float addition(float x, float y)
{
    return (double) x + (double) y;
}

float subtraction(float x, float y)
{
    return (double) x - (double) y;
}

float multiplication(float x, float y)
{
    return (double) x * (double) y;
}

float division(float x, float y)
{
    return (double) x / (double) y;
}





