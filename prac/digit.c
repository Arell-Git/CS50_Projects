#include <cs50.h>
#include <stdio.h>
#include <math.h>


//Geting value of specific digits
int main(void)
{
    long num = get_long("Number: ");
    //int dig = get_int("What digit? ");





int i = 2;
int x = 0;

while(i < 16)
{
long p = pow(10, i);
x = x  num % p / pow(10, (i -1));

i+=2;
}
printf("%i", x);





}
















