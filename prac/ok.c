#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
long x = pow(10,16);
long ae = 60 % x / pow(10,14) ;

if ( ae == 3 || ae == 34)
{
    printf("AMEX\n");
}
else
{
    printf("INVALID");
}
}