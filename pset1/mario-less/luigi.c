#include <cs50.h>
#include <stdio.h>

int main(void)
{
//prompts user for height
int height;
do
    height = get_int("Height: ");
while( height < 1 || height > 8 );
//height minus "i" is number of spaces needed per row
     for (int i = 1; i <= height; i++)
  {
    for (int s = height - i; s > 0; s--)
    {
        printf(" ");
    }
      for (int j = 0; j < i; j++)
      {
          printf("#");
      }
      printf("\n");
  }
}












