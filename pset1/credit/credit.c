//program to check credit card validity

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long CreditCardNumber;
    long divisor = 10;

    // getting input from user
    do
    {
        CreditCardNumber = get_long("Card Number:");

    }
    while (CreditCardNumber <= 0);

    //variable declaration

    int firstDigit, firstTwoDigits;
    int lastDigit, secondToLastDigits;
    int i;
    int sum = 0, count = 0;
    int lastDigits;


    long validCreditCard = CreditCardNumber;

    //calculating check sum
    // first case
    while (validCreditCard > 0)
    {
        lastDigits = validCreditCard % 10;
        sum += lastDigits;
        validCreditCard /= 100;
    }

    //second case
    validCreditCard = CreditCardNumber / 10;
    while (validCreditCard > 0)
    {
        lastDigits = validCreditCard % 10;
        int timesTwo = lastDigits * 2;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        validCreditCard /= 100;
    }


    validCreditCard = CreditCardNumber;

    //counter
    while (validCreditCard != 0)
    {
        validCreditCard /= 10;
        count++;
    }

    // Divisor to get first and first two digits
    for (i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    firstDigit = CreditCardNumber / divisor;
    firstTwoDigits = CreditCardNumber / (divisor / 10);


    lastDigit = CreditCardNumber % 10;
    secondToLastDigits = (CreditCardNumber / 10) % 10;

    // conditions to check card length and starting numbers

    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }

        else if ((firstTwoDigits  == 34 || firstTwoDigits == 37) && count == 15)
        {
            printf("AMEX\n");
        }

        else if ((50 < firstTwoDigits && firstTwoDigits <= 55) && count == 16)
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}