#include <cs50.h>
#include <stdio.h>
#include <math.h>


//Geting value of specific digits
int main(void)





{
    long num = get_long("Number: ");
    //int dig = get_int("What digit? ");




    long s;
    long sum = 0;

    for (int i = 2; i < 17; i += 2)
    {

    long p = pow(10, i);
    long x = num % p / pow(10, (i -1));


    s = (x * 2);

    while(s>0)
        {
        long m = s%10;
        sum = sum + m;
        s = s/10;
        }
    }






    //1st digit
    long k = 0;


    for (int q = 1; q < 17; q += 2)
    {

    long po = pow(10, q);
    long x = num % po / pow(10, (q -1));




    while(x>0)
    {
    long t = x%10;
    k = k + t;
    x = x/10;
    }

    }
long check = k + sum;
//printf("%li", check);
//Check card type




if(check % 10 == 0)
{

    long amex = pow(10,15);
    long ae = num % amex / pow(10,13);

    long master = pow(10,16);
    long mc = num % master / pow(10,14);
    
    long visa1 = pow(10,13);
    long vs1 = num % visa1 / pow(10,12);
    long visa2 = pow(10,16);
    long vs2 = num % visa2 / pow(10,15);


    if(ae == 37 || ae == 34)
    {
        printf("AMEX\n");
    }
    else if(mc == 51 || mc == 52 || mc == 53 || mc == 54 || mc == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (vs1 == 4 || vs2 == 4)
    {
        printf("VISA\n");
    }
}
else
{
    printf("INVALID\n");
}

}


