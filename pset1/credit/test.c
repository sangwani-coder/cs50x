//program to check credit card validity
//
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long CCNumber;
    long divisor = 10;

    do
    {
    CCNumber = get_long("Enter Card Number:");

    }
    while (CCNumber <= 0);

//checksum

int firstDigit, firstTwoDigits,lastDigit, secondToLastDigits;
int i;
int sum=0;
int count=0;
int lastDigits;


 long workingCC = CCNumber;
 //first case
    while (workingCC > 0)
    {
        lastDigits = workingCC % 10;
        sum += lastDigits;
        workingCC = (workingCC / 100);
    }

//second case
   workingCC = CCNumber / 10;
    while (workingCC > 0)
    {
        lastDigits = workingCC % 10;
        int timesTwo = lastDigits * 2;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        workingCC = workingCC / 100;
    }


      workingCC = CCNumber;

      while (workingCC != 0)
     {
         workingCC /= 10;
          count++;
     }


      for (i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    firstDigit = CCNumber / divisor;
    firstTwoDigits = CCNumber / (divisor / 10);


    lastDigit = CCNumber % 10;
    secondToLastDigits = (CCNumber / 10) % 10;

// conditional

     if (sum % 10 ==0)
     {
         if (firstDigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }

         else if ((firstTwoDigits  == 34 || firstTwoDigits == 37) && count ==15)
        {
            printf("AMEX\n");
        }

        else if ((50 < firstTwoDigits || firstTwoDigits > 56) && count ==16)
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