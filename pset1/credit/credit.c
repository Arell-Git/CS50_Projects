#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
//Get credit card #
    long num = get_long("Number: ");
    long s;
    long sum = 0;

//Multipy every other digit starting with second digit to the right by two, than add products digits together

    for (int i = 2; i < 17; i += 2)
    {

        long p = pow(10, i);
        long x = num % p / pow(10, (i - 1));


        s = (x * 2);

        while (s > 0)
        {
            long m = s % 10;
            sum = sum + m;
            s = s / 10;
        }
    }

//Add every other digit starting with first to the right

    long k = 0;

    for (int q = 1; q < 17; q += 2)
    {

        long po = pow(10, q);
        long x = num % po / pow(10, (q - 1));

        while (x > 0)
        {
            long t = x % 10;
            k = k + t;
            x = x / 10;
        }

    }
    long check = k + sum;

//Check card type

    if (check % 10 == 0)
    {

        long amex = pow(10, 15);
        long ae = num % amex / pow(10, 13);

        long master = pow(10, 16);
        long mc = num % master / pow(10, 14);

        long visa1 = pow(10, 13);
        long vs1 = num % visa1 / pow(10, 12);
        long visa2 = pow(10, 16);
        long vs2 = num % visa2 / pow(10, 15);


        if (ae == 37 || ae == 34)
        {
            printf("AMEX\n");
        }
        else if (mc == 51 || mc == 52 || mc == 53 || mc == 54 || mc == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (vs1 == 4 || vs2 == 4)
        {
            printf("VISA\n");
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



